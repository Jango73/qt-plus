
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
    \a pPosition is the position of the token in the file \br
    \a pContext if the parser.
*/
QMLFile::QMLFile(const QPoint& pPosition, QMLTreeContext* pContext, const QString& sFileName)
    : QMLComplexItem(pPosition)
    , m_pContext(pContext)
    , m_sFileName(sFileName)
    , m_bParsed(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLFile as copy of \a target. Does nothing, exists only to make containers happy.
*/
QMLFile::QMLFile(const QMLFile& target)
    : QMLComplexItem(target.position())
    , m_bParsed(false)
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
    Sets the parsed flag to \a bValue.
*/
void QMLFile::setParsed(bool bValue)
{
    m_bParsed = bValue;
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
    Returns the parsed flag.
*/
bool QMLFile::parsed() const
{
    return m_bParsed;
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
    xNode.attributes()["Parsed"] = m_bParsed ? "true" : "false";

    return xNode;
}
