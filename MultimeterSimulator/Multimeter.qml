import QtQuick 2.0
import App_Enum 1.0
Item {
    id: root

    property var stopRedPoint: [280/6 + bg.x,2519/6 + bg.y]
    property var stopBlackPoint: [280/6 + bg.x,2943/6 +bg.y]


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
    }
    Rectangle{
        id: pointerMouse
        anchors.centerIn: pointer
        width: pointer.width + 60
        height: pointer.height +60
        radius: width/2
        color: "transparent"

        Rectangle {
            id: center
            anchors.centerIn: pointerMouse
            width: 1
            height: 1
            color: "red"
        }

        Repeater{
            model: 10
            Rectangle{
                id: rtg
                width: 25
                height: pointerMouse.width
                anchors.centerIn: pointerMouse
                color: "transparent"
                rotation: index * 18
                Rectangle{
                    id: upMouse
                    width: parent.width
                    height: parent.height/2
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    color: "transparent"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            var radius = Math.abs(mouseY - center.y);
                            console.log("Radius: " + radius)
                            if(radius >= pointer.width/2 && radius <= pointerMouse.width/2){
                                ModelData.pointerMode = index
                            }
                        }
                    }
                }
                Rectangle{
                    id: downMouse
                    width: parent.width
                    height: parent.height/2
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    color: "transparent"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            var radius = Math.abs(mouseY/* - center.y*/);
                            console.log("Radius: " + radius)
                            if(radius >= pointer.width/2 && radius <= pointerMouse.width/2){
                                ModelData.pointerMode = index + 10
                            }
                        }
                    }
                }
            }
        }
    }
}
