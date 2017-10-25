
// Application
#include "QMLPropertyDeclaration.h"
#include "QMLIdentifier.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLPropertyDeclaration
    \inmodule qt-plus
    \brief A property declaration in a QML file, as in [ property string myColor: "red" ].
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLPropertyDeclaration. \br\br
    \a pPosition is the position of the token in the file.
    \a pType is the type of the property.
    \a pName is the name of the entity.
*/
QMLPropertyDeclaration::QMLPropertyDeclaration(const QPoint& pPosition, QMLType* pType, QMLEntity* pName)
    : QMLEntity(pPosition)
    , m_pType(pType)
    , m_pName(pName)
    , m_pContent(nullptr)
    , m_eModifiers(mNone)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLPropertyDeclaration, with a value equal to \a pContent. \br\br
    \a pPosition is the position of the token in the file.
    \a pType is the type of the property.
    \a pName is the name of the entity.
*/
QMLPropertyDeclaration::QMLPropertyDeclaration(const QPoint& pPosition, QMLType* pType, QMLEntity* pName, QMLEntity* pContent)
    : QMLEntity(pPosition)
    , m_pType(pType)
    , m_pName(pName)
    , m_pContent(pContent)
    , m_eModifiers(mNone)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLPropertyDeclaration.
*/
QMLPropertyDeclaration::~QMLPropertyDeclaration()
{
    if (m_pType != nullptr)
        delete m_pType;
    if (m_pName != nullptr)
        delete m_pName;
    if (m_pContent != nullptr)
        delete m_pContent;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's modifiers \a eModifiers.
*/
void QMLPropertyDeclaration::setModifiers(EModifier eModifiers)
{
    m_eModifiers = eModifiers;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's type.
*/
QMLType* QMLPropertyDeclaration::type() const
{
    return m_pType;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's name.
*/
QMLEntity* QMLPropertyDeclaration::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's content.
*/
QMLEntity* QMLPropertyDeclaration::content()
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's content.
*/
const QMLEntity* QMLPropertyDeclaration::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's modifiers.
*/
QMLPropertyDeclaration::EModifier QMLPropertyDeclaration::modifiers() const
{
    return m_eModifiers;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a map of class members.
*/
QMap<QString, QMLEntity*> QMLPropertyDeclaration::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["type"] = m_pType;
    vReturnValue["name"] = m_pName;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared symbols.
*/
QMap<QString, QMLEntity*> QMLPropertyDeclaration::getDeclaredSymbols()
{
    QMap<QString, QMLEntity*> mReturnValue;

    QMLIdentifier* pIdentifier = dynamic_cast<QMLIdentifier*>(m_pName);

    if (pIdentifier != nullptr)
    {
        mReturnValue[pIdentifier->value().toString()] = pIdentifier;
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the entity as QML to \a stream using \a iIdent for indentation. \br\br
    \a pParent is the caller of this method.
*/
void QMLPropertyDeclaration::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (m_pType != nullptr && m_pName != nullptr)
    {
        formatter.processFragment(stream, QMLFormatter::qffBeforePropertyName);

        if (m_eModifiers == mReadonly)
        {
            stream << "readonly ";
        }
        else if (m_eModifiers == mDefault)
        {
            stream << "default ";
        }

        stream << "property ";
        m_pType->toQML(stream, formatter, this);
        stream << " ";
        m_pName->toQML(stream, formatter, this);

        formatter.processFragment(stream, QMLFormatter::qffAfterPropertyName);

        if (m_pContent != nullptr)
        {
            stream << ": ";

            formatter.processFragment(stream, QMLFormatter::qffBeforePropertyContent);
            m_pContent->toQML(stream, formatter, this);
            formatter.processFragment(stream, QMLFormatter::qffAfterPropertyContent);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode representation of this item. \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode QMLPropertyDeclaration::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
    CXMLNode xType("Type");
    CXMLNode xName("Name");
    CXMLNode xContent("Content");

    xNode.attributes()["Modifiers"] = QString::number((int) m_eModifiers);

    if (m_pType != nullptr)
        xType.nodes() << m_pType->toXMLNode(pContext, this);

    if (m_pName != nullptr)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pContent != nullptr)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xType;
    xNode.nodes() << xName;
    xNode.nodes() << xContent;

    return xNode;
}
