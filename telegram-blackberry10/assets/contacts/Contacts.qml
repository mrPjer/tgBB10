import bb.cascades 1.2
import "../shared/"

Page {
    Container {
        SearchableContactList {
            id: contactList
            onTriggered: {
                console.log("Selected contact " + indexPath)
                var item = contactList.dataModel.data(indexPath)
                var page = contactDetailsPage.createObject()
                page.phoneNumber = "+" + item.phone
                page.contactName = item.name
                page.imageSource = item.imagePath
                navigationPane.push(page)
            }

            attachedObjects: ComponentDefinition {
                id: contactDetailsPage
                source: "asset:///contacts/ContactInfo.qml"
            }
        }
    }

    actions: [
        ActionItem {
            title: "Add new contact"
            imageSource: "asset:///images/contacts/menu_plus.png"
        },
        ActionItem {
            title: "Invite friends"
            imageSource: "asset:///images/contacts/menu_bar_contact_plus.png"
        },
        ActionItem {
            title: "New Secret Chat"
            imageSource: "asset:///images/contacts/menu_sectretchat.png"
        },
        ActionItem {
            title: "New Broadcast"
            imageSource: "asset:///images/contacts/menu_broadcast.png"
        }
    ]

}
