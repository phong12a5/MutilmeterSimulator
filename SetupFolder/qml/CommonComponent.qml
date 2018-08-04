import QtQuick 2.0
import App_Enum 1.0

Item {
    id: root

    property int type: modelData.objectType
    property int matchingPositive: App_Enum.E_WIRE_STATUS_EMPTY
    property int matchingNegative: App_Enum.E_WIRE_STATUS_EMPTY
    property int matchingExtend: App_Enum.E_WIRE_STATUS_EMPTY
    property bool active: type != App_Enum.E_OBJECT_TYPE_TRANSISTOR? (matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED && matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED):
                                                                     ((matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED && matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED) ||
                                                                      (matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED && matchingExtend == App_Enum.E_WIRE_STATUS_CONNECTED) ||
                                                                      (matchingExtend == App_Enum.E_WIRE_STATUS_CONNECTED && matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED))

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
        property int connetedWire: App_Enum.E_WIRE_TYPE_NONE
        x: modelData.positivePoint.x - width/2
        y: modelData.positivePoint.y - height/2
        width: 10
        height: 10
        radius: matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED? width/2:0
        color: matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED? "black":"red"
        opacity: matchingPositive == App_Enum.E_WIRE_STATUS_CONNECTED? 1:0.2
        visible: matchingPositive!= App_Enum.E_WIRE_STATUS_EMPTY
        onConnetedWireChanged: {
            modelData.posConnectedWire = connetedWire
        }
    }

    Rectangle{
        id: negative
        property int connetedWire: App_Enum.E_WIRE_TYPE_NONE
        x: modelData.negativePoint.x - width/2
        y: modelData.negativePoint.y - height/2
        width: 10
        height: 10
        radius: matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED? width/2:0
        color: matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED? "black":"red"
        opacity: matchingNegative == App_Enum.E_WIRE_STATUS_CONNECTED? 1:0.2
        visible: matchingNegative != App_Enum.E_WIRE_STATUS_EMPTY
        onConnetedWireChanged: {
            modelData.negaConnectedWire = connetedWire
        }
    }

    Rectangle{
        id: extend
        property int connetedWire: App_Enum.E_WIRE_TYPE_NONE
        x: modelData.extendPoint.x - width/2
        y: modelData.extendPoint.y - height/2
        width: 10
        height: 10
        radius: matchingExtend == App_Enum.E_WIRE_STATUS_CONNECTED? width/2:0
        color: matchingExtend == App_Enum.E_WIRE_STATUS_CONNECTED? "black":"red"
        opacity: matchingExtend == App_Enum.E_WIRE_STATUS_CONNECTED? 1:0.2
        visible: matchingExtend != App_Enum.E_WIRE_STATUS_EMPTY
        onConnetedWireChanged: {
            modelData.extConnectedWire = connetedWire
        }
    }

    onMatchingPositiveChanged: {
        if(matchingPositive != App_Enum.E_WIRE_STATUS_CONNECTED){
            positive.connetedWire = App_Enum.E_WIRE_TYPE_NONE
        }
    }
    onMatchingNegativeChanged: {
        if(matchingNegative != App_Enum.E_WIRE_STATUS_CONNECTED){
            negative.connetedWire = App_Enum.E_WIRE_TYPE_NONE
        }
    }
    onMatchingExtendChanged: {
        if(matchingExtend != App_Enum.E_WIRE_STATUS_CONNECTED){
            extend.connetedWire = App_Enum.E_WIRE_TYPE_NONE
        }
    }
}
