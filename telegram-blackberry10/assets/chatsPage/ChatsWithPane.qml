import bb.cascades 1.2

NavigationPane {
    id: navigationPane

    property alias titleBar: chatsPage.titleBar

    ChatsPage {
        id: chatsPage
    }
}