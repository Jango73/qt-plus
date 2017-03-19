
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVariant>
#include <QTextStream>
#include <QPoint>

// Library
#include "../CDumpable.h"
#include "../CXMLNodable.h"

//-------------------------------------------------------------------------------------------------
// Forward declarations

class QMLTreeContext;

//-------------------------------------------------------------------------------------------------

//! Defines a base QML item
class QTPLUSSHARED_EXPORT QMLItem : public QObject, public CDumpable, public CXMLNodable
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLItem(const QPoint& pPosition);

    //! Constructor with QVariant
    QMLItem(const QPoint& pPosition, const QVariant& value);

    //! Destructor
    virtual ~QMLItem();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void setValue(const QVariant& value);

    //!
    virtual void setPosition(const QPoint& point);

    //!
    virtual void setOrigin(QMLItem* pItem);

    //!
    void setIsParenthesized(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QPoint position() const;

    //!
    QMLItem* origin() const;

    //!
    bool isParenthesized() const;

    //!
    virtual QVariant value() const;

    //!
    virtual QString toString() const;

    //! Returns all members
    virtual QMap<QString, QMLItem*> members();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Virtual control methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void solveOrigins(QMLTreeContext* pContext, QMLItem* pParent = nullptr);

    //!
    virtual QMap<QString, QMLItem*> getDeclaredVariables();

    //!
    virtual QMLItem* findNamedItem(const QString& sName);

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent = nullptr, int iIdent = 0);

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QVariant    m_vValue;
    QPoint      m_pPosition;
    QMLItem*    m_pOrigin;
    bool        m_bIsParenthesized;
};
