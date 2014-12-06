import bb.cascades 1.2

Container {

    layout: StackLayout {
        orientation: LayoutOrientation.LeftToRight
    }

    property int activeIndicator
    property variant indicatorColors
    property variant indicators: [ indicator1, indicator2, indicator3, indicator4, indicator5, indicator6, indicator7 ]

    horizontalAlignment: HorizontalAlignment.Center

    onActiveIndicatorChanged: {
        for (var i in indicators) {
            indicators[i].isActive = false
        }
        indicators[activeIndicator].isActive = true
    }

    onIndicatorColorsChanged: {
        for (var i in indicators) {
            indicators[i].indicatorColor = Color.create(indicatorColors[i])
        }
    }

    PageIndicator {
        id: indicator1
        background: Color.create("#ff00a6df")
        isActive: true
    }

    PageIndicator {
        id: indicator2
    }

    PageIndicator {
        id: indicator3
    }

    PageIndicator {
        id: indicator4
    }

    PageIndicator {
        id: indicator5
    }

    PageIndicator {
        id: indicator6
    }

    PageIndicator {
        id: indicator7
    }

}
