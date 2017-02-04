
#pragma once

// Qt
#include <QtCore/QMutex>

//-------------------------------------------------------------------------------------------------

//! Définit un patron de Singleton
//! Defines a singleton pattern
template<class T>
class CSingleton
{
public:

	//-------------------------------------------------------------------------------------------------
	// Méthodes de contrôle
	// Control methods
	//-------------------------------------------------------------------------------------------------

	//! Accesseur a l'instance de la classe
	//! Gets the unique instance of the class
	static T* getInstance()
	{
		if (s_pInstance == NULL)
		{
			s_pInstance = new T();
		}

		return s_pInstance;
	}

	//! Destructeur de l'instance de la classe
	//! Destroys the unique instance of the class
	static void killInstance()
	{
		if (s_pInstance != NULL)
		{
			delete s_pInstance;
		}

		s_pInstance = NULL;
	}

	//-------------------------------------------------------------------------------------------------
	// Méthodes protégées
	// Protected methods
	//-------------------------------------------------------------------------------------------------

protected:

	//! Constructeur
	//! Constructor
	CSingleton() {}

	//! Destructeur
	//! Destructor
	virtual ~CSingleton() {}

	//-------------------------------------------------------------------------------------------------
	// Propriétés
	// Properties
	//-------------------------------------------------------------------------------------------------

private:
	static T*		s_pInstance;	// Instance du singleton
	static QMutex	s_mutex;		// Mutex pour accès concurrents
};

// Instance du singleton
template<class T> T* CSingleton<T>::s_pInstance = NULL;

// Mutex pour accès concurrents
template<class T> QMutex CSingleton<T>::s_mutex(QMutex::Recursive);
