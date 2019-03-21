
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QThread>
#include <QMutex>
#include <QString>
#include <QVariant>

// Foundations
#include "../CXMLNode.h"
#include "../CMacroable.h"
#include "QMLTreeContext.h"
#include "QMLComplexEntity.h"
#include "QMLImport.h"
#include "QMLPropertyDeclaration.h"
#include "QMLPropertyAssignment.h"
#include "QMLIdentifier.h"
#include "QMLQualifiedExpression.h"
#include "QMLFunctionCall.h"

//-------------------------------------------------------------------------------------------------

//! Defines a static QML analyzer
class QTPLUSSHARED_EXPORT QMLAnalyzer : public QThread, public CMacroable
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
    bool analyze(const CXMLNode& xGrammar, const CXMLNode& xFormat = CXMLNode());

    //!
    void threadedAnalyze(const CXMLNode& xGrammar, const CXMLNode& xFormat = CXMLNode());

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
    bool analyzeRecurse(QString sDirectory);

    //!
    void runGrammar(QMLFile* pFile);

    //!
    void runGrammar_Recurse(QMLFile* pFile, QMLEntity* pEntity);

    //!
    bool runGrammar_Reject(QMLFile* pFile, const QString& sClassName, QMLEntity* pEntity, CXMLNode xRule, bool bInverseLogic);

    //!
    bool runGrammar_SatisfiesConditions(QMLFile* pFile, const QString& sClassName, QMLEntity* pEntity, CXMLNode xRule);

    //!
    int runGrammar_CountNested(const QString& sClassName, QMLEntity* pEntity);

    //!
    bool runGrammar_importUsed(QMLFile* pFile, QMLImport* pImport);

    //!
    bool isClassUsed(QMLFile* pFile, QMLEntity* pEntity, const QString& sClassName);

    //!
    void outputError(const QString& sFileName, const QPoint& pPosition, const QString& sText);

protected:

    QMutex                          m_mContextMutex;
    QString                         m_sFolder;
    QString                         m_sFile;
    CXMLNode                        m_xNewRules;
    CXMLNode                        m_xNewFormat;
    QMLTreeContext*                 m_pContext;
    QVector<QMLAnalyzerError>       m_vErrors;
    bool                            m_bIncludeImports;
    bool                            m_bIncludeSubFolders;
    bool                            m_bRewriteFiles;
    bool                            m_bRemoveUnreferencedSymbols;
    bool                            m_bStopAnalyzeRequested;
};
