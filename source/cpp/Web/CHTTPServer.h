
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

// Tokens correspondant à un type MIME

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

//! Définit un serveur HTTP
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
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //! Ajoute un élément à la liste des répertoires autorisés en accès par un client
    void addAuthorizedFolder(QString sFolderName);

    //! Met le serveur en pause (toute demande de client sera ignorée)
    void pause();

    //! Reprend l'exécution du serveur
    void resume();

    //! A implémenter par toute classe dérivée pour générer du contenu web
    //! Retourne le contenu de la page web dynamique, à implémenter par toute classe dérivée
    //! Si sCustomResponse est non vide, il sera retourné tel quel au client, sHead et sBody seront ignorés
    //! Sinon, si xmlResponse est non vide, il sera retourné tel quel au client, sHead et sBody seront ignorés
    //! Sinon sHead et sBody seront retournés au client sous forme d'un document HTML
    virtual void getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME);

    //! A implémenter par toute classe dérivée pour réagir après l'envoi de données au client
    virtual void handleSocketBytesWritten(QTcpSocket* pSocket, qint64 iBytes);

    virtual void handleSocketBytesRead(QTcpSocket* pSocket);

    //! A implémenter par toute classe dérivée pour réagir après déconnexion d'un client
    virtual void handleSocketDisconnection(QTcpSocket* pSocket);

    //-------------------------------------------------------------------------------------------------
    // Méthodes statiques
    //-------------------------------------------------------------------------------------------------

    //! Encode une chaîne au format URL (remplace les caractères ASCII par leur %XX correspondant)
    static QString encodeURLParameters(QString sText);

    //! Décode une chaîne encodée au format URL (remplace les %XX par leur caractère ASCII correspondant)
    static QString decodeURLParameters(QString sText);

    //-------------------------------------------------------------------------------------------------
    // Méthodes protégées
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    QStringList getHeaderTokens(QByteArray baData);

    //! Retourne le nombre d'octets attendus dans la requête
    int getExpectedBytes(QStringList lTokens);

    //! Prend en charge la requête du client
    void processRequest(QTcpSocket* pSocket);

    //! Récupère et envoi au client le fichier demandé s'il existe
    bool getResponseFile(const CWebContext& tContext, QTcpSocket* pSocket);

    //! Récupère et envoi au client le contenu dynamique
    //! Renvoie vrai si la connexion doit être keep-alive
    bool getResponseDynamicContent(const CWebContext& tContext, QTcpSocket* pSocket);

    //!
    QString getRequestHeader(const QString& sText);

    //! Retourne le chemin décomposé et les arguments d'une requête
    void getRequestPathAndArgs(const QStringList& lTokens, QStringList& lPath, QMap<QString, QString>& mArguments);

    //! Place dans baContent le contenu d'une requête POST
    void getRequestPostContent(const QString& sText, QByteArray& baContent);

    //! Retourne la valeur correspondant à un token MIME dans un header HTTP
    QString getTokenValue(const QStringList& lTokens, QString sTokenName);

    //!
    QString getSubTokenValue(const QStringList& lTokens, QString sTokenName, QString sSubTokenName);

    //! Retourne le type MIME correspondant à une extension de fichier
    QString getContentTypeByExtension(const QString& sExtension) const;

    //! Log une requête HTTP entrante
    void LogRequest(QString sIP, QString sText);

    //-------------------------------------------------------------------------------------------------
    // Slots protégés
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onNewConnection();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketBytesWritten(qint64 iBytes);

    //-------------------------------------------------------------------------------------------------
    // Classes imbriquées
    //-------------------------------------------------------------------------------------------------

public:

    //! Cette classe utilitaire sert à associer des données utilisateur à une socket
    //! Le pointeur vers cette classe est stocké dans les propriétés de QTcpSocket
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
    // Propriétés
    //-------------------------------------------------------------------------------------------------

protected:

    int                     m_iRequestCount;
    bool					m_bDisabled;				// Indique si le serveur doit ignorer les requêtes entrantes
    QVector<QString>		m_vAuthorizedFolders;		// Indique quels sont les répertoires autorisés pour les GET non-dynamiques
    QMap<QString, QString>	m_vExtensionToContentType;	// Tableau pour conversion de token vers type MIME
};
