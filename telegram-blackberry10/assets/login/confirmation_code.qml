import bb.cascades 1.2

Page {
    titleBar: TitleBar {
        title: "Enter confirmation code"
    }

    Container {
        leftPadding: 40
        rightPadding: 40
        topPadding: 40
        bottomPadding: 40

        Container {

            Label {
                text: "Your code"
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    fontWeight: FontWeight.Bold
                    fontSize: FontSize.XXLarge
                }
            }

            Divider {
                accessibility.name: "Title divider"
            }

            Label {
                text: "We have sent an SMS with an activation code to your phone +44 7400 890000"
                multiline: true
                textStyle {
                    textAlign: TextAlign.Center
                }
            }
        }

        Label {
            text: ""
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }

        Container {
            leftPadding: 120
            rightPadding: 120
            TextField {
                id: confirmationCode
                hintText: "Code"
                inputMode: TextFieldInputMode.Pin
                onTextChanging: {
                    nextButton.enabled = confirmationCode.text.length > 0
                }
            }
            Label {
                text: "We will call you in #TODO"
                horizontalAlignment: HorizontalAlignment.Center
            }
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }

        Label {
            text: ""
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }

        Button {
            id: nextButton
            text: "Next"
            enabled: false
            horizontalAlignment: HorizontalAlignment.Center
        }

    }
}
