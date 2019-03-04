//
//  Endpoints.swift
//  JWPlayer-Developer-Guide
//
//  Created by Amitai Blickstein on 3/4/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

struct Endpoints {
    static let sources = [JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-injeKYZS.mp4", label: "180p Streaming", isDefault: true),
                          JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-52qL9xLP.mp4", label: "270p Streaming"),
                          JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-DZ7jSYgM.mp4", label: "720p Streaming")].compactMap({$0})
    
    static let sourceImage = "http://content.bitsontherun.com/thumbs/bkaovAYt-480.jpg"
    
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
}
