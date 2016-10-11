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
        self.navigationItem.title = "Swift Implementation"
        
        self.edgesForExtendedLayout =  UIRectEdge()
        self.view.backgroundColor = UIColor.white
        
        self.automaticallyAdjustsScrollViewInsets = false
        
        super.viewDidLoad()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        self.createPlayer()
        self.view.addSubview(player.view)
        self.setupCallbacks()
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
        config.premiumSkin = JWPremiumSkinRoundster
        
        /* custom css skin can be applied using: */
        //config.cssSkin = "http://p.jwpcdn.com/iOS/Skins/ethan.css"
        
        
        //MARK: JWTrack (captions)
        config.tracks = [JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-en.srt", label: "English", isDefault: true),
                         JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-sp.srt", label: "Spanish"),
                         JWTrack (file: "http://playertest.longtailvideo.com/caption-files/sintel-ru.srt", label: "Russian")]
        
        //MARK: JWCaptionStyling
        let captionStyling: JWCaptionStyling = JWCaptionStyling()
        captionStyling.font = UIFont (name: "Zapfino", size: 20)
        captionStyling.edgeStyle = raised
        captionStyling.windowColor = UIColor.purple
        captionStyling.backgroundColor = UIColor(red: 0.3, green: 0.6, blue: 0.3, alpha: 0.7)
        captionStyling.fontColor = UIColor.blue
        config.captionStyling = captionStyling
        
        //MARK: JWAdConfig
        let adConfig: JWAdConfig = JWAdConfig()
        adConfig.adMessage = "Ad duration countdown xx"
        adConfig.skipMessage = "Skip in xx"
        adConfig.skipText = "Move on"
        adConfig.skipOffset = 3
        adConfig.adClient = vastPlugin
        config.adConfig = adConfig
        
        /* auto start */
        //        config.autostart = true
        
        //MARK: Waterfall Tags
        let waterfallTags: NSArray = ["bad tag", "another bad tag", "http://playertest.longtailvideo.com/adtags/preroll_newer.xml"]
        
        //MARK: Ad Schedule
        config.adSchedule = [JWAdBreak(tags:waterfallTags as! [String], offset:"1"),
                             JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"5"),
                             JWAdBreak(tag: "http://demo.jwplayer.com/player-demos/assets/overlay.xml", offset: "7", nonLinear: true),
                             //                           JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"0:00:05"),
            JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"50%"),
            JWAdBreak(tag: "http://playertest.longtailvideo.com/adtags/preroll_newer.xml", offset:"post")]
        
        self.player = JWPlayerController(config: config)
        self.player.delegate = self

        var frame: CGRect = self.view.bounds
        frame.origin.y = 10
        frame.size.height /= 2
        frame.size.height -= 44
        
        self.player.view.frame = frame
        self.player.view.autoresizingMask = [
            UIViewAutoresizing.flexibleBottomMargin,
            UIViewAutoresizing.flexibleHeight,
            UIViewAutoresizing.flexibleLeftMargin,
            UIViewAutoresizing.flexibleRightMargin,
            UIViewAutoresizing.flexibleTopMargin,
            UIViewAutoresizing.flexibleWidth]
        
        self.player.openSafariOnAdClick = true
        self.player.forceFullScreenOnLandscape = true
        self.player.forceLandscapeOnFullScreen = true
    }
    
    @IBAction func play(_ sender: UIButton) {
        if(self.player.playerState == "PAUSED" ||
            self.player.playerState == "IDLE") {
            self.player.play()
            self.playButton?.setTitle("Pause", for: UIControlState())
        } else {
            self.player.pause()
            self.playButton?.setTitle("Play", for: UIControlState())
        }
    }
    
    func playerStateChanged(_ info: Notification) {
        let userInfo: NSDictionary = (info as NSNotification).userInfo! as NSDictionary
        if( userInfo["event"] as! String == "onPause" ||
            userInfo["event"] as! String == "onReady" ||
            userInfo["event"] as! String == "onAdPause") {
            self.playButton?.setTitle("Play", for: UIControlState())
        } else {
            self.playButton?.setTitle("Pause", for: UIControlState())
        }
    }
    
    @IBAction func insertAd(_ sender: UIButton) {
        self.player .playAd("http://playertest.longtailvideo.com/adtags/preroll_newer.xml")
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
        
        let center:  NotificationCenter = NotificationCenter.default
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
        
        var text: String = self.callbacksView!.text
        text = text.appendingFormat("\n%@", callback)
        self.callbacksView?.text = text
        
        let size: CGSize = self.callbacksView!.sizeThatFits(CGSize(width: self.callbacksView!.frame.size.width, height: CGFloat.greatestFiniteMagnitude))
        self.callbacksView?.contentSize = size as CGSize
        
        if(self.callbacksView!.contentSize.height > self.callbacksView!.frame.size.height) {
            self.callbacksView!.setContentOffset(CGPoint(x: 0, y: self.callbacksView!.contentSize.height-self.callbacksView!.frame.size.height), animated: true)
        }
    }
    
    func updatePlaybackTimer(_ notification: Notification) {
        let userInfo: NSDictionary = (notification as NSNotification).userInfo! as NSDictionary
        if(userInfo["event"] as! String == "onTime") {
            var text: String = String(format: "%.1f", userInfo["position"] as! Double) + "/"
            text += String(userInfo["duration"] as! Int)
            
            self.playbackTime.text = text
        }
    }
    
    //MARK: JW Player Delegates
    func onTime(_ position: Double, ofDuration duration: Double) {
        var text: String = String(format: "%.1f", position) + "/"
        text += String(format: "%.1f", duration)
        self.playbackTime.text = text
    }
    
    func onPlay() {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onPause() {
        self.playButton?.setTitle("Play", for: UIControlState())
    }
    
    func onBuffer() {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onIdle() {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onReady() {
        self.playButton?.setTitle("Play", for: UIControlState())
    }
    
    func onComplete() {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onAdSkipped(_ tag: String!) {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onAdComplete(_ tag: String!) {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onAdImpression(_ tag: String!) {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onBeforePlay() {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onBeforeComplete() {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onAdPlay(_ tag: String!) {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
    
    func onAdPause(_ tag: String!) {
        self.playButton?.setTitle("Play", for: UIControlState())
    }
    
    func onAdError(_ error: Error!) {
        self.playButton?.setTitle("Pause", for: UIControlState())
    }
}
