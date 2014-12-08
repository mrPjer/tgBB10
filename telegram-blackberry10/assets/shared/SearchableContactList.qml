import bb.cascades 1.2

Container {
    Container {
        leftPadding: 15
        rightPadding: 15
        topPadding: 15
        bottomMargin: 15
        TextArea {
            text: "Search"
        }
    }
    ContactList {
        showHeader: true
        showStatus: true
        source: "asset:///settings/allContacts.xml"
    }
}
