
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

    // Smoke tests: one slot per fixed critical defect
    void averagerZeroClamp();
    void rollingFilesCheckedBackup();
    void singletonRaceAndKill();
    void loggerChainedCycle();
    void timeSamplerConcurrentDump();
    void lazyPointerOwnership();
    void qtreeRemoveKeepsParentsValid();
    void qtreePathCompilesAndJoins();
    void tracableMutexNonCopyableAndBlocking();
    void xmlLoadReportsErrors();
    void xmlSkipsWhitespaceTextNodes();
    void jsonPreservesScalarsAndArrays();
    void xmlEmptyTagExportsChildren();
    void xmlBinaryRoundTrip();
    void shardFileStoreRoutingSplitAndPersistence();
};
