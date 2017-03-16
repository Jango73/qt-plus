
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
#include <QThread>
#include <QString>
#include <QVariant>

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT QMLAnalyzer : public QThread
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
    void setFolder(const QString& sFolder, bool bIncludeSubFolders = false);

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
    bool analyze(CXMLNode xGrammar, bool bIncludeImports = false);

    //!
    void threadedAnalyze(CXMLNode xGrammar, bool bIncludeImports = false);

    //!
    bool analyzeFile(const QString& sFileName);

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    virtual void run() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Signals
    //-------------------------------------------------------------------------------------------------

signals:

    //!
    void parsingStarted(QString sFileName);

    //!
    void parsingFinished(QString sFileName);

    //!
    void importParsingStarted(QString sFileName);

    //!
    void analyzeError(QString sError);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    bool analyze_Recurse(QString sDirectory);

    //!
    QStringList runGrammar(const QString& sFileName, QMLTreeContext* pContext);

    //!
    void runGrammar_Recurse(const QString& sFileName, QMLItem* pItem, QStringList& lErrors);

    //!
    int runGrammar_CountNested(const QString& sClassName, QMLItem* pItem);

    //!
    void outputError(QStringList& lErrors, const QString& sFileName, const QPoint& pPosition, const QString& sText);

protected:

    QString                         m_sFolder;
    QString                         m_sFile;
    QMap<QString, QMLTreeContext*>  m_mContexts;     // The QML context used for parsing
    QStringList                     m_lErrors;
    CXMLNode                        m_xGrammar;
    bool                            m_bIncludeImports;
    bool                            m_bIncludeSubFolders;
};
