
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QMetaType>
#include <QString>
#include <QMap>
#include <QVector>
#include <QList>
#include <QDomDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//-------------------------------------------------------------------------------------------------

class CXMLNode;

//! Define CXMLNODE_USE_LIST if you wish to use QList instead of QVector for node list storage.
#ifdef CXMLNODE_USE_LIST
    typedef QList<CXMLNode> CXMLNodeList;
#else
    typedef QVector<CXMLNode> CXMLNodeList;
#endif

//-------------------------------------------------------------------------------------------------

//! Defines a XML node
class QTPLUSSHARED_EXPORT CXMLNode
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CXMLNode();

    //! Constructor with tag name
    CXMLNode(const QString& sTagName);

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Defines this node's tag
    void setTag(const QString& value);

    //! Defines this node's value
    void setValue(const QString& value);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns true if the node is empty (no tag)
    bool isEmpty() const;

    //! Returns the tag name
    const QString& tag() const;

    //! Returns the value
    const QString& value() const;

    //! Returns the attribute map
    const QMap<QString, QString>& attributes() const;

    //! Returns the attribute map
    QMap<QString, QString>& attributes();

    //! Returns the children vector
    const CXMLNodeList& nodes() const;

    //! Returns the children vector
    CXMLNodeList& nodes();

    //! Returns a child node by tag
    CXMLNode getNodeByTagName(const QString& sTagName);

    //! Returns a child node by tag
    CXMLNode getNodeByTagName(const QString& sTagName) const;

    //! Returns a child node vector by tag
    CXMLNodeList getNodesByTagName(const QString& sTagName) const;

    //! Returns true if the node has the given attribute
    bool hasAttribute(const QString& sAttribute) const;

    //! Deletes all child nodes with the given tag
    void removeNodesByTagName(QString sTagName);

    //-------------------------------------------------------------------------------------------------
    // High level control methods
    //-------------------------------------------------------------------------------------------------

    //! Loads a CXMLNode from a XML or JSON file based on the extension
    static CXMLNode load(const QString& sFileName);

    //! Saves content to a XML or JSON file based on the extension
    bool save(const QString& sFileName);

    //! Reads a XML file given a file name
    static CXMLNode loadXMLFromFile(const QString& sFileName);

    //! Reads a compressed XML file given a file name
    static CXMLNode loadXMLCFromFile(const QString& sFileName);

    //! Reads a JSON file given a file name
    static CXMLNode loadJSONFromFile(const QString& sFileName);

    //! Converts the document to a string
    QString toString(bool bXMLHeader = true) const;

    //! Saves a XML file
    bool saveXMLToFile(const QString& sFileName, bool bXMLHeader = true);

    //! Saves a compressed XML file
    bool saveXMLCToFile(const QString& sFileName, bool bXMLHeader = true);

    //! Saves a JSON file
    bool saveJSONToFile(const QString& sFileName);

    //! Appends a node to the child nodes of this node
    CXMLNode& operator << (CXMLNode value);

    //! Tests if a node is equal to another node
    bool operator == (const CXMLNode& value) const;

    //-------------------------------------------------------------------------------------------------
    // Low level control methods
    //-------------------------------------------------------------------------------------------------

    //! Converts a QDomNode to a CXMLNode
    static CXMLNode parseXMLNode(QDomNode node);

    //! Converts a XML formatted string to a CXMLNode
    static CXMLNode parseXML(QString sText);

    //! Converts a JSON object to a CXMLNode
    static CXMLNode parseJSONNode(QJsonObject jObject, QString sTagName);

    //! Converts a JSON array object to a vector of CXMLNode
    static CXMLNodeList parseJSONArray(QJsonArray jArray, QString sTagName);

    //! Converts a JSON formatted string to a CXMLNode
    static CXMLNode parseJSON(QString sText);

    //! Converts the node to a QDomDocument
    QDomDocument toQDomDocument(bool bXMLHeader = true) const;

    //! Converts the node to a QDomElement using 'xDocument'
    QDomElement toQDomElement(QDomDocument& xDocument) const;

    //! Converts the node to a QJsonDocument
    QJsonDocument toJsonDocument() const;

    //! Converts the node to a JSON string
    QString toJsonString() const;

    //! Converts the node to a JSON object
    QJsonObject toJsonObject() const;

    //! Merges the 'target' node into this node
    void merge(const CXMLNode& xTarget);

    //! Returns a string describing the list of direct childs for that node
    QString stringifyOneLevel();

    //-------------------------------------------------------------------------------------------------
    // Static public properties
    //-------------------------------------------------------------------------------------------------

public:

    static const QString sExtension_XML;
    static const QString sExtension_XMLC;
    static const QString sExtension_QRC;
    static const QString sExtension_JSON;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString                 m_sTag;         // Node's tag
    QString                 m_sValue;       // Node's value
    QMap<QString, QString>  m_vAttributes;  // Node's attributes
    CXMLNodeList            m_vNodes;       // Child nodes
};

Q_DECLARE_METATYPE(CXMLNode);
