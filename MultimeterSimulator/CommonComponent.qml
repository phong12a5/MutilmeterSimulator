import QtQuick 2.0
import App_Enum 1.0

Item {
    id: root

    property int type: modelData.objectType
    property int matchingPositive: Define._EMPTY
    property int matchingNegative: Define._EMPTY
    property int matchingExtend: Define._EMPTY
    property bool active: type != App_Enum.E_OBJECT_TYPE_TRANSISTOR &&
                          type != App_Enum.E_OBJECT_TYPE_MULTIMETER?
                              (matchingPositive == Define._CONNECTED && matchingNegative == Define._CONNECTED):
                              (matchingPositive == Define._CONNECTED && matchingNegative == Define._CONNECTED && matchingExtend == Define._CONNECTED)

    property alias _positive: positive
    property alias _negative: negative
    property alias _extend: extend
    Image{
        id: profileImage
        width: parent.width - 10
        height: parent.height -10
        source: modelData.sourceImage
        smooth: true
    }
    Rectangle{
        id: positive
        property int connetedWire: Define._NONE_WIRE
        x: modelData.positivePoint.x - width/2
        y: modelData.positivePoint.y - height/2
        width: 10
        height: 10
        radius: matchingPositive == Define._CONNECTED? width/2:0
        color: matchingPositive == Define._CONNECTED? "black":"red"
        opacity: matchingPositive == Define._CONNECTED? 1:0.2
        visible: matchingPositive!= Define._EMPTY
        onConnetedWireChanged: {
            modelData.posConnectedWire = connetedWire
        }
    }

    Rectangle{
        id: negative
        property int connetedWire: Define._NONE_WIRE
        x: modelData.negativePoint.x - width/2
        y: modelData.negativePoint.y - height/2
        width: 10
        height: 10
        radius: matchingNegative == Define._CONNECTED? width/2:0
        color: matchingNegative == Define._CONNECTED? "black":"red"
        opacity: matchingNegative == Define._CONNECTED? 1:0.2
        visible: matchingNegative != Define._EMPTY
        onConnetedWireChanged: {
            modelData.negaConnectedWire = connetedWire
        }
    }

    Rectangle{
        id: extend
        property int connetedWire: Define._NONE_WIRE
        x: modelData.extendPoint.x - width/2
        y: modelData.extendPoint.y - height/2
        width: 10
        height: 10
        radius: matchingExtend == Define._CONNECTED? width/2:0
        color: matchingExtend == Define._CONNECTED? "black":"red"
        opacity: matchingExtend == Define._CONNECTED? 1:0.2
        visible: matchingExtend != Define._EMPTY
        onConnetedWireChanged: {
            modelData.extConnectedWire = connetedWire
        }
    }

    onMatchingPositiveChanged: {
        if(matchingPositive != Define._CONNECTED){
            positive.connetedWire = Define._NONE_WIRE
        }
    }
    onMatchingNegativeChanged: {
        if(matchingNegative != Define._CONNECTED){
            negative.connetedWire = Define._NONE_WIRE
        }
    }
    onMatchingExtendChanged: {
        if(matchingExtend != Define._CONNECTED){
            extend.connetedWire = Define._NONE_WIRE
        }
    }
}
