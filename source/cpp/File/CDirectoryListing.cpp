
// qt
#include <QDir>
#include <QFileInfo>

// Library
#include "CDirectoryListing.h"

//-------------------------------------------------------------------------------------------------

/*!
	\class CDirectoryListing
    \inmodule qt-plus
	\brief A cached directory tree.
*/

//-------------------------------------------------------------------------------------------------

CDirectoryListingItem::CDirectoryListingItem()
	: QObject(nullptr)
	, m_bIsFolder(false)
{
}

//-------------------------------------------------------------------------------------------------

CDirectoryListingItem::CDirectoryListingItem(const CDirectoryListingItem& target)
	: QObject(nullptr)
{
	*this = target;
}

//-------------------------------------------------------------------------------------------------

CDirectoryListingItem& CDirectoryListingItem::operator = (const CDirectoryListingItem& target)
{
	m_bIsFolder = target.m_bIsFolder;
	m_sAbsoluteName = target.m_sAbsoluteName;
	m_sRelativeName = target.m_sRelativeName;

	return *this;
}

//-------------------------------------------------------------------------------------------------

bool CDirectoryListingItem::operator == (const CDirectoryListingItem& target) const
{
	if (m_bIsFolder != target.m_bIsFolder)
		return false;
	if (m_sAbsoluteName != target.m_sAbsoluteName)
		return false;
	if (m_sRelativeName != target.m_sRelativeName)
		return false;

	return true;
}

//-------------------------------------------------------------------------------------------------

CXMLNode CDirectoryListingItem::toNode() const
{
	CXMLNode tReturnValue;

	return tReturnValue;
}

//-------------------------------------------------------------------------------------------------

CDirectoryListingItem CDirectoryListingItem::fromNode(const CXMLNode& xNode)
{
	CDirectoryListingItem tItem;

	tItem.setIsFolder(bool(xNode.attributes()["isFolder"].toInt()));
	tItem.setAbsoluteName(xNode.attributes()["absoluteName"]);
	tItem.setRelativeName(xNode.attributes()["relativeName"]);

	return tItem;
}

//-------------------------------------------------------------------------------------------------

/*!
	Constructs a CDirectoryListing.
*/
CDirectoryListing::CDirectoryListing()
{
}

//-------------------------------------------------------------------------------------------------

/*!
	Constructs a CDirectoryListing using \a sFileName as the root path.
*/
CDirectoryListing::CDirectoryListing(const QString& sRootPath)
	: m_sRootPath(sRootPath)
{
}

//-------------------------------------------------------------------------------------------------

/*!
	Destroys a CDirectoryListing.
*/
CDirectoryListing::~CDirectoryListing()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the file name of this node to \a sFileName.
*/
void CDirectoryListing::setRootPath(const QString& sRootPath)
{
	m_sRootPath = sRootPath;
	listFiles();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the file name of this node.
*/
QString CDirectoryListing::rootPath() const
{
	return m_sRootPath;
}

//-------------------------------------------------------------------------------------------------

void CDirectoryListing::addIgnoreName(const QString& sIgnoreName)
{
	m_lIgnoreNames << sIgnoreName;
}

//-------------------------------------------------------------------------------------------------

QString CDirectoryListing::relativeFileName(const QString& sRootPath, const QString& sFileName)
{
	QDir dRoot(sRootPath);
	return dRoot.relativeFilePath(sFileName);
}

//-------------------------------------------------------------------------------------------------

void CDirectoryListing::listFiles()
{
	m_vFiles.clear();
	listFilesRecursive(m_sRootPath);
}

//-------------------------------------------------------------------------------------------------

void CDirectoryListing::listFilesRecursive(QString sCurrentDirectoryAbsolute)
{
	QStringList lFilter; lFilter << "*";

	QDir dDirectory(sCurrentDirectoryAbsolute);
	QFileInfoList lFiles = dDirectory.entryInfoList(lFilter, QDir::Files | QDir::NoSymLinks);

	CDirectoryListingItem tDirectory;
	tDirectory.setIsFolder(true);
	tDirectory.setAbsoluteName(dDirectory.absolutePath());
	tDirectory.setRelativeName(relativeFileName(m_sRootPath, sCurrentDirectoryAbsolute));

	m_vFiles << tDirectory;

	for (QFileInfo iFile : lFiles)
	{
		QString sFullName = QString("%1/%2").arg(iFile.absolutePath()).arg(iFile.fileName());

		CDirectoryListingItem tFile;
		tFile.setIsFolder(false);
		tFile.setAbsoluteName(dDirectory.absolutePath());
		tFile.setRelativeName(relativeFileName(m_sRootPath, sFullName));

		m_vFiles << tFile;
	}

	lFiles = dDirectory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);

	for (QFileInfo iFile : lFiles)
	{
		QString sDirectoryName = iFile.fileName();

		// Proceed recursively if we are not entering an ignore name
		if (not m_lIgnoreNames.contains(sDirectoryName))
		{
			QString sTargetDirectory = QString("%1/%2").arg(sCurrentDirectoryAbsolute).arg(sDirectoryName);
			listFilesRecursive(sTargetDirectory);
		}
	}
}
