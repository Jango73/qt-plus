
#pragma once

#include <QObject>
#include <QDebug>

#include "../QMLTree/QMLTreeContext.h"
#include "../QMLTree/QMLAnalyzer.h"

class ParsingMonitor : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Parametered constructor
    ParsingMonitor(QMLTreeContext* pContext);

    //! Parametered constructor
    ParsingMonitor(QMLAnalyzer* pAnalyzer);

    //! Destructor
    virtual ~ParsingMonitor();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Set the output file name
    void setOutputFileName(const QString& sFileName);

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onParsingStarted(QString sFileName);

    void onParsingFinished(QString sFileName);

    void onImportParsingStarted(QString sFileName);

    void onAnalyzeError(QMLAnalyzerError sError);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

private:

    QString m_sOutputFileName;
    QFile*  m_pOutputFile;
};
