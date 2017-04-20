
// Qt
#include <QDir>

// Application
#include "QMLImport.h"
#include "QMLTreeContext.h"

//-------------------------------------------------------------------------------------------------

QMLImport::QMLImport(const QPoint& pPosition, QMLTreeContext* pContext, QMLEntity* pName, QMLEntity* pVersion, QMLEntity* pAs)
    : QMLEntity(pPosition)
    , m_pName(pName)
    , m_pVersion(pVersion)
    , m_pAs(pAs)
{
    if (m_pName != nullptr && (m_pVersion == nullptr || m_pVersion->toString().isEmpty()))
    {
        QString sDirectory = pContext->folder() + "/" + m_pName->toString();

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
    if (m_pName != nullptr)
        delete m_pName;
    if (m_pVersion != nullptr)
        delete m_pVersion;
    if (m_pAs != nullptr)
        delete m_pAs;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLImport::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLImport::version() const
{
    return m_pVersion;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLImport::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["name"] = m_pName;
    vReturnValue["version"] = m_pVersion;
    vReturnValue["as"] = m_pAs;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLImport::toQML(QTextStream& stream, const QMLEntity* pParent, int iIdent) const
{
    Q_UNUSED(pParent);

    QString sText = "";

    if (m_pName != nullptr)
    {
        if (m_pVersion == nullptr || m_pVersion->toString().isEmpty())
        {
            sText = QString("import \"%1\"").arg(m_pName->toString());
        }
        else
        {
            sText = QString("import %1 %2").arg(m_pName->toString()).arg(m_pVersion->toString());
        }

        if (m_pAs != nullptr && m_pAs->toString().isEmpty() == false)
        {
            sText += (" as " + m_pAs->toString());
        }

        stream << sText << " ";
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLImport::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
    CXMLNode xName("Name");
    CXMLNode xVersion("Version");
    CXMLNode xAs("As");

    if (m_pName != nullptr)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pVersion != nullptr)
        xVersion.nodes() << m_pVersion->toXMLNode(pContext, this);

    if (m_pAs != nullptr)
        xAs.nodes() << m_pAs->toXMLNode(pContext, this);

    xNode.nodes() << xName;
    xNode.nodes() << xVersion;
    xNode.nodes() << xAs;

    return xNode;
}
