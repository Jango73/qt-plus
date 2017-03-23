
// Application
#include "QMLOnExpression.h"

//-------------------------------------------------------------------------------------------------

QMLOnExpression::QMLOnExpression(const QPoint& pPosition, QMLEntity* pTarget, QMLEntity* pName, QMLComplexEntity* pContents)
    : QMLComplexEntity(pPosition, pName)
    , m_pTarget(pTarget)
{
    if (pContents != nullptr)
    {
        /*
        foreach (QMLEntity* pItem, pContents->contents())
        {
            m_vContents << pItem;
        }

        pContents->contents().clear();
        */

        m_vContents = pContents->grabContents();

        delete pContents;
    }

    if (m_pTarget != nullptr) m_pTarget->setParent(this);
}

//-------------------------------------------------------------------------------------------------

QMLOnExpression::~QMLOnExpression()
{
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLOnExpression::members()
{
    QMap<QString, QMLEntity*> vReturnValue = QMLComplexEntity::members();

    vReturnValue["target"] = m_pTarget;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLOnExpression::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpIndentedNoNewLine(stream, iIdent, "");

    if (m_pName != nullptr)
    {
        m_pName->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, " on ");

    if (m_pTarget != nullptr)
    {
        m_pTarget->toQML(stream, pContext, this, iIdent + 1);
    }

    if (pParent != nullptr)
    {
        dumpOpenBlock(stream, iIdent);
    }

    foreach (QMLEntity* pItem, m_vContents)
    {
        if (pItem != nullptr)
        {
            pItem->toQML(stream, pContext, this, pParent != NULL ? iIdent + 1 : iIdent);
        }
    }

    if (pParent != nullptr)
    {
        dumpCloseBlock(stream, iIdent);
    }

    // QMLComplexItem::toQML(stream, pContext, pParent, iIdent);
}
