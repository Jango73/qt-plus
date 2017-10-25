
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"
#include "QMLComplexEntity.h"
#include "QMLIdentifier.h"

//-------------------------------------------------------------------------------------------------

//! Defines a function
class QTPLUSSHARED_EXPORT QMLFunction : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with name, parameters and content
    QMLFunction(const QPoint& pPosition, QMLEntity* pName, QMLEntity *pParameters, QMLEntity *pContent);

    //! Destructor
    virtual ~QMLFunction();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setIsSignal(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* name() const;

    //!
    QMLEntity* parameters() const;

    //!
    QMLEntity* content() const;

    //!
    bool isSignal() const;

    //!
    QMap<QString, QMLEntity*> unusedParameters();

    //!
    QMap<QString, QMLEntity*> unusedVariables();

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

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
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLEntity*                  m_pName;
    QMLEntity*                  m_pParameters;
    QMLEntity*                  m_pContent;
    bool                        m_bIsSignal;

    // Constructed after parsing
    QMap<QString, QMLEntity*>   m_mParameterList;
    QMap<QString, QMLEntity*>   m_mVariableList;
};
