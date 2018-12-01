import QtQuick 2.3
import QtQuick.Window 2.10
import App_Enum 1.0

Window {
    id: window
    visible: true
    title: qsTr("Phần mềm kiểm tra linh kiện điện tử")
    width: Screen.width
    height: Screen.height

    signal dragPointChanged(point dragPoint, int _index, var _dlg, point _prevPoint)
    signal resetSignal()

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
//        boundsBehavior: ListView.StopAtBounds
        model: ModelData.listModel
        delegate: CommonComponent{
            id: dlg
            property point prevPoint: Qt.point(index * dlg.width,0)
            width: Define.WIDGET_WIDTH
            height: Define.WIDGET_HEIGHT
            Rectangle{
                id : bg
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
                    console.log("MouseX:" + mouseX)
                    console.log("MouseY:" + mouseY)
                    lsv.currentIndex = index
                    prevPoint = Qt.point(dlg.x,dlg.y)
                }
                onReleased: {
                    console.log("MouseX: " + mouseX)
                    console.log("MouseY: " + mouseY)
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
                    console.log("MouseX:" + mouseX)
                    console.log("MouseY:" + mouseY)
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
                    finger.x = dlg.x + 54
                }
            }
            Connections{
                target: window
                onDragPointChanged:{
                    if(_index !== index){
                        if(dragPoint.x > dlg.x - dlg.width && dragPoint.x < dlg.x + dlg.width &&
                           dragPoint.y > dlg.y - dlg.height && dragPoint.y < dlg.y + dlg.height){
                            console.log("Item at " + index + " contains this point")
                            _dlg.x = _prevPoint.x
                            _dlg.y = _prevPoint.y
                        }
                    }
                }
                onResetSignal:{
                    dlg.y = 0;
                    dlg.x = index * Define.WIDGET_WIDTH
                    dlg.matchingNegative = App_Enum.E_WIRE_STATUS_EMPTY
                    dlg.matchingPositive = App_Enum.E_WIRE_STATUS_EMPTY
                    dlg.matchingExtend = App_Enum.E_WIRE_STATUS_EMPTY
                }
            }
        }
        onContentXChanged: {
            console.log("onContentXChanged: " + contentX)
        }
    }

    Image {
        id: prevBtn
        height: lsv.height / 2
        width: height
        anchors.left: lsv.left
        anchors.verticalCenter: lsv.verticalCenter
        source: "qrc:/Image/prevBtn.png"
        opacity: mousePrev.pressed? 0.5:0.3
        visible: lsv.contentX > 0

        MouseArea{
            id: mousePrev
            anchors.fill: parent
            onClicked: {
                console.log("Clicked previous button")
                lsv.positionViewAtBeginning()
            }
        }
    }

    Image {
        id: nextBtn
        height: lsv.height / 2
        width: height
        anchors.right: lsv.right
        anchors.verticalCenter: lsv.verticalCenter
        source: "qrc:/Image/nextBtn.png"
        opacity: mouseNext.pressed? 0.5:0.3
        visible: lsv.contentX <=0 && lsv.contentWidth > window.width

        MouseArea{
            id: mouseNext
            anchors.fill: parent
            onClicked: {
                console.log("Clicked next button")
                lsv.positionViewAtEnd()
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
            source: ModelData.logoSource
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

    Image {
        id: rstBtn
        width: 100
        height: 50
        anchors.bottom: parent.bottom
        anchors.right: multimeter.left
        source: ModelData.rstBtnSource
        Rectangle{
            id: onpress
            anchors.fill: parent
            opacity: 0.2
            color: "grey"
            visible: false
        }

        MouseArea{
            signal re
            anchors.fill: parent
            onPressed: {
                onpress.visible = true
            }
            onReleased: {
                onpress.visible = false
                resetSignal()
                wire.redPointer.x = wire.redPointer.parent.width - 500
                wire.redPointer.y = wire.redPointer.parent.height - 500
                wire.blackPointer.x = wire.blackPointer.parent.width - 550
                wire.blackPointer.y = wire.blackPointer.parent.height - 500
                wire.redCanvas.requestPaint()
                wire.blackCanvas.requestPaint()
            }
        }
    }

    Rectangle{
        id: infoBtn
        width: 70
        height: 30
        color: "grey"
        opacity: 0.5
        MouseArea{
            anchors.fill: parent
            propagateComposedEvents: false
            onPressed: {
                parent.opacity = 0.6
            }
            onReleased: {
                parent.opacity = 0.5
                popupBg.visible = true
            }
        }
    }
    Text {
        text: qsTr("Thông tin")
        anchors.centerIn: infoBtn
        opacity: 2
    }
    Rectangle{
        id: popupBg
        anchors.fill: parent
        color: "black"
        opacity: 0.5
        visible: false
        MouseArea{
            anchors.fill: parent
            propagateComposedEvents: false
        }
    }

    Rectangle{
        id: info
        width: 470
        height: 200
        visible: popupBg.visible
        anchors.centerIn: parent
        color: "black"
        border.color: "white"
        border.width: 1
        Text {
            text: qsTr("Đây là phần mềm mô phỏng sự đo kiểm tra đánh giá chất lượng cấu kiện điện tử, phục vụ cho nội dung thực hành  học phần Cấu kiện điện tử (C20) và học phần Đo lường điện tử (C25)”")
            width: parent.width - 30
            height: parent.height - 30
            wrapMode: Text.Wrap
            font.pixelSize: 15
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 50
        }
        Rectangle{
            id: closeBtn
            width: 80
            height: 30
            color: "white"
            radius: 2
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 10
            Text {
                text: qsTr("Close")
                anchors.centerIn: parent
                font.pixelSize: 19
            }
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    closeBtn.color = "grey"
                }
                onReleased: {
                    closeBtn.color = "white"
                    popupBg.visible = false
                }
            }
        }
    }
}
