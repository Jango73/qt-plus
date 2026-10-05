
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QVector>

//-------------------------------------------------------------------------------------------------

//! Définit une matrice de N x N éléments
//! Defines a N x N component matrix
class QTPLUSSHARED_EXPORT CLargeMatrix
{
public:

	//-------------------------------------------------------------------------------------------------
	// Constructors and destructor
	// Constructors and destructor
	//-------------------------------------------------------------------------------------------------

	//! Default constructor
	//! Default constructor
	CLargeMatrix();

	//! Destructor
	//! Destructor
	virtual ~CLargeMatrix();

	//-------------------------------------------------------------------------------------------------
	// Setters
	//-------------------------------------------------------------------------------------------------

	//! Définit la taille de la matrice (width = colonnes)
	//! Defines the matrix' size (width = columns)
	void setSize(int width, int height);

	//! Définit la valeur de l'élément à [row, column]
	//! Defines the value for element at [row, column]
	void setValue(int row, int column, double value);

	//-------------------------------------------------------------------------------------------------
	// Getters
	//-------------------------------------------------------------------------------------------------

	//! Returns the width of the matrix (columns)
	//! Returns the matrix' width (columns)
	int width() const;

	//! Returns the height of the matrix (rows)
	//! Returns the matrix' height (rows)
	int height() const;

	//! Returns the data vector
	//! Returns the data vector
	QVector<QVector<double > >& data();

	//! Returns the data vector
	//! Returns the data vector
	const QVector<QVector<double > >& data() const;

	//! Returns row number 'index'
	//! Returns the 'index' row
	QVector<double >& row(int index);

	//! Returns row number 'index'
	//! Returns the 'index' row
	const QVector<double >& row(int index) const;

	//! Returns the value of the element at [row, column]
	//! Returns the value of element at [row, column]
	double valueAt(int row, int column) const;

	//-------------------------------------------------------------------------------------------------
	// Méthodes de contrôle
	// Control methods
	//-------------------------------------------------------------------------------------------------

	//! Returns a blur matrix with a 'radius' radius
	//! Returns a blur matrix using 'radius'
	static CLargeMatrix blurMatrix(double dRadius);

	//! Returns a dilation matrix
	//! Returns a dilation matrix
	static CLargeMatrix dilateMatrix();

	//! Returns an erosion matrix
	//! Returns an erosion matrix
	static CLargeMatrix erosionMatrix();

	//-------------------------------------------------------------------------------------------------
	// Propriétés
	// Properties
	//-------------------------------------------------------------------------------------------------

protected:

	QVector<QVector<double > >	m_vData;
	QVector<double >			m_vDummyRow;
};
