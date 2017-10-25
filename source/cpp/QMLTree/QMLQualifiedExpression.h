
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVector>

// Library
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a qualified expression (some.qualified.expression)
class QTPLUSSHARED_EXPORT QMLQualifiedExpression : public QMLComplexEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLQualifiedExpression(const QPoint& pPosition);

    //! Destructor
    virtual ~QMLQualifiedExpression();

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void solveReferences(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void solveSymbolUsages(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:
};
