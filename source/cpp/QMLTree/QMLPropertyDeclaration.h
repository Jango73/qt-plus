
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLPropertyDeclaration : public QMLItem
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
    QMLPropertyDeclaration(const QPoint& pPosition, QMLType *pType, QMLItem* pName);

    //! Constructor with type, name and content
    QMLPropertyDeclaration(const QPoint& pPosition, QMLType *pType, QMLItem* pName, QMLItem *pContent);

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
    QMLItem* name() const;

    //!
    QMLItem* content();

    //!
    const QMLItem* content() const;

    //!
    EModifier modifiers() const;

    //! Returns all members
    virtual QMap<QString, QMLItem*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLType*    m_pType;
    QMLItem*    m_pName;
    QMLItem*    m_pContent;
    EModifier   m_eModifiers;
};
