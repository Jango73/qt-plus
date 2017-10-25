
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVariant>

// Application
#include "QMLEntity.h"

#define QVARIANT_VARIANT    ((QVariant::Type) (QVariant::UserType + 1))
#define QVARIANT_LIST_MODEL ((QVariant::Type) (QVariant::UserType + 2))

//-------------------------------------------------------------------------------------------------

//! Defines a type object
class QTPLUSSHARED_EXPORT QMLType : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLType(const QPoint& pPosition);

    //! Constructor with QVariant
    QMLType(const QPoint& pPosition, QVariant::Type type);

    //! Destructor
    virtual ~QMLType();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setType(QVariant::Type type);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QVariant::Type type() const;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Static methods
    //-------------------------------------------------------------------------------------------------

    //!
    static QString typeToString(QVariant::Type eType);

    //!
    static QMLType* fromQMLEntity(QMLEntity* pEntity);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QVariant::Type  m_vType;
};
