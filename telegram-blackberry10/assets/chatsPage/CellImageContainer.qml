import bb.cascades 1.2

Container {
    
    property alias avatar : chatAvatar.imageSource
    
    ImageView {
        id: chatAvatar
        imageSource: avatar
        scalingMethod: ScalingMethod.Fill
        accessibility.name: "chat avatar"
        
    }
}

