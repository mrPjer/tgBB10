import bb.cascades 1.2

Container {
    id: usersList
    property alias source: dataModel.source
    property alias showPhoneNumber: listView.showPhoneNumber
    property alias showStatus: listView.showStatus
    property alias showHeader: listView.showHeader

    signal triggered(variant indexPath)

    onCreationCompleted: {
        listView.triggered.connect(triggered)
    }

    ListView {
        id: listView
        property bool showPhoneNumber: false
        property bool showStatus: false
        property bool showHeader: false

        dataModel: XmlDataModel {
            id: dataModel
            source: "asset:///settings/allContacts.xml"
        }
        listItemComponents: [
            ListItemComponent {
                type: "header"
                Header {
                    visible: ListItem.view.showHeader
                    title: ListItemData.title
                }
            },
            ListItemComponent {
                type: "contact"

                CustomListItem {
                    id: itemRoot
                    Container {

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
                                textStyle.fontSize: FontSize.Large
                            }
                            Label {
                                id: phone
                                visible: itemRoot.ListItem.view.showPhoneNumber
                                topMargin: 0
                                text: ListItemData.phone
                                textStyle.color: Color.Gray
                            }
                            Label {
                                id: status
                                visible: itemRoot.ListItem.view.showStatus
                                topMargin: 0
                                text: ListItemData.status
                                textStyle.fontSize: FontSize.Small
                                textStyle.color: status.text === "online" ? Color.Blue : Color.LightGray
                            }
                        }
                    }
                }
            }
        ]
    }
}
