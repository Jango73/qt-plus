
#pragma once

#include "../qtplus_global.h"

// Qt
#include <QDebug>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

// Application
#include "CWebContext.h"

//-------------------------------------------------------------------------------------------------

// New line as output in web page
#define HTML_NL                         "\r\n"

// 1er token d'un header HTTP

#define HTTP_HEADER						"HTTP/1.1 "

#define HTTP_GET                        "GET"
#define HTTP_POST                       "POST"

// Liste des retours possibles d'un serveur HTTP

#define HTTP_200_OK						"200 Ok"

#define HTTP_201_CREATED				"201 Created"
#define HTTP_202_ACCEPTED				"202 Accepted"
#define HTTP_203_NA_INFORMATION			"203 Non-Authoritative Information"
#define HTTP_204_NO_CONTENT				"204 No Content"
#define HTTP_205_RESET_CONTENT			"205 Reset Content"
#define HTTP_206_PARTIAL_CONTENT		"206 Partial Content"

#define HTTP_400_BAD_REQUEST			"400 Bad Request"
#define HTTP_401_UNAUTHORIZED			"401 Unauthorized"
#define HTTP_402_PAYMENT_REQUIRED		"402 Payment Required"
#define HTTP_403_FORBIDDEN				"403 Forbidden"
#define HTTP_404_NOT_FOUND				"404 Not Found"
#define HTTP_405_METHOD_NOT_ALLOWED		"405 Method Not Allowed"
#define HTTP_406_NOT_ACCEPTABLE			"406 Not Acceptable"
#define HTTP_407_PROXY_AUTH_REQUIRED	"407 Proxy Authentication Required"
#define HTTP_408_REQUEST_TIMEOUT		"408 Request Timeout"
#define HTTP_409_CONFLICT				"409 Conflict"
#define HTTP_410_GONE					"410 Gone"

#define HTTP_500_INTERNAL_SERVER_ERROR	"500 Internal Server Error"
#define HTTP_501_NOT_IMPLEMENTED		"501 Not Implemented"
#define HTTP_502_BAD_GATEWAY			"502 Bad Gateway"
#define HTTP_503_SERVICE_UNAVAILABLE	"503 Service Unavailable"
#define HTTP_504_GATEWAY_TIMEOUT		"504 Gateway Timeout"
#define HTTP_505_HTTP_VERSION_NS		"505 HTTP Version Not Supported"

// Tokens importants du header HTTP

#define Token_Host						"Host:"
#define Token_Connection				"Connection:"
#define Token_ContentType				"Content-Type:"
#define Token_ContentLength				"Content-Length:"
#define Token_ContentDisposition        "Content-Disposition:"
#define Token_boundary                  "boundary"
#define Token_name                      "name"

// Tokens correspondant � un type MIME

#define MIME_Content_PlainText			"text/plain"
#define MIME_Content_HTML				"text/html"
#define MIME_Content_CSS				"text/css"
#define MIME_Content_URLForm			"application/x-www-form-urlencoded"
#define MIME_Content_Javascript			"application/javascript"
#define MIME_Content_Stream				"application/octet-stream"
#define MIME_Content_PDF				"application/pdf"
#define MIME_Content_XHTML				"application/xhtml+xml"
#define MIME_Content_JSON				"application/json"
#define MIME_Content_XML				"application/xml"
#define MIME_Content_ZIP				"application/zip"
#define MIME_Content_GIF				"image/gif"
#define MIME_Content_JPG				"image/jpg"
#define MIME_Content_PNG				"image/png"
#define MIME_Content_MultiPart          "multipart"
#define MIME_Content_MultiPart_FormData "multipart/form-data"
#define MIME_Content_Custom             "custom"

//-------------------------------------------------------------------------------------------------

