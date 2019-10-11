
// Qt
#include <QFile>
#include <QStringList>

// Library
#include "CXMLNode.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CXMLNode
    \inmodule qt-plus
    \brief A simple XML class, based on QDomDocument and QJsonDocument.
*/

//-------------------------------------------------------------------------------------------------

QString const CXMLNode::sExtension_XML = ".xml";
QString const CXMLNode::sExtension_XMLC = ".xmlc";
QString const CXMLNode::sExtension_QRC = ".qrc";
QString const CXMLNode::sExtension_JSON = ".json";

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
CXMLNode CXMLNode::load(const QString& sFileName)
{
    if (sFileName.toLower().endsWith(sExtension_XML))
    {
        return loadXMLFromFile(sFileName);
    }
    if (sFileName.toLower().endsWith(sExtension_XMLC))
    {
        return loadXMLCFromFile(sFileName);
    }
    else if (sFileName.toLower().endsWith(sExtension_JSON))
    {
        return loadJSONFromFile(sFileName);
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
CXMLNode CXMLNode::loadXMLFromFile(const QString& sFileName)
{
    QFile xmlFile(sFileName);

    if (xmlFile.exists())
    {
        if (xmlFile.open(QIODevice::ReadOnly))
        {
            QString sText = QString(xmlFile.readAll());
            xmlFile.close();

            return parseXML(sText);
        }
    }

    return CXMLNode();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode hierarchy loaded from the compressed XML file named \a sFileName.
*/
CXMLNode CXMLNode::loadXMLCFromFile(const QString& sFileName)
{
    QFile xmlFile(sFileName);

    // toto

    if (xmlFile.exists())
    {
        if (xmlFile.open(QIODevice::ReadOnly))
        {
            QByteArray baData = xmlFile.readAll();
            xmlFile.close();

            return parseXML(QString(qUncompress(baData)));
        }
    }

    return CXMLNode();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode hierarchy loaded from the JSON file named \a sFileName.
*/
CXMLNode CXMLNode::loadJSONFromFile(const QString& sFileName)
{
    QFile jsonFile(sFileName);

    if (jsonFile.exists())
    {
        if (jsonFile.open(QIODevice::ReadOnly))
        {
            QString sText = QString(jsonFile.readAll());
            jsonFile.close();

            return parseJSON(sText);
        }
    }

    return CXMLNode();
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
            tNode.m_vNodes.append(CXMLNode::parseXMLNode(node.childNodes().at(Index)));
        }
    }

    return tNode;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode tree parsed from the \a sText string.
*/
CXMLNode CXMLNode::parseXML(QString sText)
{
    CXMLNode tNode;

    if (sText.isEmpty() == false)
    {
        QDomDocument doc("myDocument");

        if (doc.setContent(sText) == true)
        {
            tNode = CXMLNode::parseXMLNode(doc.documentElement());
        }
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
        if (jObject[sKey].isObject())
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
            tNode.m_vAttributes[sKey] = jObject[sKey].toString();
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
        vNodes.append(CXMLNode::parseJSONNode(jArray[iIndex].toObject(), sTagName));
    }

    return vNodes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a JSON hierarchy from \a sText, as a CXMLNode tree.
*/
CXMLNode CXMLNode::parseJSON(QString sText)
{
    CXMLNode tNode;

    if (sText.isEmpty() == false)
    {
        QJsonDocument doc = QJsonDocument::fromJson(sText.toUtf8());

        tNode = CXMLNode::parseJSONNode(doc.object(), "");
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

    doc.appendChild(toQDomElement(doc));

    return doc;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the QDomElement equivalent of this CXMLNode tree, using \a xDocument.
*/
QDomElement CXMLNode::toQDomElement(QDomDocument& xDocument) const
{
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
        if (sTagList.contains(m_vNodes[iIndex].tag()) == false)
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
