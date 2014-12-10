import bb.cascades 1.2

Container {
    id: root

    property alias name: chatName.text
    property alias status: chatCurrentStatus.text
    property alias lastUser: lastUserActive.text

    layout: StackLayout {
    }
    Label {
        id: chatName
        text: "test name"
        textStyle.fontSize: FontSize.Medium
        bottomMargin: 10
    }

    Container {
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        Label {
            id: lastUserActive
            text: "test user"
            rightMargin: 5
            textStyle.color: Color.create("#ff0077b9")
            textStyle.fontSize: FontSize.Small
            layoutProperties: StackLayoutProperties {
                spaceQuota: -1
            }
        }

        Label {
            id: chatCurrentStatus
            leftMargin: 0
            text: "test status"
            textStyle.fontSize: FontSize.Small
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }

    }

}
