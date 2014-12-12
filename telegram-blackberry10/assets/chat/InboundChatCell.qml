import bb.cascades 1.2

Container {
    property alias messageText: messageText.text
    property alias timestamp: timestamp.text

    layout: StackLayout {
        orientation: LayoutOrientation.LeftToRight
    }
    
    bottomMargin: 10
    Container {
        topPadding: 10
        bottomPadding: 10
        leftPadding: 10
        rightPadding: 10
        background: Color.create("#FFFFFF")
        layoutProperties: StackLayoutProperties {
            spaceQuota: 8
        }
        Container {
            bottomPadding: 32
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
            topMargin: 5
            leftMargin: 5
            Label {
                id: timestamp
                text: "time"
                textStyle.color: Color.LightGray
                textStyle.fontSize: FontSize.XSmall
            }
        }
    }
    Container {
        layoutProperties: StackLayoutProperties {
            spaceQuota: 2
        }
    }
}