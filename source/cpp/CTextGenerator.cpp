
// Std
#include <math.h>

// Application
#include "CTextGenerator.h"
#include "Macros.h"

//-------------------------------------------------------------------------------------------------

CTextGenerator::CTextGenerator()
{
    m_vWordLengths = QVector<int>
            ({
                 1, 1,
                 2, 2, 2, 2, 2, 2, 2,
                 3, 3, 3, 3,
                 4, 4,
                 5
             });

    m_vSyllableCounts = QVector<int>
            ({
                 10, 15, 20, 25,
                 30, 35, 40, 45,
                 50, 75, 100, 125,
                 150, 175, 175, 175
             });

    m_lSyllables = QStringList
            ({
                 "the",  "ing",  "er",    "a",   "ly",   "ed",  "i",     "es",   "re",   "tion", "in",    "e",
                 "con",  "y",    "ter",   "ex",  "al",   "de",  "com",   "o",    "di",   "en",   "an",    "ty",
                 "ry",   "u",    "ti",    "ri",  "be",   "per", "to",    "pro",  "ac",   "ad",   "ar",    "ers",
                 "ment", "or",   "tions", "ble", "der",  "ma",  "na",    "si",   "un",   "at",   "dis",   "ca",
                 "cal",  "man",  "ap",    "po",  "sion", "vi",  "el",    "est",  "la",   "lar",  "pa",    "ture",
                 "for",  "is",   "mer",   "pe",  "ra",   "so",  "ta",    "as",   "col",  "fi",   "ful",   "get",
                 "low",  "ni",   "par",   "son", "tle",  "day", "ny",    "pen",  "pre",  "tive", "car",   "ci",
                 "mo",   "an",   "aus",   "pi",  "se",   "ten", "tor",   "ver",  "ber",  "can",  "dy",    "et",
                 "it",   "mu",   "no",    "ple", "cu",   "fac", "fer",   "gen",  "ic",   "land", "light", "ob",
                 "of",   "pos",  "tain",  "den", "ings", "mag", "ments", "set",  "some", "sub",  "sur",   "ters",
                 "tu",   "af",   "au",    "cy",  "fa",   "im",  "li",    "lo",   "men",  "min",  "mon",   "op",
                 "out",  "rec",  "ro",    "sen", "side", "tal", "tic",   "ties", "ward", "age",  "ba",    "but",
                 "cit",  "cle",  "co",    "cov", "daq",  "dif", "ence",  "ern",  "eve",  "hap",  "ies",   "ket",
                 "lec",  "main", "mar",   "mis", "my",   "nal", "ness",  "ning", "nu",   "oc",   "pres",  "sup",
                 "te",   "ted",  "tem",   "tin", "tri",  "tro", "up"
             });
}

//-------------------------------------------------------------------------------------------------

QString CTextGenerator::word()
{
    return capitalize(getWord());
}

//-------------------------------------------------------------------------------------------------

QString CTextGenerator::sentence(int length)
{
    if (!length)
        length = 4 + int(std::floor(randomDouble() * 7));

    QString ending = (randomDouble() < 0.95) ? "." : (randomDouble() < 0.5) ? "!" : "?";
    QString result = capitalize(getWord());

    for (int i = 1; i < length; ++i)
    {
        result += " " + getWord();
    }

    return result + ending;
}

//-------------------------------------------------------------------------------------------------

QString CTextGenerator::paragraph(int length)
{
    if (!length)
        length = 6 + int(std::floor(randomDouble() * 7));

    QString result = sentence();

    for (int i = 1; i < length; ++i)
    {
        result += " " + sentence();
    }

    return result;
}

//-------------------------------------------------------------------------------------------------

QString CTextGenerator::text(int length)
{
    if (!length)
        length = 5 + int(std::floor(randomDouble() * 9));

    QString result = paragraph();

    for (int i = 1; i < length; ++i)
    {
        result += "\n" + paragraph();
    }

    return result;
}

//-------------------------------------------------------------------------------------------------

double CTextGenerator::randomDouble()
{
    return CLIPPED(double(std::rand()) / double(RAND_MAX), 0.00, 0.99);
}

//-------------------------------------------------------------------------------------------------

QString CTextGenerator::capitalize(const QString& sText)
{
    QString sReturnValue(sText);
    sReturnValue.replace(0, 1, sReturnValue[0].toUpper());
    return sReturnValue;
};

//-------------------------------------------------------------------------------------------------

QString CTextGenerator::getWord()
{
    int length = m_vWordLengths[int(std::floor(randomDouble() * m_vWordLengths.count()))];

    QString word;

    for (int i = 0; i < length; ++i)
    {
        int iIndex1 = int(std::floor(randomDouble() * m_vSyllableCounts.count()));
        int iCount = m_vSyllableCounts[iIndex1];
        int iIndex2 = int(std::floor(randomDouble() * iCount));
        word += m_lSyllables[iIndex2];
    }

    return word;
};

//-------------------------------------------------------------------------------------------------
