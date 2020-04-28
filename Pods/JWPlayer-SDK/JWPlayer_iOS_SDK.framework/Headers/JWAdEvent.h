//
//  JWAdEvent.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 5/16/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWEvent.h"
#import "JWAdConfig.h"
#import "JWAdBreak.h"

NS_ASSUME_NONNULL_BEGIN
/**
    Base class for various ad event classes. Exposes specific information based on the derived class.
 */
@interface JWAdEvent : NSObject

/**
 The ad tag that for which the event was fired.
 */
@property (nonatomic, copy) NSString *tag;

@end

/**
    Exposes additional details commonly found in ad events, and is a base class for other ad events.
 */
@protocol JWAdDetailEvent <NSObject>

/**
 The type of ad that is being played.
 */
@property (nonatomic, copy) NSString *creativeType;

/**
 The client that is currently being used, vast, googima or freewheel.
 */
@property (nonatomic) JWAdClient client;

@end

/**
   JWAdBreakEvent provides information for an ad break.
*/
@protocol JWAdBreakEvent <NSObject>

/**
 The client that is currently being used, vast, googima or freewheel.
 */
@property (nonatomic) JWAdClient client;

/**
 Whether an ad break is in a pre, mid, or post position.
 */
@property (nonatomic, copy) NSString *adPosition;

@end

/**
    JWAdRequestEvent provides information for a requested ad.
 */
@protocol JWAdRequestEvent <JWAdDetailEvent>

/**
 Whether an ad is in a pre, mid, or post position.
 */
@property (nonatomic, copy) NSString *adPosition;

/**
 An ad's position. Will return a number (in seconds) of a midroll's position
 */
@property (nonatomic, copy) NSString *offset;

@end

/**
    JWAdCompanionsEvent provides ad companion information for an ad.
 */
@protocol JWAdCompanionsEvent <NSObject>

/**
 An array with available companion information.
 */
@property (nonatomic) NSArray <JWAdCompanion *> *companions;

@end

/**
    JWAdScheduleEvent provides scheduling information specific to the loaded VMAP tag.
 */
@protocol JWAdScheduleEvent <NSObject>

/**
 An array containing the adBreaks of the VMAP schedule.
 */
@property (nonatomic) NSArray <JWAdBreak *> *adBreaks;

/**
 The client that is currently being used, vast, googima or freewheel.
 */
@property (nonatomic) JWAdClient client;

@end

/**
    JWAdImpressionEvent provides ad impression information of an ad.
 */
@protocol JWAdImpressionEvent <JWAdDetailEvent>

/**
 An ad's position (pre, mid, post).
 */
@property (nonatomic, copy) NSString *adPosition;

/**
 AdSystem referenced inside of the VAST XML.
 */
@property (nonatomic, nullable, copy) NSString *adSystem;

/**
 AdTitle referenced inside of the VAST XML.
 */
@property (nonatomic, nullable, copy) NSString *adTitle;

/**
 GoogleIMA and Freewheel-only: AdId referenced inside of the VAST XML.
 @note Google IMA and Freewheel only. Not yet supported in VAST.
 */
@property (nonatomic, nullable, copy) NSString *adId;

/**
GoogleIMA only: creativeId referenced inside of the VAST XML.
@note Google IMA only
*/
@property (nonatomic, nullable, copy) NSString *creativeAdId;

/**
GoogleIMA only: creativeId referenced inside of the VAST XML.
@note Google IMA only
*/
@property (nonatomic, nullable, copy) NSString *creativeId;

/**
 VAST-only: An array of the AdSystems specified in any utilized ad wrappers; index denotes level of wrapper.
 */
@property (nonatomic, nullable) NSArray *wrapper;

/**
 The URL which will be opened if the ad is clicked.
 */
@property (nonatomic, copy) NSString *clickThroughUrl;

/**
 The currently playing media item.
 */
@property (nonatomic, copy) NSString *mediaFile;

/**
 VAST-only: The version of VAST referenced in the VAST XML.
 */
@property (nonatomic) CGFloat vastVersion;

/**
 Wether the ad is linear or nonlinear.
 */
@property (nonatomic) JWAdType linear;

/**
 Details of the VMAP schedule's adBreak that is currently playing. Available only for VMAP schedules on Vast.
 */
@property (nonatomic, nullable) NSDictionary *vmapInfo;

@end

/**
    JWAdStateChangeEvent describes the state change of the player.
 */
@protocol JWAdStateChangeEvent <JWAdDetailEvent, JWStateChangeEvent>

/**
 The new state of the player.
 */
@property (nonatomic) JWPlayerState newState;

@end

/**
    JWAdTimeEvent denotes the sequence of the current ad.
 */
@protocol JWAdTimeEvent <JWAdDetailEvent, JWTimeEvent>

/**
 Returns the sequence number the ad is a part of.
 */
@property (nonatomic) NSUInteger sequence;

@end
NS_ASSUME_NONNULL_END
