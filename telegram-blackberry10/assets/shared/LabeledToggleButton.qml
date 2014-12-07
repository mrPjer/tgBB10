import bb.cascades 1.2

Container {
    id: labeledToggleButtonRoot
    layout: StackLayout {
        orientation: LayoutOrientation.LeftToRight
    }
    property alias text: label.text
    property alias checked: toggleButton.checked
    leftPadding: 20
    rightPadding: 20
    topPadding: 5
    bottomPadding: 5

    Label {
        id: label
        text: "Toggle button label"
        verticalAlignment: VerticalAlignment.Center
        layoutProperties: StackLayoutProperties {
            spaceQuota: 1
        }
    }
    ToggleButton {
        id: toggleButton
        verticalAlignment: VerticalAlignment.Center
        checked: true
    }
}