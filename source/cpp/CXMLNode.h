
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include <QMap>
#include <QVector>
#include <QDomDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//-------------------------------------------------------------------------------------------------

//! Définit un noeud XML
class QTPLUSSHARED_EXPORT CXMLNode
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructeur par défaut
    //! Default constructor
    CXMLNode();

    //! Constructeur avec nom de tag
    //! Constructor with tag name
    CXMLNode(const QString& sTagName);

    //! Destructeur
    //! Destructor
    virtual ~CXMLNode();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Définit le tag de ce noeud
    //! Defines this node's tag
    void setTag(const QString& value);

    //! Définit la valeur de ce noeud
    //! Defines this node's value
    void setValue(const QString& value);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Retourne vrai si le neoud est vide (pas de tag)
    //! Returns true if the node is empty (no tag)
    bool isEmpty() const;

    //! Retourne le tag de ce noeud
    const QString& tag() const;

    //! Retourne la valeur de ce noeud
    const QString& value() const;

    //! Retourne les attributs de ce noeud
    const QMap<QString, QString>& attributes() const;

    //! Retourne les attributs de ce noeud
    QMap<QString, QString>& attributes();

    //! Retourne les noeuds enfants de ce noeud
    const QVector<CXMLNode>& nodes() const;

    //! Retourne les noeuds enfants de ce noeud
    QVector<CXMLNode>& nodes();

    //! Retourne un noeud selon son tag
    CXMLNode getNodeByTagName(const QString& sTagName);

    //! Retourne un noeud selon son tag
    CXMLNode getNodeByTagName(const QString& sTagName) const;

    //! Retourne une liste de noeuds selon leur tag
    QVector<CXMLNode> getNodesByTagName(const QString& sTagName) const;

    //! Returns true if the node has the given attribute
    bool hasAttribute(const QString& sAttribute) const;

    //! Supprime tous les tags spécifiés
    void removeNodesByTagName(QString sTagName);

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle haut niveau
    // High level control methods
    //-------------------------------------------------------------------------------------------------

    //! Charge un CXMLNode depuis un fichier XML ou JSON selon son extension
    //! Loads a CXMLNode from a XML or JSON file based on the extension
    static CXMLNode load(const QString& sFileName);

    //! Ecrit le contenu dans un fichier XML ou JSON selon son extension
    //! Saves content to a XML or JSON file based on the extension
    bool save(const QString& sFileName);

    //! Lit un fichier XML d'après un nom de fichier
    //! Reads a XML file given a file name
    static CXMLNode loadXMLFromFile(const QString& sFileName);

    //! Lit un fichier XML d'après un nom de fichier
    //! Reads a JSON file given a file name
    static CXMLNode loadJSONFromFile(const QString& sFileName);

    //! Convertit en QString
    //! Converts the document to a string
    QString toString(bool bXMLHeader = true) const;

    //! Ecrit un fichier XML
    //! Saves a XML file
    bool saveXMLToFile(const QString& sFileName, bool bXMLHeader = true);

    //! Ecrit un fichier XML
    //! Saves a XML file
    bool saveJSONToFile(const QString& sFileName);

    //! Ajoute un noeud aux noeuds enfants de ce noeud
    //! Appends a node to the child nodes of this node
    CXMLNode& operator << (CXMLNode value);

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle bas niveau
    // Low level control methods
    //-------------------------------------------------------------------------------------------------

    //! Lit un noeud XML depuis un QDomNode
    static CXMLNode parseXMLNode(QDomNode node);

    //! Lit un texte XML depuis un QString
    static CXMLNode parseXML(QString sText);

    //! Lit un objet JSON
    //! Reads a JSON object
    static CXMLNode parseJSONNode(QJsonObject jObject, QString sTagName);

    //! Lit un tableau JSON
    //! Reads a JSON array
    static QVector<CXMLNode> parseJSONArray(QJsonArray jArray, QString sTagName);

    //! Lit un fichier JSON
    //! Reads a JSON file
    static CXMLNode parseJSON(QString sText);

    //! Convertit en QDomDocument
    //! Converts the node to a QDomDocument
    QDomDocument toQDomDocument(bool bXMLHeader = true) const;

    //! Convertit en QDomElement en utilisant 'xDocument'
    //! Converts the node to a QDomElement using 'xDocument'
    QDomElement toQDomElement(QDomDocument& xDocument) const;

    //! Convertit en QJsonDocument
    //! Converts the node to a QJsonDocument
    QJsonDocument toJsonDocument() const;

    //! Convertit en JSON string
    //! Converts the node to a JSON string
    QString toJsonString() const;

    //!
    QJsonObject toJsonObject() const;

    //! Fusionne le noeud 'target' avec ce noeud
    //! Merges the 'target' node into this node
    void merge(const CXMLNode& target);

    //! Renvoie une chaine de carateres decrivant la liste des enfants directs
    //! Returns a string describing the list of direct childs for that node
    QString stringifyOneLevel();

    //-------------------------------------------------------------------------------------------------
    // Propriétés statiques publiques
    // Static public properties
    //-------------------------------------------------------------------------------------------------

public:

    static const QString sExtension_XML;
    static const QString sExtension_QRC;
    static const QString sExtension_JSON;

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString                 m_sTag;         // Tag du noeud - Node's tag
    QString                 m_sValue;       // Valeur du noeud - Node's value
    QMap<QString, QString>  m_vAttributes;  // Attributs du noeuds - Node's attributes
    QVector<CXMLNode>       m_vNodes;       // Noeuds enfants - Child nodes
};
