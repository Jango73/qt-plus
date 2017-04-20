
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QThread>
#include <QMutex>
#include <QString>
#include <QVariant>
#include <QJSEngine>

// Foundations
#include "../CXMLNode.h"
#include "QMLTreeContext.h"
#include "QMLComplexEntity.h"
#include "QMLImport.h"
#include "QMLPropertyDeclaration.h"
#include "QMLPropertyAssignment.h"
#include "QMLIdentifier.h"
#include "QMLQualifiedExpression.h"
#include "QMLFunctionCall.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT QMLAnalyzer : public QThread
{
    Q_OBJECT

    friend class QMLAnalyzerWrapper;

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

    //! Set file
    void setFile(const QString& sFileName);

    //! Set include imports
    void setIncludeImports(bool bValue);

    //! Set include subfolders
    void setIncludeSubFolders(bool bValue);

    //! Set rewrite files
    void setRewriteFiles(bool bValue);

    //! Set remove unreferenced symbols
    void setRemoveUnreferencedSymbols(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Return folder
    QString folder() const;

    //! Return error list
    const QVector<QMLAnalyzerError>& errors() const;

    //! Return the parse context
    QMLTreeContext* context();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void clear();

    //!
    bool analyze(CXMLNode xGrammar);

    //!
    void threadedAnalyze(CXMLNode xGrammar);

    //!
    void stopThreadedAnalyze();

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
    void parseMacros();

    //!
    QString processMacros(const QString& sText);

    //!
    bool analyze_Recurse(QString sDirectory);

    //!
    void runGrammar(const QString& sFileName, QMLFile* pFile);

    //!
    void runGrammar_Recurse(const QString& sFileName, QMLEntity* pEntity);

    //!
    bool runGrammar_Reject(const QString& sFileName, const QString& sClassName, QMLEntity* pEntity, CXMLNode xRule, bool bInverseLogic);

    //!
    bool runGrammar_SatisfiesConditions(const QString& sFileName, const QString& sClassName, QMLEntity* pEntity, CXMLNode xRule);

    //!
    int runGrammar_CountNested(const QString& sClassName, QMLEntity* pEntity);

    //!
    void outputError(const QString& sFileName, const QPoint& pPosition, const QString& sText);

protected:

    QMutex                          m_mContextMutex;
    QJSEngine                       m_eEngine;
    QString                         m_sFolder;
    QString                         m_sFile;
    QString                         m_sText;
    QString                         m_sBeautifyScript;
    QMLTreeContext*                 m_pContext;
    QVector<QMLAnalyzerError>       m_vErrors;
    CXMLNode                        m_xGrammar;
    QMap<QString, QString>          m_mMacros;
    bool                            m_bIncludeImports;
    bool                            m_bIncludeSubFolders;
    bool                            m_bRewriteFiles;
    bool                            m_bRemoveUnreferencedSymbols;
    bool                            m_bStopAnalyzeRequested;
};

//-------------------------------------------------------------------------------------------------

class UNISLIBSHARED_EXPORT QMLAnalyzerWrapper : public QObject
{
    Q_OBJECT

public:

    //!
    QMLAnalyzerWrapper(QMLAnalyzer* pAnalyzer)
        : m_pAnalyzer(pAnalyzer)
    {
    }

    //!
    Q_INVOKABLE QJSValue text()
    {
        return m_pAnalyzer->m_eEngine.toScriptValue(m_pAnalyzer->m_sText);
    }

protected:

    QMLAnalyzer* m_pAnalyzer;
};
