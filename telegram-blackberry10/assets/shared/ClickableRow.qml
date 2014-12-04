import bb.cascades 1.2

Container {
    id: clickableRowRoot
    layout: StackLayout {
        orientation: LayoutOrientation.LeftToRight
    }
    property alias text: label.text
    leftPadding: 40
    rightPadding: 40
    topPadding: 5
    bottomPadding: 5

    Label {
        id: label
        text: "Settings label"
        textStyle.fontSize: FontSize.XLarge
        verticalAlignment: VerticalAlignment.Center
        layoutProperties: StackLayoutProperties {
            spaceQuota: 1
        }
    }
    ImageView {
        imageSource: "asset:///images/shared/setting_arrow.png"
        verticalAlignment: VerticalAlignment.Center
        accessibility.name: "Arrow indicator"
    }
}