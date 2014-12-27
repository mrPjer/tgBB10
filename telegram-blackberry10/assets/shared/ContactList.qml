import bb.cascades 1.2
import TgApi 1.0

Container {
    id: usersList
    // TODO remove property source
    property variant source
    property alias showPhoneNumber: listView.showPhoneNumber
    property alias showStatus: listView.showStatus
    property alias showHeader: listView.showHeader

    property alias dataModel: listView.dataModel

    signal triggered(variant indexPath)

    onCreationCompleted: {
        listView.triggered.connect(triggered)
        updateContacts()
    }

    function updateContacts() {
        dataModel.clear()
        var contacts = api.contactList()
        for (var idx in contacts) {
            var phone = contacts[idx]
            var firstName = api.contactFirstName(phone)
            var lastName = api.contactLastName(phone)

            // TODO show correct image
            var imagePath = "asset:///images/testUsers/user_placeholder_purple.png"
            var name = firstName + " " + lastName

            // TODO fill status - right now it returns undefined
            var status = api.contactStatus(phone)

            if (status == ContactStatus.ContactStatusUnknown) {
                status = "unknown"
            } else if (status == ContactStatus.ContactStatusOffline) {
                status = "offline"
            } else if (status == ContactStatus.ContactStatusOnline) {
                status = "online"
            } else {
                status = "Unknown status type - " + status
            }

            var contact = {
                name: name,
                phone: phone,
                status: status,
                imagePath: imagePath
            }

            dataModel.insert(contact)
        }
    }

    ListView {
        id: listView
        property bool showPhoneNumber: false
        property bool showStatus: false
        property bool showHeader: false

        function itemType(data, indexPath) {
            if (indexPath.length == 1) {
                return "header"
            } else {
                return "contact"
            }
        }

        dataModel: GroupDataModel {
            id: dataModel
            sortingKeys: [ "name" ]
            grouping: ItemGrouping.ByFirstChar
        }
        attachedObjects: ContactsApi {
            id: api
            onContactListChanged: {
                console.log("Contact list changed")
                updateContacts()
            }
            onContactStatusChanged: {
                console.log("Contact status changed for " + phone + " to " + status)
                updateContacts()
            }
        }
        listItemComponents: [
            ListItemComponent {
                type: "contact"

                CustomListItem {
                    id: itemRoot
                    Container {

                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        ImageView {
                            id: image
                            preferredHeight: 115
                            preferredWidth: 115
                            imageSource: ListItemData.imagePath
                            scalingMethod: ScalingMethod.AspectFill
                        }
                        Container {
                            verticalAlignment: VerticalAlignment.Center

                            Label {
                                id: name
                                bottomMargin: 0
                                verticalAlignment: VerticalAlignment.Center
                                text: ListItemData.name
                                textStyle.fontSize: FontSize.Large
                            }
                            Label {
                                id: phone
                                visible: itemRoot.ListItem.view.showPhoneNumber
                                topMargin: 0
                                text: ListItemData.phone
                                textStyle.color: Color.Gray
                            }
                            Label {
                                id: status
                                visible: itemRoot.ListItem.view.showStatus
                                topMargin: 0
                                text: ListItemData.status
                                textStyle.fontSize: FontSize.Small
                                textStyle.color: status.text === "online" ? Color.Blue : Color.LightGray
                            }
                        }
                    }
                }
            }
        ]
    }
}
