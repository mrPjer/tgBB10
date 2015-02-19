import bb.cascades 1.2
import TgApi 1.0
import '../shared'

Page {
    id: chatPage
    property alias chatName: chatTitleBar.chatName
    property alias chatImage: chatTitleBar.imagePath
    property alias peerId: dataModel.peerPhoneNumber
    property alias backgroundImageSource: backgroundImage.imageSource
    property alias enableSend: sendButton.enabled

    titleBar: TitleBar {
        kind: TitleBarKind.FreeForm
        scrollBehavior: TitleBarScrollBehavior.Sticky
        kindProperties: FreeFormTitleBarKindProperties {
            ChatTitleBar {
                id: chatTitleBar
                chatName: "Ante Kovach"
                chatStatus: dataModel.typingStatus
                imagePath: "asset:///images/testUsers/luka.jpg"
            }
        }
    }

    Container {
        id: root
        layout: DockLayout {
        }
        attachedObjects: [
            ChatDataModel {
                id: dataModel
            }
        ]

        ImageView {
            id: backgroundImage
            imageSource: "asset:///images/chat/background.jpg"
            scalingMethod: ScalingMethod.AspectFill
            preferredHeight: maxHeight
            preferredWidth: maxWidth
        }
        //TODO set visible only when no messages
        Container {
            id: noMessages
            visible: false
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            layout: DockLayout {

            }
            Container {
                preferredHeight: 300
                preferredWidth: 400
                background: Color.create("#89afb4")
                opacity: 0.5
            }

            Container {
                verticalAlignment: VerticalAlignment.Center
                horizontalAlignment: HorizontalAlignment.Center
                ImageView {
                    horizontalAlignment: HorizontalAlignment.Center
                    imageSource: "asset:///images/chat/logo.png"
                }
                Label {
                    text: "No messages yet..."
                    horizontalAlignment: HorizontalAlignment.Center
                    textStyle.color: Color.White
                }
            }
        }
        Container {
            layout: StackLayout {

            }
            //TODO show latest not first when screen is opened
            ListView {
                id: listView
                leftPadding: 10
                rightPadding: 10
                topPadding: 10

                dataModel: dataModel

                listItemComponents: [
                    ListItemComponent {
                        type: "inbound"
                        InboundChatCell {
                            messageText: ListItemData.messageText
                            timestamp: ListItemData.timestamp
                        }
                    },
                    ListItemComponent {
                        type: "outbound"
                        OutboundChatCell {
                            messageText: ListItemData.messageText
                            timestamp: ListItemData.timestamp
                            readVisible: ListItemData.readVisible
                            sentVisible: ListItemData.sentVisible
                            unsentVisible: ListItemData.unsentVisible
                            sendingVisible: ListItemData.sendingVisible
                        }
                    }
                ]
            }

            Container {
                verticalAlignment: VerticalAlignment.Bottom
                NewMessage {
                    id: newMessage
                }
            }
        }
    }

    actions: [
        ActionItem {
            title: "Attach"
            imageSource: "asset:///images/chat/bar_attach.png"
            ActionBar.placement: ActionBarPlacement.OnBar
        },
        ActionItem {
            id: sendButton
            title: "Send"
            imageSource: "asset:///images/chat/bar_send.png"
            ActionBar.placement: ActionBarPlacement.OnBar
            enabled: newMessage.haveText
            onTriggered: {
                dataModel.sendMessage(newMessage.body)
                newMessage.body = ""
            }
        },
        ActionItem {
            title: "Call"
            imageSource: "asset:///images/chat/menu_phone.png"
        },
        ActionItem {
            title: "About"
            imageSource: "asset:///images/chat/bar_profile.png"
        },
        ActionItem {
            title: "Shared Media"
            imageSource: "asset:///images/chat/menu_sharedmedia.png"
        },
        ActionItem {
            title: "Clear Chat"
            imageSource: "asset:///images/chat/menu_bin.png"
        }
    ]
    onCreationCompleted: {
        /*
        groupDataModel.insert({
                "messageType": "inbound",
                "messageText": "This is some text. I like trains. And Animu. And games. And Pizza. Yes. Pizza very much. And cats.",
                "timestamp": "5:06 PM"
            });
        groupDataModel.insert({
                "messageType": "outbound",
                "messageText": "Weaboo.",
                "timestamp": "5:12 PM",
                "readVisible": true
            });
        groupDataModel.insert({
                "messageType": "outbound",
                "messageText": "Such a weaboo.",
                "timestamp": "5:13 PM",
                "unsentVisible": true
            });
        groupDataModel.insert({
                "messageType": "outbound",
                "messageText": "I'm so funny.",
                "timestamp": "5:14 PM",
                "sentVisible": true
            });
            */
    }
}
