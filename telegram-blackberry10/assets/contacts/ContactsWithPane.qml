import bb.cascades 1.2

NavigationPane {
    id: navigationPane

    property alias titleBar: contacts.titleBar

    Contacts {
        id: contacts
    }
}