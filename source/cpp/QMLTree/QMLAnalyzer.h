
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

    //! Default constructor
    QMLAnalyzer();

    //! Destructor
    virtual ~QMLAnalyzer();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Set folder
    void setFolder(const QString& sFolder);

    //! Set folder
    void setFile(const QString& sFileName);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Return folder
    QString folder() const;

    //! Return error list
    const QStringList& errors() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    bool analyze(CXMLNode xGrammar);

    //!
    void analyzeFile(const QString& sFileName, CXMLNode xGrammar);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    QStringList runGrammar(const QString& sFileName, QMLTreeContext* pContext, CXMLNode& xGrammar);

    void runGrammar_Recurse(const QString& sFileName, QMLItem* pItem, CXMLNode& xGrammar, QStringList& lErrors);

protected:

    QString                         m_sFolder;
    QString                         m_sFile;
    QMap<QString, QMLTreeContext*>  m_mContexts;     // The QML context used for parsing
    QStringList                     m_lErrors;
};
