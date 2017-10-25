
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Library
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines an identifier
class QTPLUSSHARED_EXPORT QMLIdentifier : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLIdentifier(const QPoint& pPosition);

    //! Constructor with QVariant
    QMLIdentifier(const QPoint& pPosition, const QString& value);

    //! Destructor
    virtual ~QMLIdentifier();

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
