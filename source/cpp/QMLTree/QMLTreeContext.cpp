
// Qt
#include <QDebug>
#include <QDir>

// Library
#include "QMLTreeContext.h"
#include "QMLComment.h"

//-------------------------------------------------------------------------------------------------

/*!
    \fn QMLTreeContext::QMLScope::QMLScope()

    Constructs a QMLScope using default values.
*/

/*!
    \fn QMLTreeContext::QMLScope::QMLScope(QMLFile* pFile)

    Constructs a QMLScope using \a pFile. Opens the file for reading.
*/

/*!
    \fn QMLTreeContext::QMLScope::QMLScope(const QMLScope& target)

    Constructs a QMLScope as a copy of using \a target. Does nothing, exists only to make containers happy.
*/

/*!
    \fn QMLTreeContext::QMLScope::~QMLScope()

    Destroys a QMLScope.
*/

/*!
    \fn bool QMLTreeContext::QMLScope::operator == (const QMLScope& target)

    Returns \c true if this object equals \a target.
*/

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLTreeContext
    \inmodule qt-plus
    \brief A QML parser using a Bison grammar file. \br
    \section1 How it works
    After parsing one or many QML files, QMLFile entites hold all QML declarations and JS code as a tree.
    This tree can be traversed in code or exported as a XML or JSON document. \br
    \section1 Example of file parsing
    \code
    QMLTreeContext context;
    context.addFile("SomeFile.qml");
    context.setIncludeImports(true);    // This tells the parse engine to parse all included files
    if (context.parse() == QMLTreeContext::peSuccess)
    {
        // do something in case of success
    }
    else
    {
        qWarning() << context.error();
    }
    \endcode
    \section1 Example of parsing result usage
    We suppose here that the context contains parsed files.
    \code
    // Check if the context has at least one parsed file
    if (context.files().count() > 0 && context.files().first()->parsed())
    {
        // Iterate through the contents of the first parsed file
        foreach (QMLEntity* pEntity, context.files().first()->contents())
        {
            QMLImport* pImport = dynamic_cast<QMLImport*>(pEntity);

            // Check that this entity is an import statement
            if (pImport != nullptr)
            {
                // Return the import's name
                return pImport->name();
            }
        }
    }
    \endcode
    \section1 Example of the structure of a QML file
    With this input file named MyQMLFile.qml,
    \code
    import QtQuick 2.0
    Item {
        id: root
        width: 400
        height: 200

        property real myNumber: 5.0

        Rectangle {
            id: myRectangle
            width: parent.width * 0.5
            height: parent.height
        }

        function update() {
            root.myNumber = 100
        }
    }
    \endcode
    the QML tree will look like
    \code
    QMLFile
    |-- fileName() : "MyQMLFile.qml"
    |-- parsed() : true
    |-- isSingleton() : false
    |-- contents() [0]
        |-- QMLImport
            |-- name() : "QtQuick"
            |-- version() : "2.0"
            |-- as() : nullptr
    |-- contents() [1]
        |-- QMLItem
            |-- name() : "Item"
            |-- id() : "root"
            |-- contents() [0]
            |   |-- QMLPropertyAssignment
            |       |-- type() : nullptr    (No type since this is not a declaration)
            |       |-- name() : "id"
            |       |-- content()
            |           |-- QMLIdentifier
            |               |-- value() : "root"
            |-- contents() [1]
            |   |-- QMLPropertyAssignment
            |       |-- type() : nullptr    (No type since this is not a declaration)
            |       |-- name() : "width"
            |       |-- content()
            |           |-- QMLIdentifier
            |               |-- value() : 400
            |-- contents() [2]
            |   |-- QMLPropertyAssignment
            |       |-- type() : nullptr    (No type since this is not a declaration)
            |       |-- name() : "height"
            |       |-- content()
            |           |-- QMLIdentifier
            |               |-- value() : 200
            |-- contents() [3]
            |   |-- QMLPropertyDeclaration
            |       |-- type()
            |           |-- QMLType
            |               |-- type() : QVariant::Double
            |       |-- name() : "myNumber"
            |       |-- content()
            |           |-- QMLIdentifier
            |               |-- value() : 5.0
            |-- contents() [4]
            |   |-- QMLItem
            |       |-- name() : "Rectangle"
            |       |-- id() : "myRectangle"
            |       |-- contents() [0]
            |       |   |-- QMLPropertyAssignment
            |       |       |-- type() : nullptr    (No type since this is not a declaration)
            |       |       |-- name() : "id"
            |       |       |-- content()
            |       |           |-- QMLIdentifier
            |       |               |-- value() : "myRectangle"
            |       |-- contents() [1]
            |       |   |-- QMLPropertyAssignment
            |       |       |-- type() : nullptr    (No type since this is not a declaration)
            |       |       |-- name() : "width"
            |       |       |-- content()
            |       |           |-- QMLBinaryOperation
            |       |               |-- operator() : QMLBinaryOperation::boMul
            |       |               |-- left()
            |       |               |   |-- QMLQualifiedExpression
            |       |               |       |-- contents() [0]
            |       |               |       |   |-- QMLIdentifier
            |       |               |       |       |-- name() : "parent"
            |       |               |       |-- contents() [1]
            |       |               |           |-- QMLIdentifier
            |       |               |               |-- name() : "width"
            |       |               |-- right()
            |       |                   |-- QMLIdentifier
            |       |                       |-- value() : 0.5
            |       |-- contents() [2]
            |           |-- QMLPropertyAssignment
            |               |-- type() : nullptr    (No type since this is not a declaration)
            |               |-- name() : "height"
            |               |-- content()
            |                   |-- QMLQualifiedExpression
            |                       |-- contents() [0]
            |                       |   |-- QMLIdentifier
            |                       |       |-- name() : "parent"
            |                       |-- contents() [1]
            |                           |-- QMLIdentifier
            |                               |-- name() : "height"
            |-- contents() [5]
                |-- QMLFunction
                    |-- name() : "update"
                    |-- parameters() : nullptr      (No arguments)
                    |-- content()
                        |-- QMLBinaryOperation
                            |-- operator() : QMLBinaryOperation::boAssign
                            |-- left()
                            |   |-- QMLQualifiedExpression
                            |       |-- contents() [0]
                            |       |   |-- QMLIdentifier
                            |       |       |-- name() : "root"
                            |       |-- contents() [1]
                            |           |-- QMLIdentifier
                            |               |-- name() : "myNumber"
                            |-- right()
                                |-- QMLIdentifier
                                    |-- value() : 100
    \endcode
