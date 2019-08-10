import QtQuick 2.12

Rectangle {
    id: root

    /*! Used internally. */
    property color mainColor: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)

    /*! Used internally. */
    property real maxSize: Math.min(width, height) * 0.1

    /*! Used internally. */
    property real fontSize: Math.min(15, maxSize * 0.5)

    anchors.fill: parent
    color: "transparent"
    border.color: mainColor
    border.width: 1
    z: 9999
    opacity: 0.75

    Rectangle {
        width: maxSize * 5
        height: maxSize
        anchors.top: parent.top
        anchors.left: parent.left
        color: mainColor

        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "" + toFixed(root.width, 2) + " x " + toFixed(root.height, 2)
            font.pixelSize: root.fontSize
        }
    }

    function toFixed(value, digits) {
        var power = Math.pow(10, digits || 0)
        return Math.round(value * power) / power
    }
}
