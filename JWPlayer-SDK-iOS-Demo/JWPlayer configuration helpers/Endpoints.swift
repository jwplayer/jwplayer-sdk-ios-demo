//
//  Endpoints.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 3/4/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

/// A struct that abstracts out the strings used in the project.
struct Endpoints {
    static let audioOnly   = "http://content.bitsontherun.com/videos/3XnJSIm4-I3ZmuSFT.m4a"
    static let video4Kdemo = "http://ftp.nluug.nl/pub/graphics/blender/demo/movies/ToS/ToS-4k-1920.mov"
    static let videoDemo   = "http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4"
    
    static let sources = [JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-injeKYZS.mp4", label: "180p Streaming", isDefault: true),
                          JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-52qL9xLP.mp4", label: "270p Streaming"),
                          JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-DZ7jSYgM.mp4", label: "720p Streaming")].compactMap({$0})
    
    static let videoImage = "http://content.bitsontherun.com/thumbs/bkaovAYt-480.jpg"
    static let audioImage = "http://content.bitsontherun.com/thumbs/3XnJSIm4-480.jpg"
    
    //MARK: JWTrack (captions)
    static let tracks = [JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-en.srt", label: "English", isDefault: true),
                         JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-sp.srt", label: "Spanish"),
                         JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-ru.srt", label: "Russian")].compactMap({$0})
    
    
    static let waterfallTags = ["bad tag", "another bad tag", "http://playertest.longtailvideo.com/adtags/preroll_newer.xml"]
    
    //MARK: Ads: AdSchedule
    static let schedule = [JWAdBreak(tags:waterfallTags, offset:"1"),
                           JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"5"),
                           //                             JWAdBreak(tag: "http://demo.jwplayer.com/player-demos/assets/overlay.xml", offset: "7", nonLinear: true),
        JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"0:00:05"),
        JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"50%"),
        JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"post")].compactMap({$0})
    
    // MARK: VMAP
    static let googimaVMAP = "http://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/ad_rule_samples&ciu_szs=300x250&ad_rule=1&impl=s&gdfp_req=1&env=vp&output=vmap&unviewed_position_start=1&cust_params=sample_ar%3Dpremidpost&cmsid=496&vid=short_onecue&correlator="
    static let vastVMAP = "https://playertest.longtailvideo.com/adtags/vmap2.xml"

}
