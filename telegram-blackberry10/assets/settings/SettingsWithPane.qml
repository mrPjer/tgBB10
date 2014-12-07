import bb.cascades 1.2

NavigationPane {

    id: navigationPane

    property alias titleBar: settingsScreen.titleBar

    SettingsScreen {
        id: settingsScreen
    }

}
