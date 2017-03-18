
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVector>

// Library
#include "QMLItem.h"

//-------------------------------------------------------------------------------------------------

//! Defines a base QML item
class QTPLUSSHARED_EXPORT QMLComplexItem : public QMLItem
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLComplexItem(const QPoint& pPosition, QMLItem* pName = nullptr);

    //! Destructor
    virtual ~QMLComplexItem();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setName(QMLItem* pName);

    //!
    void setIsArray(bool bValue);

    //!
    void setIsObject(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLItem* name() const;

    //!
    QVector<QMLItem*>& contents();

    //!
    bool isArray() const;

    //!
    bool isObject() const;

    //!
    const QVector<QMLItem*>& contents() const;

    //!
    virtual QString toString() const Q_DECL_OVERRIDE;

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

    QMLItem*            m_pName;
    QVector<QMLItem*>   m_vContents;
    bool                m_bIsArray;
    bool                m_bIsObject;
};
