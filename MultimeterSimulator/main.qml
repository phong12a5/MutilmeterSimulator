import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    id: window
    visible: true
    title: qsTr("Electronic circurt simulator Software")
    width: 1200
    height: 720

    ListModel{
        id: mod
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
                    console.log("Pressing")
                    lsv.currentIndex = index
                }

                onPressAndHold: {
                    console.log("Pressing and hold")
                }
                onReleased: {
                    if(dlg.y <= 0 || (dlg.y - lsv.y < dlg.height)){
                        dlg.y = 0
                        dlg.x = index* dlg.width
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

    Multimeter{
        id: multimeter
        width: 400
        height: parent.height - lsv.height
        anchors.top: lsv.bottom
        anchors.right: parent.right
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
}
