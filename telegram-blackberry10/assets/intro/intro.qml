import bb.cascades 1.2

Page {
    // main container of Intro page
    Container {
        id: introID
        background: Color.White
        layout: StackLayout {
            
        }
        
        //track on which page we are currently
        property int pagenumber: 0 
        
        //properties for swiping
        property int touchEnteredX: 0
        property int touchEndX: 0

        
        property variant title: [
            "Telegram",
            "Fast",
            "Free",
            "Secure",
            "Powerful",
            "Cloud-Based",
            "Private"]
        
        property variant text: [
            "<html>The world's <b>fastest</b> messaging app.\nIt is <b>free</b> and <b>secure</b>.</html>",
            "<html><b>Telegram</b> delivers messages\nfaster than any other application.</html>",
            "<html><b>Telegram</b> is free forever. No ads.\nNo subscription fees.</html>",
            "<html><b>Telegram</b> keeps your messages\nsafe from hacker attacks.</html>",
            "<html><b>Telegram</b> has no limit on\nthe size of your chats and media.</html>",
            "<html><b>Telegram</b> lets you access your\n messages from multiple devices.</html>",
            "<html><b>Telegram</b> messages are heavily\nencrypted and can self-destruct.</html>"]
        
        property variant pageIndicatorActiveColor: [
            "#ff00a6df",
            "#ffef4d3e",
            "#fff1bf5b",
            "#ff62c657",
            "#ff956fbc",
            "#ff00bfd3",
            "#ffff8c4d"]

        property string image: "asset:///images/Intro/intro1.png"
        
        
        
        Container {
            id: emptySpaceTop
            background: Color.White
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            
        }
        
        
        // Container from which you can swipe and change through different messages
        Container {
            id: swipablePartID
            background: Color.White
            preferredWidth: maxWidth
            verticalAlignment: VerticalAlignment.Center
            //topPadding: ui.sdu(10)
            layout: StackLayout {
                
            }
            layoutProperties: StackLayoutProperties {
                spaceQuota: 5
            }
            
            
            // Logo 
            ImageView {
                id: logoID
                imageSource: introID.image.replace(/[0-9]/, (introID.pagenumber + 1).toString())
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                bottomMargin: ui.sdu(5)
                accessibility.name: "logoImage"
                
            }
            
            
            // title text
            Label {
                id: titleLabelID
                text: introID.title[introID.pagenumber]
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                textStyle.fontWeight: FontWeight.Normal
                textStyle.textAlign: TextAlign.Center
                textStyle.color: Color.Black
                textStyle.fontFamily: "Trebuchet MS"
                autoSize.maxLineCount: -1
                textStyle.fontSize: FontSize.XLarge
                textFit.mode: LabelTextFitMode.FitToBounds

            }

            // message text
            Label {
                id: textLabelID
                text: introID.text[introID.pagenumber]
                textStyle.color: Color.Black
                textStyle.textAlign: TextAlign.Center
                multiline: true
                textStyle.fontFamily: "Trebuchet MS"
                horizontalAlignment: HorizontalAlignment.Center
                textFormat: TextFormat.Html
                textStyle.fontSize: FontSize.Medium
                textFit.mode: LabelTextFitMode.FitToBounds

            }

        }

        //swipe logic
        property int sWIPE_TRESHOLD: ui.sdu(20)
        onTouch: {
            if (event.isDown()) {
                introID.touchEnteredX = event.windowX
            }

            if (event.isUp()) {
                introID.touchEndX = event.windowX

                if ((introID.touchEndX - introID.touchEnteredX) > sWIPE_TRESHOLD) {
                    if (pagenumber > 0) {
                        pagenumber = pagenumber - 1
                        
                    }
                }
                  
                if ((introID.touchEndX - introID.touchEnteredX) < -sWIPE_TRESHOLD) {
                    if (pagenumber < 6) {
                        pagenumber = pagenumber + 1
                    }
                }
                
                introID.touchEnteredX = 0
                introID.touchEndX = 0
            }
        }
        
        
        //page indicator logic
        onPagenumberChanged: {
            pageIndicatorBar.activeIndicator = pagenumber
        }

         PageIndicatorBar {
             id: pageIndicatorBar
             indicatorColors: introID.pageIndicatorActiveColor
             bottomMargin: 48
         }

        Container {
            horizontalAlignment: HorizontalAlignment.Center
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }

            Button {
                preferredWidth: ui.sdu(63)
                text: "Start messaging"
            }

        }

    }

}
