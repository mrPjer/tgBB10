import bb.cascades 1.2
import bb.cascades.pickers 1.0

Page {
    id: editPage

    function validateInputs() {
        editDone.enabled = firstName.text.length > 0 && lastName.text.length > 0
    }

    titleBar: TitleBar {
        id: editTitleBar
        title: "Edit"

        dismissAction: ActionItem {
            id: editCancel
            title: "Cancel"
            onTriggered: {
                navigationPane.pop()
            }
        }
        acceptAction: ActionItem {
            id: editDone
            title: "Done"
            onTriggered: {
                //TODO save new first and last name
                navigationPane.pop()
            }
        }
    }
    Container {
        leftPadding: 8
        rightPadding: 8
        topPadding: 8
        bottomPadding: 8

        layout: StackLayout {
        }

        Container {
            leftPadding: 32
            rightPadding: 32

            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }

            Container {
                preferredHeight: 180
                preferredWidth: 180
                rightMargin: 32

                layout: AbsoluteLayout {
                }

                ImageView {
                    id: avatar
                    preferredHeight: 180
                    preferredWidth: 180
                    scalingMethod: ScalingMethod.AspectFill
                    imageSource: 'asset:///images/shared/bar_profile.png'
                    accessibility.name: "User avatar"
                }
                ImageButton {
                    preferredHeight: 180
                    preferredWidth: 180
                    accessibility.name: "User avatar button"
                    onClicked: {
                        //TODO add camera option
                        filePicker.open()
                    }
                }
            }

            Container {
                TextField {
                    id: firstName
                    text: "Daniel"
                    onTextChanging: {
                        editPage.validateInputs()
                    }

                }
                TextField {
                    id: lastName
                    text: "Ash"
                    onTextChanging: {
                        editPage.validateInputs()
                    }
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
