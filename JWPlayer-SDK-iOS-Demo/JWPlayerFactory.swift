//
//  JWPlayerFactory.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 3/4/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

fileprivate let useLocalFiles = true

class JWPlayerFactory: NSObject {
    @objc
    public static func newPlayer(delegate: JWPlayerDelegate? = nil) -> JWPlayerController {
        let config: JWConfig  = JWConfig(contentURL: Endpoints.videoDemo)
        config.image          = Endpoints.videoImage
        config.title          = "JWPlayer Demo"
        
        return JWPlayerController(config: config, delegate: delegate)
    }
}


/// A struct that abstracts out the strings used in the project.
struct Endpoints {
    static let videoDemo  = "http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4"
    static let videoImage = "http://content.bitsontherun.com/thumbs/bkaovAYt-480.jpg"
}
