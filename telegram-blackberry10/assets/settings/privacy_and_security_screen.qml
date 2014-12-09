import bb.cascades 1.2
import bb.cascades.pickers 1.0
import '../shared'

Page {
    id: privacyAndSecurityPage

    titleBar: TitleBar {
        title: 'Privacy and Security'
    }
    attachedObjects: [
        ComponentDefinition {
            id: blockedUsersPageDefinition
            source: "asset:///settings/blocked_users_screen.qml"
        },
        ComponentDefinition {
            id: lastSeenPageDefinition
            source: "asset:///settings/last_seen_screen.qml"
        }
    ]

    ScrollView {
        accessibility.name: "Content"

        Container {
            id: root

            Header {
                title: "Privacy"
                bottomMargin: 15
            }
            ClickableRow {
                preferredHeight: 80
                text: "Blocked Users"
                rightText: "3"
                onRowClicked: {
                    var newPage = blockedUsersPageDefinition.createObject()
                    navigationPane.push(newPage)
                }
            }
            Divider {

            }
            ClickableRow {
                text: "Last Seen"
                rightText: "Everybody (-3)"
                onRowClicked: {
                    var newPage = lastSeenPageDefinition.createObject()
                    navigationPane.push(newPage)
                }
            }
            Container {
                leftPadding: 20
                Label {

                    text: "Change who can see your Last Seen time."
                    textStyle.fontSize: FontSize.XSmall
                    textStyle.color: Color.Gray
                }
            }
            Divider {

            }
            Header {
                title: "Security"
            }
            Container {
                leftPadding: 20
                topPadding: 15
                Label {
                    text: "Terminate all other sessions"
                }
                Label {
                    text: "Logs out all devices except for this one."
                    textStyle.fontSize: FontSize.XSmall
                    textStyle.color: Color.Gray
                }
            }
            Divider {

            }
            Header {
                title: "Delete My Account"
            }
            Container {
                leftPadding: 20
                rightPadding: 20
                topPadding: 15
                DropDown {
                    title: "If Away For"
                    Option {
                        text: "1 week"
                    }
                    Option {
                        text: "2 weeks"
                    }
                    Option {
                        text: "1 month"
                    }
                    Option {
                        text: "6 months"
                    }
                    Option {
                        text: "1 year"
                    }
                    Option {
                        text: "Never"
                        selected: true
                    }
                }
                Label {
                    multiline: true
                    text: "If you do not log in at least once within this period, your account will be deleted along with all groups, messages and contacts"
                    textStyle.fontSize: FontSize.XSmall
                    textStyle.color: Color.Gray
                }
            }

        }
    }
}