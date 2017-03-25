
// Qt
#include <QMessageBox>
#include <QFileInfo>
#include <QDir>
#include <QRegExp>

// Application
#include "QMLAnalyzer.h"

//-------------------------------------------------------------------------------------------------

#define ANALYZER_TOKEN_CHECK        "Check"
#define ANALYZER_TOKEN_CLASS        "Class"
#define ANALYZER_TOKEN_COUNT        "Count"
#define ANALYZER_TOKEN_MEMBER       "Member"
#define ANALYZER_TOKEN_NESTED_COUNT "NestedCount"
#define ANALYZER_TOKEN_REJECT       "Reject"
#define ANALYZER_TOKEN_TEXT         "Text"
#define ANALYZER_TOKEN_TYPE         "Type"
#define ANALYZER_TOKEN_VALUE        "Value"
#define ANALYZER_TOKEN_REGEXP       "RegExp"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CCodeAnalyzer.
*/
QMLAnalyzer::QMLAnalyzer()
    : QThread(NULL)
    , m_pContext(nullptr)
    , m_bIncludeImports(false)
    , m_bIncludeSubFolders(false)
    , m_bRewriteFiles(false)
{
}

/*!
    Destroys a CCodeAnalyzer.
*/
QMLAnalyzer::~QMLAnalyzer()
{
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

bool QMLAnalyzer::analyze(CXMLNode xGrammar)
{
    m_xGrammar = xGrammar;

    if (m_pContext != nullptr)
    {
        delete m_pContext;
    }

    m_pContext = new QMLTreeContext();

    connect(m_pContext, SIGNAL(parsingStarted(QString)), this, SIGNAL(parsingStarted(QString)), Qt::DirectConnection);
    connect(m_pContext, SIGNAL(parsingFinished(QString)), this, SIGNAL(parsingFinished(QString)), Qt::DirectConnection);
    connect(m_pContext, SIGNAL(importParsingStarted(QString)), this, SIGNAL(importParsingStarted(QString)), Qt::DirectConnection);

    m_vErrors.clear();

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
            QFile file(sFileName);

            if (file.open(QFile::WriteOnly))
            {
                QTextStream stream(&file);
                pFile->toQML(stream, m_pContext);
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

void QMLAnalyzer::run()
{
    analyze(m_xGrammar);
}

bool QMLAnalyzer::analyze_Recurse(QString sDirectory)
{
    QStringList slNameFilter;
    slNameFilter << "*.qml" << "*.js";

    QDir dDirectory(sDirectory);

    dDirectory.setFilter(QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Files);
    QStringList lFiles = dDirectory.entryList(slNameFilter);

    foreach (QString sFile, lFiles)
    {
        QString sFullName = QString("%1/%2").arg(sDirectory).arg(sFile);

        analyzeFile(sFullName);
    }

    if (m_bIncludeSubFolders)
    {
        dDirectory.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
        QStringList lDirectories = dDirectory.entryList();

        foreach (QString sNewDirectory, lDirectories)
        {
            QString sFullName = QString("%1/%2").arg(sDirectory).arg(sNewDirectory);

            analyze_Recurse(sFullName);
        }
    }

    return true;
}

void QMLAnalyzer::runGrammar(const QString& sFileName, QMLFile* pFile)
{
    foreach (QMLEntity* pItem, pFile->contents())
    {
        runGrammar_Recurse(sFileName, pItem);
    }
}

void QMLAnalyzer::runGrammar_Recurse(const QString& sFileName, QMLEntity* pItem)
{
    if (pItem == nullptr)
    {
        return;
    }

    bool bHasRejects = false;

    QMap<QString, QMLEntity*> mMembers = pItem->members();

    QVector<CXMLNode> vChecks = m_xGrammar.getNodesByTagName(ANALYZER_TOKEN_CHECK);

    foreach (CXMLNode xCheck, vChecks)
    {
        QString sClassName = xCheck.attributes()[ANALYZER_TOKEN_CLASS];

        if (pItem->metaObject()->className() == sClassName)
        {
            QVector<CXMLNode> vRejects = xCheck.getNodesByTagName(ANALYZER_TOKEN_REJECT);

            foreach (CXMLNode xReject, vRejects)
            {
                QString sMember = xReject.attributes()[ANALYZER_TOKEN_MEMBER].toLower();
                QString sValue = xReject.attributes()[ANALYZER_TOKEN_VALUE];
                QString sType = xReject.attributes()[ANALYZER_TOKEN_TYPE];
                QString sText = xReject.attributes()[ANALYZER_TOKEN_TEXT];
                QString sNestedCount = xReject.attributes()[ANALYZER_TOKEN_NESTED_COUNT];
                QString sCount = xReject.attributes()[ANALYZER_TOKEN_COUNT];
                QString sRegExp = xReject.attributes()[ANALYZER_TOKEN_REGEXP];

                if (sNestedCount.isEmpty() == false)
                {
                    int iNestedCountAllowed = sNestedCount.toInt();

                    if (iNestedCountAllowed > 0)
                    {
                        int iNestedCount = runGrammar_CountNested(sClassName, pItem);

                        if (iNestedCount > iNestedCountAllowed)
                        {
                            bHasRejects = true;
                            outputError(sFileName, pItem->position(), sText);
                        }
                    }
                }
                else if (mMembers.contains(sMember) && mMembers[sMember] != nullptr)
                {
                    QString sMemberToString = mMembers[sMember]->toString();

                    if (sRegExp.isEmpty() == false && sMemberToString.isEmpty() == false)
                    {
                        QRegExp tRegExp(sRegExp);

                        if (tRegExp.exactMatch(sMemberToString) == false)
                        {
                            bHasRejects = true;
                            outputError(sFileName, pItem->position(), sText);
                        }
                    }
                    else if (sCount.isEmpty() == false)
                    {
                        int iCountToCheck = sCount.toInt();
                        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(mMembers[sMember]);

                        if (pComplex != nullptr && pComplex->contents().count() > iCountToCheck)
                        {
                            bHasRejects = true;
                            outputError(sFileName, pItem->position(), sText);
                        }
                    }
                    else if (sType.isEmpty() == false)
                    {
                        QString sTypeToString = QMLType::typeToString(mMembers[sMember]->value().type());

                        if (sTypeToString == sType)
                        {
                            bHasRejects = true;
                            outputError(sFileName, pItem->position(), sText);
                        }
                    }
                    else
                    {
                        if (sMemberToString == sValue)
                        {
                            bHasRejects = true;
                            outputError(sFileName, pItem->position(), sText);
                        }
                    }
                }
            }
        }
    }

    if (bHasRejects == false)
    {
        foreach (QString sKey, mMembers.keys())
        {
            runGrammar_Recurse(sFileName, mMembers[sKey]);
        }

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(pItem);

        if (pComplex != nullptr)
        {
            foreach (QMLEntity* pChildItem, pComplex->contents())
            {
                runGrammar_Recurse(sFileName, pChildItem);
            }
        }
    }
}

int QMLAnalyzer::runGrammar_CountNested(const QString& sClassName, QMLEntity* pItem)
{
    int iCount = 0;

    if (pItem != nullptr)
    {
        QMap<QString, QMLEntity*> mMembers = pItem->members();

        foreach (QString sKey, mMembers.keys())
        {
            int iNewCount = runGrammar_CountNested(sClassName, mMembers[sKey]);

            if (iNewCount > iCount)
                iCount = iNewCount;
        }

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(pItem);

        if (pComplex != nullptr)
        {
            foreach (QMLEntity* pChildItem, pComplex->contents())
            {
                int iNewCount = runGrammar_CountNested(sClassName, pChildItem);

                if (iNewCount > iCount)
                    iCount = iNewCount;
            }
        }

        if (pItem->metaObject()->className() == sClassName)
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
