
// Qt
#include <QDebug>
#include <QTemporaryDir>
#include <QThread>
#include <QFile>

// std
#include <type_traits>

// qt-plus
#include "CAverager.h"
#include "CLazyPointer.h"
#include "CLogger.h"
#include "CSingleton.h"
#include "CTimeSampler.h"
#include "CTracableMutex.h"
#include "CXMLNode.h"
#include "QTree.h"
#include "File/CRollingFiles.h"
#include "RemoteControl/CRemoteControl.h"

#include "CUnitTests.h"

//-------------------------------------------------------------------------------------------------

// Dummy singleton used by the race test: never touch production singletons here,
// killing them would break the other slots.
class SmokeDummySingleton : public CSingleton<SmokeDummySingleton>
{
public:

    SmokeDummySingleton()
        : m_iValue(42)
    {
    }

    int m_iValue;
};

//-------------------------------------------------------------------------------------------------

static int g_iLazyInstantiations = 0;

static int* smoke_lazyInstantiator(void* pContext)
{
    g_iLazyInstantiations++;
    return new int(*static_cast<int*>(pContext));
}

//-------------------------------------------------------------------------------------------------

// File helpers without QTest macros (QVERIFY/QCOMPARE expand to return
// statements and must never appear inside a lambda).

static bool smoke_writeFile(const QString& sPath, const QByteArray& sData)
{
    QFile tFile(sPath);

    if (tFile.open(QIODevice::WriteOnly | QIODevice::Truncate) == false)
    {
        return false;
    }

    return tFile.write(sData) == sData.size();
}

static QByteArray smoke_readFile(const QString& sPath, bool* pOk = nullptr)
{
    QFile tFile(sPath);

    if (tFile.open(QIODevice::ReadOnly) == false)
    {
        if (pOk != nullptr) *pOk = false;
        return QByteArray();
    }

    if (pOk != nullptr) *pOk = true;
    return tFile.readAll();
}

//-------------------------------------------------------------------------------------------------

CUnitTests::CUnitTests()
{
}

//-------------------------------------------------------------------------------------------------

CUnitTests::~CUnitTests()
{
}

//-------------------------------------------------------------------------------------------------

void CUnitTests::xml()
{
    CXMLNode xTest;
    QVERIFY(true);
}

//-------------------------------------------------------------------------------------------------

void CUnitTests::remoteControlMultiClient()
{
    CRemoteControl rcServer(CRemoteControl::defaultPort());
    CRemoteControl rcClient1("127.0.0.1", CRemoteControl::defaultPort());
    CRemoteControl rcClient2("127.0.0.1", CRemoteControl::defaultPort());

    QVERIFY(rcClient1.connectedToServer());

    rcClient1.setLoginPassword("guest", "guest");
    rcClient1.sendCommand("dir", false, true);

    rcClient2.setLoginPassword("guest", "guest");
    rcClient2.sendCommand("dir", false, true);
}

//-------------------------------------------------------------------------------------------------
// Clamped window sizes, no division by zero

void CUnitTests::averagerZeroClamp()
{
    CRollingAverager<double> tRolling(0);   // must clamp to 1, not divide by zero
    tRolling.append(5.0);
    QCOMPARE(tRolling.getAverage(), 5.0);

    CAverager<int> tAverager(0);            // must clamp to 1, not stay empty
    tAverager.append(3);
    QCOMPARE(tAverager.getAverage(), 3);
}

//-------------------------------------------------------------------------------------------------
// Checked, rename-based rotation

void CUnitTests::rollingFilesCheckedBackup()
{
    CRollingFiles tEmpty;
    QVERIFY(!tEmpty.backup());              // empty file name: refuse, no stray ".0"

    QTemporaryDir tDir;
    QVERIFY(tDir.isValid());

    CRollingFiles tZero(tDir.path() + "/zero.log", 0);
    QVERIFY(!tZero.backup());               // degenerate backup count: refuse

    CRollingFiles tRoll(tDir.path() + "/roll.log", 2);

    QVERIFY(smoke_writeFile(tRoll.fileName(), "v1"));
    QVERIFY(tRoll.backup());

    bool bOk = false;
    QCOMPARE(smoke_readFile(tRoll.fileName() + ".0", &bOk), QByteArray("v1"));
    QVERIFY(bOk);

    QVERIFY(smoke_writeFile(tRoll.fileName(), "v2"));
    QVERIFY(tRoll.backup());
    QCOMPARE(smoke_readFile(tRoll.fileName() + ".0", &bOk), QByteArray("v1"));
    QVERIFY(bOk);
    QCOMPARE(smoke_readFile(tRoll.fileName() + ".1", &bOk), QByteArray("v2"));
    QVERIFY(bOk);

    QVERIFY(smoke_writeFile(tRoll.fileName(), "v3"));
    QVERIFY(tRoll.backup());                // rotation: .1 -> .0, live -> .1
    QCOMPARE(smoke_readFile(tRoll.fileName() + ".0", &bOk), QByteArray("v2"));
    QVERIFY(bOk);
    QCOMPARE(smoke_readFile(tRoll.fileName() + ".1", &bOk), QByteArray("v3"));
    QVERIFY(bOk);
}

