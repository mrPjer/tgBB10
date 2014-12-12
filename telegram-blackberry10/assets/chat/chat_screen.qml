import bb.cascades 1.2
import '../shared'

Page {

    property alias backgroundImageSource: backgroundImage.imageSource

    titleBar: TitleBar {
        kind: TitleBarKind.FreeForm
        kindProperties: FreeFormTitleBarKindProperties {
            ChatTitleBar {
                chatName: "Ana Kovach"
                chatStatus: "typing..."
                imagePath: "asset:///images/testUsers/luka.jpg"
            }
        }
    }

    Container {
        layout: DockLayout {
        }
        attachedObjects: [
            GroupDataModel {
                id: groupDataModel
                sortingKeys: [ "timestamp" ]
                grouping: ItemGrouping.None
            }
        ]

        ImageView {
            id: backgroundImage
            imageSource: "asset:///images/testUsers/pjer.jpg"
            scalingMethod: ScalingMethod.AspectFill
            preferredHeight: maxHeight
            preferredWidth: maxWidth
        }
        Container {

            ListView {
                leftPadding: 10
                rightPadding: 10
                topPadding: 10

                dataModel: groupDataModel

                function itemType(data, indexPath) {
                    return data.messageTypeInbound ? "inbound" : "outbound"
                }

                listItemComponents: [
                    ListItemComponent {
                        type: "inbound"
                        InboundChatCell {
                            messageText: ListItemData.messageText
                            timestamp: ListItemData.timestamp
                        }
                    },
                    // TODO load the proper chat cell directly
                    ListItemComponent {
                        type: "outbound"
                        OutboundChatCell {
                            messageText: ListItemData.messageText
                            timestamp: ListItemData.timestamp
                        }
                    },
                    ListItemComponent {
                        type: "outbound"
                        OutboundChatCell {
                            messageText: ListItemData.messageText
                            timestamp: ListItemData.timestamp
                        }
                    }
                ]
            }
        }
        NewMessage {
            id: newMessage
        }
    }

    actions: [
        ActionItem {
            title: "Attach"
            imageSource: "asset:///images/chat/bar_attach.png"
            ActionBar.placement: ActionBarPlacement.OnBar
        },
        ActionItem {
            title: "Send"
            imageSource: "asset:///images/chat/bar_send.png"
            ActionBar.placement: ActionBarPlacement.OnBar
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
        groupDataModel.insert({
                // TODO: messageType should be just inbound or outbound
                "messageTypeInbound": true,
                "messageText": "This is some text. I like trains. And Animu. And games. And Pizza. Yes. Pizza very much. And cats.",
                "timestamp": "5:06 PM"
            });
        groupDataModel.insert({
                "messageTypeInbound": false,
                "messageText": "Weaboo.",
                "timestamp": "5:12 PM"
            });
        groupDataModel.insert({
                "messageTypeInbound": false,
                "messageText": "Weabooooooooooooo.",
                "timestamp": "5:13 PM"
        });
    }
}
