
// Application
#include "QMLFile.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLFile
    \inmodule qt-plus
    \brief A QML file.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLFile with \a sFileName. \br\br
    \a pContext if the parser.
*/
QMLFile::QMLFile(QMLTreeContext* pContext, const QString& sFileName)
    : m_pContext(pContext)
    , m_sFileName(sFileName)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLFile as copy of \a target. Does nothing, exists only to make containers happy.
*/
QMLFile::QMLFile(const QMLFile& target)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLFile.
*/
QMLFile::~QMLFile()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the file's name.
*/
QString QMLFile::fileName() const
{
    return m_sFileName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation.
*/
void QMLFile::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLFile]"));
    dumpIndented(stream, iIdent, QString("File name : %1").arg(m_sFileName));

    QMLComplexItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode representation of this item. \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode QMLFile::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLComplexItem::toXMLNode(pContext, pParent);

    xNode.attributes()["FileName"] = m_sFileName;

    return xNode;
}
