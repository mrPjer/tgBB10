import bb.cascades 1.2


Container {
    
    property alias name: chatName.text
    property alias status: chatCurrentStatus.text
    
    layout: StackLayout {    
    }
    Label {
        id: chatName
        text: "test name"
        textStyle.fontSize: FontSize.Medium

    }

    Label {
        id: chatCurrentStatus
        text: "test status"
        textStyle.fontSize: FontSize.Small

    }

}
