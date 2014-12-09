import bb.cascades 1.2
import "../chatsPage"


TabbedPane {
    id: root

    showTabsOnActionBar: true

    property bool showBackButton: false
    signal dismiss

    attachedObjects: [
        ComponentDefinition {
            id: cancelItem

        }
    ]

    onCreationCompleted: {
        console.log("Will show back buton: " + showBackButton)
        if (showBackButton) {
            contacts.dismissAction = closeItemContacts
            chat.dismissAction = closeItemChats
            settings.dismissAction = closeItemSettings
        }
    }

    Tab {
        title: "Contacts"
        imageSource: "asset:///images/main/attach_contact.png"
        MockContactsPage {
            titleBar: TitleBar {
                id: contacts
                title: "Contacts"
            }
            attachedObjects: [
                ActionItem {
                    id: closeItemContacts
                    title: "Close"
                    onTriggered: {
                        dismiss()
                    }
                }
            ]
        }
    }

    Tab {
        title: "Chats"
        imageSource: "asset:///images/main/bar_chats.png"
        
        
         ChatsPage {
            titleBar: TitleBar {
                id: chat
                title: "Chats"
            }
            attachedObjects: [
                ActionItem {
                    id: closeItemChats
                    title: "Close"
                    onTriggered: {
                        dismiss()
                    }
                }
            ]
        }
        
        
    }

    Tab {
        title: "Settings"
        imageSource: "asset:///images/main/bar_menu_settings.png"
        MockSettingsPage {
            titleBar: TitleBar {
                id: settings
                title: "Settings"
            }
            attachedObjects: [
                ActionItem {
                    id: closeItemSettings
                    title: "Close"
                    onTriggered: {
                        dismiss()
                    }
                }
            ]
        }
    }

}