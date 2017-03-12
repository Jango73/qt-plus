
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QIODevice>

//-------------------------------------------------------------------------------------------------

#define STREAM_PARAM_BAUD           "BaudRate"
#define STREAM_PARAM_DATABITS       "DataBits"
#define STREAM_PARAM_DATA_5         "Data5"
#define STREAM_PARAM_DATA_6         "Data6"
#define STREAM_PARAM_DATA_7         "Data7"
#define STREAM_PARAM_DATA_8         "Data8"
#define STREAM_PARAM_PARITY         "Parity"
#define STREAM_PARAM_PARITY_NONE    "None"
#define STREAM_PARAM_PARITY_EVEN    "Even"
#define STREAM_PARAM_PARITY_ODD     "Odd"
#define STREAM_PARAM_PARITY_SPACE   "Space"
#define STREAM_PARAM_STOP           "StopBits"
#define STREAM_PARAM_STOP_1         "1"
#define STREAM_PARAM_STOP_1_5       "1.5"
#define STREAM_PARAM_STOP_2         "2"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CConnectedStream : public QIODevice
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur par d�faut
    CConnectedStream();

    //! Constructeur avec nom
    CConnectedStream(const QString& name);

    //! Destructeur
    virtual ~CConnectedStream();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setMinBytesForReadyRead(int iMinBytes);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    // Retourne le nom utilis� � la cr�ation de l'objet
    virtual QString name() const;

    //-------------------------------------------------------------------------------------------------
    // Signaux
    //-------------------------------------------------------------------------------------------------

signals:

    //!
    void connected();

    //!
    void disconnected();

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

protected:

    QString		m_sName;
    int         m_iMinBytesForReadyRead;
};