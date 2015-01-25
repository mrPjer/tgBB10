import bb.cascades 1.2

NavigationPane {
    id: navigationPane

    property alias titleBar: chatsPage.titleBar
    property alias unreadCount: chatsPage.unreadCount

    ChatsPage {
        id: chatsPage
    }
}