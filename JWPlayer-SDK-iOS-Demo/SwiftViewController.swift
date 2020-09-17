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

        let VIDEO_TAG = "http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4"
        let config = JWConfig(contentURL: VIDEO_TAG)
        config.advertising = getAdConfig()
        player = JWPlayerController(config: config)
        
        #warning("The JWP Key must be set here, or in info.plist.")
//        JWPlayerController.setPlayerKey("")
        title = "JWP SDK ver: \(JWPlayerController.sdkVersionToMinor())"
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        if let playerView = player?.view {
            playerContainerView.addSubview(playerView)
            playerView.constrainToSuperview()
        }
    }
    
    private func getAdConfig() -> JWAdConfig {
        // Putting it all together:
        let adConfig = JWAdConfig()
        adConfig.schedule  = [JWAdBreak(tag: "fw_Ad", offset: "pre")]
        adConfig.client    = .freewheel
        adConfig.freewheel = .fwConfigWithTestAppsValues // .fwConfigSanomaValues
                
        return adConfig
    }
}

extension JWFreewheelConfig {
    
    static var fwConfigSanomaValues: JWFreewheelConfig {
        let config = JWFreewheelConfig()
        config.mediaId   = "YYhcQ8rH"
        config.networkId = 506166
        config.profileId = "506166:sanoma_sbs_external_live"
        config.sectionId = "sanomanl_nu_jw_ios_phone_app_tech"
        config.serverId  = "https://7b935.v.fwmrm.net/" // + "ad/g/1"
        config.duration  = 600
        
        return config
    }

    /// Values extracted from the JW Test App, by reverse-engineering `ConfigParser`.
    static var fwConfigWithTestAppsValues: JWFreewheelConfig {
        let fwConfig = JWFreewheelConfig()
        fwConfig.mediaId   = "jw_test_asset_h"
        fwConfig.networkId = 90750
        fwConfig.profileId = "90750:jw_ios_test"
        fwConfig.sectionId = "jw_test_site_section"
        fwConfig.serverId  = "https://demo.v.fwmrm.net/" // MUST remove "ad/g/1"
        fwConfig.duration  = 600
        return fwConfig
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
