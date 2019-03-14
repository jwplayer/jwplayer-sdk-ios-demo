//
//  JWPlayerFactory.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 3/4/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

class JWPlayerFactory: NSObject {
    @objc public static func newPlayer(delegate: JWPlayerDelegate? = nil) -> JWPlayerController {
        // MARK: JWConfig with convenience init
        let config: JWConfig = JWConfig(contentURL: Endpoints.videoDemo)
        
        // MARK: JWConfig with [JWSources]
//        let config: JWConfig = JWConfig()
//        config.sources = Endpoints.sources
        
        config.image = Endpoints.videoImage
        config.title = "JWPlayer Demo"
        config.controls = true  //default
        config.`repeat` = false   //default
        
        addCaptions(to: config)
        
        addAdvertising(to: config)
        
        return JWPlayerController(config: config, delegate: delegate)
    }
    
    fileprivate static func addCaptions(to config: JWConfig) {
        //MARK: JWTrack (the actual captions)
        config.tracks = Endpoints.tracks
        
        //MARK: JWCaptionStyling
        let captionStyling: JWCaptionStyling = JWCaptionStyling()
        captionStyling.font            = UIFont (name: "Zapfino", size: 20)
        captionStyling.edgeStyle       = JWEdgeStyleRaised
        captionStyling.windowColor     = .purple
        captionStyling.backgroundColor = UIColor(red: 0.3, green: 0.6, blue: 0.3, alpha: 0.7)
        captionStyling.color           = .blue
        config.captions                = captionStyling
    }
    
    fileprivate static func addAdvertising(to config: JWConfig) {
        //MARK: Ads: JWAdConfig
        let adConfig: JWAdConfig = JWAdConfig()
        adConfig.adMessage   = "Ad duration countdown xx"
        adConfig.skipMessage = "Skip in xx"
        adConfig.skipText    = "Move on"
        adConfig.skipOffset  = 3
        adConfig.client      = JWAdClientVast
        
        //MARK: Ads: AdSchedule
        adConfig.schedule  = Endpoints.schedule
        
        //  MARK: Ads: VMAP
        //        adConfig.adVmap    = Endpoints.vastVMAP

        //MARK: Ads: Waterfall Tags
        //        let waterfallTags = Endpoints.waterfallTags
        
    
        config.advertising = adConfig
    }
}
