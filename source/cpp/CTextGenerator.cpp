
// Std
#include <math.h>

// Application
#include "CTextGenerator.h"

//-------------------------------------------------------------------------------------------------

CTextGenerator::CTextGenerator()
{
    init();
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
        length = 4 + int(floor(randomDouble() * 8));

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
        length = 6 + int(floor(randomDouble() * 8));

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
        length = 5 + int(floor(randomDouble() * 10));

    QString result = paragraph();

    for (int i = 1; i < length; ++i)
    {
        result += "\n" + paragraph();
    }

    return result;
}

//-------------------------------------------------------------------------------------------------

void CTextGenerator::init()
{
    m_vWordLengths = QVector<int>
            ({
                 1, 1,
                 2, 2, 2, 2, 2, 2, 2,
                 3, 3, 3, 3,
                 4, 4,
                 5
             });

    m_vSyllabeCounts = QVector<int>
            ({
                 10, 15, 20, 25,
                 30, 35, 40, 45,
                 50, 75, 100, 125,
                 150, 175, 175, 175
             });

    m_lSyllabes = QStringList
            ({
                 "the","ing","er","a","ly","ed","i","es","re","tion","in","e","con","y","ter","ex","al","de","com","o","di","en","an","ty","ry","u",
                 "ti","ri","be","per","to","pro","ac","ad","ar","ers","ment","or","tions","ble","der","ma","na","si","un","at","dis","ca","cal","man","ap",
                 "po","sion","vi","el","est","la","lar","pa","ture","for","is","mer","pe","ra","so","ta","as","col","fi","ful","get","low","ni","par","son",
                 "tle","day","ny","pen","pre","tive","car","ci","mo","an","aus","pi","se","ten","tor","ver","ber","can","dy","et","it","mu","no","ple","cu",
                 "fac","fer","gen","ic","land","light","ob","of","pos","tain","den","ings","mag","ments","set","some","sub","sur","ters","tu","af","au","cy","fa","im",
                 "li","lo","men","min","mon","op","out","rec","ro","sen","side","tal","tic","ties","ward","age","ba","but","cit","cle","co","cov","daq","dif","ence",
                 "ern","eve","hap","ies","ket","lec","main","mar","mis","my","nal","ness","ning","nu","oc","pres","sup","te","ted","tem","tin","tri","tro","up"
             });
}

//-------------------------------------------------------------------------------------------------

double CTextGenerator::randomDouble()
{
    return double(rand()) / double(RAND_MAX);
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
    int length = m_vWordLengths[int(floor(randomDouble() * 16))];

    QString word;

    for (int i = 0; i < length; ++i)
    {
        int count = m_vSyllabeCounts[int(floor(randomDouble() * 16))];
        word += m_lSyllabes[int(floor(randomDouble() * count))];
    }

    return word;
};

//-------------------------------------------------------------------------------------------------
