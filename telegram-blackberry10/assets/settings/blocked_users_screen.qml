import bb.cascades 1.2
import '../shared'

Page {
    titleBar: TitleBar {
        title: "Blocked Users"
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }
    attachedObjects: [
        ComponentDefinition {
            id: addBlockedUserPageDefinition
            source: "asset:///settings/add_blocked_user_screen.qml"
        }
    ]
    ContactList {
        source: "asset:///settings/blockedUsers.xml"
        showPhoneNumber: true
    }
    actions: [
        ActionItem {
            title: "Add User"
            ActionBar.placement: ActionBarPlacement.OnBar
            imageSource: "asset:///images/settings/menu_bar_contact_plus.png"
            onTriggered: {
                var newPage = addBlockedUserPageDefinition.createObject()
                navigationPane.push(newPage)
            }
        }
    ]
}
