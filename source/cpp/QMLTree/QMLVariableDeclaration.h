
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVariant>
#include <QTextStream>

// Library
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a function variable declaration
class QTPLUSSHARED_EXPORT QMLVariableDeclaration : public QMLComplexEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with filename
    QMLVariableDeclaration(const QPoint& pPosition);

    //! Copy constructor
    QMLVariableDeclaration(const QMLVariableDeclaration& target);

    //! Destructor
    virtual ~QMLVariableDeclaration();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QMap<QString, QMLEntity*> getDeclaredSymbols() Q_DECL_OVERRIDE;

    //!
    virtual void toQML(QTextStream& stream, const QMLEntity* pParent = nullptr, int iIdent = 0) const Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:
};
