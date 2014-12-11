import bb.cascades 1.2

Container {

    property alias name: chatName.text
    property alias status: chatCurrentStatus.text
    property int fontWeightStyle

    layout: StackLayout {
    }
    Label {
        id: chatName
        text: "test name"
        textStyle.fontSize: FontSize.Small
        bottomMargin: 0
        textStyle.fontWeight: fontWeightStyle

    }

    Label {
        id: chatCurrentStatus
        text: "test status"
        textStyle.fontSize: FontSize.XSmall
        topMargin: 0

    }

}
