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

    Divider {
        id: divider
        bottomMargin: 0
    }
    
    Container {
        id: cell
        maxWidth: maxWidth
        maxHeight: maxHeight
        bottomPadding: 2
        topPadding: 2
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
            
        }
        
        CellImageContainer {
            rightMargin: 10
            id: chatAvatar
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1.3
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
    
   
    
}