import bb.cascades 1.2

Container {
    id: cellRoot
    property alias avatar: chatAvatar.avatar
    property string chatName
    property string currentStatus
    property string lastUserActive
    property alias outgoingStatus: status.outgoingStatus
    property alias time: status.timeStamp
    property bool normalVisible
    property bool groupVisible
    property bool secretVisible

    property string type

    signal rowClicked()
    
    preferredHeight: 80
    leftPadding: 0

    Divider {
        id: divider
        bottomMargin: 0
        accessibility.name: "divider"
    }

    Container {
        id: cell
        bottomPadding: 2
        topPadding: 2
        leftMargin: 0
        leftPadding: 0
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight

        }

        CellImageContainer {
            id: chatAvatar
            layoutProperties: StackLayoutProperties {
                spaceQuota: 0.7
            }
        }

        CellTextContainerNormal {
            id: textNormal
            name: chatName
            status: currentStatus
            layoutProperties: StackLayoutProperties {
                spaceQuota: 4
            }
            visible: normalVisible
        }

        CellTextContainerGroup {
            id: textGroup
            name: chatName
            lastUser: lastUserActive
            status: currentStatus
            layoutProperties: StackLayoutProperties {
                spaceQuota: 4
            }
            visible: groupVisible
        }

        CellTextContainerSecret {
            id: textSecret
            name: chatName
            status: currentStatus
            layoutProperties: StackLayoutProperties {
                spaceQuota: 4
            }
            visible: secretVisible
        }

        CellStatusContainer {
            id: status
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1.2
            }
        }

    }

    onTouch: {
        if (event.isUp()) {
            rowClicked()
        }
    }

}
