
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

// #define TRACK_ENTITIES

//-------------------------------------------------------------------------------------------------
// Forward declarations

class QMLTreeContext;

//-------------------------------------------------------------------------------------------------

//! Defines the base entity of a QML tree
class QTPLUSSHARED_EXPORT QMLFormatter
{
public:

    enum EQMLFormatterFragment {
        qffBeforeImport,
        qffAfterImport,
        qffBeforeItemName,
        qffAfterItemName,
        qffBeforeItemContent,
        qffAfterItemContent,
        qffBeforePropertyName,
        qffAfterPropertyName,
        qffBeforePropertyContent,
        qffAfterPropertyContent,
        qffBeforeFunction,
        qffAfterFunction,
        qffBeforeVariableDeclaration,
        qffBeforeFunctionCall,
        qffAfterFunctionCall,
        qffBeforeFor,
        qffAfterFor,
        qffBeforeWhile,
        qffAfterWhile,
        qffBeforeSwitch,
        qffAfterSwitch,
        qffBeforeIf,
        qffAfterIf,
        qffBeforeTopLevelBinaryOp,
        qffBeforeTopLevelUnaryOp,
        qffBeforeQualifiedExpression
    };

    QMLFormatter();

    void incIndentation();

    void decIndentation();

    void writeNewLine(QTextStream& stream);

    void writeDoubleNewLine(QTextStream& stream);

    void processFragment(QTextStream& stream, EQMLFormatterFragment fragment);

    int m_iIndentation;
};

//-------------------------------------------------------------------------------------------------

//! Defines the base entity of a QML tree
class QTPLUSSHARED_EXPORT QMLEntity : public QObject, public CDumpable, public CXMLNodable
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLEntity(const QPoint& pPosition);

    //! Constructor with QVariant
    QMLEntity(const QPoint& pPosition, const QVariant& value);

    //! Destructor
    virtual ~QMLEntity();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void setValue(const QVariant& value);

    //!
    virtual void setPosition(const QPoint& point);

    //!
    virtual void setOrigin(QMLEntity* pEntity);

    //!
    void setIsParenthesized(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QPoint position() const;

    //!
    QMLEntity* origin() const;

    //!
    int usageCount() const;

    //!
    bool isParenthesized() const;

    //!
    virtual QVariant value() const;

    //!
    virtual QString toString() const;

    //!
    QString toSimpleString() const;

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void incUsageCount();

    //-------------------------------------------------------------------------------------------------
    // Virtual control methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QMLEntity* clone() const;

    //!
    virtual void solveSymbols(QMLTreeContext* pContext);

    //!
    virtual void solveReferences(QMLTreeContext* pContext);

    //!
    virtual void solveSymbolUsages(QMLTreeContext* pContext);

    //!
    virtual QMap<QString, QMLEntity*> getDeclaredSymbols();

    //!
    virtual QMLEntity* findSymbolDeclaration(const QString& sName);

    //!
    virtual QMLEntity* findSymbolDeclarationDescending(QStringList& lQualifiedName);

    //!
    virtual void removeUnreferencedSymbols(QMLTreeContext* pContext);

    //!
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Static methods
    //-------------------------------------------------------------------------------------------------

    //!
    static QStringList qualifiedNameAsList(const QString& sName);

    //!
    static QString listAsQualifiedName(const QStringList& sNameList);

    //!
    static int entityCount();

    //!
    static int createdEntities();

    //!
    static int deletedEntities();

    //!
    static QList<QMLEntity*>& entities();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QVariant    m_vValue;
    QPoint      m_pPosition;
    QMLEntity*  m_pOrigin;
    int         m_iUsageCount;
    bool        m_bIsParenthesized;

    static QList<QMLEntity*>    s_vEntities;
    static int                  s_iCreatedEntities;
    static int                  s_iDeletedEntities;
};
