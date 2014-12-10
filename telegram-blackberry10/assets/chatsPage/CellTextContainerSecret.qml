import bb.cascades 1.2


Container {
    
    property alias name: chatName.text
    property alias status: chatCurrentStatus.text
    
    layout: StackLayout {    
    }
    
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        
        ImageView {
           id: lockIcon
           imageSource: "asset:///images/chatsList/secretChat/secretchat_green.png" 
           verticalAlignment: VerticalAlignment.Center

        }
        
        Label {
            id: chatName
            text: "test name"
            textStyle.color: Color.create("#ff299d44")
            leftMargin: 0
            verticalAlignment: VerticalAlignment.Center
        }
    }
    
    
    Label {
        id: chatCurrentStatus
        text: "test status"
    }

}