*/

/*!
    \fn void QMLTreeContext::parsingStarted(QString sFileName)

    This signal is emitted when parsing on \a sFileName is starting.
*/

/*!
    \fn void QMLTreeContext::parsingFinished(QString sFileName)

    This signal is emitted when parsing on \a sFileName has ended.
*/

/*!
    \fn void QMLTreeContext::importParsingStarted(QString sFileName)

    This signal is emitted when parsing on the imported file \a sFileName is starting.
*/

/*!
    \enum QMLTreeContext::EParseError
    Used to identify the result of a file parsing.

    \value peSuccess
    This indicates that parsing was successful.

    \value peNoFile
    This indicates that there are no files to parse.

    \value peSyntaxError
    This indicates that there was a syntax error while parsing.
*/

//-------------------------------------------------------------------------------------------------

#define SCOPE                   (*(m_sScopes.last()))
#define GET(a)                  { (a) = getChar(); }
#define UNGET(a)                { ungetChar((a)); }
#define STORE(a)                { *(SCOPE.m_pCurrentTokenValue) += QString(QChar(a)); }

#define TOKEN_IDENTIFIER        300
#define TOKEN_LITERAL           301
#define TOKEN_BOOLCONSTANT      302
#define TOKEN_INTEGERCONSTANT   303
#define TOKEN_REALCONSTANT      304
#define TOKEN_NULL              305
#define TOKEN_UNDEFINED         306

#define TOKEN_ASSIGN            310
#define TOKEN_ADD               311
#define TOKEN_SUB               312
#define TOKEN_MUL               313
#define TOKEN_DIV               314
#define TOKEN_MOD               315
#define TOKEN_AND               316
#define TOKEN_OR                317
#define TOKEN_XOR               318
#define TOKEN_SHL               319
#define TOKEN_SHR               320
#define TOKEN_ADD_ASSIGN        321
#define TOKEN_SUB_ASSIGN        322
#define TOKEN_MUL_ASSIGN        323
#define TOKEN_DIV_ASSIGN        324
#define TOKEN_MOD_ASSIGN        325
#define TOKEN_AND_ASSIGN        326
#define TOKEN_OR_ASSIGN         327
#define TOKEN_XOR_ASSIGN        328
#define TOKEN_SHL_ASSIGN        329
#define TOKEN_SHR_ASSIGN        330
#define TOKEN_LOWER             331
#define TOKEN_GREATER           332
#define TOKEN_LOWER_EQUALS      333
#define TOKEN_GREATER_EQUALS    334
#define TOKEN_EQUALS            335
#define TOKEN_EQUALS_CHECK      336
#define TOKEN_NOT_EQUALS        337
#define TOKEN_NOT_EQUALS_CHECK  338
#define TOKEN_LOGICAL_AND       339
#define TOKEN_LOGICAL_OR        340
#define TOKEN_NOT               341
#define TOKEN_NOT_NOT           342
#define TOKEN_INC               343
#define TOKEN_DEC               344
#define TOKEN_COMPLEMENT        345
#define TOKEN_DIMENSION         346

