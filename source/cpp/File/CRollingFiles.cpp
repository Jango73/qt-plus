
// Qt
#include <QFile>
#include <QStringList>

// Library
#include "CRollingFiles.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CRollingFiles
    \inmodule qt-plus
    \brief A rolling file system.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CRollingFiles.
*/
CRollingFiles::CRollingFiles()
    : m_iMaximumBackups(10)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CRollingFiles using \a sFileName as a tag and \a iMaximumBackups as maximum number of backups.
*/
CRollingFiles::CRollingFiles(const QString& sFileName, int iMaximumBackups)
    : m_sFileName(sFileName)
    , m_iMaximumBackups(iMaximumBackups)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CRollingFiles.
*/
CRollingFiles::~CRollingFiles()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the file name of this node to \a sFileName.
*/
void CRollingFiles::setFileName(const QString& sFileName)
{
    m_sFileName = sFileName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the file name of this node.
*/
QString CRollingFiles::fileName() const
{
    return m_sFileName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Backs up the file.
    Returns true on success, false if inputs are invalid or any step failed.
*/
bool CRollingFiles::backup()
{
    // Guard against degenerate inputs (previously produced "<name>.-1" or stray ".0" files)
    if (m_sFileName.isEmpty() || m_iMaximumBackups <= 0)
    {
        return false;
    }

    // Search for a free file name for copy
    for (int iIndex = 0; iIndex < m_iMaximumBackups; iIndex++)
    {
        QString sCopyFileName(m_sFileName + "." + QString::number(iIndex));

        if (QFile::exists(sCopyFileName) == false)
        {
            return QFile::copy(m_sFileName, sCopyFileName);
        }
    }

    // All slots full: shift backups down with renames (no data is deleted before
    // its replacement is safely in place), then copy the live file on top.
    if (QFile::exists(m_sFileName + "." + QString::number(0)))
    {
        if (QFile::remove(m_sFileName + "." + QString::number(0)) == false)
        {
            return false;
        }
    }

    for (int iIndex = 1; iIndex < m_iMaximumBackups; iIndex++)
    {
        QString sSourceFileName(m_sFileName + "." + QString::number(iIndex));
        QString sTargetFileName(m_sFileName + "." + QString::number(iIndex - 1));

        if (QFile::exists(sSourceFileName))
        {
            if (QFile::rename(sSourceFileName, sTargetFileName) == false)
            {
                return false;
            }
        }
    }

    QString sCopyFileName(m_sFileName + "." + QString::number(m_iMaximumBackups - 1));

    if (QFile::exists(sCopyFileName))
    {
        if (QFile::remove(sCopyFileName) == false)
        {
            return false;
        }
    }

    return QFile::copy(m_sFileName, sCopyFileName);
}
