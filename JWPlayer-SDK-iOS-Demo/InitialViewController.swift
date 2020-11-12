//
//  ViewController.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 8/31/20.
//  Copyright © 2020 JWPlayer. All rights reserved.
//

import UIKit

class InitialViewController: UIViewController {
    @IBOutlet weak var objc: UIButton!
    @IBOutlet weak var swift: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        addBorder(to: objc)
        addBorder(to: swift)
    }
    
    private func addBorder(to button: UIButton?) {
        button?.layer.borderColor  = UIColor.white.cgColor
        button?.layer.borderWidth  = 1
        button?.layer.cornerRadius = 3
    }
}
