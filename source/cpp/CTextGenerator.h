
#pragma once

#include "qtplus_global.h"

// Qt
#include <QString>
#include <QStringList>
#include <QVector>

/*
 * This class is a C++ version of fake-words by anticoders
 * https://github.com/anticoders/fake-words
*/

//-------------------------------------------------------------------------------------------------

// Defines a dumpable object
class QTPLUSSHARED_EXPORT CTextGenerator
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CTextGenerator();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QString word();

    //!
    QString sentence(int length = 0);

    //!
    QString paragraph(int length = 0);

    //!
    QString text(int length = 0);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    double randomDouble();

    //!
    QString capitalize(const QString& sText);

    //!
    QString getWord();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QVector<int>    m_vWordLengths;
    QVector<int>    m_vSyllableCounts;
    QStringList     m_lSyllables;
};