#define TOKEN_IMPORT            500
#define TOKEN_PROPERTY          501
#define TOKEN_DEFAULT           502
#define TOKEN_READ_ONLY         503
#define TOKEN_ALIAS             504
#define TOKEN_VAR               505
#define TOKEN_BOOL              506
#define TOKEN_INT               507
#define TOKEN_REAL              508
#define TOKEN_STRING            509
#define TOKEN_VARIANT           510
#define TOKEN_COLOR             511
#define TOKEN_FUNCTION          512
#define TOKEN_IF                513
#define TOKEN_ELSE              514
#define TOKEN_FOR               515
#define TOKEN_IN                516
#define TOKEN_WHILE             517
#define TOKEN_SWITCH            518
#define TOKEN_CASE              519
#define TOKEN_BREAK             520
#define TOKEN_CONTINUE          521
#define TOKEN_WITH              522
#define TOKEN_RETURN            523
#define TOKEN_TYPEOF            524
#define TOKEN_PRAGMA            525
#define TOKEN_ON                526
#define TOKEN_AS                527
#define TOKEN_SIGNAL            528
#define TOKEN_NEW               529

//-------------------------------------------------------------------------------------------------

extern int yydebug;
extern int yyparse(QMLTreeContext* pContext);

//-------------------------------------------------------------------------------------------------

QMLAnalyzerError::QMLAnalyzerError()
{
}

QMLAnalyzerError::QMLAnalyzerError(const QMLAnalyzerError& target)
{
    *this = target;
}

QMLAnalyzerError::QMLAnalyzerError(const QString& sFileName, QPoint pPosition, const QString& sText)
    : m_sFileName(sFileName)
    , m_pPosition(pPosition)
    , m_pOriginalPosition(pPosition)
    , m_sText(sText)
{
}

QMLAnalyzerError& QMLAnalyzerError::operator = (const QMLAnalyzerError& target)
{
    m_sFileName         = target.m_sFileName;
    m_pPosition         = target.m_pPosition;
    m_pOriginalPosition = target.m_pOriginalPosition;
    m_sText             = target.m_sText;

    return *this;
}

void QMLAnalyzerError::setPosition(const QPoint& point)
{
    m_pPosition = point;
}

QString QMLAnalyzerError::fileName() const
{
    return m_sFileName;
}

QPoint QMLAnalyzerError::position() const
{
    return m_pPosition;
}

QPoint QMLAnalyzerError::originalPosition() const
{
    return m_pOriginalPosition;
}

QString QMLAnalyzerError::text() const
{
    return m_sText;
}

QString QMLAnalyzerError::toString() const
{
    return QString("%1 (%2, %3) : %4")
            .arg(m_sFileName)
            .arg(m_pPosition.y() + 1)
            .arg(m_pPosition.x() + 1)
            .arg(m_sText);
}

void QMLAnalyzerError::clear()
{
    m_sFileName.clear();
    m_pPosition = QPoint(0, 0);
    m_pOriginalPosition = QPoint(0, 0);
    m_sText.clear();
}

