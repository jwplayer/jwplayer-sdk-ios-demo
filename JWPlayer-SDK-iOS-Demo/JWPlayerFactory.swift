//
//  JWPlayerFactory.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 3/4/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

class JWPlayerFactory {
    static func newPlayer(delegate: JWPlayerDelegate? = nil) -> JWPlayerController {
        //MARK: JWConfig
        
        /* JWConfig can be created with a single file reference */
        //var config: JWConfig = JWConfig(contentURL:"http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4")
        
        
        let config: JWConfig = JWConfig()
        config.sources = Endpoints.sources
        
        config.image = Endpoints.sourceImage
        config.title = "JWPlayer Demo"
        config.controls = true  //default
        config.`repeat` = false   //default
        
        //MARK: JWTrack (captions)
        config.tracks = Endpoints.tracks
        
        //MARK: JWCaptionStyling
        let captionStyling: JWCaptionStyling = JWCaptionStyling()
        captionStyling.font            = UIFont (name: "Zapfino", size: 20)
        captionStyling.edgeStyle       = JWEdgeStyleRaised
        captionStyling.windowColor     = .purple
        captionStyling.backgroundColor = UIColor(red: 0.3, green: 0.6, blue: 0.3, alpha: 0.7)
        captionStyling.color           = .blue
        config.captions                = captionStyling
        
        //MARK: Ads: JWAdConfig
        let adConfig: JWAdConfig = JWAdConfig()
        adConfig.adMessage   = "Ad duration countdown xx"
        adConfig.skipMessage = "Skip in xx"
        adConfig.skipText    = "Move on"
        adConfig.skipOffset  = 3
        adConfig.client      = JWAdClientVast
        
        //MARK: Ads: Waterfall Tags
        let waterfallTags = Endpoints.waterfallTags
        
        //MARK: Ads: AdSchedule
        adConfig.schedule = Endpoints.schedule
        
        config.advertising   = adConfig
        
        return JWPlayerController(config: config, delegate: delegate)
    }
}
