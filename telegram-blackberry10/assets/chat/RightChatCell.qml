import bb.cascades 1.2

Container {
    property alias messageText: messageText.text
    property alias timeStamp: timeStamp.text
    property alias sentVisible: imageSent.visible
    property alias sendingVisible: imageSending.visible
    property alias readVisible: imageRead.visible
    property alias unsentVisible: imageUnsent.visible

    preferredWidth: 600
    background: Color.create("#E0FFCD")
    layout: DockLayout {

    }
    topPadding: 10
    bottomPadding: 10
    leftPadding: 10
    rightPadding: 10
    bottomMargin: 10
    horizontalAlignment: HorizontalAlignment.Right
    Container {
        Label {
            id: messageText
            text: "Message text"
            multiline: true
            textStyle.color: Color.Black
            textStyle.fontSize: FontSize.Medium
        }
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
            id: timeStamp
            verticalAlignment: VerticalAlignment.Center
            leftMargin: 0
            text: "time"
            textStyle.color: unsentVisible ? Color.Red : Color.create("#75B166")
            textStyle.fontSize: FontSize.XSmall
        }
    }
}
