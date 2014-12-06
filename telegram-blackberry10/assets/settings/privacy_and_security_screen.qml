import bb.cascades 1.2
import bb.cascades.pickers 1.0
import '../shared'

Page {
    id: notificationAndSoundsPage

    titleBar: TitleBar {
        title: 'Privacy and Security'
    }

    ScrollView {

        Container {
            id: root
            leftPadding: 8
            rightPadding: 8
            topPadding: 8
            bottomPadding: 8

            Header {
                title: "Privacy"
                bottomMargin: 15
            }
            ClickableRow {
                preferredHeight: 100
                text: "Blocked Users"
                rightText: "3"
            }
            Divider {

            }
            ClickableRow {
                text: "Last Seen"
                rightText: "Everybody(-3)"
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