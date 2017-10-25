
#pragma once

#include "../unislib_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVector>

// Library
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a Something on Item expression
class UNISLIBSHARED_EXPORT QMLOnExpression : public QMLComplexEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLOnExpression(const QPoint& pPosition, QMLEntity* pSource, QMLEntity* pName, QMLComplexEntity* pContents);

    //! Destructor
    virtual ~QMLOnExpression();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLEntity*  m_pTarget;
};
