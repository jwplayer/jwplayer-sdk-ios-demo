//
//  JWAdBreak.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 10/3/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IMAAd;
@class IMAAdsRequest;

/**
    Type of ad redering behavior for playback, either linear or non-linear.
 */
typedef NS_ENUM(NSInteger, JWAdType) {
    /// linear ad rendering
    JWAdTypeLinear = 1,
    /// non-linear ad rendering
    JWAdTypeNonlinear = 2
};

NS_ASSUME_NONNULL_BEGIN
/**
 JWAdBreak is an object providing info for an ad break in a video, played using JWPlayer.
 Single AdBreak or a set of multiple AdBreak should be fed to the JWAdConfig's schedule array
 */
@interface JWAdBreak : NSObject


/* ========================================*/
/** @name Accessing Ad Break Attributes
 */

/**
 Offset of the ad. Describes the point in time at which to play the ad.
 @Note Supported formats are:
    * pre: specifies that the ad should be played before the video content.
    * post: specifies that the ad should be played after the video content.
    * seconds - '50'
    * fractional seconds - '50.5'
    * percentage of the entire video - '50%'
    * hours, minutes, seconds, milliseconds : 'hh:mm:ss.mmm'
 */
@property (nonatomic, copy) NSString *offset;

/**
 This option is the URL to the ad tag, which contains the VAST response.
 */
@property (nonatomic, nullable, copy) NSString *tag;

/**
 This option is the array of URLs to the ad tags, which contains the VAST response.
 tags array is used as a waterfall: if the first tag fails to play, the player falls back to the second in the list and so on, until it finds one that can be played.
 @note Only one add from the array is played, and the others are discarded.
 */
@property (nonatomic, nullable, retain) NSArray <NSString *> *tags;

/**
 This should be set to JWAdTypeNonlinear if you want to force the player to render a nonlinear ad in the ad response. Defaults to JWAdTypeLinear.
 @note Non-linear ads are not supported by Goolge IMA as of version B15. Setting this property to JWAdTypeNonlinear while using Google IMA will result in an assertion.
 */
@property (nonatomic) JWAdType type;

/**
 Available for adBreaks within a VMAP retrieved from the JWPlayerDelegate's onAdSchedule: callback.
 @note VAST only.
 @see JWPlayerDelegate
 */
@property (nonatomic, nullable, readonly) NSDictionary *vmapInfo;

/* ========================================*/
/** @name Creating Ad Break Object
 */

/**
 Factory method that creates a linear or non-linear AdBreak with tag and offset.
 @param tag This option is the URL to the ad tag, which contains the VAST response.
 @param offset Offset of the ad.
 @param nonLinear Boolean value that determines if adbreak is non-linear.
 */
+ (instancetype)adBreakWithTag:(NSString *)tag offset:(NSString *)offset nonLinear:(BOOL)nonLinear;

/**
 Factory method that creates a linear or non-linear AdBreak with waterfall tags and offset.
 @param tags This option is the array of URLs to the ad tags, which contains the VAST response.
 @param offset Offset of the ad.
 @param nonLinear Boolean value that determines if adbreak is non-linear.
 */
+ (instancetype)adBreakWithTags:(NSArray *)tags offset:(NSString *)offset nonLinear:(BOOL)nonLinear;

/**
 Factory method that creates an AdBreak with tag and offset.
 @param tag This option is the URL to the ad tag, which contains the VAST response.
 @param offset Offset of the ad.
 */
+ (instancetype)adBreakWithTag:(NSString *)tag offset:(NSString *)offset;

/**
 Factory method that creates an AdBreak with waterfall tags and offset.
 @param tags This option is the array of URLs to the ad tags, which contains the VAST response.
 @param offset Offset of the ad.
 */
+ (instancetype)adBreakWithTags:(NSArray *)tags offset:(NSString *)offset;

/* ========================================*/
/** @name Initializing Ad Break Object
 */


/**
 Inits an AdBreak with provided params.
 @param tags This option is the array of URLs to the ad tags, which contains the VAST response.
 @param offset Offset of the ad.
 */
- (instancetype)initWithTags:(NSArray *)tags offset:(NSString *)offset;

@end
NS_ASSUME_NONNULL_END
