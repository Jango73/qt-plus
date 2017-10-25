
#pragma once

#include "../unislib_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVariant>
#include <QTextStream>

// Library
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a name->value object
class UNISLIBSHARED_EXPORT QMLNameValue : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLNameValue(const QPoint& pPosition);

    //! Constructor with QVariant
    QMLNameValue(const QPoint& pPosition, const QString& sName, const QVariant& sValue);

    //! Destructor
    virtual ~QMLNameValue();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void setName(const QString& sName);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QString name() const;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sName;
};
