import bb.cascades 1.2
import '../shared'

Page {
    titleBar: TitleBar {
        title: "Never Share"
    }
    attachedObjects: [
        ComponentDefinition {
            id: addNeverSharePageDefinition
            source: "asset:///settings/add_never_share_screen.qml"
        }
    ]
    ContactList {
        source: "asset:///settings/neverShare.xml"
    }
    actions: [
        ActionItem {
            title: "Add User"
            ActionBar.placement: ActionBarPlacement.OnBar
            imageSource: "asset:///images/settings/menu_bar_contact_plus.png"
            onTriggered: {
                var newPage = addNeverSharePageDefinition.createObject()
                navigationPane.push(newPage)
            }
        }
    ]
}
