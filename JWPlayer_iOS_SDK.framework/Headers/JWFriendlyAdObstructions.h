//
//  JWFriendlyAdObstructions.h
//  JWPlayer-iOS-SDK
//
//  Created by David Almaguer on 9/5/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JWPlayerController;

NS_ASSUME_NONNULL_BEGIN

/**
 This interface allows to register views considered as friendly obstructions.
 
 @note Applicable to the Google IMA ad client only.
 
 Friendly obstructions are views such as video controls that are essential to the user’s experience but do not impact viewability. Once registered as such, these controls are excluded from ad viewability measurements. These controls must only be fully transparent overlays or small buttons. Any other non-control views must not be registered.
 
 When ad viewability via the OMSDK is calculated, all views overlaying the media element are considered obstructions and reduce the viewability rate.

 You may register:
 
    * A transparent overlay used to capture user taps.
 
    * Transient buttons such as:
 
        1. Pause
 
        2. Play
 
        3. Fullscreen
     
        4. Cast/AirPlay
     
        5. Collapse
     
        6. Progress/Seek
     
        7. Other playback relevant actions
 
 You must NOT register:
 
    * Watermarks
 
    * Pop ups
 
    * Dialogs
 
    * Non-transient buttons
 
    * Other obscuring views
 
 
 For more information, see [Open Measurement in the IMA SDK](https://developers.google.com/interactive-media-ads/docs/sdks/ios/omsdk)
 */
@interface JWFriendlyAdObstructions : NSObject

/**
 List of views registered as friendly obstructions
 */
@property (nonatomic, readonly, nullable) NSArray<UIView *> *views;

/**
 * :nodoc:
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Initializes an friendly obstructions instance with the given player.
 Must add every view that overlay the ads.

 @param player The JWPlayerController that you want to asociate
 @return A JWFriendlyAdObstructions instance
 */
- (instancetype)initWithPlayer:(JWPlayerController *)player NS_DESIGNATED_INITIALIZER;

/**
 Register your custom video playback view that will overlay the ad container.
 
 @param view
 The UI element appearing over the ad container.
 */
- (void)registerView:(UIView * _Nonnull)view;

/**
 Registers an array of custom video playback views that will overlay the ad container.
 
 @param views
 The UI elements array appearing over the ad container.
 */
- (void)registerViews:(NSArray<UIView *> * _Nonnull)views;

/**
 Unregsiter a previously registered view that is not longer appearing over the ad container.
 
 @param view
 The UI element to remove and is not longer over the ad container.
 */
- (void)unregisterView:(UIView * _Nonnull)view;

/**
 Unregsiter all previously registered views.
 */
- (void)unregisterAllViews;

@end

NS_ASSUME_NONNULL_END
