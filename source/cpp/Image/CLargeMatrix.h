
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
	// Constructeurs et destructeur
	// Constructors and destructor
	//-------------------------------------------------------------------------------------------------

	//! Constructeur par défaut
	//! Default constructor
	CLargeMatrix();

	//! Destructeur
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

	//! Retourne la largeur de la matrice (colonnes)
	//! Returns the matrix' width (columns)
	int width() const;

	//! Retourne la hauteur de la matrice (rangs)
	//! Returns the matrix' height (rows)
	int height() const;

	//! Retourne le vecteur de données
	//! Returns the data vector
	QVector<QVector<double > >& data();

	//! Retourne le vecteur de données
	//! Returns the data vector
	const QVector<QVector<double > >& data() const;

	//! Retourne le rang numéro 'index'
	//! Returns the 'index' row
	QVector<double >& row(int index);

	//! Retourne le rang numéro 'index'
	//! Returns the 'index' row
	const QVector<double >& row(int index) const;

	//! Retourne la valeur de l'élément à  [row, column]
	//! Returns the value of element at [row, column]
	double valueAt(int row, int column) const;

	//-------------------------------------------------------------------------------------------------
	// Méthodes de contrôle
	// Control methods
	//-------------------------------------------------------------------------------------------------

	//! Retourne une matrice de flou avec un rayon 'radius'
	//! Returns a blur matrix using 'radius'
	static CLargeMatrix blurMatrix(double dRadius);

	//! Retourne une matrice de dilatation
	//! Returns a dilation matrix
	static CLargeMatrix dilateMatrix();

	//! Retourne une matrice d'érosion
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
