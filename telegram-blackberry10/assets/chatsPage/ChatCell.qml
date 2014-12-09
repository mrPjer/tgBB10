import bb.cascades 1.2



    
Container {
    id: cellRoot
    property alias avatar: chatAvatar.avatar
    property alias chatName: text.name
    property alias currentStatus: text.currentStatus

    Divider {
        id: divider
        bottomMargin: -20
    }
    
    Container {
        id: cell
        maxWidth: maxWidth
        maxHeight: maxHeight
        bottomPadding: 5
        topPadding: 5
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
            
        }
        
        CellImageContainer {
            id: chatAvatar
            layoutProperties: StackLayoutProperties {
                spaceQuota: 2
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
                spaceQuota: 1
            }
        }
        
        
        
    }
    
   
    
}
