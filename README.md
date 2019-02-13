# qt-plus
Utility classes extending Qt's functionnality.

## Classes
The full documentation for classes is available after project build, in the <help> directory.

### QTree
Template for a tree structure. Each node has a value and 0 or more child nodes.  
May be used in a model where a variable can hold a scalar, a list or a tree.

### CSingleton
A template for singleton objects, based on the Singleton design pattern.

### CFactory
A template for a factory of objects, based on the Factory design pattern.

### CXMLNode
A helper class that wraps the *XML* and *JSON* facilities of Qt. Makes *DOM* style documents easier to use.

### CLogger
A simple yet efficient logger.

### CImageUtilities
A singleton that provides helpful image processing functions.
Can do the following:
* Apply a filter matrix to a *QImage*
* Select pixels in a *QImage* by tint, resulting in a grayscale mask image
* Modify the HSV values of a *QImage*, using a *QImage* mask for pixel selection
* Colorize a *QImage*, using a *QImage* mask for pixel selection
* Split RGBA channels of a *QImage*
* Merge RGBA channels of several *QImage*s
* Split HSVA channels of a *QImage*
* Merge HSVA channels of several *QImage*s
* Find the dominant hue of a *QImage*
* Find the dominant luminance (value) of a *QImage*
* Compute the disparity map (depth) from two *QImage*s (left and right eye)

### CImageHistogram
A class that contains the histogram of a *QImage*.

### CLargeMatrix
A class that can hold an NxN matrix. Used, among other things, for image filtering.

### QMLTreeContext
A full *QML* parser. <br>
Holds the contents of a *QML* file in the form of a tree, made of specialized classes for each kind of *QML* and JS declarations. <br>
* Can recreate the original *QML* file from the statement tree, **but currently throws comments away**. (To be fixed in a near future)
* Can convert the statement tree to *XML*.

### QMLAnalyzer
A class that allows static analysis of a *QML* statement tree (parsed using *QMLTreeContext*).  
Uses a grammar file in *XML* format that declares what to check and eventually reject.

### CHTTPServer
Implements the base functionalities (GET and POST) of an *HTTP* server (see RFC 7230).  
Can do the following:
* Handles GET and POST requests (maybe more in the future)
* Serve local file ressources
* Define the accessible folders for ressources
* Generate dynamic *HTML* content via overridden methods.
* More or less efficient flood protection (has not been tested on large scale)

### CDynamicHTTPServer
Implements the base functionalities of a web server that generates dynamic HTML content.
A subclass of CDynamicHTTPServer may generate content in two ways:
* Using a CWebComposer to generate HTML tags in a string
* Using a CWebFactory to generate a CWebPage, which is a container of CWebControls

The second method works like ASP, with a view state that enables to transfer a serialized, compressed and eventually crypted (when someone codes it) version of the CWebPage between server and client. See the documentation of CWebPage for more information.

### CMJPEGClient
A client for *MJPEG* streams. Notifies via signal whenever a new image arrives.

### CMJPEGServer
A server that creates an *MJPEG* stream for clients, based on *CHTTPServer*.

### CTDMADevice
A class that mimics the *TDMA* concept. But instead of devices auto-synchronizing themselves, a master device does it.  
Can be used to transfer data from master <-> slave on a network with a single data channel.  
Inherits *QIODevice* and uses a *QIODevice* instance for input and output.

### CPIDController
A *PID* (Proportional Integral Derivative) controller for autopilots or mechanical controls.

### CAverager
A template used to average values.

### CGeoUtilities
Contains methods to convert from geo coordinates (latitude, longitude, altitude) to cartesian coordinates (x, y, z) and back.

# Third party files

## beautify.js
Copyright (c) 2007-2017 Einar Lielmanis, Liam Newman, and contributors
