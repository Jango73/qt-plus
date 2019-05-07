
// Qt
#include <QDebug>

// qt-plus
#include "CXMLNode.h"
#include "RemoteControl/CRemoteControl.h"

#include "CUnitTests.h"

//-------------------------------------------------------------------------------------------------

CUnitTests::CUnitTests()
{
}

//-------------------------------------------------------------------------------------------------

CUnitTests::~CUnitTests()
{
}

//-------------------------------------------------------------------------------------------------

void CUnitTests::xml()
{
    CXMLNode xTest;
    QVERIFY(true);
}

//-------------------------------------------------------------------------------------------------

void CUnitTests::remoteControlMultiClient()
{
    CRemoteControl rcServer(CRemoteControl::defaultPort());
    CRemoteControl rcClient1("127.0.0.1", CRemoteControl::defaultPort());
    CRemoteControl rcClient2("127.0.0.1", CRemoteControl::defaultPort());

    QVERIFY(rcClient1.connectedToServer());

    rcClient1.setLoginPassword("guest", "guest");
    rcClient1.sendCommand("dir", false, true);

    rcClient2.setLoginPassword("guest", "guest");
    rcClient2.sendCommand("dir", false, true);
}

//-------------------------------------------------------------------------------------------------

QTEST_MAIN(CUnitTests)
