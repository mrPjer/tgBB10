import bb.cascades 1.4

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

        property string pageIndicatorUnactiveColor: "#ffe0ded9"
        
        property variant pageIndicatorCurrentColor: [
            "#ff00a6df",
            "#ffe0ded9",
            "#ffe0ded9",
            "#ffe0ded9",
            "#ffe0ded9",
            "#ffe0ded9",
            "#ffe0ded9"]
        
        property string image: "asset:///images/Intro/intro1.png"
        
        
        // Container from which you can swipe and change through different messages
        Container {
            id: swipablePartID
            background: Color.White
            preferredWidth: maxWidth
            preferredHeight: maxHeight
            topPadding: 400
            layout: StackLayout {
            }
            
            
            // Logo 
            ImageView {
                id: logoID
                imageSource: introID.image.replace(/[0-9]/, (introID.pagenumber + 1).toString())
                horizontalAlignment: HorizontalAlignment.Center
                bottomMargin: 50
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
                textFit.minFontSizeValue: 16.0

                textStyle.color: Color.Black
                textFit.maxFontSizeValue: 16.0
                textStyle.fontFamily: "Trebuchet MS"
                autoSize.maxLineCount: -1

            }

            // message text
            Label {
                id: textLabelID
                text: introID.text[introID.pagenumber]
                textStyle.color: Color.Black
                textStyle.textAlign: TextAlign.Center
                multiline: true
                textStyle.fontFamily: "Verdana"
                horizontalAlignment: HorizontalAlignment.Center
                textFormat: TextFormat.Html

            }

        }

        //swipe logic
        property int sWIPE_TRESHOLD: 200
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
        
        
        onPagenumberChanged: {
            console.log("SUP bitches pagenumber changed yo")
            console.log(introID.pageIndicatorCurrentColor[introID.pagenumber])
            console.log(introID.pageIndicatorActiveColor[introID.pagenumber])
            var temp = introID.pageIndicatorCurrentColor
            temp[introID.pagenumber] =
                introID.pageIndicatorActiveColor[introID.pagenumber]
            console.log(introID.pageIndicatorCurrentColor[introID.pagenumber])
                
            if(pagenumber > 0) {
                temp[introID.pagenumber - 1] =
                    introID.pageIndicatorUnactiveColor
            }
            
            if(pagenumber < 6) {
                temp[introID.pagenumber + 1] =
                    introID.pageIndicatorUnactiveColor
            }
            
            introID.pageIndicatorCurrentColor = temp
        }

        //Page indicators
        Container {
            id: pageIndicatorID
            background: Color.White
            preferredWidth: maxWidth
            preferredHeight: 50
            topPadding: 50
            leftPadding: 150
            horizontalAlignment: HorizontalAlignment.Center
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            

            Container {
                id: pageIndicatorPage1
                background: Color.create(introID.pageIndicatorCurrentColor[0])
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage2
                background: Color.create(introID.pageIndicatorCurrentColor[1])
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage3
                background: Color.create(introID.pageIndicatorCurrentColor[2])
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50
            }

            Container {
                id: pageIndicatorPage4
                background: Color.create(introID.pageIndicatorCurrentColor[3])
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage5
                background: Color.create(introID.pageIndicatorCurrentColor[4])
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage6
                background: Color.create(introID.pageIndicatorCurrentColor[5])
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage7
                background: Color.create(introID.pageIndicatorCurrentColor[6])
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }
        }

        //Container with a button
        Container {
            id: buttonContainerID
            background: Color.White
            preferredWidth: maxWidth
            preferredHeight: 750
            topPadding: 100 
            
            Button {
                horizontalAlignment: HorizontalAlignment.Center
                color: Color.create("#ff00a6df")
                preferredWidth: 500
                text: "Start messaging"
            }
            
            Container {
                id: buttonID
                background: Color.create("#ff00a6df")
            }
        }

    }

}
