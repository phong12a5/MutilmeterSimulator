import QtQuick 2.11
import QtQuick.Window 2.11
import App_Enum 1.0

Window {
    id: window
    visible: true
    title: qsTr("Electronic circurt simulator Software")
    width: Screen.width
    height: Screen.height

    ListModel{
        id: mod
    }

    Multimeter{
        id: multimeter
        width: Define.multiMeterWidth
        height: parent.height - lsv.height
        anchors.top: lsv.bottom
        anchors.right: parent.right
    }

    ListView{
        id: lsv
        width: parent.width
        height: Define.WIDGET_HEIGHT
        orientation : ListView.Horizontal
        boundsBehavior: ListView.StopAtBounds
        model: mod
        delegate: CommonComponent{
            id: dlg
            property point prevPoint: Qt.point(index * dlg.width,0)
            width: Define.WIDGET_WIDTH
            height: Define.WIDGET_HEIGHT
            model: mod.get(index)
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
                    dlg.matchingNegative = dlg._EMPTY
                    dlg.matchingPositive = dlg._EMPTY
                    dlg.matchingExtend = dlg._EMPTY
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
                            if(dlg.matchingPositive == dlg._CONNECTED && dlg._positive.connetedWire == dlg._BLACK_WIRE){
                                return;
                            }
                            dlg.matchingPositive = dlg._FOCUSED;
                        }else if(_point.x >= dlg._negative.x &&
                                 _point.x <= dlg._negative.x + dlg._negative.width &&
                                 _point.y >= dlg._negative.y &&
                                 _point.y <= dlg._negative.y + dlg._negative.height)
                        {
                            if(dlg.matchingNegative == dlg._CONNECTED && dlg._negative.connetedWire == dlg._BLACK_WIRE){
                                return;
                            }
                            dlg.matchingNegative = dlg._FOCUSED;
                        }else{
                            if(dlg.matchingPositive == dlg._FOCUSED)
                                dlg.matchingPositive = dlg._EMPTY;
                            if(dlg.matchingNegative == dlg._FOCUSED)
                                dlg.matchingNegative = dlg._EMPTY;
                        }
                    }else{
                        if(dlg.matchingPositive == dlg._FOCUSED)
                            dlg.matchingPositive = dlg._EMPTY;
                        if(dlg.matchingNegative == dlg._FOCUSED)
                            dlg.matchingNegative = dlg._EMPTY;
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
                            if(dlg.matchingPositive == dlg._CONNECTED && dlg._positive.connetedWire == dlg._RED_WIRE){
                                return;
                            }
                            dlg.matchingPositive = dlg._FOCUSED;
                        }else if(_point.x >= dlg._negative.x &&
                                 _point.x <= dlg._negative.x + dlg._negative.width &&
                                 _point.y >= dlg._negative.y &&
                                 _point.y <= dlg._negative.y + dlg._negative.height)
                        {
                            if(dlg.matchingNegative == dlg._CONNECTED && dlg._negative.connetedWire == dlg._RED_WIRE){
                                return;
                            }
                            dlg.matchingNegative = dlg._FOCUSED;
                        }else{
                            if(dlg.matchingPositive == dlg._FOCUSED)
                                dlg.matchingPositive = dlg._EMPTY;
                            if(dlg.matchingNegative == dlg._FOCUSED)
                                dlg.matchingNegative = dlg._EMPTY;
                        }
                    }else {
                        if(dlg.matchingPositive == dlg._FOCUSED)
                            dlg.matchingPositive = dlg._EMPTY;
                        if(dlg.matchingNegative == dlg._FOCUSED)
                            dlg.matchingNegative = dlg._EMPTY;
                    }
                }
                onRedWireRelesedPos:{
                    if(dlg.matchingPositive == dlg._FOCUSED){
                        dlg._positive.connetedWire = dlg._RED_WIRE;
                        dlg.matchingPositive = dlg._CONNECTED;
                    }

                    if(dlg.matchingNegative == dlg._FOCUSED){
                        dlg._negative.connetedWire = dlg._RED_WIRE;
                        dlg.matchingNegative = dlg._CONNECTED;
                    }
                }
                onBlackWireRelesedPos:{
                    if(dlg.matchingPositive == dlg._FOCUSED){
                        dlg._positive.connetedWire = dlg._BLACK_WIRE;
                        dlg.matchingPositive = dlg._CONNECTED;
                    }
                    if(dlg.matchingNegative == dlg._FOCUSED){
                        dlg._negative.connetedWire = dlg._BLACK_WIRE;
                        dlg.matchingNegative = dlg._CONNECTED;
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
        stopRedPoint:[multimeter.stopRedPoint[0] + multimeter.x, multimeter.stopRedPoint[1] ]
        stopBlackPoint:[multimeter.stopBlackPoint[0] + multimeter.x, multimeter.stopBlackPoint[1]]
    }

    function creatModel(){
        mod.append(ModelData.resistor1);
        mod.append(ModelData.resistor2);
        mod.append(ModelData.capictor_normal);
        mod.append(ModelData.capictor_abnormal);
        mod.append(ModelData.cappictor_error);
        mod.append(ModelData.condutor_normal);
        mod.append(ModelData.condutor_error);
        mod.append(ModelData.diode);
        mod.append(ModelData.transistor);
    }
    Component.onCompleted: {
        creatModel()
        window.showMaximized()
    }
    onWidthChanged: {
        wire.redCanvas.requestPaint()
        wire.blackCanvas.requestPaint()
    }
}
