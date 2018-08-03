import QtQuick 2.0
import App_Enum 1.0

Item {
    id: root

    property var model: ""
    property int type: model.objectType
    readonly property int _EMPTY: 0
    readonly property int _FOCUSED: 1
    readonly property int _CONNECTED: 2
    property int matchingPositive: _EMPTY
    property int matchingNegative: _EMPTY
    property int matchingExtend: _EMPTY
    property int _NONE_WIRE: 0
    property int _RED_WIRE: 1
    property int _BLACK_WIRE: 2

    property bool active: type != App_Enum.E_OBJECT_TYPE_TRANSISTOR &&
                          type != App_Enum.E_OBJECT_TYPE_MULTIMETER?
                              (matchingPositive == _CONNECTED && matchingNegative == _CONNECTED):
                              (matchingPositive == _CONNECTED && matchingNegative == _CONNECTED && matchingExtend == _CONNECTED)

    property var positivePoint: model.positivePoint
    property var negativePoint: model.negativePoint
    property var extendPoint: model.extendPoint

    property alias _positive: positive
    property alias _negative: negative
    property alias _extend: extend
    Image{
        id: profileImage
        width: parent.width - 10
        height: parent.height -10
        source: model.sourceImage
        smooth: true
    }
    Rectangle{
        id: positive
        property int connetedWire: _NONE_WIRE
        x: positivePoint.x - width/2
        y: positivePoint.y - height/2
        width: 10
        height: 10
        radius: matchingPositive == _CONNECTED? width/2:0
        color: matchingPositive == _CONNECTED? "black":"red"
        opacity: matchingPositive == _CONNECTED? 1:0.2
        visible: matchingPositive!= _EMPTY
    }

    Rectangle{
        id: negative
        property int connetedWire: _NONE_WIRE
        x: negativePoint.x - width/2
        y: negativePoint.y - height/2
        width: 10
        height: 10
        radius: matchingNegative == _CONNECTED? width/2:0
        color: matchingNegative == _CONNECTED? "black":"red"
        opacity: matchingNegative == _CONNECTED? 1:0.2
        visible: matchingNegative != _EMPTY
    }

    Rectangle{
        id: extend
        property int connetedWire: _NONE_WIRE
        x: negativePoint.x - width/2
        y: negativePoint.y - height/2
        width: 10
        height: 10
        radius: matchingExtend == _CONNECTED? width/2:0
        color: matchingExtend == _CONNECTED? "black":"red"
        opacity: matchingExtend == _CONNECTED? 1:0.2
        visible: matchingExtend != _EMPTY
    }

    onMatchingPositiveChanged: {
        if(matchingPositive != _CONNECTED){
            positive.connetedWire = _NONE_WIRE
        }
    }
    onMatchingNegativeChanged: {
        if(matchingNegative != _CONNECTED){
            negative.connetedWire = _NONE_WIRE
        }
    }
    onMatchingExtendChanged: {
        if(matchingExtend != _CONNECTED){
            extend.connetedWire = _NONE_WIRE
        }
    }
}
