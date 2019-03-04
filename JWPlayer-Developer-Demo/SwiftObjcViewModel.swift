//
//  SwiftObjcViewModel.swift
//  JWPlayer-Developer-Guide
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

import Foundation

let sdkVerMsg = "*****\n SDK Version: \(JWPlayerController.sdkVersion() ?? "unavailable")\n*****\n"

@objcMembers
class SwiftObjcViewModel: NSObject {
    public static var shared = SwiftObjcViewModel()
    private override init() {
        super.init()
        // receive model updates
        setupNotifications()
    }
    /// UI counter for callbacks (see extension).
    var callNumber = 0
    var kvoObservations = [NSKeyValueObservation]()
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    var player = JWPlayerFactory.newPlayer()
    var outputTextView: UITextView? { didSet { setupOutputKVO() }}
    var outputDetailsTextView: UITextView? { didSet { setupDetailsOutputKVO() }}
    
    @objc dynamic var outputText        = sdkVerMsg
    @objc dynamic var outputDetailsText = sdkVerMsg
}

extension SwiftObjcViewModel /* Notifications & Output */ {
    private func setupNotifications() {
        // Notifications to get Model updates
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
        
        let notificationNames = notifications.map({ Notification.Name($0)})
        
        for(_, nName) in notificationNames.enumerated() {
            NotificationCenter.default.addObserver(self, selector: #selector(handleNotification(_:)), name: nName, object: nil)
        }
    }

    @objc func handleNotification(_ notification: Notification) {
        var userInfo: Dictionary = (notification as NSNotification).userInfo!
        let callbackEventName: String = userInfo["event"] as! String
        
        if callbackEventName == "onTime" {return}
        
        callNumber += 1
        outputText += "\n\(callNumber). " + callbackEventName
        let outputDetailsMsg = "\(callNumber).\n" + details(for: notification)
        outputDetailsText += "\n=+=+=" + outputDetailsMsg
    }
    
    @objc func details(for notification: Notification) -> String {
        let userInfo: Dictionary = (notification as NSNotification).userInfo!
        return userInfo.prettyPrint()
    }
    
    // MARK: KVO to update UI
    private func setupOutputKVO() {
        outputTextView?.text = outputText;
        
        kvoObservations += [observe(\.outputText, options: .new, changeHandler: { (viewModel, changes) in
                viewModel.outputTextView?.text = changes.newValue
            self.outputTextView?.scrollToBottom()
        })]
    }
    
    private func setupDetailsOutputKVO() {
        outputDetailsTextView?.text = outputDetailsText;
        
        kvoObservations += [observe(\.outputDetailsText, options: .new, changeHandler: { (viewModel, changes) in
                viewModel.outputDetailsTextView?.text = changes.newValue
            self.outputDetailsTextView?.scrollToBottom()
        })]
    }
}

// Optional
extension SwiftObjcViewModel: JWPlayerDelegate {
    // Convenience callbacks as an alternative to
    // notification subscriptions can go here.
}


// Helpers

fileprivate extension UIScrollView {
    func scrollToBottom() {
        setContentOffset(bottomOffset, animated: true)
    }
    
    var bottomOffset: CGPoint {
        let newY = max(0, contentSize.height - bounds.size.height + contentInset.bottom)
        return CGPoint(x: 0, y: newY) }
}
