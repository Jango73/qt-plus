
#include <QApplication>
#include <QThread>

#include "TDMATest.h"

void TestRunner::run()
{
    SingleChannelDeviceRelay relay;
    SingleChannelDevice device1(&relay);
    SingleChannelDevice device2(&relay);

    relay.addDevice(&device1);
    relay.addDevice(&device2);
}

TestApplication::TestApplication(int argc, char** argv)
    : QApplication(argc, argv)
{
    connect(&runner, SIGNAL(finished()), this, SLOT(onFinished()));
    runner.start();
}

void TestApplication::onFinished()
{
    quit();
}

int main(int argc, char** argv)
{
    TestApplication app(argc, argv);

    return app.exec();
}
