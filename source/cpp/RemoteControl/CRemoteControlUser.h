
#ifndef	CREMOTECONTROLUSER_H
#define	CREMOTECONTROLUSER_H

#include <QObject>
#include <QString>
#include <QVector>

#define BIT_0	1
#define BIT_1	2
#define BIT_2	4
#define BIT_3	8
#define BIT_4	16
#define BIT_5	32
#define BIT_6	64
#define BIT_7	128

// User privilege flags
enum EPrivilege
{
	EP_None			= 0,
	EP_FileRead		= BIT_0,
	EP_FileWrite	= BIT_1,
	EP_FileDelete	= BIT_2,
	EP_Execute		= BIT_3,
	EP_Shutdown		= BIT_7
};

// Data for users
class CRemoteControlUser : public QObject
{
	Q_OBJECT

public:

	// Default constructor
	CRemoteControlUser();

	// Constructor with parmeters
	CRemoteControlUser(QString sName, QString sPassword, int iPrivileges);

	// Copy constructor
	CRemoteControlUser(const CRemoteControlUser&);

	// Destructor
	~CRemoteControlUser();

	// Operator =
	virtual CRemoteControlUser& operator = (const CRemoteControlUser&);

	// Getters
	QString login() { return m_sLogin; }
	QString password() { return m_sPassword; }
    QString encodedPassword() { return m_sEncodedPassword; }
	int privileges() { return m_iPrivileges; }

    // Static methods
    static QString encoded(QString sText);

protected:

	QString		m_sLogin;
	QString		m_sPassword;
    QString		m_sEncodedPassword;
	int			m_iPrivileges;
};

#endif // CREMOTECONTROLUSER_H
