import bb.cascades 1.2

Container {
    readonly property bool haveText: newMessage.text.length > 0
    preferredHeight: 130
    background: Color.create("#282929")
    layout: StackLayout {
        orientation: LayoutOrientation.LeftToRight
    }
    property alias body: newMessage.text
    Container {
        verticalAlignment: VerticalAlignment.Center
        preferredWidth: 100
        ImageButton {
            id: speakButton
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            preferredWidth: 100
            defaultImageSource: "asset:///images/chat/bar_voice1.png"
        }
    }
    TextArea {
        verticalAlignment: VerticalAlignment.Center
        id: newMessage
        hintText: "Enter a message"
        leftMargin: 0
        rightMargin: 0
    }
    Container {
        verticalAlignment: VerticalAlignment.Center
        preferredWidth: 100
        ImageButton {
            id: emoji
            defaultImageSource: "asset:///images/chat/bar_smile.png"
            horizontalAlignment: HorizontalAlignment.Center
        }
    }
}
