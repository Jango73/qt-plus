
// Qt
#include <QDebug>
#include <QDateTime>
#include <QElapsedTimer>
#include <QFileInfo>
#include <QTemporaryDir>
#include <QThread>
#include <QFile>

// std
#include <atomic>
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
#include "File/CShardFileStore.h"
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
// Kill during concurrent get must not deadlock: the destructor runs outside
// the pool lock, so getters keep flowing through getInstance while it runs

static QAtomicInt s_iBlockingGettersDone = 0;
static QAtomicInt s_iBlockingGettersActive = 0;

class SmokeBlockingSingleton : public CSingleton<SmokeBlockingSingleton>
{
public:

    SmokeBlockingSingleton()
    {
    }

    ~SmokeBlockingSingleton()
    {
        // Wait for getter progress during the kill. With the pool lock held
        // across delete getters stay blocked and this spins the full budget.
        // Skipped when no getter runs (final cleanup kill).
        int iBaseline = s_iBlockingGettersDone.loadRelaxed();

        for (int iSpin = 0; iSpin < 1000; iSpin++)
        {
            if (s_iBlockingGettersDone.loadRelaxed() != iBaseline)
            {
                break;
            }

            if (s_iBlockingGettersActive.loadRelaxed() == 0)
            {
                break;
            }

            QThread::msleep(5);
        }
    }
};

