
// Qt
#include <QDebug>

// Library
#include "CFileUtilities.h"

//-------------------------------------------------------------------------------------------------

CFileUtilities::CFileUtilities()
{
}

//-------------------------------------------------------------------------------------------------

QStringList CFileUtilities::concernedFiles(const QString& sBaseDirecory, const QStringList& lNames)
{
    QStringList lResult;

    for (QString sName : lNames)
    {
        QString sFullName = QString("%1/%2")
                .arg(sBaseDirecory)
                .arg(sName);

        if (QFile(sFullName).exists() && not QDir(sFullName).exists())
        {
            lResult << sName;
        }
        else
        {
            QString sDirectory = sFullName;
            QString sWildCard = "";

            if (sFullName.contains("*"))
            {
                sWildCard = sFullName.split("/").last();
                sDirectory.replace(sWildCard, "");
            }

            concernedFilesRecurse(lResult, sDirectory, sWildCard);
        }
    }

    return lResult;
}

//-------------------------------------------------------------------------------------------------

void CFileUtilities::concernedFilesRecurse(QStringList& lResut, const QString& sCurrentDirectory, const QString& sWildCard)
{
    QStringList lFilter;
    lFilter << sWildCard;

    QDir dDirectory(sCurrentDirectory);
    QFileInfoList lFiles = dDirectory.entryInfoList(lFilter, QDir::Files | QDir::NoSymLinks);

    for (QFileInfo iFile : lFiles)
    {
        QString sFile = QString("%1/%2").arg(iFile.absolutePath()).arg(iFile.fileName());
        lResut << sFile;
    }

    lFilter.clear();
    lFilter << "*";

    lFiles = dDirectory.entryInfoList(lFilter, QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    for (QFileInfo iFile : lFiles)
    {
        QString sTargetDirectory = QString("%1/%2").arg(sCurrentDirectory).arg(iFile.fileName());
        concernedFilesRecurse(lResut, sTargetDirectory, sWildCard);
    }
}
