
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a comment
class QTPLUSSHARED_EXPORT QMLComment : public QMLEntity
{
    Q_OBJECT

public:

    enum ECommentType
    {
        ctSingleLineAtEnd,
        ctSingleLine,
        ctMultiLine,
        ctMultiLineDoc
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    QMLComment(const QPoint& pPosition, const QString& sText, ECommentType eType);

    //! Destructor
    virtual ~QMLComment();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setAttachedTo(QMLEntity* pAttachedTo);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* attachedTo() const;

    //!
    ECommentType type() const;

    //!
    bool deadCode() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void writeMultiLineComment(QTextStream& stream, QMLFormatter& formatter, const QString& sText) const;

    //!
    void checkForCode();

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLEntity*      m_pAttachedTo;
    ECommentType    m_eType;
    bool            m_bDeadCode;
};
