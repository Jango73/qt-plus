
// Qt
#include <QCryptographicHash>

// Application
#include "CRemoteControlUser.h"

//-------------------------------------------------------------------------------------------------

CRemoteControlUser::CRemoteControlUser()
    : m_iPrivileges(EP_None)
{
}

//-------------------------------------------------------------------------------------------------

CRemoteControlUser::CRemoteControlUser(const CRemoteControlUser& target)
{
    *this = target;
}

//-------------------------------------------------------------------------------------------------

CRemoteControlUser::CRemoteControlUser(QString sName, QString sPassword, int iPrivileges)
    : m_sLogin(sName)
    , m_sPassword(sPassword)
    , m_iPrivileges(iPrivileges)
{
    m_sEncodedPassword = encoded(sPassword);
}

//-------------------------------------------------------------------------------------------------

CRemoteControlUser::~CRemoteControlUser()
{
}

//-------------------------------------------------------------------------------------------------

CRemoteControlUser& CRemoteControlUser::operator = (const CRemoteControlUser& target)
{
    m_sLogin            = target.m_sLogin;
    m_sPassword         = target.m_sPassword;
    m_sEncodedPassword  = target.m_sEncodedPassword;
    m_iPrivileges       = target.m_iPrivileges;

    return *this;
}

//-------------------------------------------------------------------------------------------------

QString CRemoteControlUser::encoded(QString sText)
{
    return QString(QCryptographicHash::hash(sText.toLatin1(), QCryptographicHash::Md5).toBase64());
}
