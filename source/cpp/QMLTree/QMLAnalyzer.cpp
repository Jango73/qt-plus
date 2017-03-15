
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
void QMLAnalyzer::setFolder(const QString& sFolder, bool bIncludeSubFolders)
{
    m_sFolder = sFolder;
    m_bIncludeSubFolders = bIncludeSubFolders;
}

/*!
    Sets the base file member to \a sFileName.
*/
void QMLAnalyzer::setFile(const QString& sFileName)
{
    m_sFile = sFileName;
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
const QStringList& QMLAnalyzer::errors() const
{
    return m_lErrors;
}

bool QMLAnalyzer::analyze(CXMLNode xGrammar, bool bIncludeImports)
{
    m_xGrammar = xGrammar;
    m_bIncludeImports = bIncludeImports;

    foreach (QString sKey, m_mContexts.keys())
    {
        delete m_mContexts[sKey];
    }

    m_mContexts.clear();
    m_lErrors.clear();

    if (m_sFolder.isEmpty() == false)
    {
        QStringList slNameFilter;
        slNameFilter << "*.qml" << "*.js";

        QDir dDirectory(m_sFolder);
        QStringList lFiles = dDirectory.entryList(slNameFilter);

        foreach (QString sFile, lFiles)
        {
            if (sFile != "." && sFile != "..")
            {
                QString sFullName = QString("%1/%2").arg(m_sFolder).arg(sFile);

                analyzeFile(sFullName, xGrammar);
            }
        }
    }
    else if (m_sFile.isEmpty() == false)
    {
        analyzeFile(m_sFile, xGrammar);
    }

    return true;
}

void QMLAnalyzer::threadedAnalyze(CXMLNode xGrammar, bool bIncludeImports)
{
    if (isRunning() == false)
    {
        m_xGrammar = xGrammar;
        m_bIncludeImports = bIncludeImports;

        start();
    }
}

void QMLAnalyzer::analyzeFile(const QString& sFileName, CXMLNode xGrammar)
{
    m_mContexts[sFileName] = new QMLTreeContext(sFileName);

    connect(m_mContexts[sFileName], SIGNAL(parsingStarted(QString)), this, SIGNAL(parsingStarted(QString)), Qt::DirectConnection);
    connect(m_mContexts[sFileName], SIGNAL(parsingFinished(QString)), this, SIGNAL(parsingFinished(QString)), Qt::DirectConnection);
    connect(m_mContexts[sFileName], SIGNAL(importParsingStarted(QString)), this, SIGNAL(importParsingStarted(QString)), Qt::DirectConnection);

    m_mContexts[sFileName]->setIncludeImports(m_bIncludeImports);

    if (m_mContexts[sFileName]->parse() == QMLTreeContext::peSuccess)
    {
        QFileInfo info(sFileName);
        QString sShortFileName = info.baseName();
        m_lErrors << runGrammar(sShortFileName, m_mContexts[sFileName], xGrammar);
    }
    else
    {
        m_lErrors << m_mContexts[sFileName]->errorString();
    }
}

void QMLAnalyzer::run()
{
    analyze(m_xGrammar, m_bIncludeImports);
}

QStringList QMLAnalyzer::runGrammar(const QString& sFileName, QMLTreeContext* pContext, CXMLNode& xGrammar)
{
    QStringList lErrors;

    runGrammar_Recurse(sFileName, &(pContext->item()), xGrammar, lErrors);

    return lErrors;
}

void QMLAnalyzer::runGrammar_Recurse(const QString& sFileName, QMLItem* pItem, CXMLNode& xGrammar, QStringList& lErrors)
{
    if (pItem == nullptr)
    {
        return;
    }

    bool bHasRejects = false;

    QMap<QString, QMLItem*> mMembers = pItem->members();

    QVector<CXMLNode> vChecks = xGrammar.getNodesByTagName(ANALYZER_TOKEN_CHECK);

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

                            lErrors << QString("%1 (%2, %3) : %4")
                                       .arg(sFileName)
                                       .arg(pItem->position().y())
                                       .arg(pItem->position().x())
                                       .arg(sText);
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

                            lErrors << QString("%1 (%2, %3) : %4")
                                       .arg(sFileName)
                                       .arg(pItem->position().y())
                                       .arg(pItem->position().x())
                                       .arg(sText);
                        }
                    }
                    else if (sType.isEmpty() == false)
                    {
                        QString sTypeToString = QMLType::typeToString(mMembers[sMember]->value().type());

                        if (sTypeToString == sType)
                        {
                            bHasRejects = true;

                            lErrors << QString("%1 (%2, %3) : %4")
                                       .arg(sFileName)
                                       .arg(pItem->position().y())
                                       .arg(pItem->position().x())
                                       .arg(sText);
                        }
                    }
                    else
                    {
                        QString sMemberToString = mMembers[sMember]->toString();

                        if (sMemberToString == sValue)
                        {
                            bHasRejects = true;

                            lErrors << QString("%1 (%2, %3) : %4")
                                       .arg(sFileName)
                                       .arg(pItem->position().y())
                                       .arg(pItem->position().x())
                                       .arg(sText);
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
            runGrammar_Recurse(sFileName, mMembers[sKey], xGrammar, lErrors);
        }

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(pItem);

        if (pComplex != nullptr)
        {
            foreach (QMLItem* pChildItem, pComplex->contents())
            {
                runGrammar_Recurse(sFileName, pChildItem, xGrammar, lErrors);
            }
        }
    }
}

int QMLAnalyzer::runGrammar_CountNested(const QString& sClassName, QMLItem* pItem)
{
    int iCount = 0;

    if (pItem != nullptr)
    {
        if (pItem->metaObject()->className() == sClassName)
        {
            iCount++;
        }

        QMap<QString, QMLItem*> mMembers = pItem->members();

        foreach (QString sKey, mMembers.keys())
        {
            iCount += runGrammar_CountNested(sClassName, mMembers[sKey]);
        }

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(pItem);

        if (pComplex != nullptr)
        {
            foreach (QMLItem* pChildItem, pComplex->contents())
            {
                iCount += runGrammar_CountNested(sClassName, pChildItem);
            }
        }
    }

    return iCount;
}
