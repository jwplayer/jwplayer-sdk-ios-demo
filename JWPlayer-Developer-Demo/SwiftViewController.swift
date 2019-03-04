//
//  SwiftViewController.swift
//  JWPlayer-Developer-Guide
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import UIKit

class SwiftViewController: UIViewController {
    fileprivate var viewModel = SwiftObjcViewModel.shared
    
    @IBOutlet weak var callbacksTextView: UITextView!
    @IBOutlet weak var callbacksDetailsTextView: UITextView!
    @IBOutlet weak var playerContainerView: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        viewModel.outputTextView = callbacksTextView
        viewModel.outputDetailsTextView = callbacksDetailsTextView
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        layout(playerView: viewModel.player.view)
    }

    override func viewWillDisappear(_ animated: Bool) {
        viewModel.player.pause()
        super.viewWillDisappear(animated)
    }
    
    func layout(playerView: UIView) {
        playerContainerView.addSubview(playerView)
        playerView.frame = playerContainerView.bounds
        playerView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
    }
    
    @IBAction func outputToggleTapped(_ sender: UISwitch) {
        view.bringSubview(toFront:
        (sender.isOn ? callbacksDetailsTextView : callbacksTextView))
    }
    
}
