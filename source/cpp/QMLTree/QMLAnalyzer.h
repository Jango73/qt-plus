
#pragma once

#include "../qtplus_global.h"

// Foundations
#include "../CXMLNode.h"
#include "QMLTreeContext.h"
#include "QMLComplexItem.h"
#include "QMLImport.h"
#include "QMLPropertyDeclaration.h"
#include "QMLPropertyAssignment.h"
#include "QMLIdentifier.h"
#include "QMLQualifiedExpression.h"
#include "QMLFunctionCall.h"

// Qt
#include <QObject>
#include <QString>
#include <QVariant>

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT QMLAnalyzer : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    // Default constructor
    QMLAnalyzer();

    // Destructor
    virtual ~QMLAnalyzer();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    // Set folder
    void setFolder(const QString& sFrom);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    // Return folder
    QString folder() const;

    const QStringList& errors() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    bool analyze(CXMLNode xGrammar);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    QStringList runGrammar(QMLTreeContext* pContext, CXMLNode xGrammar);

    void runGrammar_Recurse(QMLItem* pItem, CXMLNode xGrammar, QStringList& lErrors);

protected:

    QString                         m_sFolder;
    QMap<QString, QMLTreeContext*>  m_mContexts;     // The QML context used for parsing
    QStringList                     m_lErrors;
};
