import QtQuick 2.11
import QtQuick.Window 2.11
import App_Enum 1.0

Window {
    id: window
    visible: true
    title: qsTr("Electronic circuit simulator Software")
    width: Screen.width
    height: Screen.height

    signal dragPointChanged(point dragPoint, int _index, var _dlg, point _prevPoint)

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

                    if((dlg.x + dlg.width > multimeter.x && dlg.y > 0) ||
                        (dlg.x < logo.width && dlg.y + dlg.height > logo.y)){
                        dlg.x = dlg.prevPoint.x
                        dlg.y = dlg.prevPoint.y
                    }

                    dragPointChanged(Qt.point(dlg.x,dlg.y), index, dlg, prevPoint)
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
                    if(index !== App_Enum.E_OBJECT_INDEX_TRANSISTOR){
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
                    }else{
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
                            }else if(_point.x >= dlg._extend.x &&
                                     _point.x <= dlg._extend.x + dlg._extend.width &&
                                     _point.y >= dlg._extend.y &&
                                     _point.y <= dlg._extend.y + dlg._extend.height)
                            {
                                if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_CONNECTED && dlg._extend.connetedWire == App_Enum.E_WIRE_TYPE_BLACK){
                                    return;
                                }
                                dlg.matchingExtend = App_Enum.E_WIRE_STATUS_FOCUSED;
                            }else{
                                if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                                    dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                                if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                                    dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                                if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_FOCUSED)
                                    dlg.matchingExtend = App_Enum.E_WIRE_STATUS_EMPTY;
                            }
                        }else{
                            if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                            if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                            if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingExtend = App_Enum.E_WIRE_STATUS_EMPTY;
                        }
                    }
                }
                onBlackWireChangingPos:{
                    var _point = Qt.point(posX - dlg.x,posY + lsv.height - dlg.y)
                    if(index !== App_Enum.E_OBJECT_INDEX_TRANSISTOR){
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
                    }else{
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
                            }else if(_point.x >= dlg._extend.x &&
                                     _point.x <= dlg._extend.x + dlg._extend.width &&
                                     _point.y >= dlg._extend.y &&
                                     _point.y <= dlg._extend.y + dlg._extend.height)
                            {
                                if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_CONNECTED && dlg._extend.connetedWire == App_Enum.E_WIRE_TYPE_RED){
                                    return;
                                }
                                dlg.matchingExtend = App_Enum.E_WIRE_STATUS_FOCUSED;
                            }else{
                                if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                                    dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                                if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                                    dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                                if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_FOCUSED)
                                    dlg.matchingExtend = App_Enum.E_WIRE_STATUS_EMPTY;
                            }
                        }else {
                            if(dlg.matchingPositive == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY;
                            if(dlg.matchingNegative == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY;
                            if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_FOCUSED)
                                dlg.matchingExtend = App_Enum.E_WIRE_STATUS_EMPTY;
                        }
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

                    if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_FOCUSED){
                        dlg._extend.connetedWire = App_Enum.E_WIRE_TYPE_RED;
                        dlg.matchingExtend = App_Enum.E_WIRE_STATUS_CONNECTED;
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
                    if(dlg.matchingExtend == App_Enum.E_WIRE_STATUS_FOCUSED){
                        dlg._extend.connetedWire = App_Enum.E_WIRE_TYPE_BLACK;
                        dlg.matchingExtend = App_Enum.E_WIRE_STATUS_CONNECTED;
                    }
                }
            }
            onActiveChanged: {
                ModelData.activedDeviced = dlg.active?index:-1;
                ModelData.updateActivedDevice(dlg.active,index,dlg._positive.connetedWire,dlg._negative.connetedWire,dlg._extend.connetedWire)
                if(ModelData.activedDeviced === App_Enum.E_OBJECT_INDEX_TRANSISTOR &&
                   dlg._extend.connetedWire === App_Enum.E_WIRE_TYPE_NONE){
                    finger.y = dlg.y + dlg.height - 20
                    finger.x = dlg.x + 74
                }
            }
            Connections{
                target: window
                onDragPointChanged:{
                    if(_index !== index){
                        bg.color = "grey"
                        if(dragPoint.x > dlg.x - dlg.width && dragPoint.x < dlg.x + dlg.width &&
                           dragPoint.y > dlg.y - dlg.height && dragPoint.y < dlg.y + dlg.height){
                            console.log("Item at " + index + " contains this point")
                            _dlg.x = _prevPoint.x
                            _dlg.y = _prevPoint.y
                        }
                    }
                }
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
    Item {
        id: logo
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 160
        height: 160
        Image {
            anchors.fill: parent
            source: "qrc:/Logo.jpg"
            smooth: true
        }
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

    Image {
        id: finger
        source: ModelData.fingerSource
        width: 50
        height: 50
        visible: ModelData.activedDeviced === App_Enum.E_OBJECT_INDEX_TRANSISTOR &&
                 (ModelData.transistor.extConnectedWire === App_Enum.E_WIRE_TYPE_NONE ||
                  ModelData.transistor.extConnectedWire === App_Enum.E_WIRE_TYPE_FINGER)
        onVisibleChanged: {
            if(visible){
                ani.start()
            }
        }

        PropertyAnimation{
            id: ani
            target: finger
            property: "opacity"
            from: 1
            to: 0
            duration: 1000
            loops: Animation.Infinite
        }

        MouseArea{
            anchors.fill: parent
            onPressAndHold:{
                ModelData.transistor.extConnectedWire = App_Enum.E_WIRE_TYPE_FINGER
                ModelData.updateActivedDevice(true,ModelData.activedDeviced,
                                              ModelData.transistor.posConnectedWire,
                                              ModelData.transistor.negaConnectedWire,
                                              ModelData.transistor.extConnectedWire)
                ani.stop()
                finger.opacity = 1
            }
            onReleased: {
                ModelData.transistor.extConnectedWire = App_Enum.E_WIRE_TYPE_NONE
                ModelData.updateActivedDevice(true,ModelData.activedDeviced,
                                              ModelData.transistor.posConnectedWire,
                                              ModelData.transistor.negaConnectedWire,
                                              ModelData.transistor.extConnectedWire)
                if(finger.visible){
                    ani.start()
                }
            }
        }

    }

    Component.onCompleted: {
        window.showMaximized()
    }
    onWidthChanged: {
        wire.redCanvas.requestPaint()
        wire.blackCanvas.requestPaint()
    }

//    function checkOverLap(dlg,prePoint,index){
//        var result = false;
//        for(var i = 0; i < ModelData.listModel.length; i++){
//            if(index === i)
//                continue;
//            else{
//                if(dlg.)
//            }
//        }
//        return false
//    }
}
