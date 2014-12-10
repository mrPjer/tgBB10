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
        bottomMargin: 10

        ImageView {
            id: lockIcon
            imageSource: "asset:///images/chatsList/secretChat/secretchat_green.png"
            verticalAlignment: VerticalAlignment.Center
            accessibility.name: "lock icon"

        }

        Label {
            id: chatName
            text: "test name"
            textStyle.color: Color.create("#ff299d44")
            leftMargin: 0
            verticalAlignment: VerticalAlignment.Center
            textStyle.fontSize: FontSize.Medium
        }
    }

    Label {
        id: chatCurrentStatus
        text: "test status"
        textStyle.fontSize: FontSize.Small
        topMargin: 0
    }

}
