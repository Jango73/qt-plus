
// Qt
#include <QMessageBox>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

// Application
#include "QMLAnalyzer.h"

//-------------------------------------------------------------------------------------------------

#define ANALYZER_TOKEN_CHECK    "Check"
#define ANALYZER_TOKEN_CLASS    "Class"
#define ANALYZER_TOKEN_MEMBER   "Member"
#define ANALYZER_TOKEN_REJECT   "Reject"
#define ANALYZER_TOKEN_TEXT     "Text"
#define ANALYZER_TOKEN_VALUE    "Value"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CCodeAnalyzer.
*/
QMLAnalyzer::QMLAnalyzer()
    : QObject(NULL)
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
    Returns the name of the base folder.
*/
QString QMLAnalyzer::folder() const
{
    return m_sFolder;
}

const QStringList& QMLAnalyzer::errors() const
{
    return m_lErrors;
}

bool QMLAnalyzer::analyze(CXMLNode xGrammar)
{
    foreach (QString sKey, m_mContexts.keys())
    {
        delete m_mContexts[sKey];
    }

    m_mContexts.clear();
    m_lErrors.clear();

    QStringList slNameFilter;
    slNameFilter << "*.qml";

    QDir dDirectory(m_sFolder);
    QStringList lFiles = dDirectory.entryList(slNameFilter);

    foreach (QString sFile, lFiles)
    {
        if (sFile != "." && sFile != "..")
        {
            QString sFullName = QString("%1/%2").arg(m_sFolder).arg(sFile);

            m_mContexts[sFullName] = new QMLTreeContext(sFullName);

            m_mContexts[sFullName]->setIncludeImports(false);

            if (m_mContexts[sFullName]->parse() == QMLTreeContext::peSuccess)
            {
                m_lErrors << runGrammar(m_mContexts[sFullName], xGrammar);
            }
            else
            {
                m_lErrors << m_mContexts[sFullName]->errorString();
            }
        }
    }

    return true;
}

QStringList QMLAnalyzer::runGrammar(QMLTreeContext* pContext, CXMLNode xGrammar)
{
    QStringList lErrors;

    runGrammar_Recurse(&(pContext->item()), xGrammar, lErrors);

    return lErrors;
}

void QMLAnalyzer::runGrammar_Recurse(QMLItem* pItem, CXMLNode xGrammar, QStringList& lErrors)
{
    bool bHasRejects = false;

    QMap<QString, QMLItem*> mMembers = pItem->members();

    QVector<CXMLNode> vChecks = xGrammar.getNodesByTagName(ANALYZER_TOKEN_CHECK);

    foreach (CXMLNode xCheck, vChecks)
    {
        QString sClassName = xCheck.attributes()[ANALYZER_TOKEN_CLASS];

        if (pItem->metaObject()->className() == sClassName)
        {
            QVector<CXMLNode> vRejects = xGrammar.getNodesByTagName(ANALYZER_TOKEN_REJECT);

            foreach (CXMLNode xReject, vRejects)
            {
                QString sMember = xReject.attributes()[ANALYZER_TOKEN_MEMBER].toLower();
                QString sValue = xReject.attributes()[ANALYZER_TOKEN_VALUE];
                QString sText = xReject.attributes()[ANALYZER_TOKEN_TEXT];

                if (mMembers.contains(sMember))
                {
                    if (mMembers[sMember]->toString() == sValue)
                    {
                        bHasRejects = true;
                        lErrors << sText;
                    }
                }
            }
        }
    }

    if (bHasRejects == false)
    {
        foreach (QString sKey, mMembers.keys())
        {
            runGrammar_Recurse(mMembers[sKey], xGrammar, lErrors);
        }
    }
}
