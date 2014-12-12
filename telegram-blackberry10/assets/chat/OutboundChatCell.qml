import bb.cascades 1.2

Container {
    property alias messageText: messageText.text
    property alias timestamp: timestamp.text
    property alias sentVisible: imageSent.visible
    property alias sendingVisible: imageSending.visible
    property alias readVisible: imageRead.visible
    property alias unsentVisible: imageUnsent.visible

    layout: StackLayout {
        orientation: LayoutOrientation.LeftToRight
    }
    bottomMargin: 10
    Container {
        layoutProperties: StackLayoutProperties {
            spaceQuota: 2
        }
    }
    Container {
        topPadding: 10
        bottomPadding: 10
        leftPadding: 10
        rightPadding: 10
        layoutProperties: StackLayoutProperties {
            spaceQuota: 8
        }
        background: Color.create("#E0FFCD")
        Container {

            Label {
                id: messageText
                text: "Message text"
                multiline: true
                textStyle.color: Color.Black
                textStyle.fontSize: FontSize.Medium
                rightMargin: 10
            }
            bottomPadding: 32
        }
        Container {
            horizontalAlignment: HorizontalAlignment.Right
            verticalAlignment: VerticalAlignment.Bottom
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            topMargin: 5
            leftMargin: 5
            ImageView {
                id: imageSent
                verticalAlignment: VerticalAlignment.Center
                imageSource: "asset:///images/chat/check_green.png"
                visible: false
            }
            ImageView {
                id: imageSending
                verticalAlignment: VerticalAlignment.Center
                imageSource: "asset:///images/chat/clocks_green.png"
                visible: false
            }
            ImageView {
                id: imageRead
                verticalAlignment: VerticalAlignment.Center
                imageSource: "asset:///images/chat/check_2_green.png"
                visible: false
            }
            ImageView {
                id: imageUnsent
                verticalAlignment: VerticalAlignment.Center
                imageSource: "asset:///images/chat/error.png"
                visible: false
            }
            Label {
                id: timestamp
                verticalAlignment: VerticalAlignment.Center
                leftMargin: 0
                text: "time"
                textStyle.color: unsentVisible ? Color.Red : Color.create("#75B166")
                textStyle.fontSize: FontSize.XSmall
            }
        }
    }
}
