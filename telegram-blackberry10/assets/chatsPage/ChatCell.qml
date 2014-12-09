import bb.cascades 1.2



    
Container {
    id: cellRoot
    property alias avatar: chatAvatar.avatar
    property alias chatName: text.name
    property alias currentStatus: text.currentStatus
    property alias outgoingStatus: status.outgoingStatus
    property alias time: status.timeStamp

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
            id: text
            layoutProperties: StackLayoutProperties {
                spaceQuota: 4
            }
        }
        
        CellStatusContainer {
            id: status
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1.2
            }
        }
        
        
        
    }
    
   
    
}
