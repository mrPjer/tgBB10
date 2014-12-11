import bb.cascades 1.2

Container {

    property alias avatar: chatAvatar.imageSource

    ImageView {
        id: chatAvatar
        imageSource: avatar
        scalingMethod: ScalingMethod.AspectFill
        accessibility.name: "chat avatar"
        preferredWidth: 128
        preferredHeight: 128
        minHeight: 128
        minWidth: 128
    }
}
