import bb.cascades 1.2


Container {
    
    property alias name: chatName.text
    property alias status: chatCurrentStatus.text
    property alias lastUser: lastUserActive.text
    
    layout: StackLayout {    
    }
    Label {
        id: chatName
        text: "test name"
    }
    
    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        Label {
            id: lastUserActive
            text: "test user"
            textStyle.color: Color.create("#ffadd9eb")
        }
        
        Label {
            id: chatCurrentStatus
            text: "test status"
        }
        
    }
    
    

}

