import bb.cascades 1.2
import TgApi 1.0
import bb.system 1.2

Page {

    id: page

    titleBar: TitleBar {
        title: "Registration"
    }

    property string confirmationPhoneNumber

    function phoneNumber() {
        return countryCode.text + phoneNumber.text
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
        },
        RegistrationApi {
            id: api
            onPhoneStatusReceived: {
                console.log("Received phone status for " + phoneNumber)
                console.log("\t(Registered, invited) = " + registered + ", " + invited)
                confirmationPhoneNumber = phoneNumber
                api.requestPhoneCode(phoneNumber)
            }
            onSmsSent: {
                phoneNumberProgress.cancel()
                if (result) {
                    console.log("Auth code dispatched")
                    var newPage = confirmationCodePageDefinition.createObject()
                    newPage.phoneNumber = confirmationPhoneNumber
                    navigationPane.push(newPage)
                } else {
                    console.log("Auth code wasn't dispatched")
                    codeErrorToast.show()
                }

            }
        },
        SystemProgressDialog {
            id: phoneNumberProgress
            dismissAutomatically: false
            title: "Confirming phone number"
            body: "Trying to dispatch the confirmation code..."
        },
        SystemToast {
            id: codeErrorToast
            body: "An error occurred while sending the SMS. Please check your number."
            button {
                label: "OK"
                enabled: true
            }
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
                phoneNumberProgress.show()
                api.requestPhoneStatus(page.phoneNumber())
            }
        }

    }
}
