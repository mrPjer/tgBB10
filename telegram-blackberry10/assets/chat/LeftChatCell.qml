import bb.cascades 1.2

Container {
    property alias messageText: messageText.text
    property alias timeStamp: timeStamp.text
    preferredWidth: 600
    background: Color.create("#FFFFFF")
    layout: DockLayout {

    }
    topPadding: 10
    bottomPadding: 10
    leftPadding: 10
    rightPadding: 10
    bottomMargin: 10
    Label {
        id: messageText
        text: "Message text"
        multiline: true
        textStyle.color: Color.Black
        textStyle.fontSize: FontSize.Medium
    }
    Label {
        id: timeStamp
        text: "time"
        horizontalAlignment: HorizontalAlignment.Right
        verticalAlignment: VerticalAlignment.Bottom
        textStyle.color: Color.LightGray
        textStyle.fontSize: FontSize.XSmall
        topMargin: 5
        leftMargin: 5
    }
}
