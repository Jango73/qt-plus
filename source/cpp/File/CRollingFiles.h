
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include <QMap>
#include <QVector>
#include <QDomDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//-------------------------------------------------------------------------------------------------

//! Defines a rolling file system
class QTPLUSSHARED_EXPORT CRollingFiles
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CRollingFiles();

    //! Constructor with file name
    CRollingFiles(const QString& sFileName, int iMaximumBackups = 10);

    //! Destructor
    virtual ~CRollingFiles();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Defines the file name
    void setFileName(const QString& sFileName);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the file name
    QString fileName() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    void backup();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sFileName;            // The base file name
    int         m_iMaximumBackups;      // The maximum number of copies
};
