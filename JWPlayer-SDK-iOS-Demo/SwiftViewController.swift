//
//  SwiftViewController.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import UIKit

class SwiftViewController: UIViewController {
    @IBOutlet weak var playerContainerView: UIView!
    var player: JWPlayerController?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        player = JWPlayerFactory.newPlayer()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        layout(playerView: player!.view)
    }

    func layout(playerView: UIView) {
        playerContainerView.addSubview(playerView)

        if JWPlayerController.supportsAutolayout
        {
            playerView.constrainToSuperview()
        } else {
            playerView.frame = playerContainerView.bounds
            playerView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        }
    }
}
