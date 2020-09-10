//
//  SwiftViewController.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 9/1/20.
//  Copyright © 2020 JWPlayer. All rights reserved.
//

import UIKit

class SwiftViewController: UIViewController {
    @IBOutlet weak var playerContainerView: UIView!
    var player: JWPlayerController?
    
    override func viewDidLoad() {
        super.viewDidLoad()

        let config = JWConfig(contentURL: "http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4")
        config.advertising = getAdConfig()
        player = JWPlayerController(config: config, delegate: self)
        
        title = "JWP SDK ver: \(JWPlayerController.sdkVersionToMinor())"
        
        #warning("LICENSE KEY SET??")
        JWPlayerController.setPlayerKey("")
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        if let playerView = player?.view {
            playerContainerView.addSubview(playerView)
            playerView.constrainToSuperview()
        }
    }
    
    private func getAdConfig() -> JWAdConfig {
        let adConfig = JWAdConfig()
     
        adConfig.client = .googima
        adConfig.schedule = [
            JWAdBreak(tag: "https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/single_ad_samples&ciu_szs=300x250&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ct%3Dskippablelinear&correlator=", offset: "pre"),
        ]
    
        return adConfig
    }
}


extension SwiftViewController: JWPlayerDelegate {
    func onAdTime(_ event: JWAdEvent & JWAdTimeEvent) {
        if (player != nil && event.position > 0.1)
        {
            print("nilling player...")
            player = nil
        }
    }
}

// MARK: - Helper method

extension UIView {
    /// Constrains the view to its superview, if it exists, using Autolayout.
    /// - precondition: For player instances, JWP SDK 3.3.0 or higher.
    @objc func constrainToSuperview() {
        translatesAutoresizingMaskIntoConstraints = false
        let horizontalConstraints = NSLayoutConstraint.constraints(withVisualFormat: "H:|[thisView]|",
                                                                   options: [],
                                                                   metrics: nil,
                                                                   views: ["thisView": self])
        
        let verticalConstraints   = NSLayoutConstraint.constraints(withVisualFormat: "V:|[thisView]|",
                                                                   options: [],
                                                                   metrics: nil,
                                                                   views: ["thisView": self])
        
        NSLayoutConstraint.activate(horizontalConstraints + verticalConstraints)
    }
}
