
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QByteArray>
#include <QVector>

//-------------------------------------------------------------------------------------------------

// Defines an encryption class - Random Order Key Encryption
class QTPLUSSHARED_EXPORT ROKE : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    ROKE();

    //! Constructor with key
    ROKE(const QString& sKey);

    //! Destructor
    virtual ~ROKE();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Sets the current key
    void setKey(const QString& sKey);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the current key
    QString key() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Encrypts a string using the current key
    QString encryptString(const QString& sText);

    //! Decrypts data using the current key
    QString decryptString(const QString& sText);

    //! Encrypts data using the current key
    QByteArray encrypt(const QByteArray& baData);

    //! Decrypts data using the current key
    QByteArray decrypt(const QByteArray& baData);

    //-------------------------------------------------------------------------------------------------
    // Static control methods
    //-------------------------------------------------------------------------------------------------

    static QString generateKey(QString sMetaData = "");

    //-------------------------------------------------------------------------------------------------
    // Signals
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    void decodeKey();

    //-------------------------------------------------------------------------------------------------
    // Protected static control methods
    //-------------------------------------------------------------------------------------------------

protected:

    // Shuffles a vector of 8 bit integers
    static void shuffle(QVector<quint8>& vValues, int iIterations);

    // Returns a true random 32 bit integer
    static quint32 randomInt32();

    // Reverses the bits of a 32 bit integer
    static quint32 reverseBits32(quint32 n);

    // Reverses the content of a byte array
    static QByteArray reverseArray(const QByteArray& seq);

    // Tests some features
    static void test();

signals:

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString             m_sKey;
    quint32             m_uiKeySize;
    QVector<quint8>     m_vKeyOrders;
    QVector<quint8>     m_vKeyMasks;

    static bool         s_bSeedInit;
};