//-------------------------------------------------------------------------------------------------
// Singleton race and kill-before-init

void CUnitTests::singletonRaceAndKill()
{
    SmokeDummySingleton::killInstance();  // must not crash before any getInstance()

    const int iThreads = 8;
    QVector<SmokeDummySingleton*> vResults(iThreads, nullptr);
    QVector<QThread*> vThreads;
    vThreads.reserve(iThreads);

    for (int i = 0; i < iThreads; i++)
    {
        vThreads << QThread::create([&, i]() {
            vResults[i] = SmokeDummySingleton::getInstance();
        });
    }

    for (QThread* pThread : vThreads) pThread->start();
    for (QThread* pThread : vThreads)
    {
        QVERIFY(pThread->wait(30000));
        delete pThread;
    }

    for (int i = 1; i < iThreads; i++)
    {
        QVERIFY(vResults[i] != nullptr);
        QCOMPARE(vResults[i], vResults[0]); // exactly one instance
    }
    QCOMPARE(vResults[0]->m_iValue, 42);

    SmokeDummySingleton::killInstance();
    SmokeDummySingleton::killInstance();  // double kill: no-op, no crash
}

//-------------------------------------------------------------------------------------------------
// Chained logger cycle must terminate instead of overflowing the stack

void CUnitTests::loggerChainedCycle()
{
    QTemporaryDir tDir;
    QVERIFY(tDir.isValid());

    CLogger tLoggerA(tDir.path(), "a.log");
    CLogger tLoggerB(tDir.path(), "b.log");

    tLoggerA.registerChainedLogger(&tLoggerB);
    tLoggerB.registerChainedLogger(&tLoggerA);   // cycle!

    tLoggerA.log(llWarning, "cycle-probe", "SmokeTest");  // must return
    tLoggerB.log(llWarning, "cycle-probe", "SmokeTest");  // must return

    // No event loop runs during the test, so the periodic flush timer never
    // fires: flush explicitly before reading the files back.
    tLoggerA.flush();
    tLoggerB.flush();

    tLoggerA.unregisterChainedLogger(&tLoggerB);
    tLoggerB.unregisterChainedLogger(&tLoggerA);

    bool bOkA = false, bOkB = false;
    QByteArray sLogA = smoke_readFile(tDir.path() + "/a.log", &bOkA);
    QByteArray sLogB = smoke_readFile(tDir.path() + "/b.log", &bOkB);

    QVERIFY(bOkA);
    QVERIFY(bOkB);
    QVERIFY(sLogA.contains("cycle-probe"));
    QVERIFY(sLogB.contains("cycle-probe"));
}

//-------------------------------------------------------------------------------------------------
// Concurrent sampling during dump must not crash

void CUnitTests::timeSamplerConcurrentDump()
{
    const int iThreads = 4;
    const int iIters = 200;
    QVector<QThread*> vThreads;
    vThreads.reserve(iThreads);

    for (int i = 0; i < iThreads; i++)
    {
        vThreads << QThread::create([=]() {
            for (int j = 0; j < iIters; j++)
            {
                CTimeSampler::getInstance()->startSample("smoke-sample");
                CTimeSampler::getInstance()->stopSample("smoke-sample");
            }
        });
    }

    for (QThread* pThread : vThreads) pThread->start();

    for (int j = 0; j < 20; j++)
    {
        CTimeSampler::getInstance()->dumpAccumulatedTimes();  // unlocked maps used to crash here
    }

    for (QThread* pThread : vThreads)
    {
        QVERIFY(pThread->wait(60000));
        delete pThread;
    }

    QVERIFY(true);  // reaching here without crashing is the assertion
}

//-------------------------------------------------------------------------------------------------
// No shared ownership: copies are rejected, loads are cached

void CUnitTests::lazyPointerOwnership()
{
    QVERIFY(!std::is_copy_constructible<CLazyPointer<int>>::value);
    QVERIFY(!std::is_copy_assignable<CLazyPointer<int>>::value);

    g_iLazyInstantiations = 0;
    int iSeed = 7;

    CLazyPointer<int> tPointer(smoke_lazyInstantiator, &iSeed);

    QCOMPARE(*tPointer.get(), 7);
    QCOMPARE(g_iLazyInstantiations, 1);
    QVERIFY(tPointer.get() == tPointer.get());   // cached, no second factory call
    QCOMPARE(g_iLazyInstantiations, 1);

    tPointer.clear();
    QCOMPARE(*tPointer.get(), 7);                // reloads after clear
    QCOMPARE(g_iLazyInstantiations, 2);
}

//-------------------------------------------------------------------------------------------------
// Removing siblings must keep the survivors' parent links navigable

