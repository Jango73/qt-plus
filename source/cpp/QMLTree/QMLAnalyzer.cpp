
// Qt
#include <QMessageBox>
#include <QFileInfo>
#include <QDir>
#include <QRegExp>
#include <QMutexLocker>
#include <QDebug>

// Application
#include "QMLAnalyzer.h"
#include "QMLItem.h"
#include "QMLFunction.h"

//-------------------------------------------------------------------------------------------------

#define ANALYZER_TOKEN_MACRO        "Macro"
#define ANALYZER_TOKEN_NAME         "Name"
#define ANALYZER_TOKEN_CHECK        "Check"
#define ANALYZER_TOKEN_CLASS        "Class"
#define ANALYZER_TOKEN_COUNT        "Count"
#define ANALYZER_TOKEN_MEMBER       "Member"
#define ANALYZER_TOKEN_NESTED_COUNT "NestedCount"
#define ANALYZER_TOKEN_ACCEPT       "Accept"
#define ANALYZER_TOKEN_REJECT       "Reject"
#define ANALYZER_TOKEN_TEXT         "Text"
#define ANALYZER_TOKEN_TYPE         "Type"
#define ANALYZER_TOKEN_VALUE        "Value"
#define ANALYZER_TOKEN_REGEXP       "RegExp"
#define ANALYZER_TOKEN_PATH         "Path"
#define ANALYZER_TOKEN_EXISTS       "Exists"
#define ANALYZER_TOKEN_CONDITION    "Condition"
#define ANALYZER_TOKEN_EMPTY        "Empty"
#define ANALYZER_TOKEN_TRUE         "true"
#define ANALYZER_TOKEN_FALSE        "false"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CCodeAnalyzer.
*/
QMLAnalyzer::QMLAnalyzer()
    : QThread(NULL)
    , m_mContextMutex(QMutex::Recursive)
    , m_pContext(nullptr)
    , m_bIncludeImports(false)
    , m_bIncludeSubFolders(false)
    , m_bRewriteFiles(false)
    , m_bRemoveUnreferencedSymbols(false)
    , m_bStopAnalyzeRequested(false)
{
    m_eEngine.globalObject().setProperty("analyzer", m_eEngine.newQObject(new QMLAnalyzerWrapper(this)));

    QFile fScript(":/beautify.js");
    if (fScript.open(QFile::ReadOnly))
    {
        m_sBeautifyScript = fScript.readAll();
        fScript.close();
    }
}

/*!
    Destroys a CCodeAnalyzer.
*/
QMLAnalyzer::~QMLAnalyzer()
{
    m_eEngine.globalObject().setProperty("analyzer", m_eEngine.newQObject(nullptr));

    if (m_pContext != nullptr)
    {
        delete m_pContext;
    }
}

/*!
    Sets the base folder member to \a sFolder.
*/
void QMLAnalyzer::setFolder(const QString& sFolder)
{
    m_sFolder = sFolder;
}

/*!
    Sets the base file member to \a sFileName.
*/
void QMLAnalyzer::setFile(const QString& sFileName)
{
    m_sFile = sFileName;
}

/*!
    Sets the include imports flag to \a bValue.
*/
void QMLAnalyzer::setIncludeImports(bool bValue)
{
    m_bIncludeImports = bValue;
}

/*!
    Sets the include subfolders flag to \a bValue.
*/
void QMLAnalyzer::setIncludeSubFolders(bool bValue)
{
    m_bIncludeSubFolders = bValue;
}

/*!
    Sets the include rewrite files flag to \a bValue.
*/
void QMLAnalyzer::setRewriteFiles(bool bValue)
{
    m_bRewriteFiles = bValue;
}

/*!
    Sets the remove referenced symbols flag to \a bValue.
*/
void QMLAnalyzer::setRemoveUnreferencedSymbols(bool bValue)
{
    m_bRemoveUnreferencedSymbols = bValue;
}

/*!
    Returns the name of the base folder.
*/
QString QMLAnalyzer::folder() const
{
    return m_sFolder;
}

/*!
    Returns the list of errors.
*/
const QVector<QMLAnalyzerError>& QMLAnalyzer::errors() const
{
    return m_vErrors;
}

/*!
    Returns the parsing context.
*/
QMLTreeContext* QMLAnalyzer::context()
{
    QMutexLocker locker(&m_mContextMutex);

    return m_pContext;
}

void QMLAnalyzer::clear()
{
    if (m_pContext != nullptr)
    {
        delete m_pContext;
    }

    m_pContext = new QMLTreeContext();
}

