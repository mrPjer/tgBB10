import bb.cascades 1.2
import '../shared'

Page {
    titleBar: TitleBar {
        title: "Last Seen"
        scrollBehavior: TitleBarScrollBehavior.Sticky
    }

    attachedObjects: [
        ComponentDefinition {
            id: neverSharePageDefinition
            source: "asset:///settings/never_share_screen.qml"
        }
    ]
    ScrollView {
        accessibility.name: "Content"

        Container {
            id: root

            Header {
                title: "Settings"
            }
            Container {
                leftPadding: 20
                rightPadding: 20
                topPadding: 15
                DropDown {
                    title: "Last Seen"
                    Option {
                        text: "Everybody"
                        selected: true
                    }
                    Option {
                        text: "My Contacts"
                    }
                    Option {
                        text: "Nobody"
                    }
                }
                Label {
                    multiline: true
                    textStyle.fontSize: FontSize.XSmall
                    textStyle.color: Color.Gray
                    text: "Important: you won't be able to see Last Seen times for people with whom you don't share your Last Seen times. Approximate last seen will be shown instead (recently, within a week, within a month)."
                }
            }
            Divider {

            }
            ClickableRow {
                text: "Never Share With"
                rightText: "3 users"

                onRowClicked: {
                    var newPage = neverSharePageDefinition.createObject()
                    navigationPane.push(newPage)
                }
            }
            Divider {

            }
        }
    }
}
