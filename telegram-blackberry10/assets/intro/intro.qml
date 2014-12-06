import bb.cascades 1.2

Page {
    Container {
        id: root

        //track on which page we are currently
        property int pagenumber: 0

        //properties for swiping
        property int touchEnteredX: 0
        property int touchEndX: 0

        property variant title: [ "Telegram", "Fast", "Free", "Secure", "Powerful", "Cloud-Based", "Private" ]

        property variant text: [ "The world's <b>fastest</b> messaging app.\nIt is <b>free</b> and <b>secure</b>.",
            "<b>Telegram</b> delivers messages\nfaster than any other application.",
            "<b>Telegram</b> is free forever. No ads.\nNo subscription fees.",
            "<b>Telegram</b> keeps your messages\nsafe from hacker attacks.",
            "<b>Telegram</b> has no limit on\nthe size of your chats and media.",
            "<b>Telegram</b> lets you access your\n messages from multiple devices.",
            "<b>Telegram</b> messages are heavily\nencrypted and can self-destruct." ]

        property variant pageIndicatorActiveColor: [ "#ff00a6df", "#ffef4d3e", "#fff1bf5b", "#ff62c657", "#ff956fbc", "#ff00bfd3", "#ffff8c4d" ]

        property string image: "asset:///images/Intro/intro1.png"

        Container {
            id: emptySpaceTop
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }

        // Container from which you can swipe and change through different messages
        Container {
            preferredWidth: maxWidth
            verticalAlignment: VerticalAlignment.Center

            layoutProperties: StackLayoutProperties {
                spaceQuota: 5
            }

            // Logo
            ImageView {
                imageSource: root.image.replace(/[0-9]/, (root.pagenumber + 1).toString())
                horizontalAlignment: HorizontalAlignment.Center
                bottomMargin: 5
                accessibility.name: "logoImage"
            }

            // title text
            Label {
                text: root.title[root.pagenumber]
                horizontalAlignment: HorizontalAlignment.Center

                textStyle {
                    fontSize: FontSize.XLarge
                    textAlign: TextAlign.Center
                }
            }

            // message text
            Label {
                text: root.text[root.pagenumber]
                multiline: true
                horizontalAlignment: HorizontalAlignment.Center
                textFormat: TextFormat.Html

                textStyle {
                    fontSize: FontSize.Medium
                    textAlign: TextAlign.Center
                }
            }
        }

        //swipe logic
        property int sWIPE_TRESHOLD: 20
        onTouch: {
            if (event.isDown()) {
                root.touchEnteredX = event.windowX
            }

            if (event.isUp()) {
                root.touchEndX = event.windowX

                if ((root.touchEndX - root.touchEnteredX) > sWIPE_TRESHOLD) {
                    if (pagenumber > 0) {
                        pagenumber = pagenumber - 1

                    }
                }

                if ((root.touchEndX - root.touchEnteredX) < - sWIPE_TRESHOLD) {
                    if (pagenumber < 6) {
                        pagenumber = pagenumber + 1
                    }
                }

                root.touchEnteredX = 0
                root.touchEndX = 0
            }
        }

        //page indicator logic
        onPagenumberChanged: {
            pageIndicatorBar.activeIndicator = pagenumber
        }

        PageIndicatorBar {
            id: pageIndicatorBar
            indicatorColors: root.pageIndicatorActiveColor
            bottomMargin: 48
        }

        Container {
            horizontalAlignment: HorizontalAlignment.Center
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }

            Button {
                text: "Start messaging"
            }
        }

    }
}
