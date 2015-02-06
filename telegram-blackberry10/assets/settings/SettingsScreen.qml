import bb.cascades 1.2
import bb.system 1.0
import TgApi 1.0
import '../shared'

Page {
    property string userFullName: ""
    property string userPhoneNumber: ""
    property string userUsername: ""
    property string userAvatar: ""

    titleBar: TitleBar {
        title: 'Settings'
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }
    attachedObjects: [
        UserInfoApi {
            id: userInfoApi
            onSelfUserKnown: {
                userFullName = userInfoApi.selfFirstName() + " " + userInfoApi.selfLastName()
                userPhoneNumber = userInfoApi.selfPhone()
                userUsername = userInfoApi.selfUsername()
                userAvatar = avatarUtil.getAvatarPath(userPhoneNumber)
            }
        },
        AvatarUtil {
            id: avatarUtil
        },
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
        },
        ComponentDefinition {
            id: chatSettingsPageDefinition
            source: "asset:///settings/chat_settings_screen.qml"
        },
        ComponentDefinition {
            id: chatBackgroundPageDefinition
            source: "asset:///settings/chat_background_screen.qml"
        }
    ]
    ScrollView {
        accessibility.name: "Content"

        Container {
            id: root

            topPadding: 8
            bottomPadding: 8

            Container {
                id: user
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }

                Container {
                    layout: AbsoluteLayout {
                    }
                    preferredHeight: 180
                    preferredWidth: 180

                    ImageView {
                        id: avatarPlaceholder
                        accessibility.name: "Avatar placeholder"
                        preferredHeight: 160
                        preferredWidth: 160
                        layoutProperties: AbsoluteLayoutProperties {
                            positionX: 10
                            positionY: 10
                        }
                        scalingMethod: ScalingMethod.AspectFill
                        imageSource: "asset:///images/settings/bar_profile.png"
                    }

                    ImageView {
                        id: avatar
                        accessibility.name: "Avatar"
                        preferredHeight: 160
                        preferredWidth: 160
                        layoutProperties: AbsoluteLayoutProperties {
                            positionX: 10
                            positionY: 10
                        }
                        scalingMethod: ScalingMethod.AspectFill
                        imageSource: userAvatar
                    }
                }

                Container {
                    layout: StackLayout {

                    }
                    layoutProperties: StackLayoutProperties {
                        spaceQuota: 1
                    }

                    topPadding: 10

                    Label {
                        id: userName
                        text: userFullName + (userUsername ? " (@" + userUsername + ")" : "")
                        textStyle.fontSize: FontSize.Medium
                        bottomMargin: 8
                    }
                    Label {
                        id: userStatus
                        text: "online"
                        textStyle.color: Color.Blue
                        textStyle.fontSize: FontSize.Small
                        topMargin: 0
                        bottomMargin: 8
                    }
                    Label {
                        id: phoneNumber
                        text: "+" + userPhoneNumber
                        textStyle.fontSize: FontSize.Small
                        topMargin: 0
                    }
                }
                Container {
                    preferredWidth: 1
                    preferredHeight: 80
                    background: Color.Gray
                    verticalAlignment: VerticalAlignment.Center
                }
                Container {
                    rightPadding: 20
                    leftMargin: 20
                    verticalAlignment: VerticalAlignment.Center
                    ImageButton {
                        accessibility.name: "Edit profile"
                        defaultImageSource: "asset:///images/settings/profile_edit.png"

                        onClicked: {
                            var newPage = editPageDefinition.createObject()
                            navigationPane.push(newPage)
                        }
                    }

                }
            }
            Header {
                title: "Settings"

            }
            Container {
                leftPadding: 20
                rightPadding: 20
                topPadding: 15
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

                    onRowClicked: {
                        var newPage = chatSettingsPageDefinition.createObject()
                        navigationPane.push(newPage)
                    }
                }
                Divider {

                }
                ClickableRow {
                    text: "Chat Background"

                    onRowClicked: {
                        var newPage = chatBackgroundPageDefinition.createObject()
                        navigationPane.push(newPage)
                    }
                }
                Divider {

                }

            }
            Container {
                Container {
                    leftPadding: 20
                    rightPadding: 20
                    topPadding: 15
                    Button {
                        text: "Log Out"
                        preferredWidth: maxWidth
                        onClicked: {
                            logOut.show();
                        }
                    }

                    attachedObjects: [
                        SystemDialog {
                            id: logOut
                            title: "Log Out"
                            body: "Are you sure you want to log out?"
                            confirmButton.label: "Log Out"
                            onFinished: {
                                if (result == SystemUiResult.ConfirmButtonSelection) {
                                    session.clearSession()
                                    Application.quit()
                                }
                            }
                        },
                        Session {
                            id: session
                        }
                    ]
                }
                Label {
                    text: "Telegram for BlackBerry v" + Application.applicationVersion
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
            imageSource: "asset:///images/settings/menu_bar_edit.png"
            onTriggered: {
                var newPage = editPageDefinition.createObject()
                navigationPane.push(newPage)
            }

        },
        ActionItem {
            title: "Ask a Question"
            imageSource: "asset:///images/settings/menu_FAQ.png"
        },
        ActionItem {
            title: "Telegram FAQ"
            imageSource: "asset:///images/settings/menu_FAQ.png"
            onTriggered: {
                tgFAQInvocation.trigger("bb.action.OPEN")
            }

            attachedObjects: [
                Invocation {
                    id: tgFAQInvocation
                    query: InvokeQuery {
                        uri: "https://telegram.org/faq"
                        invokeActionId: "bb.action.OPEN"
                    }
                }
            ]
        },
        ActionItem {
            title: "Log Out"
            imageSource: "asset:///images/settings/menu_logout.png"
            onTriggered: {
                logOut.show()
            }
        }
    ]

}