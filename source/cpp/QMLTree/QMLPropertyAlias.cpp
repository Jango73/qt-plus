
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

void QMLPropertyAlias::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (m_pName != nullptr && m_pContent != nullptr)
    {
        formatter.processFragment(stream, QMLFormatter::qffBeforePropertyName);

        if (m_eModifiers == mReadonly)
        {
            stream << "readonly ";
        }
        else if (m_eModifiers == mDefault)
        {
            stream << "default ";
        }

        stream << "property alias ";

        m_pName->toQML(stream, formatter, this);

        formatter.processFragment(stream, QMLFormatter::qffAfterPropertyName);

        if (m_pContent != nullptr)
        {
            stream << ": ";

            formatter.processFragment(stream, QMLFormatter::qffBeforePropertyContent);
            m_pContent->toQML(stream, formatter, this);
            formatter.processFragment(stream, QMLFormatter::qffAfterPropertyContent);
        }
    }
}
