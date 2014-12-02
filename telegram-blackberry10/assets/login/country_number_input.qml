import bb.cascades 1.2

Page {
    titleBar: TitleBar {
        title: "Registration"
    }

    attachedObjects: [
        ComponentDefinition {
            id: optionControlDefinition
            Option {
            }
        },
        ComponentDefinition {
            id: confirmationCodePageDefinition
            source: "asset:///login/confirmation_code.qml"
        }
    ]

    onCreationCompleted: {
        for (var country in countries) {
            var option = optionControlDefinition.createObject()
            option.text = country
            countrySelect.add(option)
        }
    }

    Container {
        id: root
        leftPadding: 40
        rightPadding: 40
        topPadding: 40
        bottomPadding: 40

        function validateFields() {
            next.enabled = countryCode.text.length > 0 && phoneNumber.text.length > 0
        }

        Container {

            Label {
                text: "Your phone"
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
                text: "Please confirm your country code and enter your phone number."
                multiline: true
            }

        }

        DropDown {
            id: countrySelect
            title: "Select your country"
            onSelectedOptionChanged: {
                var selectedValue = selectedOption.text
                var cc
                if (selectedValue) {
                    cc = '+' + countries[selectedValue]
                } else {
                    cc = ''
                }
                countryCode.text = cc
                root.validateFields()
            }
        }

        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            TextField {
                id: countryCode
                hintText: "CC"
                enabled: false
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                onTextChanging: {
                    root.validateFields()
                }
            }

            TextField {
                id: phoneNumber
                hintText: "Your phone number"
                inputMode: TextFieldInputMode.PhoneNumber
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 3
                }
                onTextChanging: {
                    root.validateFields()
                }
            }
        }

        Label {
            text: ''
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }

        Button {
            id: next
            text: 'Next'
            enabled: false
            horizontalAlignment: HorizontalAlignment.Center
            onClicked: {
                var newPage = confirmationCodePageDefinition.createObject()
                navigationPane.push(newPage)
            }
        }

    }
}
