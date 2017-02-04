/*******************************************************************************
* P. C. A.
*
* Peugeot Citroen Automobiles
*
* This file is the property of PCA. All rights are reserved
* by PCA and this file must not be copied or disclosed
* (in whole or in part) without prior written consent of PCA.
*
*******************************************************************************/

#ifndef CHTMLGENERATOR_H
#define CHTMLGENERATOR_H

#include "unislib_global.h"

// Fondations
#include "CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

//! Définit un serveur simple de page HTML
class UNISLIBSHARED_EXPORT CHTMLGenerator : public CHTTPServer
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur
    CHTMLGenerator(int iPort);

    //! Destructeur
    virtual ~CHTMLGenerator();

    //-------------------------------------------------------------------------------------------------
    // Méthodes protégées
    //-------------------------------------------------------------------------------------------------

protected:

    //! Commence une nouvelle section
    void beginSection(QString sText, QString sAdditionalAttr = "");

    //! Termine la section courante
    void endSection();

    //! Ajoute une sous-section
    void addSubSection(QString sText);

    //! Commence une nouvelle table
    void beginTable();

    //! Termine la table courante
    void endTable();

    //! Commence une nouvelle ligne dans la table courante
    void beginRow();

    //! Termine la ligne courante
    void endRow();

    //! Commence une nouvelle colonne dans la ligne courante
    void beginColumn();

    //! Termine la colonne courante
    void endColumn();

    //! Ajoute une information de la forme clé = valeur
    void addKeyValue(QString sKey, QString sValue);

    //! Ajoute un lien
    void addKeyLink(QString sKey, QString sValue, QString sLink);

    //! Ajoute une combo box
    void addKeyChoice(QString sKey, QString sID, QStringList lValues, QString sOnChange, QString sSelected);

    //! Ajoute une zone de texte dans une table : créé une nouvelle ligne
    void addTableText(QString sKey, QString sID, QString sText);

    //! Ajoute un bouton dans une table : créé une nouvelle ligne
    void addTableButton(QString sDesc, QString sText, QString sOnClick);

    //! Ajoute le texte brut
    void addText(QString sText);

    //! Ajoute un bouton
    void addButton(QString sText, QString sOnClick);

    //! Ajoute une zone de texte monoligne
    void addTextbox(QString sID, QString sText, int iWidth = 100);

    //! Ajoute une zone de texte multiligne
    void addTableTextEdit(QString sID, QString sText, QString sOnKeyPress, int iWidth = 600);

    //! Ajoute un indicateur de booléen avec variation de la couleur
    void addCriticalBoolValue(QString sKey, bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    //-------------------------------------------------------------------------------------------------

protected:

    //! Texte retourné par getBody()
    QString m_sText;
};

#endif // CHTMLGENERATOR_H
