import bb.cascades 1.2
import '../shared'

Page {
    titleBar: TitleBar {
        title: "Add User"
        scrollBehavior: TitleBarScrollBehavior.Sticky
        dismissAction: ActionItem {
            id: editCancel
            title: "Cancel"
            onTriggered: {
                navigationPane.pop()
            }
        }
    }

    Container {
        SearchableContactList {
        }
    }
}
