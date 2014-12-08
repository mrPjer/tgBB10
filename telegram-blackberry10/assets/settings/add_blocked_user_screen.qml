import bb.cascades 1.2
import '../shared'

Page {
    titleBar: TitleBar {
        title: "Add User"
        dismissAction: ActionItem {
            id: editCancel
            title: "Cancel"
            onTriggered: {
                navigationPane.pop()
            }
        }
        acceptAction: ActionItem {
            id: editDone
            title: "Done"
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
