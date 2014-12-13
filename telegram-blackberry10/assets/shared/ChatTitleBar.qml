import bb.cascades 1.2

Container {
    property alias imagePath: image.imageSource
    property alias chatName: name.text
    property alias chatStatus: status.text
    layout: StackLayout {
        orientation: LayoutOrientation.LeftToRight
    }
    ImageView {
        id: image
        preferredWidth: 100
        topMargin: 0
        bottomMargin: 0
        verticalAlignment: VerticalAlignment.Center
        imageSource: "asset:///images/chat/bar_profile.png"
        scalingMethod: ScalingMethod.AspectFill

    }
    Container {
        leftPadding: 10
        verticalAlignment: VerticalAlignment.Center
        Label {
            id: name
            text: "Chat name"
            textStyle.color: Color.White
            bottomMargin: 0
        }
        Label {
            id: status
            text: "chat status"
            topMargin: 0
            textStyle.color: Color.create("#D8EDF9")
            textStyle.fontSize: FontSize.Small
        }
    }
}
