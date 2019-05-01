
#pragma once

#include <QtTest/QtTest>

class CUnitTests : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CUnitTests();

    //! Destructor
    virtual ~CUnitTests();

    //-------------------------------------------------------------------------------------------------
    // Tests
    //-------------------------------------------------------------------------------------------------

private slots:

    void xml();
    void remoteControlMultiClient();
};
