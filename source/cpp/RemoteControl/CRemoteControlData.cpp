
// Qt
#include <QDateTime>

// Application
#include "CRemoteControlData.h"

//-------------------------------------------------------------------------------------------------

quint32 CFileTransferData::m_ulNextTransferID = 1;

CFileTransferData::CFileTransferData(QTcpSocket* pSocket, const QString& sSourceName, const QString& sTargetName, quint32 ulFileSize, bool bOut)
    : m_pSocket(pSocket)
    , m_pFile(nullptr)
    , m_tLastIncomingMessageTime(QDateTime::currentDateTime())
    , m_sSourceName(sSourceName)
    , m_sTargetName(sTargetName)
    , m_ulOffsetInFile(0)
    , m_ulFileSize(ulFileSize)
    , m_bOut(bOut)
    , m_bDone(false)
    , m_bCompCRC(false)
    , m_bSameCRC(false)
    , m_bFileInfoSent(false)
    , m_bGotFileInfo(false)
    , m_bEchoFileCRC(false)
{
    m_ulTransferID = getNewTransferID();
}

CFileTransferData::CFileTransferData(QTcpSocket* pSocket, const QString& sSourceName, const QString& sTargetName, quint32 ulFileSize, quint32 ulTransferID, bool bOut)
    : m_pSocket(pSocket)
    , m_pFile(nullptr)
    , m_tLastIncomingMessageTime(QDateTime::currentDateTime())
    , m_sSourceName(sSourceName)
    , m_sTargetName(sTargetName)
    , m_ulOffsetInFile(0)
    , m_ulFileSize(ulFileSize)
    , m_bOut(bOut)
    , m_bDone(false)
    , m_bCompCRC(false)
    , m_bSameCRC(false)
    , m_bFileInfoSent(false)
    , m_bGotFileInfo(false)
    , m_bEchoFileCRC(false)
{
    m_ulTransferID = ulTransferID;
    m_ulNextTransferID = ulTransferID + 1;
}

CFileTransferData::~CFileTransferData()
{
    if (m_pFile != nullptr)
    {
        if (m_pFile->isOpen()) m_pFile->close();

        delete m_pFile;
    }
}

// Generates a file transfer ID using current time and an auto-incremented integer
quint32 CFileTransferData::getNewTransferID()
{
    m_ulNextTransferID++;

    return QDateTime::currentDateTime().time().second() + QDateTime::currentDateTime().time().msec() + m_ulNextTransferID;
}
