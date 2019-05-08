
HEADERS += \
    source/cpp/qtplus_global.h \
    source/cpp/CFactory.h \
    source/cpp/CSingleton.h \
    source/cpp/CSingletonPool.h \
    source/cpp/CDumpable.h \
    source/cpp/CXMLNodable.h \
    source/cpp/CXMLNode.h \
    source/cpp/QTree.h \
    source/cpp/CPIDController.h \
    source/cpp/CAverager.h \
    source/cpp/CLogger.h \
    source/cpp/CMacroable.h \
    source/cpp/CTracableMutex.h \
    source/cpp/CTimeSampler.h \
    source/cpp/CMemoryMonitor.h \
    source/cpp/Image/CLargeMatrix.h \
    source/cpp/Image/CImageHistogram.h \
    source/cpp/Image/CImageUtilities.h \
    source/cpp/CSoundSynth.h \
    source/cpp/CSecureContext.h \
    source/cpp/CTDMADevice.h \
    source/cpp/CStreamFactory.h \
    source/cpp/CConnectedStream.h \
    source/cpp/CSocketStream.h \
    source/cpp/CSerialStream.h \
    source/cpp/File/CRollingFiles.h \
    source/cpp/RemoteControl/CRemoteControl.h \
    source/cpp/RemoteControl/CRemoteControlData.h \
    source/cpp/RemoteControl/CRemoteControlUser.h \
    source/cpp/Web/CMJPEGClient.h \
    source/cpp/Web/CMJPEGServer.h \
    source/cpp/Web/CWebComposer.h \
    source/cpp/Web/CWebContext.h \
    source/cpp/Web/CHTTPServer.h \
    source/cpp/Web/CHTTPRequestProcessor.h \
    source/cpp/Web/CDynamicHTTPServer.h \
    source/cpp/Web/WebControls/CWebButton.h \
    source/cpp/Web/WebControls/CWebControl.h \
    source/cpp/Web/WebControls/CWebDiv.h \
    source/cpp/Web/WebControls/CWebFactory.h \
    source/cpp/Web/WebControls/CWebLabel.h \
    source/cpp/Web/WebControls/CWebPage.h \
    source/cpp/Web/WebControls/CWebTextBox.h \
    source/cpp/Web/WebControls/CWebTextEdit.h \
    source/cpp/Web/WebControls/CWebFileInput.h \
    source/cpp/Web/WebControls/CWebModelControl.h \
    source/cpp/Web/WebControls/CWebListView.h \
    source/cpp/ISerializable.h \
    source/cpp/IJSONModelProvider.h \
    source/cpp/CInterpolator.h \
    source/cpp/GeoTools/coordcnv.h \
    source/cpp/GeoTools/geocent.h \
    source/cpp/GeoTools/mgrs.h \
    source/cpp/GeoTools/polarst.h \
    source/cpp/GeoTools/tranmerc.h \
    source/cpp/GeoTools/ups.h \
    source/cpp/GeoTools/utm.h \
    source/cpp/GeoTools/UtmMgrs.h \
    source/cpp/GeoTools/geotrans.h \
    source/cpp/CGeoUtilities.h \
    source/cpp/QMLTree/QMLFormatter.h \
    source/cpp/QMLTree/QMLEntity.h \
    source/cpp/QMLTree/QMLComplexEntity.h \
    source/cpp/QMLTree/QMLNameValue.h \
    source/cpp/QMLTree/QMLIdentifier.h \
    source/cpp/QMLTree/QMLType.h \
    source/cpp/QMLTree/QMLFile.h \
    source/cpp/QMLTree/QMLImport.h \
    source/cpp/QMLTree/QMLPragma.h \
    source/cpp/QMLTree/QMLItem.h \
    source/cpp/QMLTree/QMLSpecialValue.h \
    source/cpp/QMLTree/QMLPropertyDeclaration.h \
    source/cpp/QMLTree/QMLPropertyAssignment.h \
    source/cpp/QMLTree/QMLPropertyAlias.h \
    source/cpp/QMLTree/QMLFunction.h \
    source/cpp/QMLTree/QMLFunctionCall.h \
    source/cpp/QMLTree/QMLFunctionParameter.h \
    source/cpp/QMLTree/QMLVariableDeclaration.h \
    source/cpp/QMLTree/QMLQualifiedExpression.h \
    source/cpp/QMLTree/QMLArrayAccess.h \
    source/cpp/QMLTree/QMLOnExpression.h \
    source/cpp/QMLTree/QMLUnaryOperation.h \
    source/cpp/QMLTree/QMLBinaryOperation.h \
    source/cpp/QMLTree/QMLIf.h \
    source/cpp/QMLTree/QMLFor.h \
    source/cpp/QMLTree/QMLForIn.h \
    source/cpp/QMLTree/QMLSwitch.h \
    source/cpp/QMLTree/QMLConditional.h \
    source/cpp/QMLTree/QMLComment.h \
    source/cpp/QMLTree/QMLTreeContext.h \
    source/cpp/QMLTree/QMLAnalyzer.h \
    source/cpp/rsa/source/BigInt.h \
    source/cpp/rsa/source/Key.h \
    source/cpp/rsa/source/KeyPair.h \
    source/cpp/rsa/source/PrimeGenerator.h \
    source/cpp/rsa/source/RSA.h \
    source/cpp/roke/ROKE.h

