import QtQuick 2.3
import App_Enum 1.0


Item{
    id: root

    property var stopRedPoint: [0,0]
    property var stopBlackPoint: [0,0]
    property bool bothWireAtSamePos: Math.abs(redPointer.x - blackPointer.x) < 5 && Math.abs(redPointer.y - blackPointer.y)
    signal redWireChangingPos(int posX, int posY)
    signal blackWireChangingPos(int posX, int posY)
    signal redWireRelesedPos()
    signal blackWireRelesedPos()

    property alias redPointer: redPointer
    property alias blackPointer: blackPointer

    property alias redCanvas: redCanvas
    property alias blackCanvas: blackCanvas


    Image{
        id: redPointer
        width: sourceSize.width/2
        height: sourceSize.height/2
        source: ModelData.multimeter.redSourceImg
        x: root.width - 500
        y: root.height - 500
        Rectangle{
            anchors.verticalCenter: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: 1
            width: parent.width/2
            height: 10
            radius: 10
            color: "#cc3300"
        }

        Rectangle{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            width: 10
            height: width
            radius: width/2
            color: "#B87333"
            visible: bothWireAtSamePos
        }

        MouseArea{
            id: redMouse
            anchors.fill: parent
            drag.target: parent
            drag.minimumX: 0//parent.width
            drag.maximumX: root.width - Define.multiMeterWidth - 50
            drag.minimumY: 0
            drag.maximumY: root.height - parent.height
            onPressed: {
                redPointer.z = 10
                redPointer.z = 11
                blackCanvas.z = 5
                blackCanvas.z = 6
            }

            onPositionChanged: {
                redCanvas.requestPaint()
                redWireChangingPos(redPointer.x + redPointer.width/2, redPointer.y)
            }
            onReleased: {
                redWireRelesedPos()
            }
        }
    }

    Canvas {

        id: redCanvas;
        anchors.fill: parent
        z: 1000

        property var startRedPoint: [redPointer.x + redPointer.width/2,redPointer.y + redPointer.height]

        onPaint: {
            var ctx = redCanvas.getContext("2d");
            ctx.reset()
            ctx.clearRect(0,0, width, height);

            ctx.strokeStyle = "#cc3300";
            ctx.lineWidth = 5;
            ctx.beginPath();
            ctx.moveTo(startRedPoint[0], startRedPoint[1]);
//            for (var i=1; i<20; i++) {
                //              ctx.bezierCurveTo(xPos(j-0.5),yPos(i,j-1),xPos(j-0.5),yPos(i,j),xPos(j),yPos(i,j));
                ctx.lineTo(root.stopRedPoint[0],root.stopRedPoint[1]);
//            }

            ctx.stroke();
        }
    }

    Image{
        id: blackPointer
        width: sourceSize.width/2
        height: sourceSize.height/2
        source: ModelData.multimeter.blackSourceImg
        x: root.width - 550
        y: root.height - 500

        Rectangle{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            width: 10
            height: width
            radius: width/2
            color: "#B87333"
            visible: bothWireAtSamePos
        }

        Rectangle{
            anchors.verticalCenter: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: 1
            width: parent.width/2
            height: 10
            radius: 10
            color: "black"
        }
        MouseArea{
            id: blueMouse
            anchors.fill: parent
            drag.target: parent
            drag.minimumX: 0//parent.width
            drag.maximumX: root.width - Define.multiMeterWidth - 50
            drag.minimumY: 0
            drag.maximumY: root.height - parent.height
            onPressed: {
                blackPointer.z = 10
                blackCanvas.z = 11
                redPointer.z = 5
                redCanvas.z = 6
            }

            onPositionChanged: {
                blackCanvas.requestPaint()
                blackWireChangingPos(blackPointer.x + blackPointer.width/2, blackPointer.y)
            }
            onReleased: {
                blackWireRelesedPos()
            }
        }
    }

    Canvas {

        id: blackCanvas;
        anchors.fill: parent
        z: 1000

        property var startBlackPoint: [blackPointer.x + blackPointer.width/2,blackPointer.y + blackPointer.height]

        onPaint: {
            var ctx = blackCanvas.getContext("2d");
            ctx.reset()
            ctx.clearRect(0,0, width, height);

            ctx.strokeStyle = "black";
            ctx.lineWidth = 5;
            ctx.beginPath();
            ctx.moveTo(startBlackPoint[0], startBlackPoint[1]);
//            for (var i=1; i<20; i++) {
                //              ctx.bezierCurveTo(xPos(j-0.5),yPos(i,j-1),xPos(j-0.5),yPos(i,j),xPos(j),yPos(i,j));
                ctx.lineTo(root.stopBlackPoint[0],root.stopBlackPoint[1]);
//            }

            ctx.stroke();
        }
    }
    Component.onCompleted: {
        redCanvas.requestPaint()
        blackCanvas.requestPaint()
    }

    onBothWireAtSamePosChanged: {
        ModelData.bothWireAtSamePos = bothWireAtSamePos;
    }
}

