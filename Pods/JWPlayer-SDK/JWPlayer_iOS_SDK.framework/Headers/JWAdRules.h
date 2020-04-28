//
//  JWAdRules.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/24/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
    Type of ad behavior indicating if an ad is served when the first playback is caused by a seek.
 */
typedef NS_ENUM(NSInteger, JWAdShown) {
    /// Do not show ad
    JWAdShownNone = 1,
    /// play preRoll before the content's initial playback
    JWAdShownPre = 2
};

NS_ASSUME_NONNULL_BEGIN

/**
    JWAdRules playback rules for the scheduled ads.
 */
@interface JWAdRules : NSObject
/**
 The first playlist item that will allow ad playback, index starting at 1.
 */
@property (nonatomic) NSUInteger startOn;

/**
 Play ads only on every X playlist item. i.e. frequency 3 means only play on ads on every third playlist item.
 @note Use 0 to only play ads on the first playlist item.
 */
@property (nonatomic) NSUInteger frequency;

/**
 Allows publishers to configure a minimum amount of time (in seconds) that needs to pass before the viewer is served another ad.
 */
@property (nonatomic) NSUInteger timeBetweenAds;

/**
 Indicates which ad (if any) should play if playback starts by seeking.
 */
@property (nonatomic) JWAdShown startOnSeek;

@end
NS_ASSUME_NONNULL_END
