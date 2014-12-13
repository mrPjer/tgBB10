import bb.cascades 1.2

Container {

    id: clickableRowRoot

    property alias text: label.text
    property alias rightText: rightLabel.text
    property alias accessoryVisible: accessory.visible
    signal rowClicked()

    verticalAlignment: VerticalAlignment.Center
    layout: DockLayout {
    }

    Container {
        verticalAlignment: VerticalAlignment.Center

        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }
        leftPadding: 20
        rightPadding: 20
        topPadding: 5
        bottomPadding: 5

        Label {
            id: label
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }

            text: "Settings label"
        }
        Label {
            id: rightLabel
            text: ""

        }
        ImageView {
            id: accessory
            imageSource: "asset:///images/shared/setting_arrow.png"
            verticalAlignment: VerticalAlignment.Center
            accessibility.name: "Arrow indicator"
        }

        onTouch: {
            if (event.isUp()) {
                rowClicked()
            }
        }
    }
}