SOURCES += \
    source/cpp/CSingletonPool.cpp \
    source/cpp/CDumpable.cpp \
    source/cpp/CXMLNodable.cpp \
    source/cpp/CXMLNode.cpp \
    source/cpp/CPIDController.cpp \
    source/cpp/CLogger.cpp \
    source/cpp/CMacroable.cpp \
    source/cpp/CTracableMutex.cpp \
    source/cpp/CTimeSampler.cpp \
    source/cpp/CMemoryMonitor.cpp \
    source/cpp/Image/CLargeMatrix.cpp \
    source/cpp/Image/CImageHistogram.cpp \
    source/cpp/Image/CImageUtilities.cpp \
    source/cpp/CSoundSynth.cpp \
    source/cpp/CSecureContext.cpp \
    source/cpp/CTDMADevice.cpp \
    source/cpp/CStreamFactory.cpp \
    source/cpp/CConnectedStream.cpp \
    source/cpp/CSocketStream.cpp \
    source/cpp/CSerialStream.cpp \
    source/cpp/File/CRollingFiles.cpp \
    source/cpp/RemoteControl/CRemoteControl.cpp \
    source/cpp/RemoteControl/CRemoteControlData.cpp \
    source/cpp/RemoteControl/CRemoteControlUser.cpp \
    source/cpp/Web/CMJPEGClient.cpp \
    source/cpp/Web/CMJPEGServer.cpp \
    source/cpp/Web/CWebComposer.cpp \
    source/cpp/Web/CWebContext.cpp \
    source/cpp/Web/CHTTPServer.cpp \
    source/cpp/Web/CHTTPRequestProcessor.cpp \
    source/cpp/Web/CDynamicHTTPServer.cpp \
    source/cpp/Web/WebControls/CWebButton.cpp \
    source/cpp/Web/WebControls/CWebControl.cpp \
    source/cpp/Web/WebControls/CWebDiv.cpp \
    source/cpp/Web/WebControls/CWebFactory.cpp \
    source/cpp/Web/WebControls/CWebLabel.cpp \
    source/cpp/Web/WebControls/CWebPage.cpp \
    source/cpp/Web/WebControls/CWebTextBox.cpp \
    source/cpp/Web/WebControls/CWebTextEdit.cpp \
    source/cpp/Web/WebControls/CWebFileInput.cpp \
    source/cpp/Web/WebControls/CWebModelControl.cpp \
    source/cpp/Web/WebControls/CWebListView.cpp \
    source/cpp/ISerializable.cpp \
    source/cpp/GeoTools/coordcnv.cpp \
    source/cpp/GeoTools/geocent.cpp \
    source/cpp/GeoTools/mgrs.cpp \
    source/cpp/GeoTools/polarst.cpp \
    source/cpp/GeoTools/tranmerc.cpp \
    source/cpp/GeoTools/ups.cpp \
    source/cpp/GeoTools/utm.cpp \
    source/cpp/GeoTools/UtmMgrs.cpp \
    source/cpp/GeoTools/geotrans.cpp \
    source/cpp/CGeoUtilities.cpp \
    source/cpp/QMLTree/QMLFormatter.cpp \
    source/cpp/QMLTree/QMLEntity.cpp \
    source/cpp/QMLTree/QMLComplexEntity.cpp \
    source/cpp/QMLTree/QMLNameValue.cpp \
    source/cpp/QMLTree/QMLIdentifier.cpp \
    source/cpp/QMLTree/QMLType.cpp \
    source/cpp/QMLTree/QMLFile.cpp \
    source/cpp/QMLTree/QMLImport.cpp \
    source/cpp/QMLTree/QMLPragma.cpp \
    source/cpp/QMLTree/QMLItem.cpp \
    source/cpp/QMLTree/QMLSpecialValue.cpp \
    source/cpp/QMLTree/QMLPropertyDeclaration.cpp \
    source/cpp/QMLTree/QMLPropertyAssignment.cpp \
    source/cpp/QMLTree/QMLPropertyAlias.cpp \
    source/cpp/QMLTree/QMLFunction.cpp \
    source/cpp/QMLTree/QMLFunctionCall.cpp \
    source/cpp/QMLTree/QMLFunctionParameter.cpp \
    source/cpp/QMLTree/QMLVariableDeclaration.cpp \
    source/cpp/QMLTree/QMLQualifiedExpression.cpp \
    source/cpp/QMLTree/QMLArrayAccess.cpp \
    source/cpp/QMLTree/QMLOnExpression.cpp \
    source/cpp/QMLTree/QMLUnaryOperation.cpp \
    source/cpp/QMLTree/QMLBinaryOperation.cpp \
    source/cpp/QMLTree/QMLIf.cpp \
    source/cpp/QMLTree/QMLFor.cpp \
    source/cpp/QMLTree/QMLForIn.cpp \
    source/cpp/QMLTree/QMLSwitch.cpp \
    source/cpp/QMLTree/QMLConditional.cpp \
    source/cpp/QMLTree/QMLComment.cpp \
    source/cpp/QMLTree/QMLTreeContext.cpp \
    source/cpp/QMLTree/QMLGrammarParser.cpp \
    source/cpp/QMLTree/QMLAnalyzer.cpp \
    source/cpp/rsa/source/BigInt.cpp \
    source/cpp/rsa/source/Key.cpp \
    source/cpp/rsa/source/KeyPair.cpp \
    source/cpp/rsa/source/PrimeGenerator.cpp \
    source/cpp/rsa/source/RSA.cpp \
    source/cpp/roke/ROKE.cpp

RESOURCES += \
    resources.qrc
