
// Qt
#include <QDebug>
#include <QFile>
#include <QJsonParseError>
#include <QStringList>

// Library
#include "CXMLNode.h"
#include "Macros.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CXMLNode
    \inmodule qt-plus
    \brief A simple XML class, based on QDomDocument and QJsonDocument.
*/

//-------------------------------------------------------------------------------------------------

const char* CXMLNode::sExtension_XML    = ".xml";
const char* CXMLNode::sExtension_XMLC   = ".xmlc";
const char* CXMLNode::sExtension_QRC    = ".qrc";
const char* CXMLNode::sExtension_JSON   = ".json";
const char* CXMLNode::sValueAttribute   = "value";

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CXMLNode.
*/
CXMLNode::CXMLNode()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CXMLNode using \a sTagName as a tag.
*/
CXMLNode::CXMLNode(const QString& sTagName)
    : m_sTag(sTagName)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the tag of this node to \a value.
*/
void CXMLNode::setTag(const QString& value)
{
    m_sTag = value;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the value of this node to \a value.
*/
void CXMLNode::setValue(const QString& value)
{
    m_sValue = value;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the node's tag is empty.
*/
bool CXMLNode::isEmpty() const
{
    return m_sTag.isEmpty();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the tag of this node.
*/
const QString& CXMLNode::tag() const
{
    return m_sTag;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value of this node.
*/
const QString& CXMLNode::value() const
{
    return m_sValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a constant map of this node's attributes.
*/
const QMap<QString, QString>& CXMLNode::attributes() const
{
    return m_vAttributes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a map of this node's attributes.
*/
QMap<QString, QString>& CXMLNode::attributes()
{
    return m_vAttributes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a constant vector of this node's children.
*/
const CXMLNodeList &CXMLNode::nodes() const
{
    return m_vNodes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a vector of this node's children.
*/
CXMLNodeList& CXMLNode::nodes()
{
    return m_vNodes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode hierarchy loaded from the file named \a sFileName (XML or JSON).
*/
CXMLNode CXMLNode::load(const QString& sFileName, QString* pErrorString)
{
    if (sFileName.toLower().endsWith(sExtension_XML))
    {
        return loadXMLFromFile(sFileName, pErrorString);
    }
    if (sFileName.toLower().endsWith(sExtension_XMLC))
    {
        return loadXMLCFromFile(sFileName, pErrorString);
    }
    else if (sFileName.toLower().endsWith(sExtension_JSON))
    {
        return loadJSONFromFile(sFileName, pErrorString);
    }

    SAFE_USE(pErrorString)
    {
        *pErrorString = QString("CXMLNode::load(): unsupported file extension: %1").arg(sFileName);
    }

    return CXMLNode();
}

//-------------------------------------------------------------------------------------------------

/*!
    Saves this CXMLNode tree to the file named \a sFileName (XML or JSON). \br
    Returns \c true if successful, \c false otherwise.
*/
bool CXMLNode::save(const QString& sFileName)
{
    QString sLowerFileName = sFileName.toLower();

    if (sLowerFileName.endsWith(sExtension_QRC))
    {
        return saveXMLToFile(sFileName, false);
    }
    else if (sLowerFileName.endsWith(sExtension_XML))
    {
        return saveXMLToFile(sFileName);
    }
    else if (sLowerFileName.endsWith(sExtension_XMLC))
    {
        return saveXMLCToFile(sFileName);
    }
    else if (sLowerFileName.endsWith(sExtension_JSON))
    {
        return saveJSONToFile(sFileName);
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode hierarchy loaded from the XML file named \a sFileName.
*/
CXMLNode CXMLNode::loadXMLFromFile(const QString& sFileName, QString* pErrorString)
{
    QFile xmlFile(sFileName);

    if (xmlFile.exists() == false)
    {
        SAFE_USE(pErrorString)
        {
            *pErrorString = QString("CXMLNode::loadXMLFromFile(): file not found: %1").arg(sFileName);
        }

        return CXMLNode();
    }

    if (xmlFile.open(QIODevice::ReadOnly) == false)
    {
        SAFE_USE(pErrorString)
        {
            *pErrorString = QString("CXMLNode::loadXMLFromFile(): cannot open file: %1").arg(sFileName);
        }

        return CXMLNode();
    }

    QString sText = QString::fromUtf8(xmlFile.readAll());
    xmlFile.close();

    return parseXML(sText, pErrorString);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode hierarchy loaded from the compressed XML file named \a sFileName.
*/
CXMLNode CXMLNode::loadXMLCFromFile(const QString& sFileName, QString* pErrorString)
{
    QFile xmlFile(sFileName);

    // toto

    if (xmlFile.exists() == false)
    {
        SAFE_USE(pErrorString)
        {
            *pErrorString = QString("CXMLNode::loadXMLCFromFile(): file not found: %1").arg(sFileName);
        }

        return CXMLNode();
    }

    if (xmlFile.open(QIODevice::ReadOnly) == false)
    {
        SAFE_USE(pErrorString)
        {
            *pErrorString = QString("CXMLNode::loadXMLCFromFile(): cannot open file: %1").arg(sFileName);
        }

        return CXMLNode();
    }

    QByteArray baData = xmlFile.readAll();
    xmlFile.close();

    return parseXML(QString::fromUtf8(qUncompress(baData)), pErrorString);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode hierarchy loaded from the JSON file named \a sFileName.
*/
CXMLNode CXMLNode::loadJSONFromFile(const QString& sFileName, QString* pErrorString)
{
    QFile jsonFile(sFileName);

    if (jsonFile.exists() == false)
    {
        SAFE_USE(pErrorString)
        {
            *pErrorString = QString("CXMLNode::loadJSONFromFile(): file not found: %1").arg(sFileName);
        }

        return CXMLNode();
    }

    if (jsonFile.open(QIODevice::ReadOnly) == false)
    {
        SAFE_USE(pErrorString)
        {
            *pErrorString = QString("CXMLNode::loadJSONFromFile(): cannot open file: %1").arg(sFileName);
        }

        return CXMLNode();
    }

    QString sText = QString::fromUtf8(jsonFile.readAll());
    jsonFile.close();

    return parseJSON(sText, pErrorString);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode tree parsed from the \a node.
*/
CXMLNode CXMLNode::parseXMLNode(QDomNode node)
{
    CXMLNode tNode;

    tNode.m_sTag = node.nodeName();
    tNode.m_sValue = node.nodeValue();

    for (int Index = 0; Index < node.attributes().length(); Index++)
    {
        QDomNode attrNode = node.attributes().item(Index);

        tNode.m_vAttributes[attrNode.nodeName()] = attrNode.nodeValue();
    }

    if (node.childNodes().length() == 1)
    {
        if (node.childNodes().at(0).nodeName().startsWith("#text"))
        {
            tNode.m_sValue = node.childNodes().at(0).nodeValue();
        }
        else
        {
            tNode.m_vNodes.append(CXMLNode::parseXMLNode(node.childNodes().at(0)));
        }
    }
    else
    {
        for (int Index = 0; Index < node.childNodes().length(); Index++)
        {
            QDomNode xChild = node.childNodes().at(Index);

            // Skip whitespace-only text nodes: pretty-printed XML indentation
            // is not data and must not become child nodes.
            if (xChild.isText() && xChild.nodeValue().trimmed().isEmpty())
            {
                continue;
            }

            tNode.m_vNodes.append(CXMLNode::parseXMLNode(xChild));
        }
    }

    return tNode;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode tree parsed from the \a sText string.
*/
CXMLNode CXMLNode::parseXML(QString sText, QString* pErrorString)
{
    CXMLNode tNode;

    if (sText.isEmpty() == false)
    {
        QDomDocument doc("myDocument");

        QString sError;
        int iErrorLine = 0;
        int iErrorColumn = 0;

        if (doc.setContent(sText, &sError, &iErrorLine, &iErrorColumn) == true)
        {
            tNode = CXMLNode::parseXMLNode(doc.documentElement());
        }
        else SAFE_USE(pErrorString)
        {
            *pErrorString = QString("CXMLNode::parseXML(): line %1, column %2: %3")
                .arg(iErrorLine).arg(iErrorColumn).arg(sError);
        }
    }
    else SAFE_USE(pErrorString)
    {
        *pErrorString = QString("CXMLNode::parseXML(): empty input");
    }

    return tNode;
}

//-------------------------------------------------------------------------------------------------

/*!
    Parses a JSON node from \a jObject, using \a sTagName as a tag name.
*/
CXMLNode CXMLNode::parseJSONNode(QJsonObject jObject, QString sTagName)
{
    CXMLNode tNode;

    tNode.m_sTag = sTagName;
    tNode.m_sValue = "";

    if (tNode.m_sTag.isEmpty())
    {
        tNode.m_sTag = QString("NOTAG");
    }

    for(QString sKey : jObject.keys())
    {
        if (sKey == sValueAttribute && jObject[sKey].isString())
        {
            tNode.m_sValue = jObject[sKey].toString();
        }
        else if (jObject[sKey].isObject())
        {
            tNode.m_vNodes.append(CXMLNode::parseJSONNode(jObject[sKey].toObject(), sKey));
        }
        else if (jObject[sKey].isArray())
        {
            CXMLNodeList vNodes = parseJSONArray(jObject[sKey].toArray(), sKey);

            for(CXMLNode xNode : vNodes)
            {
                tNode.m_vNodes.append(xNode);
            }
        }
        else
        {
            // Scalars (numbers, booleans, null) have no CXMLNode counterpart:
            // store their text form. Note QJsonValue::toString() returns empty
            // for non-strings, so go through QVariant to preserve the value.
            tNode.m_vAttributes[sKey] = jObject[sKey].toVariant().toString();
        }
    }

    return tNode;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of CXMLNode that is parsed from \a jArray, using \a sTagName as a tag name.
*/
CXMLNodeList CXMLNode::parseJSONArray(QJsonArray jArray, QString sTagName)
{
    CXMLNodeList vNodes;

    for (int iIndex = 0; iIndex < jArray.count(); iIndex++)
    {
        if (jArray[iIndex].isObject())
        {
            vNodes.append(CXMLNode::parseJSONNode(jArray[iIndex].toObject(), sTagName));
        }
        else
        {
            // Scalar array items are not objects: keep them as value nodes
            // instead of dropping them into empty placeholder nodes.
            CXMLNode tValueNode(sTagName);
            tValueNode.setValue(jArray[iIndex].toVariant().toString());
            vNodes.append(tValueNode);
        }
    }

    return vNodes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a JSON hierarchy from \a sText, as a CXMLNode tree.
*/
CXMLNode CXMLNode::parseJSON(QString sText, QString* pErrorString)
{
    CXMLNode tNode;

    if (sText.isEmpty() == false)
    {
        QJsonParseError tError;
        QJsonDocument doc = QJsonDocument::fromJson(sText.toUtf8(), &tError);

        if (tError.error != QJsonParseError::NoError)
        {
            SAFE_USE(pErrorString)
            {
                *pErrorString = QString("CXMLNode::parseJSON(): offset %1: %2")
                    .arg(tError.offset).arg(tError.errorString());
            }

            return tNode;
        }

        if (doc.isArray())
        {
            // Top-level arrays have no key: collect items under a NOTAG root
            // instead of dropping them.
            tNode.setTag("NOTAG");

            for (CXMLNode xNode : parseJSONArray(doc.array(), "NOTAG"))
            {
                tNode.m_vNodes.append(xNode);
            }
        }
        else
        {
            tNode = CXMLNode::parseJSONNode(doc.object(), "");
        }
    }
    else SAFE_USE(pErrorString)
    {
        *pErrorString = QString("CXMLNode::parseJSON(): empty input");
    }

    return tNode;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a string containing the textual XML equivalent of this CXMLNode tree. \br\br
    If \a bXMLHeader is \c true, the xml file will contain a header of the type <?xml version="1.0" encoding="UTF-8"?>
*/
QString CXMLNode::toString(bool bXMLHeader) const
{
    return toQDomDocument(bXMLHeader).toString();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the QDomDocument equivalent of this CXMLNode tree. \br\br
    If \a bXMLHeader is \c true, the xml file will contain a header of the type <?xml version="1.0" encoding="UTF-8"?>
*/
QDomDocument CXMLNode::toQDomDocument(bool bXMLHeader) const
{
    QDomDocument doc;

    if (bXMLHeader)
    {
        QDomNode xmlNode = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
        doc.appendChild(xmlNode);
    }

    if (m_sTag.isEmpty())
    {
        // No tag: no single root element exists. Serialize children at document
        // level (fragment-style) instead of silently discarding the subtree.
        for (CXMLNode xChild : m_vNodes)
        {
            doc.appendChild(xChild.toQDomElement(doc));
        }
    }
    else
    {
        doc.appendChild(toQDomElement(doc));
    }

    return doc;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the QDomElement equivalent of this CXMLNode tree, using \a xDocument.
*/
QDomElement CXMLNode::toQDomElement(QDomDocument& xDocument) const
{
    if (m_sTag.isEmpty())
    {
        qWarning() << "CXMLNode::toQDomElement(): empty tag, node and its subtree cannot be exported as an element";
        return QDomElement();
    }

    QDomElement thisElement = xDocument.createElement(m_sTag);

    if (!thisElement.isNull())
    {
        for (QString sAttributeName : m_vAttributes.keys())
        {
            thisElement.setAttribute(sAttributeName, m_vAttributes[sAttributeName]);
        }

        if (m_sValue.isEmpty() == false)
        {
            QDomText textElement = xDocument.createTextNode(m_sValue.toUtf8());
            thisElement.appendChild(textElement);
        }

        for (CXMLNode xChild : m_vNodes)
        {
            thisElement.appendChild(xChild.toQDomElement(xDocument));
        }
    }

    return thisElement;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the QJsonDocument equivalent of this CXMLNode tree.
*/
QJsonDocument CXMLNode::toJsonDocument() const
{
    QJsonDocument doc;

    doc.setObject(toJsonObject());

    return doc;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the JSON string equivalent of this CXMLNode tree.
*/
QString CXMLNode::toJsonString() const
{
    QJsonDocument doc;

    doc.setObject(toJsonObject());

    return QString::fromUtf8(doc.toJson());
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the QJsonObject equivalent of this CXMLNode tree.
*/
QJsonObject CXMLNode::toJsonObject() const
{
    QJsonObject object;

    for (QString sKey : m_vAttributes.keys())
    {
        object[sKey] = m_vAttributes[sKey];
    }

    QStringList sTagList;

    for (int iIndex = 0; iIndex < m_vNodes.count(); iIndex++)
    {
        if (not sTagList.contains(m_vNodes[iIndex].tag()))
        {
            sTagList << m_vNodes[iIndex].tag();
        }
    }

    for (QString sTag : sTagList)
    {
        CXMLNodeList vNodes = getNodesByTagName(sTag);

        if (vNodes.count() > 1)
        {
            QJsonArray array;

            for (CXMLNode xNode : vNodes)
            {
                array << xNode.toJsonObject();
            }

            object[sTag] = array;
        }
        else
        {
            object[sTag] = vNodes[0].toJsonObject();
        }
    }

    if (not m_sValue.isEmpty() && not object.contains(sValueAttribute))
    {
        object[sValueAttribute] = m_sValue;
    }

    return object;
}

//-------------------------------------------------------------------------------------------------

/*!
    Saves this CXMLNode tree as XML in the file named \a sFileName. \br
    If \a bXMLHeader is \c true, the xml file will contain a header of the type <?xml version="1.0" encoding="UTF-8"?> \br
    Returns \c true if successful, \c false otherwise.
*/
bool CXMLNode::saveXMLToFile(const QString& sFileName, bool bXMLHeader)
{
    QFile xmlFile(sFileName);

    if (xmlFile.open(QIODevice::WriteOnly))
    {
        xmlFile.write(toString(bXMLHeader).toUtf8());
        xmlFile.close();

        return true;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Saves this CXMLNode tree as compressed XML in the file named \a sFileName. \br
    If \a bXMLHeader is \c true, the xml file will contain a header of the type <?xml version="1.0" encoding="UTF-8"?> \br
    Returns \c true if successful, \c false otherwise.
*/
bool CXMLNode::saveXMLCToFile(const QString& sFileName, bool bXMLHeader)
{
    QFile xmlFile(sFileName);
    QByteArray baData = qCompress(toString(bXMLHeader).toUtf8(), 8);

    if (xmlFile.open(QIODevice::WriteOnly))
    {
        xmlFile.write(baData);
        xmlFile.close();

        return true;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Saves this CXMLNode tree as JSON in the file named \a sFileName. \br
    Returns \c true if successful, \c false otherwise.
*/
bool CXMLNode::saveJSONToFile(const QString& sFileName)
{
    QFile xmlFile(sFileName);

    if (xmlFile.open(QIODevice::WriteOnly))
    {
        xmlFile.write(toJsonDocument().toJson());
        xmlFile.close();

        return true;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends \a value to the child nodes of this node.
*/
CXMLNode& CXMLNode::operator << (CXMLNode value)
{
    m_vNodes << value;
    return *this;
}


//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if this node is equal to \a value.
*/
bool CXMLNode::operator == (const CXMLNode& value) const
{
    return
            m_sTag == value.m_sTag &&
            m_sValue == value.m_sValue &&
            m_vAttributes == value.m_vAttributes &&
            m_vNodes == value.m_vNodes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the child node whose tag is \a sTagName.
*/
CXMLNode CXMLNode::getNodeByTagName(const QString& sTagName)
{
    for (CXMLNode tNode : m_vNodes)
    {
        if (tNode.m_sTag == sTagName) return tNode;
    }

    return CXMLNode();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the child node whose tag is \a sTagName.
*/
CXMLNode CXMLNode::getNodeByTagName(const QString& sTagName) const
{
    for (CXMLNode tNode : m_vNodes)
    {
        if (tNode.m_sTag == sTagName) return tNode;
    }

    return CXMLNode();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of child nodes whose tag is \a sTagName.
*/
CXMLNodeList CXMLNode::getNodesByTagName(const QString& sTagName) const
{
    CXMLNodeList vNodes;

    for (const CXMLNode& tNode : m_vNodes)
    {
        if (tNode.m_sTag == sTagName)
        {
            vNodes << tNode;
        }
    }

    return vNodes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the has the attribute \a sAttribute.
*/
bool CXMLNode::hasAttribute(const QString& sAttribute) const
{
    return m_vAttributes.keys().contains(sAttribute);
}

//-------------------------------------------------------------------------------------------------

/*!
    Removes child nodes whose tag is \a sTagName.
*/
void CXMLNode::removeNodesByTagName(QString sTagName)
{
    for (int index = 0; index < m_vNodes.count(); index++)
    {
        if (m_vNodes[index].tag() == sTagName)
        {
            m_vNodes.removeAt(index);
            index--;
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Merges the child nodes of \a xTarget in this node's children.
*/
void CXMLNode::merge(const CXMLNode& xTarget)
{
    for (CXMLNode node : xTarget.m_vNodes)
    {
        m_vNodes.append(node);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Stringify one level only.
*/
QString CXMLNode::stringifyOneLevel()
{
    QStringList lChildren;

    for (CXMLNode xNode : m_vNodes)
    {
        lChildren << xNode.toJsonString();
    }

    return lChildren.join(",");
}
