import bb.cascades 1.2
import TgApi 1.0

Page {
    property alias unreadCount: dataModel.unreadCount

    attachedObjects: [
        ChatsDataModel {
            id: dataModel
        }
    ]

    Container {
        id: root
        layout: DockLayout {
        }

        ListView {
            dataModel: dataModel

            onTriggered: {
                var page = chatPage.createObject()

                var item = dataModel.data(indexPath)
                page.chatName = item.chatName
                page.chatImage = item.chatAvatar
                navigationPane.push(page)
            }

            attachedObjects: ComponentDefinition {
                id: chatPage
                source: "asset:///chat/chat_screen.qml"
            }

            listItemComponents: [
                ListItemComponent {
                    type: "normalChat"
                    ChatCell {
                        type: "normalChat"
                        avatar: ListItemData.chatAvatar
                        chatName: ListItemData.chatName
                        currentStatus: ListItemData.chatDescription
                        outgoingStatus: ListItemData.outgoingStatus
                        fontWeight: fontType(ListItemData.unreadCount)
                        unreadVisible: showUnread(ListItemData.unreadCount)
                        time: ListItemData.timeStamp
                        unreadCount: ListItemData.unreadCount
                        normalVisible: true
                        groupVisible: false
                        secretVisible: false
                    }

                },
                ListItemComponent {
                    type: "groupChat"
                    ChatCell {
                        type: "groupChat"
                        avatar: ListItemData.chatAvatar
                        chatName: ListItemData.chatName
                        currentStatus: ListItemData.chatDescription
                        lastUserActive: ListItemData.lastSender
                        outgoingStatus: ListItemData.outgoingStatus
                        fontWeight: fontType(ListItemData.unreadCount)
                        unreadVisible: showUnread(ListItemData.unreadCount)
                        time: ListItemData.timeStamp
                        unreadCount: ListItemData.unreadCount
                        normalVisible: false
                        groupVisible: true
                        secretVisible: false

                    }
                },

                ListItemComponent {
                    type: "secretChat"
                    ChatCell {
                        type: "secretChat"
                        avatar: ListItemData.chatAvatar
                        chatName: ListItemData.chatName
                        currentStatus: ListItemData.chatDescription
                        outgoingStatus: ListItemData.outgoingStatus
                        fontWeight: fontType(ListItemData.unreadCount)
                        unreadVisible: showUnread(ListItemData.unreadCount)
                        time: ListItemData.timeStamp
                        unreadCount: ListItemData.unreadCount
                        normalVisible: false
                        groupVisible: false
                        secretVisible: true

                    }
                }
            ]

            accessibility.name: "list view"

        }
    }

    actions: [
        ActionItem {
            title: "New Chat"
            imageSource: "asset:///images/chatsList/actions/menu_bar_chat.png"
        },
        ActionItem {
            title: "New Group"
            imageSource: "asset:///images/chatsList/actions/menu_group.png"
        },
        ActionItem {
            title: "New Secret Chat"
            imageSource: "asset:///images/chatsList/actions/menu_sectretchat.png"
        },
        ActionItem {
            title: "New Broadcast"
            imageSource: "asset:///images/chatsList/actions/menu_broadcast.png"
        }
    ]
}
