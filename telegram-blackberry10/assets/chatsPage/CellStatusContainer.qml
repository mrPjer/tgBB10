import bb.cascades 1.2

Container {

    property alias timeStamp: timeStampLabel.text
    property string outgoingStatus
    property alias unreadMessagesCount: unreadMessagesLabel.text

    layout: StackLayout {

    }

    Container {
        property variant statusIcon: {
            "none": "asset:///images/chatsList/outgoingStatus/blank.png",
            "sending": "asset:///images/chatsList/outgoingStatus/clocks_green.png",
            "delivered": "asset:///images/chatsList/outgoingStatus/check_green.png",
            "seen": "asset:///images/chatsList/outgoingStatus/check_2_green.png"
        }

        id: outgoingStatusAndTimeStampCointainer
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }

        ImageView {
            id: outgoingStatusImage
            imageSource: outgoingStatusAndTimeStampCointainer.statusIcon[outgoingStatus]
            accessibility.name: "status image"
            horizontalAlignment: HorizontalAlignment.Left
            verticalAlignment: VerticalAlignment.Center
        }

        Label {
            id: timeStampLabel
            text: "2:22 PM"
//            rightMargin: 0
//            rightPadding: 0
            textStyle.color: Color.create("#ff8b8985")
            textStyle.fontSize: FontSize.XXSmall
            horizontalAlignment: HorizontalAlignment.Right
            verticalAlignment: VerticalAlignment.Center

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