void QMLAnalyzerError::revertToOriginalPosition()
{
    m_pPosition = m_pOriginalPosition;
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLTreeContext.
*/
QMLTreeContext::QMLTreeContext()
    : m_eError(peSuccess)
    , m_bIncludeImports(false)
{
    m_mTokens["import"] = TOKEN_IMPORT;
    m_mTokens["property"] = TOKEN_PROPERTY;
    m_mTokens["default"] = TOKEN_DEFAULT;
    m_mTokens["readonly"] = TOKEN_READ_ONLY;
    m_mTokens["alias"] = TOKEN_ALIAS;
    m_mTokens["function"] = TOKEN_FUNCTION;
    m_mTokens["if"] = TOKEN_IF;
    m_mTokens["else"] = TOKEN_ELSE;
    m_mTokens["for"] = TOKEN_FOR;
    m_mTokens["in"] = TOKEN_IN;
    m_mTokens["while"] = TOKEN_WHILE;
    m_mTokens["switch"] = TOKEN_SWITCH;
    m_mTokens["case"] = TOKEN_CASE;
    m_mTokens["break"] = TOKEN_BREAK;
    m_mTokens["continue"] = TOKEN_CONTINUE;
    m_mTokens["with"] = TOKEN_WITH;
    m_mTokens["return"] = TOKEN_RETURN;
    m_mTokens["typeof"] = TOKEN_TYPEOF;
    m_mTokens["pragma"] = TOKEN_PRAGMA;
    m_mTokens["on"] = TOKEN_ON;
    m_mTokens["as"] = TOKEN_AS;
    m_mTokens["signal"] = TOKEN_SIGNAL;
    m_mTokens["var"] = TOKEN_VAR;
    m_mTokens["new"] = TOKEN_NEW;
    m_mTokens["null"] = TOKEN_NULL;
    m_mTokens["undefined"] = TOKEN_UNDEFINED;

    m_eEngine.globalObject().setProperty("wrapper", m_eEngine.newQObject(new QMLTreeContextWrapper(this)));

//    QFile fScript(":/beautify.js");
//    if (fScript.open(QFile::ReadOnly))
//    {
//        m_sBeautifyScript = fScript.readAll();
//        fScript.close();
//    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLTreeContext.
*/
QMLTreeContext::~QMLTreeContext()
{
    foreach (QMLScope* pScope, m_sScopes)
    {
        delete pScope;
    }

    foreach (QMLFile* pFile, m_vFiles)
    {
        delete pFile;
    }

    m_sScopes.clear();
    m_vFiles.clear();

    m_eEngine.globalObject().setProperty("wrapper", m_eEngine.newQObject(nullptr));

#ifdef TRACK_ENTITIES

    if (QMLEntity::createdEntities() != QMLEntity::deletedEntities())
    {
        qWarning() << QString("Created entities : %1").arg(QMLEntity::createdEntities());
        qWarning() << QString("Deleted entities : %1").arg(QMLEntity::deletedEntities());

        foreach (QMLEntity* pEntity, QMLEntity::entities())
        {
            qWarning() << QString("Leaked entity : ") + QString::number((qint64)pEntity) + " < " + pEntity->metaObject()->className() + " > " + " ( " + pEntity->toString() + " )";
        }
    }
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the include imports flag to \a bValue.
*/
void QMLTreeContext::setIncludeImports(bool bValue)
{
    m_bIncludeImports = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the parsed flag for \a sFileName to \a bValue.
*/
void QMLTreeContext::setFileParsed(const QString& sFileName, bool bValue)
{
    foreach (QMLFile* pFile, m_vFiles)
    {
        if (pFile->fileName() == sFileName)
        {
            pFile->setParsed(bValue);
            return;
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the folder.
*/
QString QMLTreeContext::folder() const
{
    return m_sFolder;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the parse was done and successful.
*/
bool QMLTreeContext::success() const
{
    return m_eError == peSuccess;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the last error.
*/
QMLAnalyzerError QMLTreeContext::error() const
{
    return m_tErrorObject;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the last error string.
*/
QString QMLTreeContext::errorString() const
{
    return m_tErrorObject.toString();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the current position in the file. \br\br
    The x component is the column (from 0).\br
    The y component is the line (from 0).
*/
QPoint QMLTreeContext::position() const
{
    if (m_sScopes.count() > 0)
    {
        return QPoint(SCOPE.m_iPreviousColumn, SCOPE.m_iPreviousLine);
    }

    return QPoint(0, 0);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the list of QMLFile objects.
*/
QVector<QMLFile*>& QMLTreeContext::files()
{
    return m_vFiles;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the QMLFile object for \a sFileName. \br\br
    If no QMLFile object refers to \a sFileName, one will be created and returned.
*/
QMLFile* QMLTreeContext::fileByFileName(const QString& sFileName)
{
    foreach (QMLFile* pFile, m_vFiles)
    {
        if (pFile->fileName() == sFileName)
        {
            return pFile;
        }
    }

    QMLFile* pFile = new QMLFile(QPoint(), this, sFileName);

    m_vFiles << pFile;

    return pFile;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if \a sFileName was parsed.
*/
bool QMLTreeContext::fileParsed(const QString& sFileName)
{
    foreach (QMLFile* pFile, m_vFiles)
    {
        if (pFile->fileName() == sFileName && pFile->parsed())
        {
            return true;
        }
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the scope stack.
*/
QStack<QMLTreeContext::QMLScope*>& QMLTreeContext::scopes()
{
    return m_sScopes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds \a sFileName for parsing.
*/
void QMLTreeContext::addFile(const QString& sFileName)
{
    fileByFileName(sFileName);
}

//-------------------------------------------------------------------------------------------------

/*!
    Parses the input file.
*/
QMLTreeContext::EParseError QMLTreeContext::parse()
{
    m_eError = peSuccess;
    m_tErrorObject.clear();

    foreach (QMLFile* pFile, m_vFiles)
    {
        if (pFile->parsed() == false)
        {
            QFileInfo info(pFile->fileName());
            m_sFolder = info.absoluteDir().path();

            // Stack a new scope with the first file
            m_sScopes.push(new QMLScope(pFile));

            // Tell the world parsing started
            emit parsingStarted(pFile->fileName());

            m_eError = parse_Internal();

            // Delete all scopes
            foreach (QMLScope* pScope, m_sScopes)
            {
                delete pScope;
            }

            // Clear scope stack
            m_sScopes.clear();

            pFile->solveSymbols(this);
            pFile->solveReferences(this);
            pFile->solveSymbolUsages(this);
            pFile->solveComments();

            // Mark the file as parsed
            pFile->setParsed(true);

            // Tell the world parsing has ended
            emit parsingFinished(pFile->fileName());
        }
    }

    return m_eError;
}

//-------------------------------------------------------------------------------------------------

/*!
    Starts parsing in a thread.
*/
void QMLTreeContext::threadedParse()
{
    if (isRunning() == false)
    {
        start();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Calls yyparse on the current scope.
*/
QMLTreeContext::EParseError QMLTreeContext::parse_Internal()
{
    // Assume success, will be changed on error
    SCOPE.m_eError = peSuccess;

    // yydebug = 1;

    // Call generated parser
    yyparse(this);

    return SCOPE.m_eError;
}

//-------------------------------------------------------------------------------------------------

/*!
    Parses the imported file \a sFileName.
*/
QMLTreeContext::EParseError QMLTreeContext::parseImportFile(const QString& sFileName)
{
    if (m_bIncludeImports)
    {
        if (fileParsed(sFileName) == false)
        {
            QMLFile* pFile = fileByFileName(sFileName);

            m_sScopes.push(new QMLScope(pFile));

            // Tell the world parsing started
            emit importParsingStarted(SCOPE.m_pFile->fileName());

            parse_Internal();

            delete m_sScopes.pop();
        }
    }

    return peSuccess;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the next parsed token. \br\br
    \a LVAL is a context parameter from parser.
*/
int QMLTreeContext::nextToken(void* LVAL)
{
    return parseNextToken((UParserValue*) LVAL);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the current token value.
*/
QString QMLTreeContext::tokenValue() const
{
    return *(SCOPE.m_pCurrentTokenValue);
}

//-------------------------------------------------------------------------------------------------

/*!
    Shows the error text in \a sText.
*/
void QMLTreeContext::showError(const QString& sText)
{
    m_eError = SCOPE.m_eError = peSyntaxError;
    m_tErrorObject = QMLAnalyzerError(SCOPE.m_pFile->fileName(), QPoint(SCOPE.m_iColumn, SCOPE.m_iLine), sText);
}

//-------------------------------------------------------------------------------------------------

void QMLTreeContext::writeFile(QMLFile* pFile)
{
    QFile file(pFile->fileName());

    if (file.open(QFile::WriteOnly))
    {
        m_sText.clear();
        QTextStream stream(&m_sText);

        QMLFormatter formatter;
        pFile->toQML(stream, formatter);

        // QJSValue output = m_eEngine.evaluate(m_sBeautifyScript);
        // m_sText = output.toString();

        file.write(m_sText.toLatin1());
        file.close();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Implements the thread's \c run method, simply calls \c parse().
*/
void QMLTreeContext::run()
{
    parse();
}

//-------------------------------------------------------------------------------------------------

int QMLTreeContext::parseNextToken(UParserValue* LVAL)
{
    if (SCOPE.m_pCurrentTokenValue != nullptr)
        SCOPE.m_pCurrentTokenValue->clear();

    SCOPE.m_iCommentLevel   = 0;
    SCOPE.m_bParsingFloat   = false;
    SCOPE.m_bParsingHexa    = false;

    int c, d, e;
    QPoint pCommentStart;

    // Skip white spaces and comments
    // Whites are considered to be every ASCII code below 0x21

    while (true)
    {
        GET(c);

        if (c == EOF) return 0;

        if (SCOPE.m_iCommentLevel > 0)
        {
            if (c == '*')
            {
                GET(d);
                if (d == '/')
                {
                    // This is the end of a multi-line comment

                    if (SCOPE.m_pCurrentTokenValue != nullptr)
                    {
                        QMLComment::ECommentType eType = SCOPE.m_bDocComment ? QMLComment::ctMultiLineDoc : QMLComment::ctMultiLine;
                        QMLComment* pComment = new QMLComment(pCommentStart, SCOPE.m_pCurrentTokenValue->trimmed(), eType);
                        m_sScopes.last()->m_pFile->comments() << pComment;

                        SCOPE.m_pCurrentTokenValue->clear();
                    }

                    SCOPE.m_iCommentLevel--;
                }
                else
                {
                    UNGET(d);
                }
            }
            else
            {
                STORE(c);
            }
        }
        else if (c == '/')
        {
            GET(d);
            if (d == '*')
            {
                GET(e);
                if (e == '!')
                {
                    // This is the start of a multi-line doc comment

                    SCOPE.m_iCommentLevel++;
                    SCOPE.m_bDocComment = true;

                    pCommentStart = QPoint(SCOPE.m_iColumn, SCOPE.m_iLine);
                }
                else
                {
                    UNGET(e);

                    // This is the start of a multi-line comment

                    SCOPE.m_iCommentLevel++;
                    SCOPE.m_bDocComment = false;

                    pCommentStart = QPoint(SCOPE.m_iColumn, SCOPE.m_iLine);
                }
            }
            else if (d == '/')
            {
                // This is a single-line comment

                pCommentStart = QPoint(SCOPE.m_iColumn, SCOPE.m_iLine);

                if (SCOPE.m_iCommentLevel == 0)
                {
                    while (c != '\n')
                    {
                        GET(c); STORE(c);
                        if (c == EOF) return 0;
                    }

                    if (SCOPE.m_pCurrentTokenValue != nullptr)
                    {
                        QMLComment::ECommentType eType = SCOPE.m_bLineEmpty ? QMLComment::ctSingleLine : QMLComment::ctSingleLineAtEnd;
                        QMLComment* pComment = new QMLComment(pCommentStart, SCOPE.m_pCurrentTokenValue->trimmed(), eType);
                        m_sScopes.last()->m_pFile->comments() << pComment;

                        SCOPE.m_pCurrentTokenValue->clear();
                    }
                }
            }
            else
            {
                UNGET(d);
                UNGET(c);
                break;
            }
        }
        else
        {
            if (c > ' ') { UNGET(c); break; }
        }
    }

    if (SCOPE.m_pCurrentTokenValue != nullptr)
        SCOPE.m_pCurrentTokenValue->clear();

    // Set context parsing stuff

    SCOPE.m_iPreviousLine   = SCOPE.m_iLine;
    SCOPE.m_iPreviousColumn = SCOPE.m_iColumn;

    GET(c);

    if (c == EOF) return 0;

    // Add, increment, add assign
    if (c == '+')
    {
        STORE(c); GET(d);
        if (d == '+') { STORE(d); return TOKEN_INC; }
        if (d == '=') { STORE(d); return TOKEN_ADD_ASSIGN; }
        UNGET(d); return TOKEN_ADD;
    }

    // Sub, decrement, sub assign
    if (c == '-')
    {
        STORE(c); GET(d);
        if (d == '-') { STORE(d); return TOKEN_DEC; }
        if (d == '=') { STORE(d); return TOKEN_SUB_ASSIGN; }
        UNGET(d); return TOKEN_SUB;
    }

    // Mul, mul assign
    if (c == '*')
    {
        STORE(c); GET(d);
        if (d == '=') { STORE(d); return TOKEN_MUL_ASSIGN; }
        UNGET(d); return TOKEN_MUL;
    }

    // Div, div assign
    if (c == '/')
    {
        STORE(c); GET(d);
        if (d == '=') { STORE(d); return TOKEN_DIV_ASSIGN; }
        UNGET(d); return TOKEN_DIV;
    }

    // Modulo, modulo assign (division remainder)
    if (c == '%')
    {
        STORE(c); GET(d);
        if (d == '=') { STORE(d); return TOKEN_MOD_ASSIGN; }
        UNGET(d); return TOKEN_MOD;
    }

    // And, logical and, and assign
    if (c == '&')
    {
        STORE(c); GET(d);
        if (d == '&') { STORE(d); return TOKEN_LOGICAL_AND; }
        if (d == '=') { STORE(d); return TOKEN_AND_ASSIGN; }
        UNGET(d); return TOKEN_AND;
    }

    // Or, logical or, or assign
    if (c == '|')
    {
        STORE(c); GET(d);
        if (d == '|') { STORE(d); return TOKEN_LOGICAL_OR; }
        if (d == '=') { STORE(d); return TOKEN_OR_ASSIGN; }
        UNGET(d); return TOKEN_OR;
    }

    // Xor, xor assign
    if (c == '^')
    {
        STORE(c); GET(d);
        if (d == '=') { STORE(d); return TOKEN_XOR_ASSIGN; }
        UNGET(d); return TOKEN_XOR;
    }

    // Lower than, lower or equal, shift left, shift left assign
    if (c == '<')
    {
        STORE(c); GET(d);
        if (d == '=') { STORE(d); return TOKEN_LOWER_EQUALS; }
        else
            if (d == '<')
            {
                STORE(d); GET(e);
                if (e == '=') { STORE(e); return TOKEN_SHL_ASSIGN; }
                UNGET(e); return TOKEN_SHL;
            }
            else
                if (d == '>')
                {
                    // ParserWarning(Ctx, "'<>' operator should be '!='. This is not BASIC ! :)");
                    STORE(d); return TOKEN_NOT_EQUALS;
                }
        UNGET(d); return TOKEN_LOWER;
    }

    // Greater than, greater or equal, shift right, shift right assign
    if (c == '>')
    {
        STORE(c); GET(d);
        if (d == '=') { STORE(d); return TOKEN_GREATER_EQUALS; }
        else
            if (d == '>')
            {
                STORE(d); GET(e);
                if (e == '=') { STORE(e); return TOKEN_SHR_ASSIGN; }
                UNGET(e); return TOKEN_SHR;
            }
        UNGET(d); return TOKEN_GREATER;
    }

    // Assign, equals
    if (c == '=')
    {
        STORE(c); GET(d);
        if (d == '=')
        {
            STORE(d); GET(e);
            if (e == '=')
            {
                STORE(e);
                return TOKEN_EQUALS_CHECK;
            }
            UNGET(e); return TOKEN_EQUALS;
        }
        UNGET(d); return TOKEN_ASSIGN;
    }

    // Not, not not, not equals
    if (c == '!')
    {
        STORE(c); GET(d);
        if (d == '!')
        {
            STORE(d);
            return TOKEN_NOT_NOT;
        }
        else if (d == '=')
        {
            STORE(d); GET(e);
            if (e == '=')
            {
                STORE(e);
                return TOKEN_NOT_EQUALS_CHECK;
            }
            UNGET(e); return TOKEN_NOT_EQUALS;
        }
        UNGET(d); return TOKEN_NOT;
    }

    // 2's complement
    if (c == '~') { STORE(c); return TOKEN_COMPLEMENT; }

    // Simple '[' or '[]' dimension operator
    if (c == '[')
    {
        STORE(c);
        while (1)
        {
            GET(d);
            if (d > ' ')
            {
                if (d == ']') { STORE(d); return TOKEN_DIMENSION; }
                else { UNGET(d); break; }
            }
        }
        return c;
    }

    // Literal constants

    if (c == '"')
    {
        while (1)
        {
            GET(c);
            if (c == EOF ) return 0;
            if (c == '"' ) break;
            if (c == '\\') c = parseEscape();
            STORE(c);
        }

        LVAL->String = SCOPE.m_pCurrentTokenValue;
        return TOKEN_LITERAL;
    }

    if (c == '\'')
    {
        while (1)
        {
            GET(c);
            if (c == EOF ) return 0;
            if (c == '\'' ) break;
            if (c == '\\') c = parseEscape();
            STORE(c);
        }

        LVAL->String = SCOPE.m_pCurrentTokenValue;
        return TOKEN_LITERAL;
    }

    // Number starting with a dot

    if (c == '.')
    {
        GET(d);
        if (isdigit(d))
        {
            SCOPE.m_bParsingFloat = true;
            STORE('0'); STORE(c); STORE(d);
            return parseNumber(LVAL);
        }
        STORE(c); UNGET(d);
        return c;
    }

    // Number

    if (isdigit(c))
    {
        if (c == '0')
        {
            GET(d);
            if (d == 'x' || d == 'X')
            {
                STORE(c);
                STORE(d);
                SCOPE.m_bParsingHexa = true;
                return parseNumber(LVAL);
            }
            else UNGET(d);
        }
        STORE(c);
        return parseNumber(LVAL);
    }

    if (isalpha(c) | c == '_' | c == '$')
    {
        do { STORE(c); GET(c); }
        while (c != EOF && (isalnum(c) || c == '_' | c == '$'));

        UNGET(c);

        if (SCOPE.m_pCurrentTokenValue->toLower() == "true")
        {
            LVAL->Boolean = true;
            return TOKEN_BOOLCONSTANT;
        }

        if (SCOPE.m_pCurrentTokenValue->toLower() == "false")
        {
            LVAL->Boolean = false;
            return TOKEN_BOOLCONSTANT;
        }

        // Check if this is a keyword
        if (m_mTokens.contains(*(SCOPE.m_pCurrentTokenValue)))
        {
            return m_mTokens[*(SCOPE.m_pCurrentTokenValue)];
        }

        // This must be an identifier
        LVAL->String = SCOPE.m_pCurrentTokenValue;
        return TOKEN_IDENTIFIER;
    }

    STORE(c);
    return c;
}

//-------------------------------------------------------------------------------------------------

int QMLTreeContext::parseNumber(UParserValue* LVAL)
{
    int c, d;
    bool Done = false;

    while (Done == false)
    {
        GET(c);

        if (c == EOF) Done = true;

        switch (c)
        {
            case '0' : case '1' : case '2' : case '3' : case '4' :
            case '5' : case '6' : case '7' : case '8' : case '9' : STORE(c); break;

            case 'a' : case 'b' : case 'c' : case 'd' : case 'e' : case 'f' :
            case 'A' : case 'B' : case 'C' : case 'D' : case 'E' : case 'F' :
            {
                if (SCOPE.m_bParsingHexa) { STORE(c); } else { UNGET(c); Done = true; }
            }
                break;

            case '.' :
            {
                if (!SCOPE.m_bParsingFloat)
                {
                    SCOPE.m_bParsingFloat = 1; STORE(c);
                }
                else
                {
                    UNGET(c); Done = true;
                }
            }
                break;

            default : UNGET(c); Done = true; break;
        }
    }

    if (SCOPE.m_bParsingFloat)
    {
        LVAL->Real = SCOPE.m_pCurrentTokenValue->toDouble();
        return TOKEN_REALCONSTANT;
    }
    else if (SCOPE.m_bParsingHexa)
    {
        LVAL->Integer = SCOPE.m_pCurrentTokenValue->toInt();
        return TOKEN_INTEGERCONSTANT;
    }

    LVAL->Integer = SCOPE.m_pCurrentTokenValue->toInt();
    return TOKEN_INTEGERCONSTANT;
}

//-------------------------------------------------------------------------------------------------

int QMLTreeContext::parseEscape()
{
    int c;

    GET(c);

    switch (c)
    {
        case '"'  : return '"';
        case '\\' : return '\\'; // Backslash
        case 'a'  : return '\a'; // Alert
        case 'b'  : return '\b'; // Back space
        case 'f'  : return '\f'; // Page feed
        case 'n'  : return '\n'; // Line feed
        case 'r'  : return '\r'; // Carriage return
        case 't'  : return '\t'; // Horizontal tab
        case 'v'  : return '\v'; // Vertical tab
    }

    // ParserWarning(Ctx, String("Invalid escape character : ") + String((char)c));

    return ' ';
}

//-------------------------------------------------------------------------------------------------

int QMLTreeContext::getChar()
{
    if (SCOPE.m_pStream->atEnd())
        return EOF;

    int iChar = SCOPE.m_pStream->read(1)[0].toLatin1();

    switch (iChar)
    {
        case '\n' :
            SCOPE.m_iColumn = 0;
            SCOPE.m_iLine++;
            SCOPE.m_bPreviousLineEmpty = SCOPE.m_bLineEmpty;
            SCOPE.m_bLineEmpty = true;
            break;
        case '\t' :
            SCOPE.m_iColumn += 4;
            SCOPE.m_bPreviousLineEmpty = SCOPE.m_bLineEmpty;
            SCOPE.m_bLineEmpty = false;
            break;
        case '\r' :
            break;
        default:
            SCOPE.m_iColumn++;
            SCOPE.m_bPreviousLineEmpty = SCOPE.m_bLineEmpty;
            SCOPE.m_bLineEmpty = false;
            break;
    }

    return iChar;
}

//-------------------------------------------------------------------------------------------------

int QMLTreeContext::ungetChar(int iChar)
{
    SCOPE.m_pStream->seek(SCOPE.m_pStream->pos() - 1);

    switch (iChar)
    {
        case '\n' :
            SCOPE.m_iColumn = 1024;
            SCOPE.m_iLine--;
            SCOPE.m_bLineEmpty = SCOPE.m_bPreviousLineEmpty;
            break;
        case '\t' :
            SCOPE.m_iColumn -= 4;
            SCOPE.m_bLineEmpty = SCOPE.m_bPreviousLineEmpty;
            break;
        case '\r' :
            break;
        default:
            SCOPE.m_iColumn--;
            SCOPE.m_bLineEmpty = SCOPE.m_bPreviousLineEmpty;
            break;
    }

    return iChar;
}
