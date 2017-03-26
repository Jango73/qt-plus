
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLComplexEntity.h"
#include "QMLIdentifier.h"

//-------------------------------------------------------------------------------------------------

//! Defines a QML item
class QTPLUSSHARED_EXPORT QMLItem : public QMLComplexEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with name, parameters and content
    QMLItem(const QPoint& pPosition, QMLEntity* pName = nullptr);

    //! Destructor
    virtual ~QMLItem();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QString id() const;

    //!
    QMap<QString, QMLEntity*> unusedProperties();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void markAsSingleton();

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void solveSymbols(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void solveReferences(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual QMLEntity* findSymbolDeclaration(const QString& sName) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:
    // Constructed after parsing
    QMap<QString, QMLEntity*>   m_mPropertyList;
    bool                        m_bIsSingleton;
};
