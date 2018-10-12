//
//  PlayerViewController.swift
//  JWPlayerSDKDemo
//
//  Created by Max Mikheyenko on 1/5/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.


import Foundation
import UIKit

class SwiftPlayerViewController: UIViewController, JWPlayerDelegate {
    
    fileprivate var player:JWPlayerController!
    @IBOutlet var callbacksView: UITextView!
    @IBOutlet var playbackTime: UILabel!
    @IBOutlet var playButton: UIButton!
    
    @IBOutlet weak var playerViewConstraint: NSLayoutConstraint!
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: Bundle?) {
        callbacksView = UITextView(frame: CGRect.zero)
        callbacksView?.isEditable = false
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }
    
    required init?(coder aDecoder: NSCoder) {
        callbacksView = UITextView(frame: CGRect.zero)
        callbacksView?.isEditable = false
        super.init(coder: aDecoder)
    }
    
    override func viewDidLoad() {
        navigationItem.title = "Swift Implementation"
        
        edgesForExtendedLayout =  UIRectEdge()
        view.backgroundColor = UIColor.white
        
        automaticallyAdjustsScrollViewInsets = false
        
        super.viewDidLoad()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        createPlayer()
        view.addSubview(player.view)
        setupCallbacks()
        super.viewDidAppear(animated)
    }
    
    func createPlayer() {
        
        //MARK: JWConfig
        /* JWConfig can be created with a single file reference */
        //var config: JWConfig = JWConfig(contentURL:"http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4")
        
        
        let config: JWConfig = JWConfig()
        config.sources = [JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-injeKYZS.mp4", label: "180p Streaming", isDefault: true),
                          JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-52qL9xLP.mp4", label: "270p Streaming"),
                          JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-DZ7jSYgM.mp4", label: "720p Streaming")]
        
        config.image = "http://content.bitsontherun.com/thumbs/bkaovAYt-480.jpg"
        config.title = "JWPlayer Demo"
        config.controls = true  //default
        config.`repeat` = false   //default
        
        /* Removed in v3.x */
        //config.premiumSkin = JWPremiumSkinRoundster
        
        /* custom css skin can be applied using: */
        //config.skin.url = "http://p.jwpcdn.com/iOS/Skins/ethan.css"
        
        
        //MARK: JWTrack (captions)
        config.tracks = [JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-en.srt", label: "English", isDefault: true),
                         JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-sp.srt", label: "Spanish"),
                         JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-ru.srt", label: "Russian")]
        
        //MARK: JWCaptionStyling
        let captionStyling: JWCaptionStyling = JWCaptionStyling()
        captionStyling.font            = UIFont (name: "Zapfino", size: 20)
        captionStyling.edgeStyle       = JWEdgeStyleRaised
        captionStyling.windowColor     = .purple
        captionStyling.backgroundColor = UIColor(red: 0.3, green: 0.6, blue: 0.3, alpha: 0.7)
        captionStyling.color           = .blue
        config.captions                = captionStyling
        
        //MARK: JWAdConfig
        let adConfig: JWAdConfig = JWAdConfig()
        adConfig.adMessage   = "Ad duration countdown xx"
        adConfig.skipMessage = "Skip in xx"
        adConfig.skipText    = "Move on"
        adConfig.skipOffset  = 3
        adConfig.client      = JWAdClientVast
        
        
        /* auto start */
        //        config.autostart = true
        
        //MARK: Waterfall Tags
        let waterfallTags: NSArray = ["bad tag", "another bad tag", "http://playertest.longtailvideo.com/adtags/preroll_newer.xml"]

        //MARK: Ad Schedule
        adConfig.schedule = [JWAdBreak(tags:waterfallTags as! [String], offset:"1"),
                             JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"5"),
//                             JWAdBreak(tag: "http://demo.jwplayer.com/player-demos/assets/overlay.xml", offset: "7", nonLinear: true),
                             JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"0:00:05"),
                             JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"50%"),
                             JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"post")]
        
        
        config.advertising   = adConfig
        
        player = JWPlayerController(config: config)
        player.delegate = self

        var frame: CGRect = view.bounds
        frame.origin.y = 10
        
        playerViewConstraint.constant = frame.size.height / 2 - 44
        
        frame.size.height = playerViewConstraint.constant

        player.view.frame = frame
        player.view.autoresizingMask = [
            .flexibleBottomMargin,
            .flexibleHeight,
            .flexibleLeftMargin,
            .flexibleRightMargin,
            .flexibleTopMargin,
            .flexibleWidth]
        
        player.openSafariOnAdClick        = true
        player.forceFullScreenOnLandscape = true
        player.forceLandscapeOnFullScreen = true
    }
    
    @IBAction func play(_ sender: UIButton) {
        if(player.state == JWPlayerStatePaused ||
            player.state == JWPlayerStateIdle) {
            player.play()
            playButton?.setTitle("Pause", for: UIControlState())
        } else {
            player.pause()
            playButton?.setTitle("Play", for: UIControlState())
        }
    }
    
    @objc func playerStateChanged(_ info: Notification) {
        let userInfo: NSDictionary = (info as NSNotification).userInfo! as NSDictionary
        if( userInfo["event"] as! String == "onPause" ||
            userInfo["event"] as! String == "onReady" ||
            userInfo["event"] as! String == "onAdPause") {
            playButton?.setTitle("Play", for: UIControlState())
        } else {
            playButton?.setTitle("Pause", for: UIControlState())
        }
    }
    
    @IBAction func insertAd(_ sender: UIButton) {
        player .playAd("http://playertest.longtailvideo.com/adtags/preroll_newer.xml")
    }
    
    func setupCallbacks() {
        setupNotifications()
    }
    
    func setupNotifications() {
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
        
        let center:  NotificationCenter = .default
        for(_, notification) in notifications.enumerated() {
            center.addObserver(self, selector: #selector(handleNotification(_:)), name: NSNotification.Name(rawValue: notification), object: nil)
        }
        center.addObserver(self, selector: #selector(updatePlaybackTimer(_:)), name: NSNotification.Name(rawValue: JWPlaybackPositionChangedNotification), object: nil)
        center.addObserver(self, selector: #selector(playerStateChanged(_:)), name: NSNotification.Name(rawValue: JWPlayerStateChangedNotification), object: nil)
        center.addObserver(self, selector: #selector(playerStateChanged(_:)), name: NSNotification.Name(rawValue: JWAdActivityNotification), object: nil)
    }
    
    @objc func handleNotification(_ notification: Notification) {
        var userInfo: Dictionary = (notification as NSNotification).userInfo!
        let callback: String = userInfo["event"] as! String
        
        if(callback == "onTime") {return}
        
        var text: String = callbacksView!.text
        text = text.appendingFormat("\n%@", callback)
        callbacksView?.text = text
        
        let size: CGSize = callbacksView!.sizeThatFits(CGSize(width: callbacksView!.frame.size.width, height: CGFloat.greatestFiniteMagnitude))
        callbacksView?.contentSize = size as CGSize
        
        if(callbacksView!.contentSize.height > callbacksView!.frame.size.height) {
            callbacksView!.setContentOffset(CGPoint(x: 0, y: callbacksView!.contentSize.height-callbacksView!.frame.size.height), animated: true)
        }
    }
    
    @objc func updatePlaybackTimer(_ notification: Notification) {
        let userInfo: NSDictionary = (notification as NSNotification).userInfo! as NSDictionary
        if(userInfo["event"] as! String == "onTime") {
            var text: String = String(format: "%.1f", userInfo["position"] as! Double) + " / "
            text += String(userInfo["duration"] as! Int)
            
            playbackTime.text = text
        }
    }
    
    //MARK: JW Player Delegates
    //    func onTime(_ position: Double, ofDuration duration: Double) {
    func onTime(_ event: (JWEvent & JWTimeEvent)!) {
        var text: String = String(format: "%.1f", event.position) + " / "
        text += String(format: "%.1f", event.duration)
        playbackTime.text = text
    }
    
    func onPlay(_ event: (JWEvent & JWStateChangeEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onPause(_ event: (JWEvent & JWStateChangeEvent)!) {
        playButton?.setTitle("Play", for: UIControlState())
    }

    func onBuffer(_ event: (JWEvent & JWBufferEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onIdle(_ event: (JWEvent & JWStateChangeEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onReady(_ event: (JWEvent & JWReadyEvent)!) {
        playButton?.setTitle("Play", for: UIControlState())
    }

    func onPlaylistComplete() {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onAdSkipped(_ event: (JWAdEvent & JWAdDetailEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onAdComplete(_ event: (JWAdEvent & JWAdDetailEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onAdImpression(_ event: (JWAdEvent & JWAdImpressionEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onBeforePlay() {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onBeforeComplete() {
        playButton?.setTitle("Pause", for: UIControlState())
    }

    func onAdPlay(_ event: (JWAdEvent & JWAdStateChangeEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onAdPause(_ event: (JWAdEvent & JWAdStateChangeEvent)!) {
        playButton?.setTitle("Play", for: UIControlState())
    }

    func onAdError(_ event: (JWAdEvent & JWErrorEvent)!) {
        playButton?.setTitle("Pause", for: UIControlState())
    }
}
