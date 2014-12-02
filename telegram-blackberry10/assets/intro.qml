import bb.cascades 1.4

Page {
    // main container of Intro page
    Container {
        id: introMainID
        background: Color.White
        layout: StackLayout {
            
        }
        
        // Container from which you can swipe and change through different messages
        Container {
            id: swipablePartID
            background: Color.White
            preferredWidth: maxWidth
            preferredHeight: maxHeight
            topPadding: 400
            layout: StackLayout {
                
            }
            
            property string image: "asset:///images/Intro/intro1.png"
            property string titleText: "Telegram"
            property string text: "<html>The world's <b>fastest</b> messaging app.\nIt is <b>free</b> and <b>secure</b>.</html>"
            property string unactivePageIndicatorColor: "#ffe0ded9"
            
            // Logo image 
            ImageView {
                id: logoID
                imageSource: swipablePartID.image
                horizontalAlignment: HorizontalAlignment.Center
                bottomMargin: 50
                
            }
            
            // title text
            Label {
                id: titleLabelID
                text: swipablePartID.titleText
                horizontalAlignment: HorizontalAlignment.Center
                verticalAlignment: VerticalAlignment.Center
                textStyle.fontWeight: FontWeight.Normal
                textStyle.textAlign: TextAlign.Center
                textFit.minFontSizeValue: 16.0

                textStyle.color: Color.Black
                textFit.maxFontSizeValue: 15.0
                textStyle.fontFamily: "Trebuchet MS"

            }
            
            // message text
            Label {
                id: textLabelID
                text: swipablePartID.text
                textStyle.color: Color.Black
                textStyle.textAlign: TextAlign.Center
                multiline: true
                textStyle.fontFamily: "Verdana"
                horizontalAlignment: HorizontalAlignment.Center
                textFormat: TextFormat.Html

            }

        }

        //Container with page indicators
        Container {
            id: staticPartID
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
                background: Color.create("#ff00a6df")
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50
                
            }
            
            Container {
                id: pageIndicatorPage2
                background: Color.create(swipablePartID.unactivePageIndicatorColor)
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage3
                background: Color.create(swipablePartID.unactivePageIndicatorColor)
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50
            }

            Container {
                id: pageIndicatorPage4
                background: Color.create(swipablePartID.unactivePageIndicatorColor)
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage5
                background: Color.create(swipablePartID.unactivePageIndicatorColor)
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage6
                background: Color.create(swipablePartID.unactivePageIndicatorColor)
                minWidth: 15
                maxWidth: 15
                minHeight: 15
                maxHeight: 15
                rightMargin: 50

            }

            Container {
                id: pageIndicatorPage7
                background: Color.create(swipablePartID.unactivePageIndicatorColor)
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
