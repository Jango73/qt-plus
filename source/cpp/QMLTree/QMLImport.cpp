
// Qt
#include <QDebug>
#include <QDir>

// Application
#include "QMLImport.h"
#include "QMLTreeContext.h"

//-------------------------------------------------------------------------------------------------

QMLImport::QMLImport(const QPoint& pPosition, QMLTreeContext* pContext, const QString& sName, const QString& sVersion, const QString& sAs)
    : QMLItem(pPosition)
    , m_sName(sName)
    , m_sVersion(sVersion)
    , m_sAs(sAs)
{
    if (sVersion == "")
    {
        QString sDirectory = pContext->folder() + "/" + sName;

        QStringList slNameFilter;
        slNameFilter << QString("*.qml");

        QDir dDirectory(sDirectory);
        QStringList lFiles = dDirectory.entryList(slNameFilter);

        foreach (QString sFile, lFiles)
        {
            QString sQualifiedName = sDirectory + "/" + sFile;

            pContext->parseImportFile(sQualifiedName);
        }
    }
}

//-------------------------------------------------------------------------------------------------

QMLImport::~QMLImport()
{
}

//-------------------------------------------------------------------------------------------------

QString QMLImport::name() const
{
    return m_sName;
}

//-------------------------------------------------------------------------------------------------

QString QMLImport::version() const
{
    return m_sVersion;
}

//-------------------------------------------------------------------------------------------------

void QMLImport::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    QString sText = "";

    if (m_sVersion.isEmpty())
    {
        sText = QString("import \"%1\"").arg(m_sName);
    }
    else
    {
        sText = QString("import %1 %2").arg(m_sName).arg(m_sVersion);
    }

    if (m_sAs.isEmpty() == false)
    {
        sText += (" as " + m_sAs);
    }

    dumpIndented(stream, iIdent, sText);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLImport::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);

    xNode.attributes()["Name"] = m_sName;
    xNode.attributes()["Version"] = m_sVersion;

    return xNode;
}