void CUnitTests::qtreeRemoveKeepsParentsValid()
{
    QTree<QString> tTree("Root");
    tTree.append("A");
    tTree.append("B");
    tTree.append("C");
    tTree.getChildren()[1] << "B1";              // grandchild under B

    tTree.removeAt(0);                           // removes A, shifts B and C

    QCOMPARE(tTree.count(), 2);

    QTree<QString>* pGrandChild = tTree.nodeForValue("B1");
    QVERIFY(pGrandChild != nullptr);
    QCOMPARE(pGrandChild->root()->value(), QString("Root"));
    QCOMPARE(pGrandChild->parent()->value(), QString("B"));

    tTree.removeAll(QString("B"));               // removes the B subtree

    QCOMPARE(tTree.count(), 1);
    QCOMPARE(tTree.getChildren()[0].root()->value(), QString("Root"));
}

//-------------------------------------------------------------------------------------------------
// path() must instantiate and join the ancestor chain with the separator

void CUnitTests::qtreePathCompilesAndJoins()
{
    QTree<QString> tTree("Root");
    tTree.append("A");
    tTree.getChildren()[0] << "A1";

    QCOMPARE(tTree.getChildren()[0].getChildren()[0].path(), QString("Root/A/A1"));
    QCOMPARE(tTree.path(), QString("Root"));
}

//-------------------------------------------------------------------------------------------------
// A mutex must not be copyable, and lock() must only return when held

void CUnitTests::tracableMutexNonCopyableAndBlocking()
{
    QVERIFY(!std::is_copy_constructible<CTracableMutex>::value);
    QVERIFY(!std::is_copy_assignable<CTracableMutex>::value);

    CTracableMutex tMutex("smoke");
    QVERIFY(tMutex.lock("smoke-test"));
    tMutex.unlock();
    QVERIFY(tMutex.lock());
    tMutex.unlock();
}

//-------------------------------------------------------------------------------------------------
// Parse and load failures must say why instead of silently returning an empty node

void CUnitTests::xmlLoadReportsErrors()
{
    QString sError;

    CXMLNode xBad = CXMLNode::parseXML("<root><unclosed>", &sError);
    QVERIFY(xBad.isEmpty());
    QVERIFY(!sError.isEmpty());

    sError.clear();
    CXMLNode xGood = CXMLNode::parseXML("<root><a>1</a></root>", &sError);
    QVERIFY(!xGood.isEmpty());
    QVERIFY(sError.isEmpty());

    sError.clear();
    CXMLNode jBad = CXMLNode::parseJSON("{invalid}", &sError);
    QVERIFY(jBad.isEmpty());
    QVERIFY(!sError.isEmpty());

    sError.clear();
    CXMLNode xMissing = CXMLNode::load("/nonexistent/path/missing.xml", &sError);
    QVERIFY(xMissing.isEmpty());
    QVERIFY(!sError.isEmpty());

    // Without an error pointer the contract is unchanged: empty node, no crash
    QVERIFY(CXMLNode::parseXML("<root><unclosed>").isEmpty());
}

//-------------------------------------------------------------------------------------------------
// Pretty-printed indentation must not become child nodes

void CUnitTests::xmlSkipsWhitespaceTextNodes()
{
    CXMLNode xRoot = CXMLNode::parseXML("<root>\n  <a>1</a>\n  <b>2</b>\n</root>");

    QCOMPARE(xRoot.nodes().count(), 2);
    QCOMPARE(xRoot.getNodeByTagName("a").value(), QString("1"));
    QCOMPARE(xRoot.getNodeByTagName("b").value(), QString("2"));
}

//-------------------------------------------------------------------------------------------------
// JSON scalars and arrays must survive the conversion with their values

void CUnitTests::jsonPreservesScalarsAndArrays()
{
    CXMLNode xRoot = CXMLNode::parseJSON("{\"n\":3,\"b\":true,\"arr\":[\"x\",\"y\"]}");

    QCOMPARE(xRoot.attributes().value("n"), QString("3"));
    QCOMPARE(xRoot.attributes().value("b"), QString("true"));

    CXMLNodeList vArr = xRoot.getNodesByTagName("arr");
    QCOMPARE(vArr.count(), 2);
    QCOMPARE(vArr[0].value(), QString("x"));
    QCOMPARE(vArr[1].value(), QString("y"));

    CXMLNode xTopArray = CXMLNode::parseJSON("[1,2]");
    QCOMPARE(xTopArray.nodes().count(), 2);
    QCOMPARE(xTopArray.nodes()[0].value(), QString("1"));
    QCOMPARE(xTopArray.nodes()[1].value(), QString("2"));
}

//-------------------------------------------------------------------------------------------------
// An empty tag must not silently discard the subtree on export

void CUnitTests::xmlEmptyTagExportsChildren()
{
    CXMLNode xRoot;
    xRoot << CXMLNode("a");
    xRoot.nodes()[0].setValue("1");

    QVERIFY(xRoot.toString(false).contains("<a>1</a>"));
}

//-------------------------------------------------------------------------------------------------

QTEST_MAIN(CUnitTests)
