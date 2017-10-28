
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVector>

// Library
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a container for child entities
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
    const QVector<QMLEntity*>& contents() const;

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

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QVector<QMLEntity*> grabContents();

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //!
    virtual void solveSymbols(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void solveReferences(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void solveSymbolUsages(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void sortContents() Q_DECL_OVERRIDE;

    //!
    virtual QMap<QString, QMLEntity*> getDeclaredSymbols() Q_DECL_OVERRIDE;

    //!
    virtual QMLEntity* findSymbolDeclarationDescending(QStringList& lQualifiedName) Q_DECL_OVERRIDE;

    //!
    virtual void removeUnreferencedSymbols(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Static methods
    //-------------------------------------------------------------------------------------------------

    //!
    static QMLComplexEntity* fromEntity(QMLEntity* pEntity);

    //!
    static QMLComplexEntity* makeBlock(QMLEntity* pEntity);

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
