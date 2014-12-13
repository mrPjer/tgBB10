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
                text: "Alert"
            }
            Divider {

            }
            LabeledToggleButton {
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
                text: "In-App Sounds"
            }
            Divider {

            }
            LabeledToggleButton {
                text: "In-App Vibrate"
                checked: false
            }
            Divider {

            }
            LabeledToggleButton {
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
            }

        }
    }

}