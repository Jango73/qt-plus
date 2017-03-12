
// Qt
#include <QDebug>
#include <QDir>

// Application
#include "QMLImport.h"
#include "QMLTreeContext.h"

//-------------------------------------------------------------------------------------------------

QMLImport::QMLImport(const QPoint& pPosition, QMLTreeContext* pContext, const QString& sName, const QString& sVersion)
    : QMLItem(pPosition)
    , m_sName(sName)
    , m_sVersion(sVersion)
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

void QMLImport::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLImport]"));
    dumpIndented(stream, iIdent, QString("Name : %1").arg(m_sName));
    dumpIndented(stream, iIdent, QString("Version : %1").arg(m_sVersion));

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

void QMLImport::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_sVersion.isEmpty())
    {
        dumpIndented(stream, iIdent, QString("import \"%1\"").arg(m_sName));
    }
    else
    {
        dumpIndented(stream, iIdent, QString("import %1 %2").arg(m_sName).arg(m_sVersion));
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLImport::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);

    xNode.attributes()["Name"] = m_sName;
    xNode.attributes()["Version"] = m_sVersion;

    return xNode;
}
