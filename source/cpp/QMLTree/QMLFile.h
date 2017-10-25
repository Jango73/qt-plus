
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
// Forward declarations

class QMLTreeContext;

//-------------------------------------------------------------------------------------------------

//! Defines a QML file item
class QTPLUSSHARED_EXPORT QMLFile : public QMLComplexEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with filename
    QMLFile(const QPoint& pPosition, QMLTreeContext* pContext, const QString& sFileName);

    //! Copy constructor
    QMLFile(const QMLFile& target);

    //! Destructor
    virtual ~QMLFile();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setParsed(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QString fileName() const;

    //!
    bool parsed() const;

    //!
    bool isSingleton() const;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void solveReferences(QMLTreeContext* pContext) Q_DECL_OVERRIDE;

    //!
    virtual QMLEntity* findSymbolDeclaration(const QString& sName);

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sFileName;
    bool        m_bParsed;
    bool        m_bIsSingleton;
};
