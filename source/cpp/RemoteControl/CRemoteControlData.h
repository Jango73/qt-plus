
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include <QVector>
#include <QTime>
#include <QDateTime>
#include <QFile>
#include <QTcpSocket>
#include <QProcess>
#include <QNetworkInterface>

#define REMOTECONTROL_VERSION	"2.3"
#define REMOTECONTROL_SIGNATURE	"rmc22"
#define REMOTECONTROL_REVISION		1

#define FILE_OPEN_TRIES		20
#define MAX_DATA_SIZE		0x8000

#pragma pack(push)
#pragma pack(1)

// Message types

enum ERMCMessage
{
    RMC_NONE				= 0,
    RMC_EXECUTE				= 1,
    RMC_EXECUTE_FINISHED	= 2,
    RMC_RESPONSE			= 3,
    RMC_GET_FILE			= 4,
    RMC_FILE_CHUNK			= 5,
    RMC_FILE_RECEIVED		= 6,
    RMC_FILE_INFO			= 7,
    RMC_REQUEST				= 8,
    RMC_PROGRAM_WORKING_DIR	= 9,
    RMC_CHANGE_DIRECTORY	= 10,
    RMC_FILE_TRANSFER		= 11,
    RMC_LOGIN				= 12,
    RMC_MERGE_FILE			= 13,
    RMC_SECURE_CONTEXT		= 14,
    RMC_LAST				= 100
};

enum ERMCRequest
{
    RMC_REQUEST_NONE		= 0,
    RMC_REQUEST_FILEINFO	= 1,
    RMC_REQUEST_PWD			= 2,
    RMC_REQUEST_GETRIGHTS	= 3,
    RMC_REQUEST_SHUTDOWN	= 666
};

enum ERMCEncyption
{
    RMC_ENCRYPTION_UNDEF    = 0,
    RMC_ENCRYPTION_NONE		= 1,
    RMC_ENCRYPTION_ROKE		= 2
};

#define RMC_MERGETYPE_INI		1

// Messages structures

typedef struct tag_RMC_Header
{
    quint32		ulType;
    quint32		ulLength;
    quint32		ulEncryption;
    quint32		ulChecksum;
} RMC_Header, *pRMC_Header;

typedef struct tag_RMC_Date
{
    unsigned char	ucYear;
    unsigned char	ucMonth;
    unsigned char	ucDay;
    unsigned char	ucHour;
    unsigned char	ucMinute;
    unsigned char	ucSecond;
} RMC_Date, *pRMC_Date;

typedef struct tag_RMC_Execute
{
    RMC_Header	tHeader;
    char		cText [512];
    char		bDetached;
} RMC_Execute, *pRMC_Execute;

typedef struct tag_RMC_Login
{
    RMC_Header	tHeader;
    char		cLogin [512];
    char		cPassword [512];
} RMC_Login, *pRMC_Login;

typedef struct tag_RMC_Secure_Context
{
    RMC_Header	tHeader;
    char		cData [MAX_DATA_SIZE];
} RMC_Secure_Context, *pRMC_Secure_Context;

typedef struct tag_RMC_ChangeDirectory
{
    RMC_Header	tHeader;
    char		cTargetDirectory [1024];
} RMC_ChangeDirectory, *pRMC_ChangeDirectory;

typedef struct tag_RMC_ExecuteFinished
{
    RMC_Header	tHeader;
    qint32		iProcess;
    qint32		iErrorCode;
} RMC_ExecuteFinished, *pRMC_ExecuteFinished;

typedef struct tag_RMC_Response
{
    RMC_Header	tHeader;
    quint32		ulDataSize;
    char		cData [MAX_DATA_SIZE];
} RMC_Response, *pRMC_Response;

typedef struct tag_RMC_GetFile
{
    RMC_Header	tHeader;
    char		cSourceName [256];
    char		cTargetName [256];
    RMC_Date	tSourceDate;
    RMC_Date	tTargetDate;
} RMC_GetFile, *pRMC_GetFile;

typedef struct tag_RMC_MergeFile
{
    RMC_Header	tHeader;
    qint32		iType;
    char		cSourceName [256];
    char		cTargetName [256];
} RMC_MergeFile, *pRMC_MergeFile;

typedef struct tag_RMC_FileInfo
{
    RMC_Header	tHeader;
    char		cName [256];
    quint32		ulCRC;
    RMC_Date	tCreatedDate;
    RMC_Date	tModifiedDate;
} RMC_FileInfo, *pRMC_FileInfo;

typedef struct tag_RMC_ProgramWorkingDir
{
    RMC_Header	tHeader;
    char		cPath [1024];
} RMC_ProgramWorkingDir, *pRMC_ProgramWorkingDir;

