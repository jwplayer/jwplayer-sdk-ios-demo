//
//  HelperExtensions.swift
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 3/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

extension JWPlayerController {
    /// Autolayout support was introduced in SDK v3.3.0
    @objc static var supportsAutolayout: Bool {
        if
            let components = sdkVersionToMinor()?.components(separatedBy: "."),
            let majorVer = components[0].intValue,
            let minorVer = components[1].intValue
        {
            return majorVer >= 3 && minorVer >= 3
        }
        
        return false
    }
}

extension UIView {
    /// Constrains the view to its superview, if it exists.
    @objc func constrainToSuperview() {
        translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate(
            NSLayoutConstraint.constraints(withVisualFormat: "H:|[thisView]|", options: [], metrics: nil, views: ["thisView": self]) +
                NSLayoutConstraint.constraints(withVisualFormat: "V:|[thisView]|", options: [], metrics: nil, views: ["thisView": self])
        )
        
    }
}

extension String {
    var intValue: Int? {
        return Int(self)
    }
}
