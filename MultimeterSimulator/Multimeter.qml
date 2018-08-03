import QtQuick 2.3
import App_Enum 1.0
Item {
    id: root

    property real _FACTOR: 5.5
    property int _FIX: -10

    property var stopRedPoint: [280/_FACTOR + bg.x,2519/_FACTOR  + bg.y]
    property var stopBlackPoint: [280/_FACTOR + bg.x,2943/_FACTOR  + bg.y]


    Rectangle{
        width: 2
        height: parent.height
        anchors.left: parent.left
        color: "black"
    }

    Image {
        id: bg
        y: _FIX
        anchors.horizontalCenter: parent.horizontalCenter
        source: ModelData.multimeter.soureBg
        width: Define.multiImg_sourcwWidth/_FACTOR
        height: Define.multiImg_sourcwHeight/_FACTOR
        mipmap: true
    }
    Image {
        id: pointer
        width: Define.multiPointerRaius/_FACTOR
        height: Define.multiPointerRaius/_FACTOR
        x: Define.multiPointerStartXPoint/_FACTOR
        y: bg.y + Define.multiPointerStartYPoint/_FACTOR
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

    Rectangle{
        width: 20
        height: 20
        radius: 10
        x: stopRedPoint[0] - 10
        y: stopRedPoint[1] - 10
        color: "#cc3300"
    }

    Rectangle{
        width: 20
        height: 20
        radius: 10
        x: stopBlackPoint[0] - 10
        y: stopBlackPoint[1] - 10
        color: "black"
    }

    Item{
        id: anchorIndicator
        x: bg.x + Define.indicatorXpoint/_FACTOR
        y: bg.y + Define.indicatorYpoint/_FACTOR
        width: 1
        height: 1
    }
    Item{
        id: indicator
        anchors.centerIn: anchorIndicator
        width: 1
        height: 460
        rotation: ModelData.multimeter.currentRotation
        Image{
            height: parent.height/2
            width: sourceSize.width/3
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            source: ModelData.multimeter.line
        }
        RotationAnimation on rotation {
            running: ModelData.multimeter.runningAnimation
            from: ModelData.multimeter.currentRotation
            to: ModelData.multimeter.nextRotation
            duration: ModelData.multimeter.animationDuration
            easing.type: Easing.InCirc
            onRunningChanged: {
                console.log("running: " + running)
                if(!running)
                {
                    ModelData.multimeter.currentRotation = ModelData.multimeter.nextRotation
                    ModelData.multimeter.runningAnimation = false
                }
            }
        }
    }
    Image {
        id: mask
        source: ModelData.multimeter.maskSource
        width: Define.maskWidth/_FACTOR
        height: Define.maskHeight/_FACTOR
        x: bg.x + Define.maskXpoint/_FACTOR
        y: bg.y + Define.maskYpoint/_FACTOR
    }
}
