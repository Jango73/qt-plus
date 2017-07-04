
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLPropertyDeclaration : public QMLEntity
{
    Q_OBJECT

public:

    enum EModifier
    {
        mNone = 0,
        mReadonly = 0x0001,
        mDefault = 0x0002
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with type and name
    QMLPropertyDeclaration(const QPoint& pPosition, QMLType *pType, QMLEntity* pName);

    //! Constructor with type, name and content
    QMLPropertyDeclaration(const QPoint& pPosition, QMLType *pType, QMLEntity* pName, QMLEntity *pContent);

    //! Destructor
    virtual ~QMLPropertyDeclaration();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setModifiers(EModifier eModifiers);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLType* type() const;

    //!
    QMLEntity* name() const;

    //!
    QMLEntity* content();

    //!
    const QMLEntity* content() const;

    //!
    EModifier modifiers() const;

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QMap<QString, QMLEntity*> getDeclaredSymbols() Q_DECL_OVERRIDE;

    //!
    virtual void toQML(QTextStream& stream, const QMLEntity* pParent = nullptr, int iIdent = 0) const Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLType*    m_pType;
    QMLEntity*  m_pName;
    QMLEntity*  m_pContent;
    EModifier   m_eModifiers;
};
