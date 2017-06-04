
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebModelControl.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CWebListView : public CWebModelControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Constructeur par défaut
    CWebListView();

    //! Constructeur avec paramètres
    CWebListView(const QString& sName, const QString& sCaption, IJSONModelProvider* pModelProvider = nullptr);

    //! Destructeur
    virtual ~CWebListView();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Méthodes héritées
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void controlEvent(CWebControl* pControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const Q_DECL_OVERRIDE;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootControl) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    //-------------------------------------------------------------------------------------------------

protected:

    qint32      m_iUsersPerPage;
    qint32      m_iCurrentPage;
};
