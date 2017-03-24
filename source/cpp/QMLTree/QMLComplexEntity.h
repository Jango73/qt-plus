
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVector>

// Library
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a base QML item
class QTPLUSSHARED_EXPORT QMLComplexEntity : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLComplexEntity(const QPoint& pPosition, QMLEntity* pName = nullptr);

    //! Destructor
    virtual ~QMLComplexEntity();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setName(QMLEntity* pName);

    //!
    void setIsArray(bool bValue);

    //!
    void setIsObject(bool bValue);

    //!
    void setIsBlock(bool bValue);

    //!
    void setIsArgumentList(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* name() const;

    //!
    QVector<QMLEntity*>& contents();

    //!
    bool isNamed() const;

    //!
    bool isArray() const;

    //!
    bool isObject() const;

    //!
    bool isBlock() const;

    //!
    bool isArgumentList() const;

    //!
    const QVector<QMLEntity*>& contents() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QVector<QMLEntity*> grabContents();

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QString toString() const Q_DECL_OVERRIDE;

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //!
    virtual void solveOrigins(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual QMap<QString, QMLEntity*> getDeclaredSymbols() Q_DECL_OVERRIDE;

    //!
    virtual void checkSymbolUsages(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Static methods
    //-------------------------------------------------------------------------------------------------

    //!
    static QMLComplexEntity* fromItem(QMLEntity* pItem);

    //!
    static QMLComplexEntity* makeBlock(QMLEntity* pItem);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLEntity*          m_pName;
    QVector<QMLEntity*> m_vContents;
    bool                m_bIsArray;
    bool                m_bIsObject;
    bool                m_bIsBlock;
    bool                m_bIsArgumentList;
};
