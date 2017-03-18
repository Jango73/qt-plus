
#pragma once

#include "qtplus_global.h"

// Qt
#include <QTextStream>
#include <QString>

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CDumpable
{
public:

    //! Constructeur
    CDumpable();

    //! Destructeur
    virtual ~CDumpable();

    //! Dump du contenu dans un flux
    virtual void dump(QTextStream& stream, int iIdent);

    //! Ouvre un block dans le fichier de sortie
    void dumpOpenBlock(QTextStream& stream, int iIdent);

    //! Ferme un block dans le fichier de sortie
    void dumpCloseBlock(QTextStream& stream, int iIdent);

    //! Ouvre un tableau dans le fichier de sortie
    void dumpOpenArray(QTextStream& stream, int iIdent);

    //! Ferme un tableau dans le fichier de sortie
    void dumpCloseArray(QTextStream& stream, int iIdent);

    //! Ecrit un texte indenté dans le fichier de sortie
    void dumpNoIndentNoNewLine(QTextStream& stream, QString sText);

    //! Passage à la ligne suivante
    void dumpNewLine(QTextStream& stream);

    //! Ecrit un texte indenté dans le fichier de sortie sans retour à la ligne
    void dumpIndentedNoNewLine(QTextStream& stream, int iIdent, QString sText);

    //! Ecrit un texte indenté dans le fichier de sortie
    void dumpIndented(QTextStream& stream, int iIdent, QString sText);

    //-------------------------------------------------------------------------------------------------
    // Static properties
    //-------------------------------------------------------------------------------------------------

    static bool m_bJavaStyle;
};
