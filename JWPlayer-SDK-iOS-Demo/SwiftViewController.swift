//
//  SwiftViewController.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import UIKit
import AVKit
import MediaPlayer

class SwiftViewController: UIViewController {
    @IBOutlet weak var playerContainerView: UIView!
    var player: JWPlayerController?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let config = JWConfig(contentURL: "http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4")
        player = JWPlayerController(config: config)
        
        navigationItem.setupAirPlayButton()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        if let playerView = player?.view {
            playerContainerView.addSubview(playerView)
            playerView.constrainToSuperview()
        }
    }
    
//    func setupAirPlayButton() {
//        var barButtonItem: UIBarButtonItem?
//
//        if #available(iOS 11.0, *) {
//            barButtonItem = UIBarButtonItem(customView: AVRoutePickerView())
//        } else {
//            let volumeView = MPVolumeView()
//            volumeView.showsVolumeSlider = false
//            barButtonItem = UIBarButtonItem(customView: volumeView)
//        }
//
//        if let barButtonItem = barButtonItem {
//            navigationItem.rightBarButtonItems?.append(barButtonItem)
//        }
//    }
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

extension UINavigationItem {
    
    func setupAirPlayButton() {
        var barButtonItem: UIBarButtonItem?
        
        if #available(iOS 11.0, *) {
            barButtonItem = UIBarButtonItem(customView: AVRoutePickerView())
        } else {
            let volumeView = MPVolumeView()
            volumeView.showsVolumeSlider = false
            barButtonItem = UIBarButtonItem(customView: volumeView)
        }
        
        if let barButtonItem = barButtonItem {
            setRightBarButton(barButtonItem, animated: true)
        }
    }
}
