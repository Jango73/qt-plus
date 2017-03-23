
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Library
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a base QML item
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
    virtual void solveOrigins(QMLTreeContext* pContext, QMLEntity* pParent = nullptr);

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:
};