bool QMLAnalyzer::analyze(CXMLNode xGrammar)
{
    m_xGrammar = xGrammar;

    parseMacros();

    {
        QMutexLocker locker(&m_mContextMutex);

        if (m_pContext != nullptr)
        {
            delete m_pContext;
        }

        m_pContext = new QMLTreeContext();

        m_vErrors.clear();
    }

    connect(m_pContext, SIGNAL(parsingStarted(QString)), this, SIGNAL(parsingStarted(QString)), Qt::DirectConnection);
    connect(m_pContext, SIGNAL(parsingFinished(QString)), this, SIGNAL(parsingFinished(QString)), Qt::DirectConnection);
    connect(m_pContext, SIGNAL(importParsingStarted(QString)), this, SIGNAL(importParsingStarted(QString)), Qt::DirectConnection);

    if (m_sFolder.isEmpty() == false)
    {
        analyze_Recurse(m_sFolder);
    }
    else if (m_sFile.isEmpty() == false)
    {
        analyzeFile(m_sFile);
    }

    return true;
}

void QMLAnalyzer::threadedAnalyze(CXMLNode xGrammar)
{
    if (isRunning() == false)
    {
        m_xGrammar = xGrammar;

        start();
    }
}

void QMLAnalyzer::stopThreadedAnalyze()
{
    if (isRunning())
    {
        m_bStopAnalyzeRequested = true;
        wait();
        m_bStopAnalyzeRequested = false;
    }
}

void QMLAnalyzer::run()
{
    analyze(m_xGrammar);
}

void QMLAnalyzer::parseMacros()
{
    QVector<CXMLNode> vMacros = m_xGrammar.getNodesByTagName(ANALYZER_TOKEN_MACRO);

    m_mMacros.clear();

    foreach (CXMLNode xMacro, vMacros)
    {
        QString sName = xMacro.attributes()[ANALYZER_TOKEN_NAME];
        QString sValue = xMacro.attributes()[ANALYZER_TOKEN_VALUE];

        m_mMacros[sName] = sValue;
    }
}

QString QMLAnalyzer::processMacros(const QString& sText)
{
    QString sResult = sText;

    foreach (QString sMacro, m_mMacros.keys())
    {
        QString sFullMacroName = QString("$%1$").arg(sMacro);

        if (sResult.contains(sFullMacroName))
        {
            if (m_mMacros[sMacro].count() > 0)
            {
                QString sMacroValue = m_mMacros[sMacro];
                sResult.replace(sFullMacroName, sMacroValue);
            }
        }
    }

    return sResult;
}

bool QMLAnalyzer::analyzeFile(const QString& sFileName)
{
    m_pContext->addFile(sFileName);

    m_pContext->setIncludeImports(m_bIncludeImports);

    if (m_pContext->parse() == QMLTreeContext::peSuccess)
    {
        QMLFile* pFile = m_pContext->fileByFileName(sFileName);

        runGrammar(sFileName, pFile);

        if (m_bRewriteFiles)
        {
            if (m_bRemoveUnreferencedSymbols)
            {
                pFile->removeUnreferencedSymbols(m_pContext);
            }

            QFile file(sFileName);
            if (file.open(QFile::WriteOnly))
            {
                m_sText.clear();
                QTextStream stream(&m_sText);

                pFile->toQML(stream);

                QJSValue output = m_eEngine.evaluate(m_sBeautifyScript);
                m_sText = output.toString();

                file.write(m_sText.toLatin1());
                file.close();
            }
        }
    }
    else
    {
        m_vErrors << m_pContext->error();

        emit analyzeError(m_vErrors.last());
    }

    return true;
}

bool QMLAnalyzer::analyze_Recurse(QString sDirectory)
{
    if (m_bStopAnalyzeRequested)
        return false;

    QStringList slNameFilter;
    slNameFilter << "*.qml" << "*.js";

    QDir dDirectory(sDirectory);

    dDirectory.setFilter(QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Files);
    QStringList lFiles = dDirectory.entryList(slNameFilter);

    foreach (QString sFile, lFiles)
    {
        QString sFullName = QString("%1/%2").arg(sDirectory).arg(sFile);

        analyzeFile(sFullName);

        if (m_bStopAnalyzeRequested)
            return false;
    }

    if (m_bIncludeSubFolders)
    {
        dDirectory.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
        QStringList lDirectories = dDirectory.entryList();

        foreach (QString sNewDirectory, lDirectories)
        {
            QString sFullName = QString("%1/%2").arg(sDirectory).arg(sNewDirectory);

            if (analyze_Recurse(sFullName) == false)
            {
                return false;
            }
        }
    }

    return true;
}

