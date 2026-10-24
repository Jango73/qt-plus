cmake_minimum_required(VERSION 3.16)

# Version lives in the VERSION file at the repository root (same file synced
# by scripts/linux/set-version.sh). Fail fast if it is missing or malformed.
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION")
  message(FATAL_ERROR "VERSION file not found at repository root")
endif()
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" QTPLUS_VERSION_RAW)
string(STRIP "${QTPLUS_VERSION_RAW}" QTPLUS_VERSION)
if(NOT QTPLUS_VERSION MATCHES "^[0-9]+\\.[0-9]+\\.[0-9]+$")
  message(FATAL_ERROR "Malformed VERSION file: '${QTPLUS_VERSION_RAW}'")
endif()

project(qt-plus VERSION ${QTPLUS_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)

# Also usable as a submodule (quick3d, VirtualPilot): only locate Qt when the
# parent project did not do it already.
if(NOT TARGET Qt6::Core)
  find_package(Qt6 6.2 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Network
    Xml
    SerialPort
    Multimedia
    Positioning
    Qml
    Test
  )
endif()

add_library(qt-plus SHARED
    source/cpp/CConnectedStream.cpp
    source/cpp/CDumpable.cpp
    source/cpp/CGeoUtilities.cpp
    source/cpp/CLogger.cpp
    source/cpp/CMacroable.cpp
    source/cpp/CMemoryMonitor.cpp
    source/cpp/CPIDController.cpp
    source/cpp/CJoystickReader.cpp
    source/cpp/CSecureContext.cpp
    source/cpp/CSerialStream.cpp
    source/cpp/CSingletonPool.cpp
    source/cpp/CSocketStream.cpp
    source/cpp/CSoundSynth.cpp
    source/cpp/CStreamFactory.cpp
    source/cpp/CTextGenerator.cpp
    source/cpp/CTDMADevice.cpp
    source/cpp/CTimeSampler.cpp
    source/cpp/CTracableMutex.cpp
    source/cpp/CXMLNodable.cpp
    source/cpp/CXMLNode.cpp
    source/cpp/ISerializable.cpp
    source/cpp/Assembly/CAssemblyEngine.cpp
    source/cpp/Assembly/CAssemblyEngine_Compile.cpp
    source/cpp/Assembly/CAssemblyEngine_Interrupts.cpp
    source/cpp/File/CDirectoryListing.cpp
    source/cpp/File/CFileUtilities.cpp
    source/cpp/File/CRollingFiles.cpp
    source/cpp/File/CShardFileStore.cpp
    source/cpp/GeoTools/coordcnv.cpp
    source/cpp/GeoTools/geocent.cpp
    source/cpp/GeoTools/geotrans.cpp
    source/cpp/GeoTools/mgrs.cpp
    source/cpp/GeoTools/polarst.cpp
    source/cpp/GeoTools/tranmerc.cpp
    source/cpp/GeoTools/ups.cpp
    source/cpp/GeoTools/utm.cpp
    source/cpp/GeoTools/UtmMgrs.cpp
    source/cpp/Image/CImageHistogram.cpp
    source/cpp/Image/CImageUtilities.cpp
    source/cpp/Image/CLargeMatrix.cpp
    source/cpp/QMLTree/QMLAnalyzer.cpp
    source/cpp/QMLTree/QMLArrayAccess.cpp
    source/cpp/QMLTree/QMLBinaryOperation.cpp
    source/cpp/QMLTree/QMLComment.cpp
    source/cpp/QMLTree/QMLComplexEntity.cpp
    source/cpp/QMLTree/QMLConditional.cpp
    source/cpp/QMLTree/QMLEntity.cpp
    source/cpp/QMLTree/QMLFile.cpp
    source/cpp/QMLTree/QMLFor.cpp
    source/cpp/QMLTree/QMLForIn.cpp
    source/cpp/QMLTree/QMLFormatter.cpp
    source/cpp/QMLTree/QMLFunctionCall.cpp
    source/cpp/QMLTree/QMLFunction.cpp
    source/cpp/QMLTree/QMLFunctionParameter.cpp
    source/cpp/QMLTree/QMLGrammarParser.cpp
    source/cpp/QMLTree/QMLIdentifier.cpp
    source/cpp/QMLTree/QMLIf.cpp
    source/cpp/QMLTree/QMLImport.cpp
    source/cpp/QMLTree/QMLItem.cpp
    source/cpp/QMLTree/QMLNameValue.cpp
    source/cpp/QMLTree/QMLOnExpression.cpp
    source/cpp/QMLTree/QMLPragma.cpp
    source/cpp/QMLTree/QMLPropertyAlias.cpp
    source/cpp/QMLTree/QMLPropertyAssignment.cpp
    source/cpp/QMLTree/QMLPropertyDeclaration.cpp
    source/cpp/QMLTree/QMLQualifiedExpression.cpp
    source/cpp/QMLTree/QMLSpecialValue.cpp
    source/cpp/QMLTree/QMLSwitch.cpp
    source/cpp/QMLTree/QMLTreeContext.cpp
    source/cpp/QMLTree/QMLType.cpp
    source/cpp/QMLTree/QMLUnaryOperation.cpp
    source/cpp/QMLTree/QMLVariableDeclaration.cpp
    source/cpp/RemoteControl/CRemoteControl.cpp
    source/cpp/RemoteControl/CRemoteControlData.cpp
    source/cpp/RemoteControl/CRemoteControlUser.cpp
    source/cpp/roke/ROKE.cpp
    source/cpp/rsa/source/BigInt.cpp
    source/cpp/rsa/source/Key.cpp
    source/cpp/rsa/source/KeyPair.cpp
    source/cpp/rsa/source/PrimeGenerator.cpp
    source/cpp/rsa/source/RSA.cpp
    source/cpp/Web/CDynamicHTTPServer.cpp
    source/cpp/Web/CHTTPRequestProcessor.cpp
    source/cpp/Web/CHTTPServer.cpp
    source/cpp/Web/CMJPEGClient.cpp
    source/cpp/Web/CMJPEGServer.cpp
    source/cpp/Web/CWebComposer.cpp
    source/cpp/Web/CWebContext.cpp
    source/cpp/Web/CWebSession.cpp
    source/cpp/Web/WebControls/CWebButton.cpp
    source/cpp/Web/WebControls/CWebControl.cpp
    source/cpp/Web/WebControls/CWebDiv.cpp
    source/cpp/Web/WebControls/CWebFactory.cpp
    source/cpp/Web/WebControls/CWebFileInput.cpp
    source/cpp/Web/WebControls/CWebLabel.cpp
    source/cpp/Web/WebControls/CWebListView.cpp
    source/cpp/Web/WebControls/CWebModelControl.cpp
    source/cpp/Web/WebControls/CWebPage.cpp
    source/cpp/Web/WebControls/CWebTextBox.cpp
    source/cpp/Web/WebControls/CWebTextEdit.cpp
)

target_compile_definitions(qt-plus PRIVATE QTPLUS_LIBRARY)

target_include_directories(qt-plus PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/source/cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/cpp/QMLTree"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/cpp/Web"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/cpp/GeoTools"
)

target_link_libraries(qt-plus PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    Qt6::Xml
    Qt6::SerialPort
    Qt6::Multimedia
    Qt6::Positioning
    Qt6::Qml
)

set_target_properties(qt-plus PROPERTIES DEBUG_POSTFIX "d"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR})

# Tests only for standalone builds: parents (quick3d, VirtualPilot) run their
# own suites and must not inherit this one.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(QTPLUS_BUILD_TESTS_DEFAULT ON)
else()
  set(QTPLUS_BUILD_TESTS_DEFAULT OFF)
endif()
option(QTPLUS_BUILD_TESTS "Build the qt-plus unit tests" ${QTPLUS_BUILD_TESTS_DEFAULT})

if(QTPLUS_BUILD_TESTS)
  add_subdirectory(test)
endif()
