import bb.cascades 1.2


Container {
    
    property alias timeStamp: timeStampLabel.text
    property string  outgoingStatus
    property alias unreadMessagesCount: unreadMessagesLabel.text
    
    layout: StackLayout {
            
    }
        
    Container {
        
        property variant statusIcon: {"none":"", "sending":"asset:///images/chatsList/outgoingStatus/clocks_green.png", "delivered":"asset:///images/chatsList/outgoingStatus/check_green.png", "seen":"asset:///images/chatsList/outgoingStatus/check_2_green.png"}

        id: outgoingStatusAndTimeStampCointainer
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }    
        
        ImageView {
            id: outgoingStatusImage
            imageSource: outgoingStatusAndTimeStampCointainer.statusIcon[outgoingStatus]
        }
        
        Label {
            id: timeStampLabel
            text: "2:22 PM"
            textStyle.color: Color.create("#ff8b8985")
            textStyle.fontSize: FontSize.XXSmall
            

        }
    }

    Container {
        id: unreadMessagesContainer

        background: Color.create("#ff5cb061")
        Label {
            id: unreadMessagesLabel
            text: ""
        }

    }
}
