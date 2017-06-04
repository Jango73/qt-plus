
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
*/
void CRollingFiles::backup()
{
    bool bCopied = false;

    // Recherche d'un nom de fichier libre pour copie
    for (int iIndex = 0; iIndex < m_iMaximumBackups; iIndex++)
    {
        QString sCopyFileName(m_sFileName + "." + QString::number(iIndex));

        QFile tCopyFile(sCopyFileName);

        if (tCopyFile.exists() == false)
        {
            bCopied = true;

            QFile tOriginalFile(m_sFileName);
            tOriginalFile.copy(sCopyFileName);

            break;
        }
    }

    if (bCopied == false)
    {
        for (int iIndex = 0; iIndex < m_iMaximumBackups - 1; iIndex++)
        {
            QString sSourceFileName(m_sFileName + "." + QString::number(iIndex + 1));
            QString sTargetFileName(m_sFileName + "." + QString::number(iIndex + 0));

            QFile tTargetFile(sTargetFileName);
            tTargetFile.remove();

            QFile tSourceFile(sSourceFileName);
            tSourceFile.copy(sTargetFileName);
        }

        QString sCopyFileName(m_sFileName + "." + QString::number(m_iMaximumBackups - 1));

        QFile tCopyFile(sCopyFileName);

        if (tCopyFile.exists())
        {
            tCopyFile.remove();
        }

        QFile tOriginalFile(m_sFileName);
        tOriginalFile.copy(sCopyFileName);
    }
}
