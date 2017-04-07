
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVariant>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a type object
class QTPLUSSHARED_EXPORT QMLSpecialValue : public QMLEntity
{
    Q_OBJECT

public:

    enum ESpecialValue
    {
        svNone,
        svNull,
        svUndefined
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLSpecialValue(const QPoint& pPosition);

    //! Constructor with QVariant
    QMLSpecialValue(const QPoint& pPosition, ESpecialValue value);

    //! Destructor
    virtual ~QMLSpecialValue();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setSpecialValue(ESpecialValue value);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    ESpecialValue specialValue() const;

    //!
    virtual QString toString() const Q_DECL_OVERRIDE;

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

    ESpecialValue   m_eValue;
};
