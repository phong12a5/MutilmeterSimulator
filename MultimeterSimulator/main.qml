import QtQuick 2.11
import QtQuick.Window 2.11
import App_Enum 1.0

Window {
    id: window
    visible: true
    title: qsTr("Electronic circuit simulator Software")
    width: Screen.width
    height: Screen.height

    ListModel{
        id: mod
    }

    Multimeter{
        id: multimeter
        width: Define.multiMeterWidth
        anchors.bottom: parent.bottom
        anchors.top: lsv.bottom
        anchors.topMargin: -10
        anchors.right: parent.right
    }

    Rectangle{
        anchors.fill: lsv
    }

    ListView{
        id: lsv
        width: parent.width
        height: Define.WIDGET_HEIGHT
        orientation : ListView.Horizontal
        boundsBehavior: ListView.StopAtBounds
        model: ModelData.listModel
        delegate: CommonComponent{
            id: dlg
            property point prevPoint: Qt.point(index * dlg.width,0)
            width: Define.WIDGET_WIDTH
            height: Define.WIDGET_HEIGHT
            Rectangle{
                anchors.fill: parent
                visible: mousePress.pressed
                color: "grey"
                opacity: 0.1
            }
            MouseArea{
                id: mousePress
                anchors.fill: parent
                drag.target: dlg
                drag.maximumX: window.width - Define.WIDGET_WIDTH
                drag.minimumX: 0
                drag.maximumY: window.height - Define.WIDGET_HEIGHT
                drag.minimumY: 0
                onPressed: {
                    lsv.currentIndex = index
                    prevPoint = Qt.point(dlg.x,dlg.y)
                }
                onReleased: {
                    if(dlg.y <= 0 || (dlg.y - lsv.y < dlg.height)){
                        dlg.y = 0
                        dlg.x = index* dlg.width
                    }

                    if(dlg.x + dlg.width > multimeter.x &&
                            dlg.y + dlg.height > multimeter.y){
                        dlg.x = dlg.prevPoint.x
                        dlg.y = dlg.prevPoint.y
                    }
                }
                onPositionChanged: {
                    dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY
                    dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY
                    dlg.matchingExtend = App_Enum.E_WIRE_STATUS_EMPTY
                }
            }
            Connections{
                target: wire
                onRedWireChangingPos:{
                    var _point = Qt.point(posX - dlg.x,posY + lsv.height - dlg.y)
                    if(posX >= dlg.x &&
                            posX <= dlg.x + dlg.width &&
                            posY >= (dlg.y - lsv.height) &&
                            posY <= dlg.y){
                        if(_point.x >= dlg._positive.x &&
                                _point.x <= dlg._positive.x + dlg._positive.width &&
                                _point.y >= dlg._positive.y &&
                                _point.y <= dlg._positive.y + dlg._positive.height)
                        {
                            if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED && dlg._positive.connetedWire == App_Enum.E_WIRE_TYPE_BLACK){
                                return;
                            }
                            dlg.matchingPositive = App_Enum.E_WIRE_STATUS_FOCUSED;
                        }else if(_point.x >= dlg._negative.x &&
                                 _point.x <= dlg._negative.x + dlg._negative.width &&
                                 _point.y >= dlg._negative.y &&
                                 _point.y <= dlg._negative.y + dlg._negative.height)
                        {
                            if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED && dlg._negative.connetedWire == App_Enum.E_WIRE_TYPE_BLACK){
                                return;
                            }
                            dlg.matchingNegative = App_Enum.E_WIRE_STATUS_FOCUSED;
                        }else{
                            if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                            if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                        }
                    }else{
                        if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                            dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                        if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                            dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                    }
                }
                onBlackWireChangingPos:{
                    var _point = Qt.point(posX - dlg.x,posY + lsv.height - dlg.y)
                    if(posX >= dlg.x &&
                            posX <= dlg.x + dlg.width &&
                            posY >= (dlg.y - lsv.height) &&
                            posY <= dlg.y){
                        if(_point.x >= dlg._positive.x &&
                                _point.x <= dlg._positive.x + dlg._positive.width &&
                                _point.y >= dlg._positive.y &&
                                _point.y <= dlg._positive.y + dlg._positive.height)
                        {
                            if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED && dlg._positive.connetedWire == App_Enum.E_WIRE_TYPE_RED){
                                return;
                            }
                            dlg.matchingPositive = App_Enum.E_WIRE_STATUS_FOCUSED;
                        }else if(_point.x >= dlg._negative.x &&
                                 _point.x <= dlg._negative.x + dlg._negative.width &&
                                 _point.y >= dlg._negative.y &&
                                 _point.y <= dlg._negative.y + dlg._negative.height)
                        {
                            if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED && dlg._negative.connetedWire == App_Enum.E_WIRE_TYPE_RED){
                                return;
                            }
                            dlg.matchingNegative = App_Enum.E_WIRE_STATUS_FOCUSED;
                        }else{
                            if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                            if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                        }
                    }else {
                        if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                            dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                        if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                            dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                    }
                }
                onRedWireRelesedPos:{
                    if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED){
                        dlg._positive.connetedWire = App_Enum.E_WIRE_TYPE_RED;
                        dlg.matchingPositive = App_Enum.E_WIRE_STATUS_CONNECTED;
                    }

                    if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED){
                        dlg._negative.connetedWire = App_Enum.E_WIRE_TYPE_RED;
                        dlg.matchingNegative = App_Enum.E_WIRE_STATUS_CONNECTED;
                    }
                }
                onBlackWireRelesedPos:{
                    if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED){
                        dlg._positive.connetedWire = App_Enum.E_WIRE_TYPE_BLACK;
                        dlg.matchingPositive = App_Enum.E_WIRE_STATUS_CONNECTED;
                    }
                    if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED){
                        dlg._negative.connetedWire = App_Enum.E_WIRE_TYPE_BLACK;
                        dlg.matchingNegative = App_Enum.E_WIRE_STATUS_CONNECTED;
                    }
                }
            }
            onActiveChanged: {
                console.log("ACtive of " + index +
                            " >> changed: " + dlg.active +
                            " >> dlg._positive.connetedWire: " + dlg._positive.connetedWire +
                            " >> dlg._negative.connetedWire: " + dlg._negative.connetedWire)

                ModelData.activedDeviced = dlg.active?index:-1;
                ModelData.updateActivedDevice(dlg.active,index,dlg._positive.connetedWire,dlg._negative.connetedWire,dlg._extend.connetedWire)
            }
        }
        Component.onCompleted: {
            for(var i = 0; i < ModelData.listModel.length; i++){
            console.log("ModelData.listModel[i]: " + ModelData.listModel[i].objectName)
            }
        }
    }

    Rectangle{
        id: line
        width: window.width
        height: 2
        color: "grey"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: Define.WIDGET_HEIGHT - 2
    }

    PointerWire{
        id: wire
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height - lsv.height
        anchors.bottom: parent.bottom
        stopRedPoint:[multimeter.stopRedPoint[0] + multimeter.x, multimeter.stopRedPoint[1] + multimeter._FIX]
        stopBlackPoint:[multimeter.stopBlackPoint[0] + multimeter.x, multimeter.stopBlackPoint[1] + multimeter._FIX]
    }

    Component.onCompleted: {
        window.showMaximized()
    }
    onWidthChanged: {
        wire.redCanvas.requestPaint()
        wire.blackCanvas.requestPaint()
    }
}
