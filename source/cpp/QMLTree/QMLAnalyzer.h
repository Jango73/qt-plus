
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

class QTPLUSSHARED_EXPORT QMLAnalyzerError
{
public:

    //!
    QMLAnalyzerError();

    //!
    QMLAnalyzerError(const QString& sFileName, QPoint pPosition, const QString& sText);

    //!
    QString fileName() const;

    //!
    QPoint position() const;

    //!
    QString text() const;

    //!
    QString toString() const;

protected:

    QString m_sFileName;
    QPoint  m_pPosition;
    QString m_sText;
};

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
    const QVector<QMLAnalyzerError>& errors() const;

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
    void analyzeError(QMLAnalyzerError tError);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    bool analyze_Recurse(QString sDirectory);

    //!
    void runGrammar(const QString& sFileName, QMLTreeContext* pContext);

    //!
    void runGrammar_Recurse(const QString& sFileName, QMLItem* pItem);

    //!
    int runGrammar_CountNested(const QString& sClassName, QMLItem* pItem);

    //!
    void outputError(const QString& sFileName, const QPoint& pPosition, const QString& sText);

protected:

    QString                         m_sFolder;
    QString                         m_sFile;
    QMap<QString, QMLTreeContext*>  m_mContexts;     // The QML context used for parsing
    QVector<QMLAnalyzerError>       m_vErrors;
    CXMLNode                        m_xGrammar;
    bool                            m_bIncludeImports;
    bool                            m_bIncludeSubFolders;
};