//! D�finit un serveur HTTP
class QTPLUSSHARED_EXPORT CHTTPServer : public QTcpServer
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur
    CHTTPServer(quint16 port, QObject* parent = 0);

    //! Destructeur
    virtual ~CHTTPServer();

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    //-------------------------------------------------------------------------------------------------

    //! Ajoute un �l�ment � la liste des r�pertoires autoris�s en acc�s par un client
    void addAuthorizedFolder(QString sFolderName);

    //! Met le serveur en pause (toute demande de client sera ignor�e)
    void pause();

    //! Reprend l'ex�cution du serveur
    void resume();

    //! A impl�menter par toute classe d�riv�e pour g�n�rer du contenu web
    //! Retourne le contenu de la page web dynamique, � impl�menter par toute classe d�riv�e
    //! Si sCustomResponse est non vide, il sera retourn� tel quel au client, sHead et sBody seront ignor�s
    //! Sinon, si xmlResponse est non vide, il sera retourn� tel quel au client, sHead et sBody seront ignor�s
    //! Sinon sHead et sBody seront retourn�s au client sous forme d'un document HTML
    virtual void getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME);

    //! A impl�menter par toute classe d�riv�e pour r�agir apr�s l'envoi de donn�es au client
    virtual void handleSocketBytesWritten(QTcpSocket* pSocket, qint64 iBytes);

    virtual void handleSocketBytesRead(QTcpSocket* pSocket);

    //! A impl�menter par toute classe d�riv�e pour r�agir apr�s d�connexion d'un client
    virtual void handleSocketDisconnection(QTcpSocket* pSocket);

    //-------------------------------------------------------------------------------------------------
    // M�thodes statiques
    //-------------------------------------------------------------------------------------------------

    //! Encode une cha�ne au format URL (remplace les caract�res ASCII par leur %XX correspondant)
    static QString encodeURLParameters(QString sText);

    //! D�code une cha�ne encod�e au format URL (remplace les %XX par leur caract�re ASCII correspondant)
    static QString decodeURLParameters(QString sText);

    //-------------------------------------------------------------------------------------------------
    // M�thodes prot�g�es
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    QStringList getHeaderTokens(QByteArray baData);

    //! Retourne le nombre d'octets attendus dans la requ�te
    int getExpectedBytes(QStringList lTokens);

    //! Prend en charge la requ�te du client
    void processRequest(QTcpSocket* pSocket);

    //! R�cup�re et envoi au client le fichier demand� s'il existe
    bool getResponseFile(const CWebContext& tContext, QTcpSocket* pSocket);

    //! R�cup�re et envoi au client le contenu dynamique
    //! Renvoie vrai si la connexion doit �tre keep-alive
    bool getResponseDynamicContent(const CWebContext& tContext, QTcpSocket* pSocket);

    //!
    QString getRequestHeader(const QString& sText);

    //! Retourne le chemin d�compos� et les arguments d'une requ�te
    void getRequestPathAndArgs(const QStringList& lTokens, QStringList& lPath, QMap<QString, QString>& mArguments);

    //! Place dans baContent le contenu d'une requ�te POST
    void getRequestPostContent(const QString& sText, QByteArray& baContent);

    //! Retourne la valeur correspondant � un token MIME dans un header HTTP
    QString getTokenValue(const QStringList& lTokens, QString sTokenName);

    //!
    QString getSubTokenValue(const QStringList& lTokens, QString sTokenName, QString sSubTokenName);

    //! Retourne le type MIME correspondant � une extension de fichier
    QString getContentTypeByExtension(const QString& sExtension) const;

    //! Log une requ�te HTTP entrante
    void LogRequest(QString sIP, QString sText);

    //-------------------------------------------------------------------------------------------------
    // Slots prot�g�s
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onNewConnection();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketBytesWritten(qint64 iBytes);

    //-------------------------------------------------------------------------------------------------
    // Classes imbriqu�es
    //-------------------------------------------------------------------------------------------------

public:

    //! Cette classe utilitaire sert � associer des donn�es utilisateur � une socket
    //! Le pointeur vers cette classe est stock� dans les propri�t�s de QTcpSocket
    class CClientData
    {
    public:

#define PROP_DATA "Data"

        //!
        CClientData(QTcpSocket* pSocket)
            : m_bHeaderRead(false)
            , m_iExpectedBytes(0)
        {
            pSocket->setProperty(PROP_DATA, (qulonglong) this);
        }

        //!
        static CClientData* getFromSocket(QTcpSocket* pSocket)
        {
            return (CClientData*) pSocket->property(PROP_DATA).toULongLong();
        }

        //!
        static void deleteFromSocket(QTcpSocket* pSocket)
        {
            CClientData* pData = getFromSocket(pSocket);

            if (pData != NULL)
            {
                delete pData;
            }
        }

        bool					m_bHeaderRead;
        QString                 m_sMultipartBoundary;
        int						m_iExpectedBytes;
        QByteArray				m_baBuffer;
        QMap<QString, QVariant>	m_vUserData;
    };

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

protected:

    int                     m_iRequestCount;
    bool					m_bDisabled;				// Indique si le serveur doit ignorer les requ�tes entrantes
    QVector<QString>		m_vAuthorizedFolders;		// Indique quels sont les r�pertoires autoris�s pour les GET non-dynamiques
    QMap<QString, QString>	m_vExtensionToContentType;	// Tableau pour conversion de token vers type MIME
};
