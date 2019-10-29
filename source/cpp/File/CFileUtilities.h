
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFile>

// Application
#include "../CSingleton.h"

//-------------------------------------------------------------------------------------------------

//! File utilities
class QTPLUSSHARED_EXPORT CFileUtilities : public CSingleton<CFileUtilities>
{
    friend class CSingleton<CFileUtilities>;

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

protected:

    //! Default constructor
    CFileUtilities();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

public:

    QStringList concernedFiles(const QString& sBaseDirecory, const QStringList& lNames);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    void concernedFilesRecurse(QStringList& lResut, const QString& sCurrentDirectory, const QString& sWildCard);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sFileName;            // The base file name
    int         m_iMaximumBackups;      // The maximum number of copies
};
