import bb.cascades 1.2

Container {

    property alias timeStamp: timeStampLabel.text
    property string outgoingStatus
    property alias unreadMessagesCount: unreadMessagesLabel.text
    property alias unreadVisible: unreadMessagesContainer.visible

    rightPadding: 8
    leftPadding: 8
    topPadding: 4
    bottomPadding: 4

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

        horizontalAlignment: HorizontalAlignment.Right

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
            textStyle.color: Color.create("#ff8b8985")
            textStyle.fontSize: FontSize.Small
            horizontalAlignment: HorizontalAlignment.Right
            verticalAlignment: VerticalAlignment.Center

        }
    }

    Container {
        id: unreadMessagesContainer
        leftPadding: 16
        rightPadding: 16
        topPadding: 4
        bottomPadding: 8
        topMargin: 8
        bottomMargin: 4
        horizontalAlignment: HorizontalAlignment.Right
        background: Color.create("#ff299d44")
        Label {
            id: unreadMessagesLabel
            text: "10"
            textStyle.fontSize: FontSize.Small
            textStyle.color: Color.White
            horizontalAlignment: HorizontalAlignment.Center
            textStyle.textAlign: TextAlign.Center
            textFit.mode: LabelTextFitMode.FitToBounds
        }

    }

}
