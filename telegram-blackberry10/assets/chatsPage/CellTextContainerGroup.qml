import bb.cascades 1.2

Container {
    id: root
    verticalAlignment: VerticalAlignment.Center
    layout: DockLayout {}
    
    property alias name: chatName.text
    property alias status: chatCurrentStatus.text
    property alias lastUser: lastUserActive.text
    

    Container {
        layout: StackLayout {
        }
        verticalAlignment: VerticalAlignment.Center
        Label {
            id: chatName
            text: "test name"
            textStyle.fontSize: FontSize.Small
            bottomMargin: 0
        }
        
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            topMargin: 0
            Label {
                id: lastUserActive
                text: "test user"
                rightMargin: 5
                textStyle.color: Color.create("#ff0077b9")
                textStyle.fontSize: FontSize.XSmall
                layoutProperties: StackLayoutProperties {
                    spaceQuota: -1
                }
            }
            
            Label {
                id: chatCurrentStatus
                leftMargin: 0
                text: "test status"
                textStyle.fontSize: FontSize.XSmall
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
            }
        
        }
    
    }
}

