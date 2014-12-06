import bb.cascades 1.2
import "main"
import "intro"

NavigationPane {
    id: navigationPane
    Page {
        Container {
            Label {
                // Localized text with the dynamic translation and locale updates support
                text: qsTr("Hello World") + Retranslate.onLocaleOrLanguageChanged
                textStyle.base: SystemDefaults.TextStyles.BigText
                autoSize.maxLineCount: -1
            }
            ScrollView {
                Container {

                    Button {
                        text: "Intro screen"
                        onClicked: {
                            introPageSheet.open()
                        }
                        attachedObjects: Sheet {
                            id: introPageSheet
                            peekEnabled: false
                            IntroWithPane {
                            }
                        }
                    }

                    Button {
                        text: "Login and registration"
                        onClicked: {
                            var page = pageDefinition.createObject()
                            navigationPane.push(page)
                        }
                        attachedObjects: ComponentDefinition {
                            id: pageDefinition
                            source: 'login/country_number_input.qml'
                        }
                    }

                    Button {
                        text: "Main page"
                        onClicked: {
                            mainPageSheet.open()
                        }
                        attachedObjects: Sheet {
                            id: mainPageSheet
                            peekEnabled: false
                            MainPage {
                                showBackButton: true
                                onDismiss: {
                                    mainPageSheet.close()
                                }
                            }
                        }
                    }

                }
                accessibility.name: "Page links"
            }
        }

    }
}