
// Qt
#include <QMessageBox>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

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

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CCodeAnalyzer.
*/
QMLAnalyzer::QMLAnalyzer()
    : QThread(NULL)
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
    foreach (QString sKey, m_mContexts.keys())
    {
        delete m_mContexts[sKey];
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

    foreach (QString sKey, m_mContexts.keys())
    {
        delete m_mContexts[sKey];
    }

    m_mContexts.clear();
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
    m_mContexts[sFileName] = new QMLTreeContext(sFileName);

    connect(m_mContexts[sFileName], SIGNAL(parsingStarted(QString)), this, SIGNAL(parsingStarted(QString)), Qt::DirectConnection);
    connect(m_mContexts[sFileName], SIGNAL(parsingFinished(QString)), this, SIGNAL(parsingFinished(QString)), Qt::DirectConnection);
    connect(m_mContexts[sFileName], SIGNAL(importParsingStarted(QString)), this, SIGNAL(importParsingStarted(QString)), Qt::DirectConnection);

    m_mContexts[sFileName]->setIncludeImports(m_bIncludeImports);

    if (m_mContexts[sFileName]->parse() == QMLTreeContext::peSuccess)
    {
        runGrammar(sFileName, m_mContexts[sFileName]);

        if (m_bRewriteFiles)
        {
            QFile file(sFileName);

            if (file.open(QFile::WriteOnly))
            {
                QTextStream stream(&file);
                m_mContexts[sFileName]->item().toQML(stream, m_mContexts[sFileName]);
                file.close();
            }
        }
    }
    else
    {
        m_vErrors << m_mContexts[sFileName]->error();

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

    // qDebug() << sDirectory;

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

void QMLAnalyzer::runGrammar(const QString& sFileName, QMLTreeContext* pContext)
{
    runGrammar_Recurse(sFileName, &(pContext->item()));
}

void QMLAnalyzer::runGrammar_Recurse(const QString& sFileName, QMLItem* pItem)
{
    if (pItem == nullptr)
    {
        return;
    }

    bool bHasRejects = false;

    QMap<QString, QMLItem*> mMembers = pItem->members();

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
                    if (sCount.isEmpty() == false)
                    {
                        int iCountToCheck = sCount.toInt();
                        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(mMembers[sMember]);

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
                        QString sMemberToString = mMembers[sMember]->toString();

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

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(pItem);

        if (pComplex != nullptr)
        {
            foreach (QMLItem* pChildItem, pComplex->contents())
            {
                runGrammar_Recurse(sFileName, pChildItem);
            }
        }
    }
}

int QMLAnalyzer::runGrammar_CountNested(const QString& sClassName, QMLItem* pItem)
{
    int iCount = 0;

    if (pItem != nullptr)
    {
        QMap<QString, QMLItem*> mMembers = pItem->members();

        foreach (QString sKey, mMembers.keys())
        {
            int iNewCount = runGrammar_CountNested(sClassName, mMembers[sKey]);

            if (iNewCount > iCount)
                iCount = iNewCount;
        }

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(pItem);

        if (pComplex != nullptr)
        {
            foreach (QMLItem* pChildItem, pComplex->contents())
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
