import QtQuick 2.0

Item {
    id: root
    Rectangle{
        id: popupBg
        anchors.fill: parent
        color: "black"
        opacity: 0.5
        visible: root.visible
        MouseArea{
            anchors.fill: parent
            propagateComposedEvents: false
        }
    }

    Rectangle{
        id: info
        width: 550
        height: content.contentHeight + 100
        visible: root.visible
        anchors.centerIn: parent
        color: "black"
        border.color: "white"
        border.width: 1
        Text {
            id: content
            text: qsTr("Đây là phần mềm mô phỏng sự đo kiểm tra đánh giá chất lượng cấu kiện điện tử, phục vụ cho nội dung thực hành  học phần Cấu kiện điện tử (C20) và học phần Đo lường điện tử (C25)
Mọi thắc mắc xin liên hệ KS, Nguyễn Trọng Quang và nhóm tác giả.
SDT: 0374790129
gmail: trongquang3883686@gmail.com")
            width: parent.width - 30
            height: parent.height - 30
            wrapMode: Text.Wrap
            font.pixelSize: 15
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 40
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
                    root.visible = false
                }
            }
        }
    }


}
