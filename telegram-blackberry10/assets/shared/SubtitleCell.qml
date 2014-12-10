import bb.cascades 1.2

Container {

    property alias text: title.text
    property alias subtitle: _subtitle.text

    Label {
        id: title
        text: "Main text"
        bottomMargin: 0
    }
    Label {
        id: _subtitle
        text: "Subtitle"
        topMargin: 0
        textStyle {
            fontSize: FontSize.Small
            color: Color.Gray
        }
    }
}
