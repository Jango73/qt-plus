
#pragma once

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QByteArray>

// Application
#include "rsa/source/RSA.h"
#include "roke/ROKE.h"

//-------------------------------------------------------------------------------------------------

// Defines a secure context
class CSecureContext : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CSecureContext(bool bIsServer);

    //! Destructor
    virtual ~CSecureContext() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Sets the current context data, to be called only by client
    void setContextData(const QByteArray& baContext);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the current context data, to be called only by server
    QByteArray contextData() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Encrypts data using the current key
    QByteArray encrypt(const QByteArray& baData);

    //! Decrypts data using the current key
    QByteArray decrypt(const QByteArray& baData);

protected:

    void echo(QString sText);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    KeyPair*    m_pRSAKeys;
    ROKE        m_tROKE;
    bool        m_bIsServer;
};
