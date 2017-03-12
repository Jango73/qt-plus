
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QStack>

// Library
#include "../CXMLNodable.h"
#include "QMLComplexItem.h"

#define PURE_PARSER

//-------------------------------------------------------------------------------------------------

typedef union
{
    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLItem*    Object;
} UParserValue;

//-------------------------------------------------------------------------------------------------

//!
class QTPLUSSHARED_EXPORT QMLTreeContext : public CXMLNodableContext
{
public:

    //-------------------------------------------------------------------------------------------------
    // Enumerators
    //-------------------------------------------------------------------------------------------------

    enum EParseError
    {
        peSuccess = 0,
        peNoFile,
        peSyntaxError
    };

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructeur par d�faut
    //! Default constructor
    QMLTreeContext(const QString &sFileName);

    //! Destructeur
    //! Destructor
    virtual ~QMLTreeContext();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setIncludeImports(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QString folder() const;

    //!
    QMLComplexItem& item();

    //!
    bool success() const;

    //!
    QString errorString() const;

    //!
    QPoint position() const;

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    EParseError parse();

    //!
    EParseError parseImportFile(const QString& sFileName);

    //!
    int nextToken(void* LVAL);

    //!
    QString tokenValue() const;

    //!
    void showError(const QString& sText);

private:

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le priv�es
    // Private control methods
    //-------------------------------------------------------------------------------------------------

    //!
    int parseNextToken(UParserValue* LVAL);

    //!
    int parseNumber (UParserValue* lval);

    //!
    int parseEscape();

    //!
    int getChar();

    //!
    int ungetChar(int iChar);

protected:

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le prot�g�es
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

    class QMLScope
    {
    public:
        QMLScope()
            : m_eError(peSuccess)
            , m_iLine(1)
            , m_iColumn(1)
            , m_bParsingFloat(false)
            , m_bParsingHexa(false)
        {
        }

        QMLScope(const QString& sFileName)
            : m_eError(peSuccess)
            , m_sFileName(sFileName)
            , m_fInputFile(sFileName)
            , m_iLine(1)
            , m_iColumn(1)
            , m_bParsingFloat(false)
            , m_bParsingHexa(false)
        {
            m_fInputFile.open(QFile::ReadOnly);
            m_sStream.setDevice(&m_fInputFile);
            m_pCurrentTokenValue = new QString();
        }

        ~QMLScope()
        {
            m_fInputFile.close();
        }

        QMLScope(const QMLScope& target)
        {
            Q_UNUSED(target);
        }

        bool operator == (const QMLScope& target)
        {
            Q_UNUSED(target);

            return false;
        }

        EParseError         m_eError;
        QString             m_sFileName;
        QFile               m_fInputFile;
        QTextStream         m_sStream;
        QString*            m_pCurrentTokenValue;
        int                 m_iLine;
        int                 m_iColumn;
        int                 m_iPreviousLine;
        int                 m_iPreviousColumn;
        int                 m_iCommentLevel;
        bool                m_bParsingFloat;
        bool                m_bParsingHexa;
    };

    EParseError parse_Internal();

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    // Properties
    //-------------------------------------------------------------------------------------------------

    EParseError             m_eError;
    QString                 m_sErrorString;
    QString                 m_sFolder;
    QStack<QMLScope*>       m_sScopes;
    QVector<QString>        m_vFiles;
    QMLComplexItem          m_tItem;
    QMap<QString, int>      m_mTokens;
    bool                    m_bIncludeImports;
};
