import bb.cascades 1.2
import '../shared'

Page {
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
        ImageView {
            imageSource: "asset:///images/testUsers/pjer.jpg"
            scalingMethod: ScalingMethod.AspectFill
            preferredHeight: maxHeight
        }
        Container {
            topPadding: 10
            leftPadding: 10
            rightPadding: 10
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            LeftChatCell {
                messageText: "This is some text. I like trains. And Animu. And games. And Pizza. Yes. Pizza very much. And cats."
                timeStamp: "11:53 PM"
            }
            RightChatCell {
                messageText: "This is my response. I like trains too. We should go to the train station together, sometime. And get some pizza. Would you like that?"
                timeStamp: "00:02 AM"
                unsentVisible: true
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
}
