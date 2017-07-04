
#pragma once

// Qt
#include <QtCore/QMutex>

//-------------------------------------------------------------------------------------------------

//! Defines a singleton pattern
template<class T>
class CSingleton
{
public:

	//-------------------------------------------------------------------------------------------------
	// Control methods
	//-------------------------------------------------------------------------------------------------

	//! Gets the unique instance of the class
	static T* getInstance()
	{
        if (s_pInstance == nullptr)
		{
			s_pInstance = new T();
		}

		return s_pInstance;
	}

	//! Destroys the unique instance of the class
	static void killInstance()
	{
        if (s_pInstance != nullptr)
		{
			delete s_pInstance;
		}

        s_pInstance = nullptr;
	}

	//-------------------------------------------------------------------------------------------------
	// Protected methods
	//-------------------------------------------------------------------------------------------------

protected:

	//! Constructor
	CSingleton() {}

	//! Destructor
	virtual ~CSingleton() {}

	//-------------------------------------------------------------------------------------------------
	// Properties
	//-------------------------------------------------------------------------------------------------

private:
    static T*		s_pInstance;	// Unique instance
    static QMutex	s_mutex;		// Data protection
};

// Unique instance
template<class T> T* CSingleton<T>::s_pInstance = nullptr;

// Data protection
template<class T> QMutex CSingleton<T>::s_mutex(QMutex::Recursive);
