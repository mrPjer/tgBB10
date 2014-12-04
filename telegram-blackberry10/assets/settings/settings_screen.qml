import bb.cascades 1.2
import bb.cascades.pickers 1.0
import '../shared'

Page {
    titleBar: TitleBar {
        title: 'Settings'
    }
    ScrollView {

        Container {
            id: root
            leftPadding: 40
            rightPadding: 40
            topPadding: 40
            bottomPadding: 40

            Container {
                id: user
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }

                ImageView {
                    id: avatar
                    preferredHeight: 180
                    preferredWidth: 180
                    scalingMethod: ScalingMethod.AspectFill
                    imageSource: "asset:///images/shared/bar_profile.png"
                }
                Container {
                    layout: StackLayout {

                    }
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1
                    }

                    Label {
                        id: userName
                        text: "Daniel Ash"
                        textStyle.fontSize: FontSize.Small
                    }
                    Label {
                        id: userStatus
                        text: "online"
                        textStyle.color: Color.Blue
                        textStyle.fontSize: FontSize.XSmall
                    }
                    Label {
                        id: phoneNumber
                        text: "+44 7400 890000"
                        textStyle.fontSize: FontSize.Small
                    }
                }
                Container {
                    preferredWidth: 1
                    preferredHeight: 80
                    background: Color.Gray
                    verticalAlignment: VerticalAlignment.Center
                }

                ImageButton {
                    defaultImageSource: "asset:///images/shared/menu_bar_edit.png"
                    verticalAlignment: VerticalAlignment.Center

                }
            }
            Header {
                title: "Settings"

            }
            DropDown {
                title: "Language"
                Option {
                    text: "English"
                }
                Option {
                    text: "Spanish"
                }
                Option {
                    text: "German"
                }
                Option {
                    text: "Italian"
                }

            }
            Divider {

            }
            Container {

            }
            Container {
                layout: StackLayout {

                }
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                ClickableRow {
                    text: "Notifications and Sounds"
                }
                Divider {

                }
                ClickableRow {
                    text: "Privacy and Security"
                }
                Divider {

                }
                ClickableRow {
                    text: "Chat Settings"
                }
                Divider {

                }
                ClickableRow {
                    text: "Chat Background"
                }
                Divider {

                }

            }
            Container {
                Button {
                    text: "Log Out"
                    preferredWidth: maxWidth
                }
            }

            Label {
                text: "Telegram for Blackberry v0.1"
                textStyle.fontSize: FontSize.XXSmall
                textStyle.color: Color.LightGray
                horizontalAlignment: HorizontalAlignment.Center
            }
        }

    }
}