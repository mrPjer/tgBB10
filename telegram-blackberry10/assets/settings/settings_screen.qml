import bb.cascades 1.2
import bb.cascades.pickers 1.0
import '../shared'

Page {
    titleBar: TitleBar {
        title: 'Settings'
    }
    attachedObjects: [
        ComponentDefinition {
            id: editPageDefinition
            source: "asset:///settings/edit_screen.qml"
        },
        ComponentDefinition {
            id: notificationsAndSoundsPageDefinition
            source: "asset:///settings/notifications_and_sounds_screen.qml"
        },
        ComponentDefinition {
            id: privacyAndSecurityPageDefinition
            source: "asset:///settings/privacy_and_security_screen.qml"
        }
    ]
    ScrollView {

        Container {
            id: root
            leftPadding: 8
            rightPadding: 8
            topPadding: 8
            bottomPadding: 8

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
                        textStyle.fontSize: FontSize.Medium
                    }
                    Label {
                        id: userStatus
                        text: "online"
                        textStyle.color: Color.Blue
                        textStyle.fontSize: FontSize.Small
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
                    defaultImageSource: "asset:///images/shared/profile_edit.png"
                    verticalAlignment: VerticalAlignment.Center
                    onClicked: {
                        var newPage = editPageDefinition.createObject()
                        navigationPane.push(newPage)
                    }

                }
            }
            Header {
                title: "Settings"

            }
            DropDown {
                title: "Language"
                Option {
                    text: "English"
                    selected: true
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
                layout: StackLayout {

                }
                layoutProperties: StackLayoutProperties {

                }
                ClickableRow {
                    text: "Notifications and Sounds"
                    
                    onRowClicked: {
                        var newPage = notificationsAndSoundsPageDefinition.createObject()
                        navigationPane.push(newPage)
                    }
                }
                Divider {

                }
                ClickableRow {
                    text: "Privacy and Security"
                    
                    onRowClicked: {
                        var newPage = privacyAndSecurityPageDefinition.createObject()
                        navigationPane.push(newPage)
                    }
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
                Label {
                    text: "Telegram for Blackberry v0.1"
                    textStyle.fontSize: FontSize.XXSmall
                    textStyle.color: Color.LightGray
                    horizontalAlignment: HorizontalAlignment.Center
                }
            }

        }
    }
    actions: [
        ActionItem {
            title: "Edit"
            imageSource: "asset:///images/shared/menu_bar_edit.png"
            onTriggered: {
                var newPage = editPageDefinition.createObject()
                navigationPane.push(newPage)
            }

        },
        ActionItem {
            title: "Ask a Question"
            imageSource: "asset:///images/shared/menu_FAQ.png"
        },
        ActionItem {
            title: "Telegram FAQ"
            imageSource: "asset:///images/shared/menu_FAQ.png"
        },
        ActionItem {
            title: "Log Out"
            imageSource: "asset:///images/shared/menu_logout.png"
        }
    ]

}