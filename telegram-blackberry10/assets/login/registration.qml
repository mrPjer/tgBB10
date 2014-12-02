import bb.cascades 1.2
import bb.cascades.pickers 1.0

Page {
    titleBar: TitleBar {
        title: 'Registration'
    }

    Container {
        leftPadding: 40
        rightPadding: 40
        topPadding: 40
        bottomPadding: 40

        Container {

            Label {
                text: "Your name"
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
                }
                TextField {
                    id: lastName
                    hintText: 'Last name'
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
            text: 'Next'
            horizontalAlignment: HorizontalAlignment.Center
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
