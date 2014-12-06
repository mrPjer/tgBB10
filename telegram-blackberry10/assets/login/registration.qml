import bb.cascades 1.2
import bb.cascades.pickers 1.0
import "../main"

Page {
    titleBar: TitleBar {
        title: 'Registration'
    }

    Container {
        id: root
        leftPadding: 40
        rightPadding: 40
        topPadding: 40
        bottomPadding: 40

        function validateInputs() {
            next.enabled = firstName.text.length > 0 && lastName.text.length > 0
        }

        Container {

            Label {
                text: "Your name"
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    fontSize: FontSize.XXLarge
                }
            }

            Divider {
                accessibility.name: "Title divider"
            }

            Label {
                text: "Enter your name and add a profile picture"
                horizontalAlignment: HorizontalAlignment.Center
                multiline: true
                textStyle {
                    textAlign: TextAlign.Center
                }
            }
        }

        Label {
            text: ''
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
        }

        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }

            leftPadding: 32
            rightPadding: 32

            Container {
                layout: AbsoluteLayout {
                }
                preferredHeight: 180
                preferredWidth: 180
                rightMargin: 32

                ImageView {
                    id: avatar
                    preferredHeight: 180
                    preferredWidth: 180
                    scalingMethod: ScalingMethod.AspectFill
                    imageSource: 'asset:///images/registration/image_placeholder.png'
                    accessibility.name: "User avatar"
                }

                ImageButton {
                    preferredHeight: 180
                    preferredWidth: 180
                    accessibility.name: "User avatar button"
                    onClicked: {
                        filePicker.open()
                    }
                }
            }

            Container {
                TextField {
                    id: firstName
                    hintText: 'First name'
                    onTextChanging: {
                        root.validateInputs()
                    }
                }
                TextField {
                    id: lastName
                    hintText: 'Last name'
                    onTextChanging: {
                        root.validateInputs()
                    }
                }
            }

        }

        Label {
            text: ''
            layoutProperties: StackLayoutProperties {
                spaceQuota: 3
            }
        }

        Button {
            id: next
            text: 'Next'
            enabled: false
            horizontalAlignment: HorizontalAlignment.Center

            onClicked: {
                mainPage.open()
            }

            attachedObjects: Sheet {
                id: mainPage
                MainPage {
                }
            }
        }

    }

    attachedObjects: [
        FilePicker {
            id: filePicker
            type: FileType.Picture
            title: 'Select your profile picture'
            onFileSelected: {
                avatar.imageSource = 'file://' + selectedFiles[0]
            }
        }
    ]

}
