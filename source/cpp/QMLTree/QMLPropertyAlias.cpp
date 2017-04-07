
// Application
#include "QMLPropertyAlias.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyAlias::QMLPropertyAlias(const QPoint& pPosition, QMLEntity* pName, QMLEntity* pContent)
    : QMLPropertyAssignment(pPosition, pName, pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyAlias::~QMLPropertyAlias()
{
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyAlias::toQML(QTextStream& stream, const QMLEntity* pParent, int iIdent) const
{
    Q_UNUSED(pParent);

    if (m_pName != nullptr && m_pContent != nullptr)
    {
        if (m_eModifiers == mReadonly)
        {
            stream << "readonly ";
        }
        else if (m_eModifiers == mDefault)
        {
            stream << "default ";
        }

        stream << "property alias ";

        m_pName->toQML(stream, this, iIdent + 1);

        stream << ": ";

        m_pContent->toQML(stream, this, iIdent + 1);

        stream << "\n";
    }
}
