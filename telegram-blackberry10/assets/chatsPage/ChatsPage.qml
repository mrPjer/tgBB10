import bb.cascades 1.2

Page {

    Container {
        id: root
        layout: DockLayout {
        }

        attachedObjects: [
            // Add a data model that sorts based on the name property
            GroupDataModel {
                id: groupDataModel
                sortingKeys: [ "timeStamp" ]

                sortedAscending: false
                grouping: ItemGrouping.None

            }
        ]

        ListView {
            dataModel: groupDataModel

            function itemType(data, indexPath) {
                if (data["chatType"] == "normal") {
                    return "normalChat";
                } else if (data["chatType"] == "group") {
                    return "groupChat";
                } else {
                    return "secretChat"
                }
            }

            onTriggered: {
                var page = chatPage.createObject()
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

            //mocked data for testing
            onCreationCompleted: {
                groupDataModel.insert({
                        "chatName": "Damien's Shark",
                        "chatType": "group",
                        "chatDescription": "So you've come for some shark hunting?",
                        "lastSender": "Tob:",
                        "chatAvatar": "asset:///images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_cyan.png",
                        "outgoingStatus": "none",
                        "timeStamp": "5:06 PM",
                        "unreadCount": "3"
                    });
                groupDataModel.insert({
                        "chatName": "Adam Smith",
                        "chatType": "group",
                        "chatDescription": "Very cool! I'm not so surprised.",
                        "lastSender": "You:",
                        "chatAvatar": "asset:///images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_orange.png",
                        "outgoingStatus": "seen",
                        "timeStamp": "2:27 PM",
                        "unreadCount": "0"
                    });
                groupDataModel.insert({
                        "chatName": "Anastasiya Shy",
                        "chatType": "normal",
                        "chatDescription": "It's raining women",
                        "lastSender": "typing..",
                        "chatAvatar": "asset:///images/chatsList/chatAvatars/SingleChatAvatars/user_placeholder_pink.png",
                        "outgoingStatus": "none",
                        "timeStamp": "2:24 PM",
                        "unreadCount": "0"
                    });
                groupDataModel.insert({
                        "chatName": "Samus Aran",
                        "chatType": "secret",
                        "chatDescription": "Well I know everything about that.",
                        "lastSender": "You",
                        "chatAvatar": "asset:///images/chatsList/chatAvatars/SingleChatAvatars/user_placeholder_yellow.png",
                        "outgoingStatus": "none",
                        "timeStamp": "2:24 PM",
                        "unreadCount": "0"
                    });
            }

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
