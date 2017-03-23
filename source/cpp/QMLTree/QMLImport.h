
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------
// Forward declarations

class QMLTreeContext;

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLImport : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with name and content
    QMLImport(const QPoint& pPosition, QMLTreeContext* pContext, const QString& sName, const QString& sVersion, const QString& sAs = "");

    //! Destructor
    virtual ~QMLImport();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QString name() const;

    //!
    QString version() const;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString    m_sName;
    QString    m_sVersion;
    QString    m_sAs;
};
