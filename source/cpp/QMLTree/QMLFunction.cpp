
// Qt
#include <QDebug>

// Application
#include "QMLFunction.h"
#include "QMLVariableDeclaration.h"
#include "QMLBinaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLFunction::QMLFunction(const QPoint& pPosition, QMLEntity* pName, QMLEntity* pParameters, QMLEntity* pContent)
    : QMLEntity(pPosition)
    , m_pName(pName)
    , m_pParameters(pParameters)
    , m_pContent(pContent)
    , m_bIsSignal(false)
{
}

//-------------------------------------------------------------------------------------------------

QMLFunction::~QMLFunction()
{
    if (m_pName != nullptr)
        delete m_pName;
    if (m_pParameters != nullptr)
        delete m_pParameters;
    if (m_pContent != nullptr)
        delete m_pContent;
}

//-------------------------------------------------------------------------------------------------

void QMLFunction::setIsSignal(bool bValue)
{
    m_bIsSignal = bValue;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLFunction::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLFunction::parameters() const
{
    return m_pParameters;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLFunction::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

bool QMLFunction::isSignal() const
{
    return m_bIsSignal;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLFunction::unusedParameters()
{
    QMap<QString, QMLEntity*> mReturnValue;

    foreach (QString sKey, m_mParameterList.keys())
    {
        if (m_mParameterList[sKey]->usageCount() == 0)
        {
            mReturnValue[sKey] = m_mParameterList[sKey];
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLFunction::unusedVariables()
{
    QMap<QString, QMLEntity*> mReturnValue;

    foreach (QString sKey, m_mVariableList.keys())
    {
        if (m_mVariableList[sKey]->usageCount() == 0)
        {
            mReturnValue[sKey] = m_mVariableList[sKey];
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLFunction::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["name"] = m_pName;
    vReturnValue["parameters"] = m_pParameters;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds all symbols in the entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLFunction::solveSymbols(QMLTreeContext* pContext)
{
    QMLEntity::solveSymbols(pContext);

    if (m_pContent != nullptr)
        m_mVariableList = m_pContent->getDeclaredSymbols();

    if (m_bIsSignal == false)
    {
        if (m_pParameters != nullptr)
            m_mParameterList = m_pParameters->getDeclaredSymbols();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLFunction::solveReferences(QMLTreeContext* pContext)
{
    if (m_pContent != nullptr)
        m_pContent->solveReferences(pContext);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution.
*/
QMLEntity* QMLFunction::findSymbolDeclaration(const QString& sName)
{
    /*
    QMLIdentifier* pFoundEntity = dynamic_cast<QMLIdentifier*>(m_pName);

    if (pFoundEntity != nullptr)
    {
        if (pFoundEntity->value().toString() == sName)
        {
            return pFoundEntity;
        }
    }

    if (m_mParameterList.contains(sName))
    {
        return m_mParameterList[sName];
    }

    if (m_mVariableList.contains(sName))
    {
        return m_mVariableList[sName];
    }

    return QMLEntity::findSymbolDeclaration(sName);
    */

    QStringList lQualifiedName = QMLEntity::qualifiedNameAsList(sName);

    if (lQualifiedName.count() > 0)
    {
        if (m_mParameterList.contains(lQualifiedName[0]))
        {
            return m_mParameterList[lQualifiedName[0]];
        }

        if (m_mVariableList.contains(lQualifiedName[0]))
        {
            return m_mVariableList[lQualifiedName[0]];
        }

        return QMLEntity::findSymbolDeclaration(QMLEntity::listAsQualifiedName(lQualifiedName));
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pParent is the caller of this method.
*/
void QMLFunction::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (m_bIsSignal)
        formatter.processFragment(stream, QMLFormatter::qffBeforeSignal);
    else
        formatter.processFragment(stream, QMLFormatter::qffBeforeFunction);

    if (m_bIsSignal)
    {
        stream << "signal ";
    }
    else
    {
        stream << "function ";
    }

    if (m_pName != nullptr)
    {
        m_pName->toQML(stream, formatter, this);
    }

    stream << "(";

    if (m_pParameters != nullptr)
    {
        m_pParameters->toQML(stream, formatter, this);
    }

    stream << ")";

    if (m_bIsSignal)
        formatter.processFragment(stream, QMLFormatter::qffAfterSignal);
    else
        formatter.processFragment(stream, QMLFormatter::qffAfterFunction);

    if (m_bIsSignal == false)
    {
        if (m_pContent != nullptr)
        {
            m_pContent->toQML(stream, formatter, this);
        }
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLFunction::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
    CXMLNode xName("Name");
    CXMLNode xParameterList("ParameterList");
    CXMLNode xVariableList("VariableList");
    CXMLNode xParameters("Parameters");
    CXMLNode xContent("Content");

    if (m_pName != nullptr)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pParameters != nullptr)
        xParameters.nodes() << m_pParameters->toXMLNode(pContext, this);

    if (m_pContent != nullptr)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    foreach (QString sKey, m_mParameterList.keys())
    {
        CXMLNode xParameter("Parameter");
        xParameter.attributes()["Name"] = sKey;
        xParameterList << xParameter;
    }

    foreach (QString sKey, m_mVariableList.keys())
    {
        CXMLNode xVariable("Variable");
        xVariable.attributes()["Name"] = sKey;
        xVariableList << xVariable;
    }

    xNode.nodes() << xName;
    xNode.nodes() << xParameterList;
    xNode.nodes() << xVariableList;
    xNode.nodes() << xParameters;
    xNode.nodes() << xContent;

    return xNode;
}
