import QtQuick 2.0
import App_Enum 1.0
Item {
    id: root

    Rectangle{
        width: 2
        height: parent.height
        anchors.left: parent.left
        color: "black"
    }

    Image {
        id: bg
        y: 10
        anchors.horizontalCenter: parent.horizontalCenter
        source: ModelData.multimeter.soureBg
        width: Define.multiImg_sourcwWidth/6
        height: Define.multiImg_sourcwHeight/6
    }
    Rectangle{
        id: pointerMouse
        anchors.centerIn: pointer
        width: pointer.width + 60
        height: pointer.height +60
        radius: width/2
        color: "transparent"

        Repeater{
            model: 10
            Rectangle{
                id: rtg
                width: 25
                height: pointerMouse.width
                anchors.centerIn: pointerMouse
                color: "transparent"
                rotation: index * 18
                MouseArea{
                    id: upMouse
                    width: parent.width
                    height: parent.height/2
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    onClicked: {
                        ModelData.pointerMode = index
                    }
                }
                MouseArea{
                    id: downMouse
                    width: parent.width
                    height: parent.height/2
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    onClicked: {
                        ModelData.pointerMode = index + 10
                    }
                }
            }
        }
    }
    Image {
        id: pointer
        width: Define.multiPointerRaius/6
        height: Define.multiPointerRaius/6
        x: Define.multiPointerStartXPoint/6
        y: bg.y + Define.multiPointerStartYPoint/6
        source: ModelData.multimeter.sourcePointer
        anchors.horizontalCenter: parent.horizontalCenter
        rotation: ModelData.pointerMode * 18
        MouseArea{
            anchors.fill: parent
            propagateComposedEvents: true
        }

        Rectangle{
            anchors.centerIn: parent
            width: pointer.width - 10
            height: pointer.width - 10
            radius: width/2
            color: "transparent"
            MouseArea{
                anchors.fill: parent
                propagateComposedEvents: false
            }
        }
    }
}
