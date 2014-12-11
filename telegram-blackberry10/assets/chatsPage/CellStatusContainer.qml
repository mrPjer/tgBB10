import bb.cascades 1.2

Container {

    property alias timeStamp: timeStampLabel.text
    property string outgoingStatus
    property alias unreadMessagesCount: unreadMessagesLabel.text
    property alias unreadVisible: unreadMessagesContainer.visible

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
            textStyle.color: Color.create("#ff8b8985")
            textStyle.fontSize: FontSize.XXSmall
            horizontalAlignment: HorizontalAlignment.Right
            verticalAlignment: VerticalAlignment.Center

        }
    }

    Container {
        id: unreadMessagesContainer

        layout: StackLayout {
            orientation: orientation.LeftToRight
        }
        
        horizontalAlignment: HorizontalAlignment.Right
        topMargin: 10
        rightPadding: 20

        Container {
            
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            preferredHeight: 5
            preferredWidth: 20
            horizontalAlignment: HorizontalAlignment.Right
            background: Color.create("#ff299d44")
        //#ff5cb061
            Label {
                id: unreadMessagesLabel
                text: "10"
                textStyle.fontSize: FontSize.XXSmall
                textStyle.color: Color.White
                horizontalAlignment: HorizontalAlignment.Center
                textStyle.fontWeight: FontWeight.W900
                textStyle.textAlign: TextAlign.Center
                textFit.mode: LabelTextFitMode.FitToBounds

            }

        }

        Container {
            id: bla
            preferredWidth: 5
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }
    }
}
