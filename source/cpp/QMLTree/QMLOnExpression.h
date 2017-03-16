
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVector>

// Library
#include "QMLComplexItem.h"

//-------------------------------------------------------------------------------------------------

//! Defines a base QML item
class QTPLUSSHARED_EXPORT QMLOnExpression : public QMLComplexItem
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLOnExpression(const QPoint& pPosition, QMLItem* pSource, QMLItem* pName, QMLComplexItem* pContents);

    //! Destructor
    virtual ~QMLOnExpression();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns all members
    virtual QMap<QString, QMLItem*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLItem*    m_pTarget;
};
