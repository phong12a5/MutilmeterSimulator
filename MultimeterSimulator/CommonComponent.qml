import QtQuick 2.0

Item {
    id: root

    property var model: ""
    Image{
        id: profileImage
        width: parent.width - 5
        height: parent.height -5
        source: model.sourceImage
    }
}
