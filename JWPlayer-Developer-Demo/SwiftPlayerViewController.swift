//
//  PlayerViewController.swift
//  JWPlayerSDKDemo
//
//  Created by Max Mikheyenko on 1/5/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.


import Foundation
import UIKit

class SwiftPlayerViewController: UIViewController, JWPlayerDelegate {
    
    private var player:JWPlayerController!
    @IBOutlet var callbacksView: UITextView!
    @IBOutlet var playbackTime: UILabel!
    @IBOutlet var playButton: UIButton!
    
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: NSBundle?) {
        callbacksView = UITextView(frame: CGRectZero)
        callbacksView?.editable = false
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }
    
    required init?(coder aDecoder: NSCoder) {
        callbacksView = UITextView(frame: CGRectZero)
        callbacksView?.editable = false
        super.init(coder: aDecoder)
    }
    
    override func viewDidLoad() {
        self.navigationItem.title = "Swift Implementation"
        
        self.edgesForExtendedLayout =  UIRectEdge.None
        self.view.backgroundColor = UIColor.whiteColor()
        
        self.automaticallyAdjustsScrollViewInsets = false
        
        super.viewDidLoad()
    }
    
    override func viewDidAppear(animated: Bool) {
        self.createPlayer()
        self.view.addSubview(player.view)
        self.setupCallbacks()
        super.viewDidAppear(animated)
    }
    
    func createPlayer() {
        // basic config
        
        /*
        JWConfig can be created with a single file reference
        var config: JWConfig = JWConfig(contentURL:"http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4")
        */
        
        let config: JWConfig = JWConfig()
        config.sources = [JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-injeKYZS.mp4", label: "180p Streaming", isDefault: true),
            JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-52qL9xLP.mp4", label: "270p Streaming"),
            JWSource (file: "http://content.bitsontherun.com/videos/bkaovAYt-DZ7jSYgM.mp4", label: "720p Streaming")]
        
        config.image = "http://content.bitsontherun.com/thumbs/bkaovAYt-480.jpg"
        config.title = "JWPlayer Demo"
        config.controls = true  //default
        config.`repeat` = false   //default
        config.premiumSkin = JWPremiumSkinRoundster
        
        /*
        custom xml skin can be applied using:
        config.skin = "http://p.jwpcdn.com/iOS/Skins/ethan.css"
        */
        
        //captions
        config.tracks = [JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-en.srt", label: "English", isDefault: true),
            JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-sp.srt", label: "Spanish"),
            JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-ru.srt", label: "Russian")]
        
        //caption config
        let captionStyling: JWCaptionStyling = JWCaptionStyling()
        captionStyling.font = UIFont (name: "Zapfino", size: 20)
        captionStyling.edgeStyle = raised
        captionStyling.windowColor = UIColor.purpleColor()
        captionStyling.backgroundColor = UIColor(red: 0.3, green: 0.6, blue: 0.3, alpha: 0.7)
        captionStyling.fontColor = UIColor.blueColor()
        config.captionStyling = captionStyling
        
        //ad config
        let adConfig: JWAdConfig = JWAdConfig()
        adConfig.adMessage = "Ad duration countdown xx"
        adConfig.skipMessage = "Skip in xx"
        adConfig.skipText = "Move on"
        adConfig.skipOffset = 3
        adConfig.adClient = vastPlugin
        config.adConfig = adConfig
        
        //auto start
//        config.autostart = true
        
        //waterfall tags
        let waterfallTags: NSArray = ["bad tag", "another bad tag", "http://playertest.longtailvideo.com/adtags/preroll_newer.xml"]
        //ad breaks
        config.adSchedule = [JWAdBreak(tags:waterfallTags as! [String], offset:"1"),
            JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"5"),
            JWAdBreak(tag: "http://demo.jwplayer.com/player-demos/assets/overlay.xml", offset: "7", nonLinear: true),
            //                           JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"0:00:05"),
            JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"50%"),
            JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"post")]
        
        self.player = JWPlayerController(config: config)
        self.player.delegate = self
        
        //sets player frame to be half the screen
        //alternatively config.size can be used during the player creation
        var frame: CGRect = self.view.bounds
        frame.size.height /= 2
        frame.size.height -= 44
        
        self.player.view.frame = frame
        self.player.view.autoresizingMask = [UIViewAutoresizing.FlexibleBottomMargin, UIViewAutoresizing.FlexibleHeight, UIViewAutoresizing.FlexibleLeftMargin, UIViewAutoresizing.FlexibleRightMargin, UIViewAutoresizing.FlexibleTopMargin, UIViewAutoresizing.FlexibleWidth];
        
        self.player.openSafariOnAdClick = true
        self.player.forceFullScreenOnLandscape = true
        self.player.forceLandscapeOnFullScreen = true
    }
    
    @IBAction func play(sender: UIButton) {
        if(self.player.playerState == "PAUSED" ||
            self.player.playerState == "IDLE") {
                self.player.play()
                self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
        } else {
            self.player.pause()
            self.playButton?.setTitle("Play", forState: UIControlState.Normal)
        }
    }
    
    func playerStateChanged(info: NSNotification) {
        let userInfo: NSDictionary = info.userInfo!
        if( userInfo["event"] as! String == "onPause" ||
            userInfo["event"] as! String == "onReady" ||
            userInfo["event"] as! String == "onAdPause") {
                self.playButton?.setTitle("Play", forState: UIControlState.Normal)
        } else {
            self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
        }
    }
    
    @IBAction func insertAd(sender: UIButton) {
        self.player .playAd("http://playertest.longtailvideo.com/adtags/preroll_newer.xml")
    }
    
    func setupCallbacks() {
        setupNotifications()
    }
    
    func setupNotifications() {
        let notifications: Array = [JWPlayerStateChangedNotification, JWMetaDataAvailableNotification, JWAdActivityNotification, JWErrorNotification, JWCaptionsNotification, JWVideoQualityNotification, JWPlaybackPositionChangedNotification, JWFullScreenStateChangedNotification, JWAdClickNotification]
        
        let center:  NSNotificationCenter = NSNotificationCenter.defaultCenter()
        
        for(_, notification) in notifications.enumerate() {
            center.addObserver(self, selector: "handleNotification:", name: notification, object: nil)
        }
        center.addObserver(self, selector: "updatePlaybackTimer:", name: JWPlaybackPositionChangedNotification as String!, object: nil)
        center.addObserver(self, selector: "playerStateChanged:", name: JWPlayerStateChangedNotification as String!, object: nil)
        center.addObserver(self, selector: "playerStateChanged:", name: JWAdActivityNotification as String!, object: nil)
    }
    
    func handleNotification(notification: NSNotification) {
        var userInfo: Dictionary = notification.userInfo!
        let callback: String = userInfo["event"] as! String
        
        if(callback == "onTime") {return}
        
        var text: String = self.callbacksView!.text
        text = text.stringByAppendingFormat("\n%@", callback)
        self.callbacksView?.text = text
        
        let size: CGSize = self.callbacksView!.sizeThatFits(CGSizeMake(self.callbacksView!.frame.size.width, CGFloat.max))
        self.callbacksView?.contentSize = size as CGSize
        
        if(self.callbacksView!.contentSize.height > self.callbacksView!.frame.size.height) {
            self.callbacksView!.setContentOffset(CGPointMake(0, self.callbacksView!.contentSize.height-self.callbacksView!.frame.size.height), animated: true)
        }
        
    }
    
    func updatePlaybackTimer(notification: NSNotification) {
        let userInfo: NSDictionary = notification.userInfo!
        if(userInfo["event"] as! String == "onTime") {
            var text: String = String(format: "%.1f", userInfo["position"] as! Double) + "/"
            text += String(userInfo["duration"] as! Int)
            
            self.playbackTime.text = text
        }
    }
    
    func onTime(position: Double, ofDuration duration: Double) {
        var text: String = String(format: "%.1f", position) + "/"
        text += String(format: "%.1f", duration)
        self.playbackTime.text = text
    }
    
    func onPlay() {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onPause() {
        self.playButton?.setTitle("Play", forState: UIControlState.Normal)
    }
    
    func onBuffer() {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onIdle() {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onReady() {
        self.playButton?.setTitle("Play", forState: UIControlState.Normal)
    }
    
    func onComplete() {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onAdSkipped(tag: String!) {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onAdComplete(tag: String!) {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onAdImpression(tag: String!) {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onBeforePlay() {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onBeforeComplete() {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onAdPlay(tag: String!) {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func onAdPause(tag: String!) {
        self.playButton?.setTitle("Play", forState: UIControlState.Normal)
    }
    
    func onAdError(error: NSError!) {
        self.playButton?.setTitle("Pause", forState: UIControlState.Normal)
    }
    
    func controlCenter() {
        MPNowPlayingInfoCenter.defaultCenter().nowPlayingInfo = [MPMediaItemPropertyArtist : "Artist",  MPMediaItemPropertyTitle : "Title"]
    }
}