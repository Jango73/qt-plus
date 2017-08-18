# qt-plus
Utility classes extending Qt's functionnality.

## Classes
The full documentation for classes is available after project build, in the <help> directory.

### QTree
Template for a tree structure. Each node has a value and 0 or more child nodes. <br>
May be used in a model where a variable can hold a scalar, a list or a tree.

### CSingleton
A template for singleton objects, based on the Singleton design pattern.

### CFactory
A template for a factory of objects, based on the Factory design pattern.

### CXMLNode
A helper class that wraps the XML and JSON facilities of Qt. Makes DOM style document easier to use.

### CLogger
A simple yet efficient logger.

### CImageUtilities
A singleton that provides helpful image processing functions.
Can do the following:
* Apply a filter matrix to a QImage
* Select pixels in a QImage by tint, results in a grayscale mask image
* Modify the HSV values of a QImage, using a mask QImage for pixel selection
* Colorize a QImage, using a mask QImage for pixel selection
* Split RGBA channels of a QImage
* Merge RGBA channels of several QImages
* Split HSVA channels of a QImage
* Merge HSVA channels of several QImages
* Find the dominant hue of a QImage
* Find the dominant luminance (value) of a QImage
* Compute the disparity map (depth) from two QImages (left and right eye)

### CImageHistogram
A class that contains the histogram of a QImage.

### CLargeMatrix
A class that can hold an NxN matrix. Used, among other things, for image filtering.

### QMLTreeContext
A full QML parser. <br>
Holds the contents of a QML file in the form of a tree, made of specialized items for each kind of QML and JS declarations. <br>
* Can recreate the original QML file from the statement tree, but currently throws comments away.
* Can convert the statement tree to XML.

### QMLAnalyzer
A class that allows static analysis of a QML statement tree (parsed using QMLTreeContext). <br>
Uses a grammar file in XML format that declares what to check and eventually reject.

### CHTTPServer
Implements the base functionalities of an HTTP server. Can be used to generate dynamic content.

### CMJPEGClient
A client for MJPEG streams. Notifies via signal whenever a new image arrives.

### CMJPEGServer
A server that creates an MJPEG stream for clients, based on CHTTPServer.

### CPIDController
A PID (Proportional Integral Derivative) controller for autopilots or mechanical controls.

### CAverager
A class used to make averages.

### CGeoUtilities
Contains methods to convert from geo coordinates (latitude, longitude, altitude) to cartesian coordinates (x, y, z) and back.

# Third party files

## beautify.js
Copyright (c) 2007-2017 Einar Lielmanis, Liam Newman, and contributors
