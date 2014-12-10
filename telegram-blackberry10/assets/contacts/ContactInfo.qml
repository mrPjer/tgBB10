import bb.cascades 1.2
import "../shared/"

Page {

    property alias contactName: name.text
    property alias contactStatus: status.text
    property alias image: avatar.image
    property alias imageSource: avatar.imageSource

    Container {

        Container {
            leftPadding: 22
            topPadding: 22
            bottomPadding: 22
            rightPadding: 22

            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }

            ImageView {
                id: avatar
                accessibility.name: "Contact image"
                preferredHeight: 180
                preferredWidth: 180
                imageSource: "asset:///images/testUsers/user_placeholder_blue.png"
            }

            Container {

                leftPadding: 24
                verticalAlignment: VerticalAlignment.Center

                Label {
                    id: name
                    text: "Daniel Ash"
                    textStyle {
                        fontSize: FontSize.Large
                    }
                    bottomMargin: 0
                }
                Label {
                    id: status
                    topMargin: 0
                    text: "last seen at 2:34 PM"
                    textStyle {
                        color: Color.Gray
                    }
                }
            }

        }

        Header {
            title: "Phone"
        }

        SubtitleCell {
            text: "+44 7400 890000"
            subtitle: "Mobile"
            leftPadding: 24
            topPadding: 24
            rightPadding: 24
        }

        Divider {
        }

        Header {
            title: "Settings"
            bottomMargin: 24
        }

        LabeledToggleButton {
            text: "Notifications"
        }

        Divider {
        }

        ClickableRow {
            text: "Shared Media"
            rightText: "87"
            topPadding: 24
            bottomPadding: 24
        }

        Divider {
        }

    }
}
