import bb.cascades 1.2
import bb.system 1.0

Container {
    id: cellRoot
    property alias avatar: chatAvatar.avatar
    property string chatName
    property string currentStatus
    property string lastUserActive
    property alias outgoingStatus: status.outgoingStatus
    property alias time: status.timeStamp
    property alias unreadCount: status.unreadMessagesCount
    property alias unreadVisible: status.unreadVisible
    property bool normalVisible
    property bool groupVisible
    property bool secretVisible
    property int fontWeight

    property string type

    preferredHeight: 80
    leftPadding: 0

    function fontType(unreadCount) {
        if (! showUnread(unreadCount)) {
            return FontWeight.Normal
        } else {
            return FontWeight.Bold
        }
    }

    function showUnread(unreadCount) {
        return unreadCount !== 0
    }

    Divider {
        id: divider
        bottomMargin: 0
        accessibility.name: "divider"
    }

    Container {
        id: cell
        bottomPadding: 2
        topPadding: 2
        leftMargin: 0
        leftPadding: 0
        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight

        }

        CellImageContainer {
            id: chatAvatar
            verticalAlignment: VerticalAlignment.Center
        }

        Label {
            id: spacer
            preferredWidth: 8
            leftMargin: 0
            rightMargin: 0
            text: ""
        }

        CellTextContainerNormal {
            id: textNormal
            name: chatName
            status: currentStatus
            verticalAlignment: VerticalAlignment.Center
            fontWeightStyle: cellRoot.fontWeight
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            visible: normalVisible

            contextActions: [
                ActionSet {
                    title: "Chat Actions"
                    subtitle: "Delete Chats"

                    actions: [
                        ActionItem {
                            title: "Delete"
                            imageSource: "asset:///images/chatsList/actions/menu_bin.png"

                            onTriggered: {
                                deleteChatDialog.show()
                            }
                        }
                    ]
                }
            ]

        }

        CellTextContainerGroup {
            id: textGroup
            name: chatName
            lastUser: lastUserActive
            status: currentStatus
            verticalAlignment: VerticalAlignment.Center
            fontWeightStyle: cellRoot.fontWeight
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            visible: groupVisible
            contextActions: [
                ActionSet {
                    title: "Chat Actions"
                    subtitle: "Delete And Exit Chats"

                    actions: [
                        ActionItem {
                            title: "Clear History"
                            imageSource: "asset:///images/chatsList/actions/menu_deletehistory.png"
                            onTriggered: {
                                clearHistoryDialog.show()
                            }
                        },
                        ActionItem {
                            title: "Delete And Exit"
                            imageSource: "asset:///images/chatsList/actions/menu_bin.png"
                            onTriggered: {
                                deleteChatAndExitDialog.show()
                            }
                        }
                    ]
                }
            ]
        }

        CellTextContainerSecret {
            id: textSecret
            name: chatName
            status: currentStatus
            verticalAlignment: VerticalAlignment.Center
            fontWeightStyle: cellRoot.fontWeight
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            visible: secretVisible
            contextActions: [
                ActionSet {
                    title: "Chat Actions"
                    subtitle: "Delete Chats"

                    actions: [
                        ActionItem {
                            title: "Delete"
                            imageSource: "asset:///images/chatsList/actions/menu_bin.png"

                            onTriggered: {
                                deleteChatDialog.show()
                            }
                        }
                    ]
                }
            ]
        }

        CellStatusContainer {
            id: status
        }

    }

    attachedObjects: [
        SystemDialog {
            id: deleteChatDialog
            title: "Delete"
            body: "Are you sure you want to delete this chat?"
            confirmButton.label: "Delete"

        },
        SystemDialog {
            id: deleteChatAndExitDialog
            title: "Delete And Exit"
            body: "Are you sure you want to leave this group?"
            confirmButton.label: "Delete and Exit"
        },
        SystemDialog {
            id: clearHistoryDialog
            title: "Clear Chat History"
            body: "Are you sure you want to delete chat history?"
            confirmButton.label: "Delete"
        }
    ]

}