void CUnitTests::singletonKillDuringGet()
{
    SmokeBlockingSingleton::killInstance();  // start clean

    QVERIFY(SmokeBlockingSingleton::getInstance() != nullptr);

    s_iBlockingGettersDone.storeRelaxed(0);
    s_iBlockingGettersActive.storeRelaxed(1);

    std::atomic<bool> bStop{false};

    const int iThreads = 4;
    QVector<QThread*> vThreads;
    vThreads.reserve(iThreads);

    for (int i = 0; i < iThreads; i++)
    {
        vThreads << QThread::create([&]() {
            while (bStop.load() == false)
            {
                if (SmokeBlockingSingleton::getInstance() != nullptr)
                {
                    s_iBlockingGettersDone.ref();
                }
            }
        });
    }

    for (QThread* pThread : vThreads) pThread->start();

    QThread::msleep(50);  // let getters enter getInstance

    QElapsedTimer tTimer;
    tTimer.start();
    SmokeBlockingSingleton::killInstance();  // must return, not deadlock
    qint64 iKillMs = tTimer.elapsed();

    bStop.store(true);

    for (QThread* pThread : vThreads)
    {
        QVERIFY(pThread->wait(30000));
        delete pThread;
    }

    s_iBlockingGettersActive.storeRelaxed(0);

    QVERIFY(s_iBlockingGettersDone.loadRelaxed() > 0);  // getters flowed during kill
    QVERIFY(iKillMs < 4000);  // old code spins the full 5 s destructor budget

    SmokeBlockingSingleton::killInstance();  // drop the replacement instance
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

    CTimeSampler::getInstance()->setEnabled(true);

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

    CTimeSampler::getInstance()->setEnabled(false);

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
// Binary persistence must round-trip the full hierarchy and report errors

void CUnitTests::xmlBinaryRoundTrip()
{
    CXMLNode xRoot("root");
    xRoot.attributes()["name"] = QString::fromUtf8("héllo");
    xRoot.setValue("");

    CXMLNode xChild("item");
    xChild.attributes()["id"] = "1";
    xChild.setValue("first");
    xRoot << xChild;

    CXMLNode xNested("item");
    xNested.attributes()["id"] = "2";
    xNested.setValue("second");

    CXMLNode xLeaf("leaf");
    xLeaf.setValue(QString::fromUtf8("ünicode"));
    xNested << xLeaf;

    xRoot << xNested;

    QByteArray sBinary = xRoot.toBinary();
    QVERIFY(!sBinary.isEmpty());

    QString sError;
    CXMLNode xDecoded = CXMLNode::fromBinary(sBinary, &sError);
    QVERIFY2(sError.isEmpty(), qPrintable(sError));
    QVERIFY(xDecoded == xRoot);

    // Empty node round-trip
    CXMLNode xEmptyDecoded = CXMLNode::fromBinary(CXMLNode().toBinary());
    QVERIFY(xEmptyDecoded == CXMLNode());

    // File round-trip through the dedicated and generic entry points
    QTemporaryDir tDir;
    QVERIFY(tDir.isValid());

    QString sFileName = tDir.path() + "/node.bin";
    QVERIFY(xRoot.saveBINToFile(sFileName));

    sError.clear();
    CXMLNode xFromFile = CXMLNode::loadBINFromFile(sFileName, &sError);
    QVERIFY2(sError.isEmpty(), qPrintable(sError));
    QVERIFY(xFromFile == xRoot);

    QString sGenericFile = tDir.path() + "/generic.bin";
    QVERIFY(xRoot.save(sGenericFile));
    QVERIFY(CXMLNode::load(sGenericFile) == xRoot);

    // Error paths: no crash, empty node, error text when requested
    sError.clear();
    QVERIFY(CXMLNode::fromBinary(QByteArray(), &sError).isEmpty());
    QVERIFY(!sError.isEmpty());

    sError.clear();
    QVERIFY(CXMLNode::fromBinary(QByteArray("not-a-node"), &sError).isEmpty());
    QVERIFY(!sError.isEmpty());

    QByteArray sTruncated = sBinary.left(sBinary.size() / 2);
    sError.clear();
    QVERIFY(CXMLNode::fromBinary(sTruncated, &sError).isEmpty());
    QVERIFY(!sError.isEmpty());

    sError.clear();
    QVERIFY(CXMLNode::loadBINFromFile(tDir.path() + "/missing.bin", &sError).isEmpty());
    QVERIFY(!sError.isEmpty());

    QVERIFY(CXMLNode::fromBinary(QByteArray()).isEmpty());
}

//-------------------------------------------------------------------------------------------------
// Sharded map: routing, splits, dirty-only writes, reload, removal

void CUnitTests::shardFileStoreRoutingSplitAndPersistence()
{
    QTemporaryDir tDir;
    QVERIFY(tDir.isValid());

    QString sFolder = tDir.path() + "/cache";

    // Small threshold forces root and nested splits with few entries
    CShardFileStore tStore(sFolder, "TestShardStore", nullptr, 8, true);

    // Phase 1: keys spread over all 16 first hex characters (splits the root)
    QStringList lSpreadKeys;

    for (int iIndex = 0; iIndex < 32; iIndex++)
    {
        QString sKey = QString("%1").arg(iIndex % 16, 1, 16, QChar('0'))
                + QString("%1").arg(iIndex, 63, 16, QChar('0'));
        lSpreadKeys << sKey;
        tStore.setValue(sKey, QStringList() << QString("parent-%1").arg(iIndex));
    }

    QVERIFY(tStore.shardCount() > 1);

    for (const QString& sKey : lSpreadKeys)
    {
        QVERIFY(tStore.containsValue(sKey));
        QVERIFY(tStore.shardPrefixForKey(sKey).length() >= 1);
        QVERIFY(tStore.value(sKey).count() == 1);
    }

    // Phase 2: keys sharing one prefix (forces a nested split below the root)
    QStringList lNestedKeys;

    for (int iIndex = 0; iIndex < 20; iIndex++)
    {
        QString sKey = QString("ab%1").arg(iIndex, 62, 16, QChar('0'));
        lNestedKeys << sKey;
        tStore.setValue(sKey, QStringList() << "p1" << "p2");
    }

    for (const QString& sKey : lNestedKeys)
    {
        QVERIFY(tStore.shardPrefixForKey(sKey).startsWith("ab"));
        QCOMPARE(tStore.value(sKey), QStringList() << "p1" << "p2");
    }

    // Empty lists round-trip distinctly from missing keys
    QString sEmptyKey = QString("cd%1").arg(0, 62, 16, QChar('0'));
    tStore.setValue(sEmptyKey, QStringList());
    QVERIFY(tStore.containsValue(sEmptyKey));
    QVERIFY(tStore.value(sEmptyKey).isEmpty());

    // Non-hex keys fall back to the root shard without error
    tStore.setValue("not-a-hex-key!!", QStringList() << "v");
    QCOMPARE(tStore.shardPrefixForKey("not-a-hex-key!!"), QString(""));
    QCOMPARE(tStore.value("not-a-hex-key!!"), QStringList() << "v");

    // Missing keys resolve to empty without polluting the store
    QVERIFY(!tStore.containsValue("ff00000000000000000000000000000000000000000000000000000000000000"));
    QVERIFY(tStore.value("ff00000000000000000000000000000000000000000000000000000000000000").isEmpty());

    // No-op writes do not dirty anything: a fresh check below relies on save() below
    QString sFirstKey = lSpreadKeys.first();
    QStringList lFirstValue = tStore.value(sFirstKey);
    tStore.setValue(sFirstKey, lFirstValue);

    tStore.save();

    // Reload from disk through a fresh instance
    CShardFileStore tReloaded(sFolder, "TestShardStore", nullptr, 8, true);

    for (const QString& sKey : lSpreadKeys)
        QVERIFY(tReloaded.containsValue(sKey));

    for (const QString& sKey : lNestedKeys)
        QCOMPARE(tReloaded.value(sKey), QStringList() << "p1" << "p2");

    QVERIFY(tReloaded.containsValue(sEmptyKey));
    QVERIFY(tReloaded.value(sEmptyKey).isEmpty());
    QCOMPARE(tReloaded.value("not-a-hex-key!!"), QStringList() << "v");

    // Dirty-only persistence: untouched shard files keep their modification time
    QMap<QString, QDateTime> mTimesBefore;

    for (const QString& sPrefix : tReloaded.knownPrefixes())
    {
        QFileInfo tInfo(tReloaded.shardFileName(sPrefix));

        if (tInfo.exists())
            mTimesBefore[sPrefix] = tInfo.lastModified();
    }

    QVERIFY(mTimesBefore.count() > 1);

    QString sTouchedPrefix = tReloaded.shardPrefixForKey(lNestedKeys.first());
    tReloaded.setValue(lNestedKeys.first(), QStringList() << "p1" << "p2" << "p3");
    tReloaded.save();

    QCOMPARE(tReloaded.value(lNestedKeys.first()), QStringList() << "p1" << "p2" << "p3");

    for (auto iEntry = mTimesBefore.constBegin(); iEntry != mTimesBefore.constEnd(); iEntry++)
    {
        if (iEntry.key() == sTouchedPrefix)
            continue;

        QFileInfo tInfo(tReloaded.shardFileName(iEntry.key()));
        QVERIFY(tInfo.exists());
        QCOMPARE(tInfo.lastModified(), iEntry.value());
    }

    // Removal drops the entry and persists through reload
    tReloaded.removeValue(sFirstKey);
    QVERIFY(!tReloaded.containsValue(sFirstKey));
    tReloaded.save();

    CShardFileStore tPruned(sFolder, "TestShardStore", nullptr, 8, true);
    QVERIFY(!tPruned.containsValue(sFirstKey));
    QVERIFY(tPruned.containsValue(lSpreadKeys.last()));
}

//-------------------------------------------------------------------------------------------------

QTEST_MAIN(CUnitTests)
