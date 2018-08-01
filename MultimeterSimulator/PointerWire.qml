import QtQuick 2.0

import QtQuick 2.3


Item{
    id: root

    property var stopRedPoint: [0,0]
    property var stopBlackPoint: [0,0]

    Image{
        id: redPointer
        width: sourceSize.width
        height: sourceSize.height
        source: ModelData.multimeter.redSourceImg
        x: root.width - 450
        y: root.height - 300
        Rectangle{
            anchors.verticalCenter: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width/2
            height: 10
            radius: 10
            color: "red"
        }

        MouseArea{
            anchors.fill: parent
            drag.target: parent
            drag.minimumX: 0//parent.width
            drag.maximumX: root.width - Define.multiMeterWidth - 50
            drag.minimumY: 0
            drag.maximumY: root.height - parent.height
            onPositionChanged: {
                canvas.requestPaint()
            }
        }
    }

    Image{
        id: blackPointer
        width: sourceSize.width
        height: sourceSize.height
        source: ModelData.multimeter.blackSourceImg
        x: root.width - 500
        y: root.height - 300
        Rectangle{
            anchors.verticalCenter: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width/2
            height: 10
            radius: 10
            color: "black"
        }
        MouseArea{
            anchors.fill: parent
            drag.target: parent
            drag.minimumX: 0//parent.width
            drag.maximumX: root.width - Define.multiMeterWidth - 50
            drag.minimumY: 0
            drag.maximumY: root.height - parent.height
            onPositionChanged: {
                canvas.requestPaint()
            }
        }
    }

    Canvas {

        id: canvas;
        anchors.fill: parent
        z: 1000

        property var startRedPoint: [redPointer.x + redPointer.width/2,redPointer.y + redPointer.height]
        property var startBlackPoint: [blackPointer.x + blackPointer.width/2,blackPointer.y + blackPointer.height]

        onPaint: {
            console.log("Painting ")
            var ctx = canvas.getContext("2d");
            ctx.reset()
            ctx.clearRect(0,0, width, height);

            ctx.strokeStyle = "red";
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
    Component.onCompleted: {
        canvas.requestPaint()
    }
}

























//    Canvas {
//        id: canvas
//        property int prevX: 0
//        property int prevY: 0
//        property int lineWidth: 2
//        property color drawColor: "red"
//        anchors.fill: parent

//        MouseArea {
//            id:mousearea
//            anchors.fill: parent
//            onPressed: {canvas.prevX = mouseX ; canvas.prevY = mouseY}
//            onPositionChanged: canvas.requestPaint();
//        }

//        onPaint: {
//            var ctx = getContext('2d');
//            ctx.beginPath();
//            ctx.strokeStyle = drawColor
//            ctx.lineWidth = lineWidth
//            ctx.moveTo(prevX, prevY);
//            ctx.lineTo(mousearea.mouseX, mousearea.mouseY);
//            ctx.stroke();
//            ctx.closePath();
//            prevX = mousearea.mouseX;
//            prevY = mousearea.mouseY;
//        }
//    }
