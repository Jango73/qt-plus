
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLPropertyDeclaration.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property assignment
class QTPLUSSHARED_EXPORT QMLPropertyAssignment : public QMLPropertyDeclaration
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with name and content
    QMLPropertyAssignment(const QPoint& pPosition, QMLEntity* pName, QMLEntity *pContent);

    //! Destructor
    virtual ~QMLPropertyAssignment();

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
