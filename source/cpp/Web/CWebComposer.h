
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QVector>
#include <QSize>

// Application
#include "../CSingleton.h"

//-------------------------------------------------------------------------------------------------

//! Defines a class that renders HTML components
class QTPLUSSHARED_EXPORT CWebComposer : public CSingleton<CWebComposer>
{
    friend class CSingleton<CWebComposer>;

public:

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the list of required JS files
    const QVector<QString>& getJSFiles() const;

    //! Returns the list of required CSS files
    const QVector<QString>& getCSSFiles() const;

    //! Returns scripts lines that get executed in document.ready()
    const QVector<QString>& getReadyScriptLines() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Clears all lists
    void reset();

    //!
    void addJSFile(QString sFileName);

    //!
    void addCSSFile(QString sFileName);

    //!
    void addJSFileStatement(QString& sHead, QString sFileName);

    //!
    void addCSSFileStatement(QString& sHead, QString sFileName);

    //!
    void addReadyScript(QString sScript);

    //!
    void addText(QString& sPage, QString sText);

    //!
    void addNewLine(QString& sPage);

    //!
    void beginDiv(QString& sPage, QString sID = "SomeDiv", QString sClass="");

    //!
    void endDiv(QString& sPage);

    //!
    void beginTable(QString& sPage, QString sID = "SomeTable");

    //!
    void endTable(QString& sPage);

    //!
    void beginTableRow(QString& sPage);

    //!
    void endTableRow(QString& sPage);

    //!
    void beginTableCell(QString& sPage);

    //!
    void endTableCell(QString& sPage);

    //!
    void addTableCell(QString& sPage, QString sValue);

    //!
    void addLink(QString& sPage, QString sText, QString sLink);

    //!
    void addSelector(QString& sPage, QString sID, QStringList lValues, QString sSelected, QString sOnChanged = "");

    //!
    void addButton(QString& sPage, QString sID, QString sText, QSize sSize = QSize(0, 0), QString sOnClicked = "", QString sArgument = "");

    //!
    void addTextInput(QString& sPage, QString sID, QString sText, QSize sSize = QSize(0, 0), QString sPlaceHolder = "", QString sOnChanged = "");

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

private:

    //! Constructor
    CWebComposer();

    //! Destructor
    virtual ~CWebComposer() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QVector<QString>    m_vJSFiles;
    QVector<QString>    m_vCSSFiles;
    QVector<QString>    m_vReadyScriptLines;
};
