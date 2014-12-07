import bb.cascades 1.2

Container {
    property alias source: dataModel.source
    property bool showPhoneNumber: true
    property bool showStatus: true

    ListView {
        dataModel: XmlDataModel {
            id: dataModel
            source: "asset:///settings/blockedUsers.xml"
        }
        listItemComponents: [
            ListItemComponent {
                type: "contact"

                CustomListItem {
                    Container {
                        id: itemRoot
                        layout: StackLayout {
                            orientation: LayoutOrientation.LeftToRight
                        }
                        ImageView {
                            id: image
                            preferredHeight: 115
                            preferredWidth: 115
                            imageSource: ListItemData.imagePath
                            scalingMethod: ScalingMethod.AspectFill
                        }
                        Container {
                            verticalAlignment: VerticalAlignment.Center

                            Label {
                                id: name
                                bottomMargin: 0
                                verticalAlignment: VerticalAlignment.Center
                                text: ListItemData.name
                            }
                            Label {
                                id: phone
                                visible: showPhoneNumber
                                topMargin: 0
                                text: ListItem.phone
                            }
                            Label {
                                id: status
                                visible: showStatus
                                topMargin: 0
                                text: "online"
                                textStyle.fontSize: FontSize.XSmall
                                textStyle.color: status.text === "online" ? Color.Blue : Color.LightGray
                            }
                        }
                    }
                }
            }
        ]
    }
}