void QMLAnalyzer::runGrammar(const QString& sFileName, QMLFile* pFile)
{
    foreach (QMLEntity* pEntity, pFile->contents())
    {
        runGrammar_Recurse(sFileName, pEntity);
    }
}

void QMLAnalyzer::runGrammar_Recurse(const QString& sFileName, QMLEntity* pEntity)
{
    if (pEntity == nullptr)
    {
        return;
    }

    // Check symbol usage if it is an item
    QMLItem* pItem = dynamic_cast<QMLItem*>(pEntity);

    if (pItem != nullptr)
    {
        QMap<QString, QMLEntity*> unusedProperties = pItem->unusedProperties();

        foreach (QString sKey, unusedProperties.keys())
        {
            outputError(sFileName, unusedProperties[sKey]->position(), "Unreferenced property");
        }
    }

    // Check symbol usage if it is a function
    QMLFunction* pFunction = dynamic_cast<QMLFunction*>(pEntity);

    if (pFunction != nullptr)
    {
        QMap<QString, QMLEntity*> unusedVariables = pFunction->unusedVariables();

        foreach (QString sKey, unusedVariables.keys())
        {
            outputError(sFileName, unusedVariables[sKey]->position(), "Unreferenced variable");
        }

        QMap<QString, QMLEntity*> unusedParameters = pFunction->unusedParameters();

        foreach (QString sKey, unusedParameters.keys())
        {
            outputError(sFileName, unusedParameters[sKey]->position(), "Unreferenced parameter");
        }
    }

    bool bHasRejects = false;

    QMap<QString, QMLEntity*> mMembers = pEntity->members();

    QVector<CXMLNode> vChecks = m_xGrammar.getNodesByTagName(ANALYZER_TOKEN_CHECK);

    foreach (CXMLNode xCheck, vChecks)
    {
        QString sClassName = xCheck.attributes()[ANALYZER_TOKEN_CLASS];

        if (pEntity->metaObject()->className() == sClassName)
        {
            QVector<CXMLNode> vAccepts = xCheck.getNodesByTagName(ANALYZER_TOKEN_ACCEPT);
            QVector<CXMLNode> vRejects = xCheck.getNodesByTagName(ANALYZER_TOKEN_REJECT);

            foreach (CXMLNode xReject, vRejects)
            {
                if (runGrammar_Reject(sFileName, sClassName, pEntity, xReject, false))
                    bHasRejects = true;
            }

            foreach (CXMLNode xAccept, vAccepts)
            {
                if (runGrammar_Reject(sFileName, sClassName, pEntity, xAccept, true))
                    bHasRejects = true;
            }
        }
    }

    if (bHasRejects == false)
    {
        foreach (QString sKey, mMembers.keys())
        {
            runGrammar_Recurse(sFileName, mMembers[sKey]);
        }

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(pEntity);

        if (pComplex != nullptr)
        {
            foreach (QMLEntity* pChildItem, pComplex->contents())
            {
                runGrammar_Recurse(sFileName, pChildItem);
            }
        }
    }
}

