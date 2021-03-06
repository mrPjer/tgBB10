import bb.cascades 1.2
import '../shared'

Page {
    id: chatSettingsPage

    titleBar: TitleBar {
        title: 'Chat Settings'
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }

    ScrollView {
        accessibility.name: "Content"

        Container {
            id: root

            Header {
                title: "Automatic Photo Download"
                bottomMargin: 15

            }

            LabeledToggleButton {
                text: "Private Chats"

            }
            Divider {

            }
            LabeledToggleButton {
                text: "Groups"
            }
            Divider {

            }

            Header {
                title: "Automatic Audio download"
                bottomMargin: 15
            }
            LabeledToggleButton {
                text: "Private Chats"
            }
            Divider {

            }
            LabeledToggleButton {
                text: "Groups"
            }
            Divider {

            }
            LabeledToggleButton {
                text: "Autoplay Audio"
                checked: false
            }
        }
    }

}