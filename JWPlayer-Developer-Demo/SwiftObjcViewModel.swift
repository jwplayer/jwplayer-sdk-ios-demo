//
//  SwiftObjcViewModel.swift
//  JWPlayer-Developer-Guide
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

let sdkVerMsg = "*****\n SDK Version: \(JWPlayerController.sdkVersion() ?? "unavailable")\n*****\n"

class SwiftObjcViewModel: NSObject {
    public static var shared = SwiftObjcViewModel()
    private override init() {
        super.init()
        // receive model updates
        setupNotifications()
    }
    
    var kvoObservations = [NSKeyValueObservation]()
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    lazy var player = newPlayer()
    var outputTextView: UITextView? { didSet { setupOutputKVO() }}
    var outputDetailsTextView: UITextView? { didSet { setupDetailsOutputKVO() }}
    
    @objc dynamic var outputText        = sdkVerMsg
    @objc dynamic var outputDetailsText = sdkVerMsg
    
    private func newPlayer() -> JWPlayerController {
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
        
        return JWPlayerController(config: config, delegate: self)
    }
}

extension SwiftObjcViewModel /* Notifications & Output */ {
    private func setupNotifications() {
        // Notifications to get Model updates
        let notifications = [
            JWPlayerStateChangedNotification,
            JWMetaDataAvailableNotification,
            JWAdActivityNotification,
            JWErrorNotification,
            JWCaptionsNotification,
            JWVideoQualityNotification,
            JWPlaybackPositionChangedNotification,
            JWFullScreenStateChangedNotification,
            JWAdClickNotification]
        
        let notificationNames = notifications.map({ Notification.Name($0)})
        
        for(_, nName) in notificationNames.enumerated() {
            NotificationCenter.default.addObserver(self, selector: #selector(handleNotification(_:)), name: nName, object: nil)
        }
    }

    @objc func handleNotification(_ notification: Notification) {
        var userInfo: Dictionary = (notification as NSNotification).userInfo!
        let callbackEventName: String = userInfo["event"] as! String
        
        if callbackEventName == "onTime" {return}
        
        outputText += "\n" + callbackEventName
        outputDetailsText += "\n=+=+=\n" + userInfo.prettyPrint()
    }
    
    // MARK: KVO to update UI
    private func setupOutputKVO() {
        outputTextView?.text = outputText;
        
        kvoObservations += [observe(\.outputText, options: .new, changeHandler: { (viewModel, changes) in
                viewModel.outputTextView?.text = changes.newValue
            self.outputTextView?.scrollToBottom()
        })]
    }
    
    private func setupDetailsOutputKVO() {
        outputDetailsTextView?.text = outputDetailsText;
        
        kvoObservations += [observe(\.outputDetailsText, options: .new, changeHandler: { (viewModel, changes) in
                viewModel.outputDetailsTextView?.text = changes.newValue
            self.outputDetailsTextView?.scrollToBottom()
        })]
    }
}

// Optional
extension SwiftObjcViewModel: JWPlayerDelegate {
    // Convenience callbacks as an alternative to
    // notification subscriptions can go here.
}


// Helpers

fileprivate extension UIScrollView {
    func scrollToBottom() {
        setContentOffset(bottomOffset, animated: true)
    }
    
    var bottomOffset: CGPoint {
        let newY = max(0, contentSize.height - bounds.size.height + contentInset.bottom)
        return CGPoint(x: 0, y: newY) }
}

protocol Textual {
    var text: String! { get set }
}

extension UITextView: Textual {}



fileprivate struct Endpoints {
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
    static let schedule = [JWAdBreak(tags:waterfallTags as! [String], offset:"1"),
                         JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"5"),
                         //                             JWAdBreak(tag: "http://demo.jwplayer.com/player-demos/assets/overlay.xml", offset: "7", nonLinear: true),
        JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"0:00:05"),
        JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"50%"),
        JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"post")].compactMap({$0})
}