typedef struct tag_RMC_FileTransfer
{
    RMC_Header	tHeader;
    quint32		ulTransferID;
    quint32		ulFileSize;
    char		cSourceName [256];
    char		cTargetName [256];
} RMC_FileTransfer, *pRMC_FileTransfer;

typedef struct tag_RMC_FileChunk
{
    RMC_Header	tHeader;
    quint32		ulTransferID;
    quint32		ulOffsetInFile;
    quint32		ulDataSize;
    quint32		ulFileSize;
    quint32		ulCRC;
    char		cSourceName [256];
    char		cTargetName [256];
    RMC_Date	tSourceDate;
    RMC_Date	tTargetDate;
    char		cIsLastChunk;
    char		cData [MAX_DATA_SIZE];
} RMC_FileChunk, *pRMC_FileChunk;

typedef struct tag_RMC_FileReceived
{
    RMC_Header	tHeader;
    quint32		ulTransferID;
    qint32		iError;
    quint32		ulCRC;
} RMC_FileReceived, *pRMC_FileReceived;

typedef struct tag_RMC_FileSetFinished
{
    RMC_Header	tHeader;
    qint32		iDummy;
} RMC_FileSetFinished, *pRMC_FileSetFinished;

typedef struct tag_RMC_Request
{
    RMC_Header	tHeader;
    qint32		lRequest;
    char		ucParam [256];
} RMC_Request, *pRMC_Request;

#pragma pack(pop)

// Data for file transfers
class QTPLUSSHARED_EXPORT CFileTransferData
{

public:

    //! Constructors
    CFileTransferData(QTcpSocket* pSocket, const QString& sSourceName, const QString& sTargetName, quint32 ulFileSize, bool bOut);
    CFileTransferData(QTcpSocket* pSocket, const QString& sSourceName, const QString& sTargetName, quint32 ulFileSize, quint32 ulTransferID, bool bOut);

    //! Destructor
    virtual ~CFileTransferData();

    // Getters
    QTcpSocket* getSocket() { return m_pSocket; }
    QFile* getFile() { return m_pFile; }
    const QString& getSourceName() { return m_sSourceName; }
    const QString& getTargetName() { return m_sTargetName; }
    quint32 getTransferID() { return m_ulTransferID; }
    quint32 getOffsetInFile() { return m_ulOffsetInFile; }
    quint32 getFileSize() { return m_ulFileSize; }
    quint32 getSourceFileCRC() { return m_ulSourceFileCRC; }
    quint32 getTargetFileCRC() { return m_ulTargetFileCRC; }
    bool getOut() { return m_bOut; }
    bool getDone() { return m_bDone; }
    bool getCompCRC() { return m_bCompCRC; }
    bool getSameCRC() { return m_bSameCRC; }
    bool getFileInfoSent() { return m_bFileInfoSent; }
    bool getGotFileInfo() { return m_bGotFileInfo; }
    bool getEchoFileCRC() { return m_bEchoFileCRC; }
    QDateTime getLastIncomingMessageTime() { return m_tLastIncomingMessageTime; }

    // Setters
    void setFile(QFile* value) { m_pFile = value; }
    void setOffsetInFile(quint32 value) { m_ulOffsetInFile = value; }
    void setSourceFileCRC(quint32 value) { m_ulSourceFileCRC = value; }
    void setTargetFileCRC(quint32 value) { m_ulTargetFileCRC = value; }
    void setDone (bool value) { m_bDone = value; }
    void setCompCRC (bool value) { m_bCompCRC = value; }
    void setSameCRC (bool value) { m_bSameCRC = value; }
    void setFileInfoSent (bool value) { m_bFileInfoSent = value; }
    void setGotFileInfo (bool value) { m_bGotFileInfo = value; }
    void setEchoFileCRC (bool value) { m_bEchoFileCRC = value; }
    void setLastIncomingMessageTime (QDateTime value) { m_tLastIncomingMessageTime = value; }

protected:

    static quint32 getNewTransferID();
    static quint32 m_ulNextTransferID;

    QTcpSocket*	m_pSocket;
    QFile*		m_pFile;
    QDateTime	m_tLastIncomingMessageTime;
    QString		m_sSourceName;
    QString		m_sTargetName;
    quint32		m_ulTransferID;
    quint32		m_ulOffsetInFile;
    quint32		m_ulFileSize;
    quint32		m_ulSourceFileCRC;
    quint32		m_ulTargetFileCRC;
    bool		m_bOut;
    bool		m_bDone;
    bool		m_bCompCRC;
    bool		m_bSameCRC;
    bool		m_bFileInfoSent;
    bool		m_bGotFileInfo;
    bool		m_bEchoFileCRC;
};
