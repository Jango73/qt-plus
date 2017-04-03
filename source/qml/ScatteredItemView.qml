import QtQuick 2.0

/*!
     \ingroup ivi-2020-y0
     \brief An item that shows layers of a qml content.
*/

Item {
    id: root

    /*!
        Main font name.
    */
    property string fontFamily: "Arial"

    /*!
        When this is \c true, mouse area is active.
    */
    property bool mouseEnabled: true

    /*!
        When this is \c true, graph resfreshes every second in flat view.
    */
    property bool autoRefresh: false

    /*!
        When this is \c true, a help text is shown.
    */
    property bool showHelp: false

    /*!
        When this is \c true, the items are flat as if drawn by QtQuick.
    */
    property bool flatView: false

    /*!
        When this is \c true, the graph is at half opacity.
    */
    property bool seeThrough: false

    /*!
        This is the item from which we want to show layers.
    */
    property var targetItem: null

    /*!
        This is the list of accepted margins.
    */
    property var acceptedMargins: null

    /*!
        Color for unknown margin.
    */
    property var unknownMarginColor: "#FFFFFF"

    /*!
        The currently selected item.
    */
    property var selectedItem: null

    /*!
        An array containing wrappers of all qml items in targetItem.
    */
    property var complexItems: null

    /*!
        An array containing all the items that are parents of the currently selected item.
    */
    property var selectedItemParents: []

    /*!
        An array containing all the items that are children of the currently selected item.
    */
    property var selectedItemChildren: []

    /*!
        If this is \c true, the component is active and visible.
    */
    property bool exploded: false

    /*!
        The zoom factor for the graph.
    */
    property real zoomFactor: 1.0

    /*!
        This is a factor for the space seperating every layer.
    */
    property real levelFactor: 0.03

    /*!
        When this is \c true, the component will rebuild its item tree (complexItems).
    */
    property bool needRefresh: true;

    /*!
        When this is \c true, the graph will show invisible items.
    */
    property bool includeInvisibleItems: false

    /*!
        When this is \c true, the graph will show only the currently selected item and its parents and children.
    */
    property bool isolateSelectedItem: false

    /*!
        When this is \c true, the graph will show items.
    */
    property bool showItems: true

    /*!
        When this is \c true, the graph will show only the mouse areas.
    */
    property bool showOnlyMouseAreas: false

    /*!
        When this is \c true, the graph will show margins.
    */
    property bool showMargins: false

    /*!
        This is the Y rotation of the camera which visualizes the graph.
    */
    property real cameraRotationY: -Math.PI * 0.25

    /*!
        This is the X rotation of the camera which visualizes the graph.
    */
    property real cameraRotationX: -Math.PI * 0.25

    property real scaleX: targetItem !== null ? width / targetItem.width : 1.0
    property real scaleY: targetItem !== null ? height / targetItem.height : 1.0

    /*!
        Used internally.
    */
    property real xOffset: width * 0.4

    /*!
        Used internally.
    */
    property real yOffset: height * 0.5

    /*!
        Used internally.
    */
    property int stopAtLevel: 999999

    /*!
        Used internally.
    */
    property int maxLevel: 0

    /*!
        Used internally.
    */
    property real maxRotation: Math.PI * 0.5

    //-------------------------------------------------------------------------------------------------
    // Property related events

    onExplodedChanged: {
        if (root.exploded) {
            root.needRefresh = true
            graph.requestPaint();
        }
    }

    onTargetItemChanged: {
        if (root.exploded) {
            root.needRefresh = true
            graph.requestPaint();
        }
    }

    onFlatViewChanged: {
        if (root.flatView) {
            root.stopAtLevel = 999999
            root.needRefresh = true
            graph.requestPaint();
        }
    }

    onShowItemsChanged: {
        if (root.exploded) {
            graph.requestPaint();
        }
    }

    onShowMarginsChanged: {
        if (root.exploded) {
            graph.requestPaint();
        }
    }

    onSeeThroughChanged: {
        if (root.seeThrough) {
            graph.requestPaint();
        }
    }

    //-------------------------------------------------------------------------------------------------
    // Items

    Rectangle {
        id: graphContainer
        anchors.fill: parent
        visible: root.exploded
        color: "black"
        opacity: root.seeThrough ? 0.5 : 1.0

        onVisibleChanged:
        {
            if (visible) {
                graph.requestPaint()
            }
        }

        Canvas {
            id: graph
            anchors.fill: parent

            onPaint: {
                if (root.targetItem !== null)
                {
                    var context = getContext("2d");

                    if (root.cameraRotationX < -maxRotation) root.cameraRotationX = -maxRotation;
                    if (root.cameraRotationX >  maxRotation) root.cameraRotationX =  maxRotation;
                    if (root.cameraRotationY < -maxRotation) root.cameraRotationY = -maxRotation;
                    if (root.cameraRotationY >  maxRotation) root.cameraRotationY =  maxRotation;

                    // Save context current tranfsorm
                    context.save();

                    context.fillStyle = "#404040";
                    context.fillRect(0, 0, width, height);
                    context.font = "10px " + root.fontFamily;

                    context.scale(scaleX, scaleY);

                    if (root.needRefresh) {
                        root.needRefresh = false;
                        root.complexItems = getVisibleItemList(root.targetItem);
                        gc();
                    }

                    prepareExplodedItems(context, root.complexItems);

                    root.complexItems.sort(function(a, b)
                    {
                        if (a.level === b.level)
                        {
                            return a.item.z - b.item.z;
                        }

                        return a.level - b.level;
                    });

                    drawExplodedItems(context, root.complexItems);
                    showKeys(context);

                    // Restore context original tranfsorm
                    context.restore();
                }
            }
        }
    }

    Rectangle {
        width: parent.width * 0.5
        height: parent.height * 0.3
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        visible: root.exploded && root.width > 400 && root.height > 400 && root.showHelp
        color: "black"
        border.color: "white"
        border.width: 2

        Text {
            id: info
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "white"
            font.pixelSize: 15
        }
    }

    Timer {
        id: timer
        interval: 1000
        running: root.exploded && root.autoRefresh && root.flatView
        repeat: true
        onTriggered: {
            var target = root.targetItem;
            root.targetItem = null;
            root.targetItem = target;
        }
    }

    MouseArea {
        id: mouseArea
        width: root.exploded ? parent.width : 2
        height: root.exploded ? parent.height : 2
        propagateComposedEvents: true
        hoverEnabled: true
        enabled: root.visible && root.mouseEnabled && root.flatView === false

        Component.onCompleted: forceActiveFocus()

        property bool dragging: false;
        property real startX;
        property real startY;

        onClicked:
        {
            var newSelectedItem = getClickedItem(mouse);

            if (root.isolateSelectedItem)
            {
                if (newSelectedItem !== null)
                {
                    root.selectedItem = newSelectedItem;
                }
            }
            else
            {
                root.selectedItem = newSelectedItem;
            }

            getSelectedItemParents();
            getSelectedItemChildren();
            graph.requestPaint();
        }

        /*
        onPressed:
        {
            if (mouse.button === Qt.RightButton)
            {
                dragging = true;
                startX = mouse.x;
                startY = mouse.y;
            }
        }

        onReleased:
        {
            if (dragging)
            {
                dragging = false;
            }
            else
            {
                var newSelectedItem = getClickedItem(mouse);

                if (root.isolateSelectedItem)
                {
                    if (newSelectedItem !== null)
                    {
                        root.selectedItem = newSelectedItem;
                    }
                }
                else
                {
                    root.selectedItem = newSelectedItem;
                }

                getSelectedItemParents();
                getSelectedItemChildren();
                graph.requestPaint();
            }
        }

        onPositionChanged:
        {
            if (dragging)
            {
                var deltaX = mouse.x - startX;
                var deltaY = mouse.y - startY;

                cameraRotationY += deltaX * 0.01;
                cameraRotationX += deltaY * 0.01;

                startX = mouse.x;
                startY = mouse.y;

                graph.requestPaint();
            }
        }
        */

        Keys.onPressed:
        {
            if (root.stopAtLevel > root.maxLevel + 1)
            {
                root.stopAtLevel = root.maxLevel + 1;
            }

            if (event.key === Qt.Key_Space)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.exploded = root.exploded ? false : true;

                    if (root.exploded) {
                        root.needRefresh = true;
                    }
                }
            }
            else if (event.key === Qt.Key_Tab)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.flatView = true;
                    root.showItems = false;
                    root.showMargins = true;
                    root.seeThrough = true;
                    root.stopAtLevel = 999999;
                    root.exploded = !root.exploded;
                }
            }
            else if (event.key === Qt.Key_Plus)
            {
                root.zoomFactor += 0.1;
                graph.requestPaint();
            }
            else if (event.key === Qt.Key_Minus)
            {
                root.zoomFactor -= 0.1;
                graph.requestPaint();
            }
            else if (event.key === Qt.Key_Right)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.cameraRotationY += Math.PI * 0.125;
                    graph.requestPaint();
                }
                else
                {
                    root.xOffset -= root.width * 0.1;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_Left)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.cameraRotationY -= Math.PI * 0.125;
                    graph.requestPaint();
                }
                else
                {
                    root.xOffset += root.width * 0.1;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_Up)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.cameraRotationX -= Math.PI * 0.125;
                    graph.requestPaint();
                }
                else
                {
                    root.yOffset += root.height * 0.1;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_Down)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.cameraRotationX += Math.PI * 0.125;
                    graph.requestPaint();
                }
                else
                {
                    root.yOffset -= root.height * 0.1;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_Asterisk)
            {
                root.levelFactor += 0.01;
                if (root.levelFactor > 0.06)
                {
                    root.levelFactor = 0.06;
                }
                graph.requestPaint();
            }
            else if (event.key === Qt.Key_Slash)
            {
                root.levelFactor -= 0.01;
                if (root.levelFactor < 0.0)
                {
                    root.levelFactor = 0.0;
                }
                graph.requestPaint();
            }
            else if (event.key === Qt.Key_PageDown)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.stopAtLevel = 0;
                } else {
                    root.stopAtLevel -= 1;
                }
                if (root.stopAtLevel < 1) root.stopAtLevel = 1;
                graph.requestPaint();
            }
            else if (event.key === Qt.Key_PageUp)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.stopAtLevel = root.maxLevel + 1;
                } else {
                    root.stopAtLevel += 1;
                }
                if (root.stopAtLevel > root.maxLevel + 1) root.stopAtLevel = root.maxLevel + 1;
                graph.requestPaint();
            }
            else if (event.key === Qt.Key_T)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.showItems = !root.showItems;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_V)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.includeInvisibleItems = !root.includeInvisibleItems;
                    root.needRefresh = true;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_I)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.isolateSelectedItem = !root.isolateSelectedItem;
                    root.needRefresh = true;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_R)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.needRefresh = true;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_A)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.showOnlyMouseAreas = !root.showOnlyMouseAreas;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_M)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.showMargins = !root.showMargins;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_F)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.flatView = !root.flatView;
                    root.needRefresh = true;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_S)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.seeThrough = !root.seeThrough;
                    graph.requestPaint();
                }
            }
            else if (event.key === Qt.Key_H)
            {
                if (event.modifiers & Qt.ControlModifier)
                {
                    root.showHelp = !root.showHelp;
                }
            }
        }
    }

    //-------------------------------------------------------------------------------------------------

    function getClickedItem(mouse)
    {
        var globalMouse = mouseArea.mapToItem(root.targetItem, mouse.x, mouse.y);

        for (var i = root.complexItems.length - 1; i >= 0 ; i--)
        {
            var complexItem = root.complexItems[i];

            if (complexItem.level < root.stopAtLevel)
            {
                var isSelectedItem = (complexItem.item === root.selectedItem);
                var isParentOfSelectedItem = arrayContains(root.selectedItemParents, complexItem.item);
                var isChildOfSelectedItem = arrayContains(root.selectedItemChildren, complexItem.item);

                if (root.isolateSelectedItem === false || isSelectedItem || isParentOfSelectedItem || isChildOfSelectedItem)
                {
                    var text = className(complexItem.item);
                    var isItem = stringContains(text, "QQuickItem");
                    var isMouseArea = (stringContains(text, "MouseArea") || stringContains(text, "TouchArea"));

                    if (root.showOnlyMouseAreas === false || isMouseArea)
                    {
                        if (pointInPolygon(complexItem.path, globalMouse))
                        {
                            return complexItem.item;
                        }
                    }
                }
            }
        }

        return null;
    }

    //-------------------------------------------------------------------------------------------------

    function getVisibleItemList(item)
    {
        var items = [];
        root.maxLevel = 0;

        getVisibleItemListRecurse(items, item, 0);

        return items;
    }

    function getVisibleItemListRecurse(complexItems, item, level)
    {
        if (item !== root && (root.includeInvisibleItems || (item.visible && item.opacity > 0)))
        {
            if (level > root.maxLevel)
            {
                root.maxLevel = level;
            }

            var complexItem = { item: item, level: level, path: [], margins: [] };
            complexItems.push(complexItem);

            for (var i = 0; i < item.children.length; i++)
            {
                getVisibleItemListRecurse(complexItems, item.children[i], level + 1);
            }
        }
    }

    function getSelectedItemParents()
    {
        root.selectedItemParents = [];

        if (root.selectedItem !== null)
        {
            var parent = root.selectedItem.parent;

            while (parent !== null)
            {
                root.selectedItemParents.push(parent);
                parent = parent.parent;
            }
        }
    }

    function getSelectedItemChildren()
    {
        root.selectedItemChildren = [];

        if (root.selectedItem !== null)
        {
            getSelectedItemChildrenRecurse(root.selectedItem);
        }
    }

    function getSelectedItemChildrenRecurse(item)
    {
        for (var i = 0; i < item.children.length; i++)
        {
            var child = item.children[i];
            root.selectedItemChildren.push(child);
            getSelectedItemChildrenRecurse(child);
        }
    }

    //-------------------------------------------------------------------------------------------------

    function rotateY(point, angle)
    {
        var newPoint = { x: 0.0, y: 0.0, z: 0.0 };

        var mat0 = { x: Math.cos(angle), y: 0.0, z: Math.sin(angle) };
        var mat1 = { x: 0.0, y: 1.0, z: 0.0 };
        var mat2 = { x: Math.sin(angle), y: 0.0, z: Math.cos(angle) };

        newPoint.x = mat0.x * point.x + mat1.x * point.y + mat2.x * point.z;
        newPoint.y = mat0.y * point.x + mat1.y * point.y + mat2.y * point.z;
        newPoint.z = mat0.z * point.x + mat1.z * point.y + mat2.z * point.z;

        return newPoint;
    }

    function rotateX(point, angle)
    {
        var newPoint = { x: 0.0, y: 0.0, z: 0.0 };

        var mat0 = { x: 1.0, y: 0.0, z: 0.0 };
        var mat1 = { x: 0.0, y: Math.cos(angle), z: -Math.sin(angle) };
        var mat2 = { x: 0.0, y: Math.sin(angle), z: Math.cos(angle) };

        newPoint.x = mat0.x * point.x + mat1.x * point.y + mat2.x * point.z;
        newPoint.y = mat0.y * point.x + mat1.y * point.y + mat2.y * point.z;
        newPoint.z = mat0.z * point.x + mat1.z * point.y + mat2.z * point.z;

        return newPoint;
    }

    function prepareExplodedItems(context, complexItems)
    {
        for (var i = 0; i < complexItems.length; i++)
        {
            prepareExplodedItem(context, complexItems[i]);
        }
    }

    function prepareExplodedItem(context, complexItem)
    {
        var margin;
        var newMarginItem;
        var global1 = complexItem.item.mapToItem(root.targetItem, 0, 0);
        var global2 = complexItem.item.mapToItem(root.targetItem, complexItem.item.width, complexItem.item.height);

        var levelOffset = complexItem.level * (root.width * root.levelFactor) * root.zoomFactor;

        complexItem.path = [];
        complexItem.margins = [];

        complexItem.path.push( { x: global1.x, y: global1.y, z: levelOffset } );
        complexItem.path.push( { x: global2.x, y: global1.y, z: levelOffset  } );
        complexItem.path.push( { x: global2.x, y: global2.y, z: levelOffset  } );
        complexItem.path.push( { x: global1.x, y: global2.y, z: levelOffset  } );

        for (var i = 0; i < complexItem.path.length; i++)
        {
            complexItem.path[i] = projectCoordinates(complexItem.path[i]);
        }

        // Margins
        if (complexItem.item.anchors.topMargin !== 0)
        {
            margin = complexItem.item.anchors.topMargin;
            global1 = complexItem.item.mapToItem(root.targetItem, 0, -margin);
            global2 = complexItem.item.mapToItem(root.targetItem, complexItem.item.width, 0);

            newMarginItem = { size: margin, path: [] }

            newMarginItem.path.push( { x: global1.x, y: global1.y, z: levelOffset } );
            newMarginItem.path.push( { x: global2.x, y: global1.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global2.x, y: global2.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global1.x, y: global2.y, z: levelOffset  } );

            for (i = 0; i < newMarginItem.path.length; i++)
            {
                newMarginItem.path[i] = projectCoordinates(newMarginItem.path[i]);
            }

            // console.log("Adding top margin");

            complexItem.margins.push(newMarginItem);
        }

        if (complexItem.item.anchors.bottomMargin !== 0)
        {
            margin = complexItem.item.anchors.bottomMargin;
            global1 = complexItem.item.mapToItem(root.targetItem, 0, complexItem.item.height);
            global2 = complexItem.item.mapToItem(root.targetItem, complexItem.item.width, complexItem.item.height + margin);

            newMarginItem = { size: margin, path: [] }

            newMarginItem.path.push( { x: global1.x, y: global1.y, z: levelOffset } );
            newMarginItem.path.push( { x: global2.x, y: global1.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global2.x, y: global2.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global1.x, y: global2.y, z: levelOffset  } );

            for (i = 0; i < newMarginItem.path.length; i++)
            {
                newMarginItem.path[i] = projectCoordinates(newMarginItem.path[i]);
            }

            // console.log("Adding bottom margin");

            complexItem.margins.push(newMarginItem);
        }

        if (complexItem.item.anchors.leftMargin !== 0)
        {
            margin = complexItem.item.anchors.leftMargin;
            global1 = complexItem.item.mapToItem(root.targetItem, -margin, 0);
            global2 = complexItem.item.mapToItem(root.targetItem, 0, complexItem.item.height);

            newMarginItem = { size: margin, path: [] }

            newMarginItem.path.push( { x: global1.x, y: global1.y, z: levelOffset } );
            newMarginItem.path.push( { x: global2.x, y: global1.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global2.x, y: global2.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global1.x, y: global2.y, z: levelOffset  } );

            for (i = 0; i < newMarginItem.path.length; i++)
            {
                newMarginItem.path[i] = projectCoordinates(newMarginItem.path[i]);
            }

            // console.log("Adding left margin");

            complexItem.margins.push(newMarginItem);
        }

        if (complexItem.item.anchors.rightMargin !== 0)
        {
            margin = complexItem.item.anchors.rightMargin;
            global1 = complexItem.item.mapToItem(root.targetItem, complexItem.item.width, 0);
            global2 = complexItem.item.mapToItem(root.targetItem, complexItem.item.width + margin, complexItem.item.height);

            newMarginItem = { size: margin, path: [] }

            newMarginItem.path.push( { x: global1.x, y: global1.y, z: levelOffset } );
            newMarginItem.path.push( { x: global2.x, y: global1.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global2.x, y: global2.y, z: levelOffset  } );
            newMarginItem.path.push( { x: global1.x, y: global2.y, z: levelOffset  } );

            for (i = 0; i < newMarginItem.path.length; i++)
            {
                newMarginItem.path[i] = projectCoordinates(newMarginItem.path[i]);
            }

            // console.log("Adding right margin");

            complexItem.margins.push(newMarginItem);
        }
    }

    function projectCoordinates(coords)
    {
        if (root.flatView === false)
        {
            coords = rotateX(coords, root.cameraRotationX);
            coords = rotateY(coords, root.cameraRotationY);

            coords.x *= root.zoomFactor;
            coords.y *= root.zoomFactor;

            coords.x += root.xOffset;
            coords.y += root.yOffset;

            // complexItem.path[i].x /= complexItem.path[i].z;
            // complexItem.path[i].y /= complexItem.path[i].z;

            // complexItem.path[i].x *= root.height * 0.5;
            // complexItem.path[i].y *= root.height * 0.5;
        }

        return coords;
    }

    //-------------------------------------------------------------------------------------------------

    function drawExplodedItems(context, complexItems)
    {
        for (var i = 0; i < complexItems.length; i++)
        {
            drawExplodedItem(context, complexItems[i]);
        }
    }

    function drawExplodedItem(context, complexItem)
    {
        if (complexItem.level < root.stopAtLevel)
        {
            var isSelectedItem = (complexItem.item === root.selectedItem);
            var isParentOfSelectedItem = arrayContains(root.selectedItemParents, complexItem.item);
            var isChildOfSelectedItem = arrayContains(root.selectedItemChildren, complexItem.item);

            var text = className(complexItem.item);
            var isItem = stringContains(text, "QQuickItem");
            var isMouseArea = (stringContains(text, "MouseArea") || stringContains(text, "TouchArea"));
            var shade = ((complexItem.level / root.maxLevel) * 0.6) + 0.2;
            var shadeComplement = shade * 0.25;
            var fillAlpha = 1;
            var showMe = true;
            var showMyMargins = true;

            // Decide if item is to be shown based on the showItems flag
            if (root.showItems === false)
                showMe = false;

            // Decide if item is to be shown based on the showOnlyMouseAreas flag
            if (root.showOnlyMouseAreas)
                if (!isMouseArea)
                    showMe = false;

            // Decide if item is to be shown based on the flatView flag
            if (root.flatView)
            {
                if (isMouseArea)
                    showMe = false;

                if (isItem)
                    showMe = false;

                if (complexItem.item.objectName === "")
                    showMe = false;
            }

            // Decide if item is to be shown based on isolation
            if (!(root.isolateSelectedItem === false || isSelectedItem || isParentOfSelectedItem || isChildOfSelectedItem))
            {
                showMe = false;
            }

            // Decide if margins are to be shown
            if (root.showMargins === false)
            {
                showMyMargins = false;
            }

            if (showMe)
            {
                if (isItem || isMouseArea)
                    if (root.flatView === false)
                        fillAlpha = 0;

                if (root.flatView)
                {
                    context.strokeStyle = "#FFFFFF";
                    context.fillStyle = Qt.rgba(shade, shade, shade, 0.0);
                    context.lineWidth = 1;
                }
                else
                {
                    context.strokeStyle = "#000000";
                    context.fillStyle = Qt.rgba(shade, shade, shade, fillAlpha);
                    context.lineWidth = 1;

                    if (isSelectedItem)
                    {
                        context.fillStyle = Qt.rgba(shade, shadeComplement, shadeComplement, 1);
                        context.strokeStyle = context.fillStyle;
                    }
                    else if (isParentOfSelectedItem && root.isolateSelectedItem === false)
                    {
                        context.fillStyle = Qt.rgba(shadeComplement, shadeComplement, shade, fillAlpha);
                        context.strokeStyle = context.fillStyle;
                    }
                    else if (isChildOfSelectedItem && root.isolateSelectedItem === false)
                    {
                        context.fillStyle = Qt.rgba(shadeComplement, shade, shadeComplement, fillAlpha);
                        context.strokeStyle = context.fillStyle;
                    }
                    else if (isItem)
                    {
                        context.strokeStyle = Qt.rgba(0.0, 0.0, 0.0, 1);
                        context.fillStyle = Qt.rgba(0.0, 0.0, 0.0, fillAlpha);
                    }
                    else if (isMouseArea)
                    {
                        context.strokeStyle = Qt.rgba(0.0, 1.0, 0.0, 1);
                        context.fillStyle = Qt.rgba(0.0, 0.0, 0.0, fillAlpha);
                    }

                    if (isMouseArea)
                    {
                        context.lineWidth = 3;
                    }
                }

                context.beginPath();
                context.moveTo(complexItem.path[0].x, complexItem.path[0].y);
                context.lineTo(complexItem.path[1].x, complexItem.path[1].y);
                context.lineTo(complexItem.path[2].x, complexItem.path[2].y);
                context.lineTo(complexItem.path[3].x, complexItem.path[3].y);
                context.lineTo(complexItem.path[0].x, complexItem.path[0].y);
                context.fill();
                context.stroke();

                if (shade < 0.4)
                {
                    context.strokeStyle = "#FFFFFF";
                }
                else
                {
                    context.strokeStyle = "#000000";
                }

                context.font = "10px " + root.fontFamily;

                context.fillStyle = context.strokeStyle;
                context.fillText(text, complexItem.path[0].x + 10, complexItem.path[0].y + 10);

                text = "(objectName: " + complexItem.item.objectName + " )";
                context.fillText(text, complexItem.path[0].x + 10, complexItem.path[0].y + 20);
            }

            // Margins
            if (showMyMargins)
            {
                context.fillStyle = root.unknownMarginColor;

                for (var i = 0; i < complexItem.margins.length; i++)
                {
                    if (root.acceptedMargins !== null && root.acceptedMargins.length > 0)
                    {
                        for (var s = 0; s < root.acceptedMargins.length; s++)
                        {
                            var diff = Math.abs(complexItem.margins[i].size - root.acceptedMargins[s].size);

                            if (diff < 0.2)
                            {
                                context.fillStyle = root.acceptedMargins[s].color;
                            }
                        }
                    }

                    context.beginPath();
                    context.moveTo(complexItem.margins[i].path[0].x, complexItem.margins[i].path[0].y);
                    context.lineTo(complexItem.margins[i].path[1].x, complexItem.margins[i].path[1].y);
                    context.lineTo(complexItem.margins[i].path[2].x, complexItem.margins[i].path[2].y);
                    context.lineTo(complexItem.margins[i].path[3].x, complexItem.margins[i].path[3].y);
                    context.lineTo(complexItem.margins[i].path[0].x, complexItem.margins[i].path[0].y);
                    context.fill();

                    /*
                    console.log("Margin: "
                                , complexItem.margins[i].path[0].x, complexItem.margins[i].path[0].y
                                , complexItem.margins[i].path[1].x, complexItem.margins[i].path[1].y
                                , complexItem.margins[i].path[2].x, complexItem.margins[i].path[2].y
                                , complexItem.margins[i].path[3].x, complexItem.margins[i].path[3].y
                                );
                                */

                    var point1 = { x: complexItem.margins[i].path[0].x, y: complexItem.margins[i].path[0].y }
                    var point2 = { x: complexItem.margins[i].path[2].x, y: complexItem.margins[i].path[2].y }
                    var center = { x: (point1.x + point2.x) * 0.5, y: (point1.y + point2.y) * 0.5 }

                    point1.x = center.x - 30;
                    point2.x = center.x + 30;

                    point1.y = center.y - 15;
                    point2.y = center.y + 15;

                    context.fillStyle = "#000000";
                    context.fillRect(point1.x, point1.y, point2.x - point1.x, point2.y - point1.y);

                    context.font = "25px " + root.fontFamily;

                    context.textAlign = "center";
                    context.textBaseline = "middle";
                    context.fillStyle = "#FFFFFF";
                    context.fillText(complexItem.margins[i].size, center.x, center.y);
                }
            }
        }
    }

    //-------------------------------------------------------------------------------------------------

    function showKeys(context)
    {
        var text1 = "-- KEYS --";
        var text2 = "Move: [arrows]  Rotate: [ CTRL + arrows ]  Zoom: [ + | - ]";
        var text3 = "Change level: [ page up | page down ]";
        var text4 = "Minimum level: [ CTRL + page down ]  Maximum level: [ CTRL + page up ]";
        var text5 = "Toggle show items: [ CTRL + T ]  Toggle show margins: [ CTRL + M ]  Toggle flat view: [ CTRL + F ]";
        var text6 = "Toggle show invisible items: [ CTRL + V ]  Toggle see through [ CTRL + S ]";
        var text7 = "Changer layer altitude: [ * | / ]";
        var text8 = "Toggle isolate selected item (and its tree): [ CTRL + I ]";
        var text9 = "";

        if (root.selectedItem !== null)
        {
            var point = root.selectedItem.mapToItem(root.targetItem, 0, 0);
            var size = root.selectedItem.mapToItem(root.targetItem, root.targetItem.width, root.targetItem.height);

            text9 = "Selected item (" + className(root.selectedItem) + ")"
                    + " objectName: " + root.selectedItem.objectName
                    + " X: " + point.x
                    + " Y: " + point.y
                    + " Z: " + root.selectedItem.z
                    + " Width: " + size.x
                    + " Height: " + size.y
                    + " Visible: " + root.selectedItem.visible
                    + " Enabled: " + root.selectedItem.enabled;
        }

        info.text = text1 + "\n" + text2 + "\n" + text3 + "\n" + text4 + "\n" + text5 + "\n" + text6 + "\n" + text7 + "\n" + text8 + "\n\n" + text9 + "\n";
    }

    //-------------------------------------------------------------------------------------------------

    function invertColor(hexTripletColor)
    {
        var color = hexTripletColor;
        color = color.substring(1);           // remove #
        color = parseInt(color, 16);          // convert to integer
        color = 0xFFFFFF ^ color;             // invert three bytes
        color = color.toString(16);           // convert to hex
        color = ("000000" + color).slice(-6); // pad with leading zeros
        color = "#" + color;                  // prepend #
        return color;
    }

    function stringContains(src, search)
    {
        return src.indexOf(search) !== -1;
    }

    function className(item)
    {
        var text = item.toString();

        text = text.split("_QMLTYPE_")[0];
        text = text.split("_QML")[0];
        text = text.split("(0x")[0];

        return text;
    }

    //-------------------------------------------------------------------------------------------------

    function pointInPolygon(points, test)
    {
        var i;
        var j;
        var c = 0;

        for (i = 0, j = points.length - 1; i < points.length; j = i++)
        {
            if ( ((points[i].y > test.y) != (points[j].y > test.y)) &&
                    (test.x < (points[j].x - points[i].x) * (test.y - points[i].y) / (points[j].y - points[i].y) + points[i].x) )
                c = !c;
        }

        return c;
    }

    function arrayContains(array, value)
    {
        for (var i = 0; i < array.length; i++) {
            if (array[i] === value) {
                return true;
            }
        }

        return false;
    }

    function hexToRgb(hex)
    {
        // Expand shorthand form (e.g. "03F") to full form (e.g. "0033FF")
        var shorthandRegex = "/^#?([a-f\d])([a-f\d])([a-f\d])$/i";
        hex = hex.replace(shorthandRegex, function(m, r, g, b) {
            return r + r + g + g + b + b;
        });

        var result = "/^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i".exec(hex);
        return result ? {
                            r: parseInt(result[1], 16),
                            g: parseInt(result[2], 16),
                            b: parseInt(result[3], 16)
                        } : null;
    }
}
