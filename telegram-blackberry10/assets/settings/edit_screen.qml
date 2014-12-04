import bb.cascades 1.2

Page {
    id: editPage
        
    signal cancel()
    signal save()
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
                editPage.cancel();
            }
        }
        acceptAction: ActionItem {
            id: editDone
            title: "Done"
            onTriggered: {
                editPage.save();
            }
        }
    }
    Container {
        leftPadding: 40
        rightPadding: 40
        topPadding: 40
        bottomPadding: 40
        
        layout: StackLayout {
            
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
                    imageSource: 'asset:///images/shared/bar_profile.png'
                    accessibility.name: "User avatar"
                }
                ImageButton {
                    preferredHeight: 180
                    preferredWidth: 180
                    accessibility.name: "User avatar button"
                    onClicked: {
                        //TODO choice between camera and folder
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
}
