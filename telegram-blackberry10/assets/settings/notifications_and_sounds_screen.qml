import bb.cascades 1.2
import bb.cascades.pickers 1.0
import '../shared'

Page {
    id: notificationAndSoundsPage

    titleBar: TitleBar {
        title: 'Notifications and Sounds'
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }

    ScrollView {
        accessibility.name: "Content"

        Container {
            id: root

            Header {
                title: "Message Notifications"
                bottomMargin: 15
            }

            LabeledToggleButton {
                id: alert
                text: "Alert"
            }
            Divider {

            }
            LabeledToggleButton {
                id: messagePreview
                text: "Message Preview"
            }
            Divider {

            }
            Container {
                leftPadding: 20
                rightPadding: 20

                DropDown {
                    title: "Sound"
                    Option {
                        id: defaultSound
                        text: "Default"
                        selected: true
                    }
                }
            }
            Divider {

            }
            Header {
                title: "In-App Sounds"
                bottomMargin: 15
            }
            LabeledToggleButton {
                id: inAppSounds
                text: "In-App Sounds"
            }
            Divider {

            }
            LabeledToggleButton {
                id: inAppVibrate
                text: "In-App Vibrate"
                checked: false
            }
            Divider {

            }
            LabeledToggleButton {
                id: inAppPreview
                text: "In-App Preview"
            }
            Divider {

            }
            Header {
                title: "Reset"
            }
            ClickableRow {
                text: "Reset all Notifications"
                accessoryVisible: false
                topPadding: 32
                bottomPadding: 32
                onRowClicked: {
                    alert.checked = true
                    messagePreview.checked = true
                    defaultSound.selected = true
                    inAppSounds.checked = true
                    inAppVibrate.checked = false
                    inAppPreview.checked = true
                    
                }
            }

        }
    }

}