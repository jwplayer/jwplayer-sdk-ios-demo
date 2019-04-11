//
//  JWExperimentalAPI.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 3/18/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 A class that exposes experimental functionality. Some of these APIs are not yet officially supported by standards and will be modified when the industry establishes a norm. At that point these APIs will be deprecated and will subsequently be removed or replaced by the industry's standard.
 */
@interface JWExperimentalAPI : NSObject

#pragma Mark - Friendly Advertising Obstructions

/*!
 The following methods allows you to register friendly advertising obstructions.
 @discussion Applicable to the Google IMA ad client only.
 @see JWAdConfig
 @discussion When ad viewability via the OMSDK is calculated, all views overlaying the media element are considered obstructions and reduce the viewability rate. Friendly obstructions are views such as video controls that are essential to the user’s experience but do not impact viewability. Once registered as such, these controls
 are excluded from ad viewability measurements. These controls must only be fully transparent overlays or small buttons. Any other non-control views must not be registered.
 @discussion You may register:
 ● A transparent overlay used to capture user taps.
 ● Transient buttons such as:
    ○ Pause
    ○ Play
    ○ Fullscreen
    ○ Cast/AirPlay
    ○ Collapse
    ○ Progress/Seek
    ○ Other playback relevant actions
 @discussion You must NOT register:
 ● Watermarks
 ● Pop ups
 ● Dialogs
 ● Non-transient buttons
 ● Other obscuring views
 */

/*!
 Used to register UIView elements as friendly advertising obstructions.
 @param obstruction the UIView element appearing on top of the player's view during ad playback.
 */
- (void)registerFriendlyAdObstruction:(UIView *)obstruction;

/*!
 Used to retrieve all UIView elements registered as friendly advertising obstructions.
 @return the array of UIView elements registered as friendly advertising obstructions.
 */
- (NSArray <UIView *> *)getFriendlyAdObstructions;

/*!
 Used to unregister UIView elements previously registered as friendly advertising obstructions.
 @param obstruction the UIView element appearing on top of the player's view during ad playback.
 */
- (void)deregisterFriendlyAdObstruction:(UIView *)obstruction;

/*!
 Used to unregister all UIView elements previously registered as friendly advertising obstructions.
 */
- (void)deregisterAllFriendlyAdObstructions;

@end

NS_ASSUME_NONNULL_END