bool QMLAnalyzer::runGrammar_Reject(const QString& sFileName, const QString& sClassName, QMLEntity* pEntity, CXMLNode xRule, bool bInverseLogic)
{
    QString sMember = processMacros(xRule.attributes()[ANALYZER_TOKEN_MEMBER].toLower());
    QString sValue = processMacros(xRule.attributes()[ANALYZER_TOKEN_VALUE]);
    QString sType = processMacros(xRule.attributes()[ANALYZER_TOKEN_TYPE]);
    QString sText = processMacros(xRule.attributes()[ANALYZER_TOKEN_TEXT]);
    QString sNestedCount = processMacros(xRule.attributes()[ANALYZER_TOKEN_NESTED_COUNT]);
    QString sCount = processMacros(xRule.attributes()[ANALYZER_TOKEN_COUNT]);
    QString sRegExp = processMacros(xRule.attributes()[ANALYZER_TOKEN_REGEXP]);
    QString sPath = processMacros(xRule.attributes()[ANALYZER_TOKEN_PATH]);

    if (runGrammar_SatisfiesConditions(sFileName, sClassName, pEntity, xRule))
    {
        QMap<QString, QMLEntity*> mMembers = pEntity->members();

        // Check nested count
        if (sNestedCount.isEmpty() == false)
        {
            int iNestedCountAllowed = sNestedCount.toInt();

            if ((iNestedCountAllowed > 0) ^ bInverseLogic)
            {
                int iNestedCount = runGrammar_CountNested(sClassName, pEntity);

                if (iNestedCount > iNestedCountAllowed)
                {
                    outputError(sFileName, pEntity->position(), sText);
                    return true;
                }
            }
        }
        else if (mMembers.contains(sMember) && mMembers[sMember] != nullptr)
        {
            QString sMemberToString = mMembers[sMember]->toString();

            sMemberToString = sMemberToString.replace("\"", "");

            // Check the path if requested
            if (sPath.isEmpty() == false)
            {
                if (sPath == ANALYZER_TOKEN_EXISTS)
                {
                    QFileInfo tFileInfo(sFileName);
                    QString sDirectory = tFileInfo.absolutePath();
                    QDir tDirectory(sDirectory);
                    QString sFullImportPath = tDirectory.absoluteFilePath(sMemberToString);
                    QFileInfo tFullFileInfo(sFullImportPath);
                    QDir tImportDirectory(sFullImportPath);

                    if (tFullFileInfo.exists())
                    {
                        return false;
                    }

                    qDebug() << "Check path: " << sDirectory << ", " << sFullImportPath;

                    if (tImportDirectory.exists() ^ bInverseLogic)
                    {
                        outputError(sFileName, pEntity->position(), sText);
                        return true;
                    }
                }
            }
            // Match a regular expression if requested
            else if (sRegExp.isEmpty() == false && sMemberToString.isEmpty() == false)
            {
                QRegExp tRegExp(sRegExp);

                if ((tRegExp.exactMatch(sMemberToString)) ^ bInverseLogic)
                {
                    outputError(sFileName, pEntity->position(), sText);
                    return true;
                }
            }
            // Check the count if requested
            else if (sCount.isEmpty() == false)
            {
                int iCountToCheck = sCount.toInt();
                QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(mMembers[sMember]);

                if (pComplex != nullptr)
                {
                    if ((pComplex->contents().count() > iCountToCheck) ^ bInverseLogic)
                    {
                        outputError(sFileName, pEntity->position(), sText);
                        return true;
                    }
                }
            }
            // Check the type if requested
            else if (sType.isEmpty() == false)
            {
                QString sTypeToString = QMLType::typeToString(mMembers[sMember]->value().type());

                if ((sTypeToString == sType) ^ bInverseLogic)
                {
                    outputError(sFileName, pEntity->position(), sText);
                    return true;
                }
            }
            else
            {
                if ((sMemberToString == sValue) ^ bInverseLogic)
                {
                    outputError(sFileName, pEntity->position(), sText);
                    return true;
                }
            }
        }
    }

    return false;
}

bool QMLAnalyzer::runGrammar_SatisfiesConditions(const QString& sFileName, const QString& sClassName, QMLEntity* pEntity, CXMLNode xRule)
{
    QVector<CXMLNode> vConditions = xRule.getNodesByTagName(ANALYZER_TOKEN_CONDITION);

    QMap<QString, QMLEntity*> mMembers = pEntity->members();

    foreach (CXMLNode xCondition, vConditions)
    {
        QString sMember = xCondition.attributes()[ANALYZER_TOKEN_MEMBER].toLower();
        QString sEmpty = xCondition.attributes()[ANALYZER_TOKEN_EMPTY].toLower();

        if (mMembers.contains(sMember) && mMembers[sMember] != nullptr)
        {
            QString sMemberToString = mMembers[sMember]->toString();

            // Check the empty condition
            if (sEmpty.isEmpty() == false)
            {
                if ((sMemberToString.isEmpty() && (sEmpty == ANALYZER_TOKEN_TRUE)) == false)
                {
                    return false;
                }
            }
        }
        else
        {
            if (sEmpty.isEmpty() == false)
            {
                if (sEmpty != ANALYZER_TOKEN_TRUE)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int QMLAnalyzer::runGrammar_CountNested(const QString& sClassName, QMLEntity* pEntity)
{
    int iCount = 0;

    if (pEntity != nullptr)
    {
        QMap<QString, QMLEntity*> mMembers = pEntity->members();

        foreach (QString sKey, mMembers.keys())
        {
            int iNewCount = runGrammar_CountNested(sClassName, mMembers[sKey]);

            if (iNewCount > iCount)
                iCount = iNewCount;
        }

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(pEntity);

        if (pComplex != nullptr)
        {
            foreach (QMLEntity* pChildItem, pComplex->contents())
            {
                int iNewCount = runGrammar_CountNested(sClassName, pChildItem);

                if (iNewCount > iCount)
                    iCount = iNewCount;
            }
        }

        if (pEntity->metaObject()->className() == sClassName)
        {
            iCount++;
        }
    }

    return iCount;
}

void QMLAnalyzer::outputError(const QString& sFileName, const QPoint& pPosition, const QString& sText)
{
    m_vErrors << QMLAnalyzerError(sFileName, pPosition, sText);

    emit analyzeError(m_vErrors.last());
}
