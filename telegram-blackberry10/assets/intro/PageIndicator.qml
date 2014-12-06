import bb.cascades 1.2

Container {
    id: root

    property variant indicatorColor
    property bool isActive
    property variant inactiveColor: Color.create("#dbdbdb")

    background: inactiveColor
    preferredHeight: 16
    preferredWidth: 16
    leftMargin: 20
    rightMargin: 20

    onIsActiveChanged: {
        if (isActive) {
            background = indicatorColor
        } else {
            background = inactiveColor
        }
    }

}
