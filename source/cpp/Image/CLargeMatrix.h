
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QVector>

//-------------------------------------------------------------------------------------------------

//! D�finit une matrice de N x N �l�ments
//! Defines a N x N component matrix
class QTPLUSSHARED_EXPORT CLargeMatrix
{
public:

	//-------------------------------------------------------------------------------------------------
	// Constructeurs et destructeur
	// Constructors and destructor
	//-------------------------------------------------------------------------------------------------

	//! Constructeur par d�faut
	//! Default constructor
	CLargeMatrix();

	//! Destructeur
	//! Destructor
	virtual ~CLargeMatrix();

	//-------------------------------------------------------------------------------------------------
	// Setters
	//-------------------------------------------------------------------------------------------------

	//! D�finit la taille de la matrice (width = colonnes)
	//! Defines the matrix' size (width = columns)
	void setSize(int width, int height);

	//! D�finit la valeur de l'�l�ment � [row, column]
	//! Defines the value for element at [row, column]
	void setValue(int row, int column, double value);

	//-------------------------------------------------------------------------------------------------
	// Getters
	//-------------------------------------------------------------------------------------------------

	//! Retourne la largeur de la matrice (colonnes)
	//! Returns the matrix' width (columns)
	int width() const;

	//! Retourne la hauteur de la matrice (rangs)
	//! Returns the matrix' height (rows)
	int height() const;

	//! Retourne le vecteur de donn�es
	//! Returns the data vector
	QVector<QVector<double > >& data();

	//! Retourne le vecteur de donn�es
	//! Returns the data vector
	const QVector<QVector<double > >& data() const;

	//! Retourne le rang num�ro 'index'
	//! Returns the 'index' row
	QVector<double >& row(int index);

	//! Retourne le rang num�ro 'index'
	//! Returns the 'index' row
	const QVector<double >& row(int index) const;

	//! Retourne la valeur de l'�l�ment �  [row, column]
	//! Returns the value of element at [row, column]
	double valueAt(int row, int column) const;

	//-------------------------------------------------------------------------------------------------
	// M�thodes de contr�le
	// Control methods
	//-------------------------------------------------------------------------------------------------

	//! Retourne une matrice de flou avec un rayon 'radius'
	//! Returns a blur matrix using 'radius'
	static CLargeMatrix blurMatrix(double dRadius);

	//! Retourne une matrice de dilatation
	//! Returns a dilation matrix
	static CLargeMatrix dilateMatrix();

	//! Retourne une matrice d'�rosion
	//! Returns an erosion matrix
	static CLargeMatrix erosionMatrix();

	//-------------------------------------------------------------------------------------------------
	// Propri�t�s
	// Properties
	//-------------------------------------------------------------------------------------------------

protected:

	QVector<QVector<double > >	m_vData;
	QVector<double >			m_vDummyRow;
};
