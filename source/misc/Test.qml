
import QtQuick 2.4                      // QtQuick
import QtQuick.Controls 1.4             // QtQuick.Controls
import QtQuick.Dialogs 1.0 as MyLib     // QtQuick.Dialogs

Item {
    id: root                                                                                    // Root

    property real prop1: root.prop8
    property real prop_2: 20                                                                    // Camel casing error
    property real prop3: 30
    property real prop4: 40
    property real Prop5: 50                                                                     // Camel casing error and unreferenced symbol
    property bool prop6: prop1 > 0 ? prop1 : prop_2 > 0 ? prop_2 : prop3 > 0 ? prop3 : prop4    // Nested conditionals error

    property string property: ""

    signal sig1(string someParameter1)
    signal sig2

    MyLib.ColorDialog {
        id: someID
    }

    states: [
        State {
            name: "state1"
            PropertyChanges {
                target: root
                property: "foobar"
            }
        }
    ]

    property variant prop7: []                                                                  // Unreferenced symbol
    property int prop8: 88

    function func1(someParameter1, someParameter2) {
        // Comment 1
        var someVariable1 = 10, someVariable2 = 20;

        // Comment 2
        var someVariable3 = 30, someVariable4 = 40;
        var someVariable5 = 50;
        var someVariable6 = 60;
        var SomeVariable7 = 70;                                                                 // Camel casing error and unreferenced symbol

        // Too many nested ifs error
        if (someVariable1 > 0) {
            if (someVariable2 > 0) {
                if (someVariable3 > 0) {
                    if (someVariable4 > 0) {
                        if (someVariable5 > 0) {
                            if (someVariable6 > 0) {
                                someParameter1 = someParameter2
                            }
                        }
                    }
                }
            }
        }

        // Comment 3
        someVariable1 += 10;
        someVariable2 += 10;
        someVariable3 += 10;
        someVariable4 += 10;
        someVariable5 += 10;
        someVariable6 += 10;
    }

    // Camel casing error
    function Func2(someParameter1, someParameter2) {
        var someVariable1 = 10, someVariable2 = 20;         // Unreferenced symbol

        prop6 = Math.ceil(5.2);

        // Comment 4
        var date = new Date;
        prop6 = date.getMinutes();

        while (prop6 !== null) {
            func3(0.5 * prop6);
        }
    }

    //-----------------------------------------------------------------------------
    // Unreferenced parameter
    // Single line comment
    function func3(someParameter1) {
        return { x: 0, y: 0 }
    }

    function getVisibleItemList(item)
    {
        // Comment 5
        var complexItems = [];
        getVisibleItemListRecurse(complexItems, item, 0);
        return complexItems;
    }

    function getVisibleItemListRecurse(complexItems, item, level)
    {
        // Comment 6
        if (item !== root)
        {
            var complexItem = { item: item, level: level, path: [] };
            complexItems.push(complexItem);

            // Comment 7
            for (var i = 0; i < item.children.length; i++)
            {
                var returnValue = getVisibleItemListRecurse(complexItems, item.children[i], level + 1);

                if (returnValue !== null)
                    return returnValue;
            }
        }

        return null;
    }

    function Func4()
    {
        while (true)
        {
            var foo1 = 1;
            var bar1 = foo1;
        }
        while (true)
        {
            var foo2 = 1;
            var bar2 = foo2;
        }
    }
}
