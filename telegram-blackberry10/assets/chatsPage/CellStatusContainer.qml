import bb.cascades 1.2


Container {
    layout: StackLayout {
            
    }
        
    Container {
        id: outgoingStatusAndTimeStampCointainer
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }    
        
        ImageView {
            id: outgoingStatus
        }
        
        Label {
            id: timeStamp
        }
    }
    
    Container {
        id: unreadMessagesContainer
        
    }
}

