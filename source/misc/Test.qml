import QtQuick 2.4
import QtQuick.Controls 1.4

Item {
    id: root

    property real prop1: 10;
    property real prop_2: 20;   // Camel casing error
    property real prop3: 30
    property real prop4: 40
    property real Prop5: 50   // Camel casing error and unreferenced symbol

    // Nested conditionals error
    property bool prop6: prop1 > 0 ? prop1 : Prop_2 > 0 ? Prop_2 : prop3 > 0 ? prop3 : prop4;
    property variant prop7: []

    function func1(someParameter1, someParameter2) {
        var someVariable1 = 10, someVariable2 = 20;
        var someVariable3 = 30, someVariable4 = 40;
        var someVariable5 = 50;
        var someVariable6 = 60;
        var SomeVariable7 = 70;   // Camel casing error and unreferenced symbol

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

        someVariable1 += 10;
        someVariable2 += 10;
        someVariable3 += 10;
        someVariable4 += 10;
        someVariable5 += 10;
        someVariable6 += 10;
    }

    // Camel casing error
    function Func2(someParameter1) {
        var someVariable1 = 10, someVariable2 = 20; // Unreferenced symbols

        prop1 = 20;
    }
}
