import bb.cascades 1.2
import bb.cascades.pickers 1.0
import '../shared'

Page {
    id: notificationAndSoundsPage
    
    titleBar: TitleBar {
        title: 'Notifications and Sounds'
    }

    ScrollView {

        Container {
            id: root
            leftPadding: 8
            rightPadding: 8
            topPadding: 8
            bottomPadding: 8

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
            DropDown {
                title: "Sound"
                Option {
                    text: "Default"
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
            Container {
                topPadding: 15
                leftPadding: 20

                Label {
                    text: "Reset All Notifications"
                }
            }

        }
    }

}