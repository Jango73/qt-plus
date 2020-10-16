
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include "../Macros.h"
#include "../QTree.h"
#include "../CXMLNode.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CDirectoryListingItem : public QObject
{
	Q_OBJECT

public:

	//-------------------------------------------------------------------------------------------------
	// Properties
	//-------------------------------------------------------------------------------------------------

	Q_FAST_PROPERTY(bool, b, isFolder, IsFolder)
	Q_FAST_PROPERTY(QString, s, absoluteName, AbsoluteName)
	Q_FAST_PROPERTY(QString, s, relativeName, RelativeName)

	//-------------------------------------------------------------------------------------------------
	// Constructors and destructor
	//-------------------------------------------------------------------------------------------------

public:

	//! Default constructor
	CDirectoryListingItem();

	//! Copy constructor
	CDirectoryListingItem(const CDirectoryListingItem& target);

	//-------------------------------------------------------------------------------------------------
	// Control methods
	//-------------------------------------------------------------------------------------------------

	//!
	CDirectoryListingItem& operator = (const CDirectoryListingItem& target);

	//!
	bool operator == (const CDirectoryListingItem& target) const;

	//!
	CXMLNode toNode() const;

	//-------------------------------------------------------------------------------------------------
	// Static control methods
	//-------------------------------------------------------------------------------------------------

	//!
	static CDirectoryListingItem fromNode(const CXMLNode& xNode);
};

//-------------------------------------------------------------------------------------------------

typedef QVector<CDirectoryListingItem> CCachedDirectoryVector;

//-------------------------------------------------------------------------------------------------

//! Defines a cached directory tree
class QTPLUSSHARED_EXPORT CDirectoryListing : public QObject
{
	Q_OBJECT

	//-------------------------------------------------------------------------------------------------
	// Properties
	//-------------------------------------------------------------------------------------------------

	Q_FAST_PROPERTY(CCachedDirectoryVector, v, files, Files)

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
	CDirectoryListing();

	//! Constructor with root path
	CDirectoryListing(const QString& sRootPath);

    //! Destructor
	virtual ~CDirectoryListing();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Defines the file name
	void setRootPath(const QString& sRootPath);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the file name
	QString rootPath() const;

	//-------------------------------------------------------------------------------------------------
	// Control methods
	//-------------------------------------------------------------------------------------------------

	void addIgnoreName(const QString& sIgnoreName);

    //-------------------------------------------------------------------------------------------------
	// Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

	//!
	QString relativeFileName(const QString& sRootPath, const QString& sFileName);

	//!
	void listFiles();

	//!
	void listFilesRecursive(QString sCurrentDirectoryAbsolute);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

	QString			m_sRootPath;            // The base file name
	QStringList		m_lIgnoreNames;
};
