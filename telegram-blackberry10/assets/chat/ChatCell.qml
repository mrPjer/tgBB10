import bb.cascades 1.2

Container {
    id: chatCell
    property alias messageTypeInbound: inbound.visible
    property alias messageTypeOutbound: outbound.visible
    property string messageText
    property string timeStamp
    property bool sentVisible
    property bool sendingVisible
    property bool readVisible
    property bool unsentVisible

    bottomMargin: 10

    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        LeftChatCell {
            id: inbound
            layoutProperties: StackLayoutProperties {
                spaceQuota: 8
            }
            visible: false
            messageText: chatCell.messageText
            timeStamp: chatCell.timeStamp
        }
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 2
            }
        }
    }
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 2
            }
        }
        RightChatCell {
            id: outbound
            layoutProperties: StackLayoutProperties {
                spaceQuota: 8
            }
            visible: false
            messageText: chatCell.messageText
            timeStamp: chatCell.timeStamp
            sentVisible: chatCell.sendingVisible
            sendingVisible: chatCell.sendingVisible
            readVisible: chatCell.readVisible
            unsentVisible: chatCell.unsentVisible
        }
    }
}