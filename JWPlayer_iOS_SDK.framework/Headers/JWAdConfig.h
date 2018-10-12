//
//  JWAdConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 10/3/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWAdRules.h"

typedef enum {
    JWAdClientVast = 0,
    JWAdClientGoogima,
    JWAdClientFreewheel
}JWAdClient;

@class JWAdBreak, IMASettings, JWFreewheelConfig;

/*!
 An object providing information about the way ads are handled by the player. Describes adMessage, skipMessage, skipText and skipOffset.
 @discussion In the current implementation, an adConfig object can be added to config and propagates to all adBreaks.
 */
@interface JWAdConfig : NSObject

/* ========================================*/
/** @name Accessing Ad Config Attributes */

/*!
The URL of the VAST tag to display, or the custom string of the Freewheel tag to display.
 @discussion can also specify Vast vmap file to use for ad breaks.
 @discussion ignore if schedule is set.
*/
@property (nonatomic, retain) NSString *tag;

/*!
 A message to be shown to the user in place of a seekbar while the ad is playing.
 @discussion 'xx' in the message is replaced with countdown timer until the end of the ad.
 */
@property (nonatomic, retain) NSString *adMessage;

/*!
 A message to be shown on the skip button during countdown to skip availablilty.
 @discussion 'xx' in the message is replaced with countdown timer until the moment skip becomes available.
 @see skipText
 */
@property (nonatomic, retain) NSString *skipMessage;

/*!
 A message to be shown on the skip button when the skip option becomes available.
 */
@property (nonatomic, retain) NSString *skipText;

/*!
 An integer representing the number of seconds before the ad can be skipped.
 */
@property (nonatomic) NSUInteger skipOffset;

/*!
 An array of JWAdBreak objects that proivides info about ad breaks.
 @discussion tag property is ignored if this property is not nil.
 @see JWAdBreak
 */
@property (nonatomic, retain) NSArray <JWAdBreak *> *schedule;

/*!
 Vast vmap file to use for ad breaks.
 @discussion schedule is ignored if this property is not nil.
 */
@property (nonatomic, retain) NSString *adVmap;

/*!
 Set to JWAdClientGoogima if you wish to use google IMA; set to JWAdClientVast if not. Setting to nil defaults to vast.
 @discussion Due to the fact that Google IMA's iOS SDK is still in Beta mode, we suggest using the vast plugin.
 */
@property (nonatomic) JWAdClient client;

/*!
 The IMASettings class stores the Google IMA SDK settings.
 @discussion When setting a custom imaSetting, the default value of enableBackgroundPlayback is NO.
 */
@property (nonatomic) IMASettings *googimaSettings;

/*!
 The JWFreewheelConfig class stores the Freewheel SDK settings.
 @discussion When setting Freewheel settings, the value of adClient should be set to JWAdClientFreewheel.
 */
@property (nonatomic) JWFreewheelConfig *freewheel;

/*!
 For forcing controls to show for VPAID ads. Default is false.
 @discussion If the VPAID creative has built-in controls, showing the controls may be redundant.
 */
@property (nonatomic) BOOL vpaidControls;

/*!
 Use to control the frequency of ad playback.
 @discussion Available only for the VAST adClient.
 */
@property (nonatomic, retain) JWAdRules *rules;

@end
