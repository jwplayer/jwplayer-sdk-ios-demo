//
//  FWRequestConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 3/31/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FWVisitorConfiguration.h"
#import "FWSiteSectionConfiguration.h"
#import "FWVideoAssetConfiguration.h"
#import "FWTemporalSlotConfiguration.h"
#import "FWNonTemporalSlotConfiguration.h"
#import "FWConsentConfiguration.h"
#import "FWPlayerConfiguration.h"
#import <UIKit/UIKit.h>

/**
	`FWRequestConfiguration` is a configuration object used in constructing ad request with convenience methods

	`-[FWContext submitRequestWithConfiguration: timeout:]` expects a `FWRequestConfiguration` object for constructing and submitting an ad request

	@see `-[FWContext submitRequestWithConfiguration: timeout:]`
 */
@interface FWRequestConfiguration : NSObject

/**
	The server URL where the ad request will be sent

	Please consult your FreeWheel solution engineer for the value to be used
 */
@property (strong, nonatomic, readonly, nonnull) NSString *serverURL;

/**
	The mode of the ad request: FWRequestModeOnDemand(by default) or FWRequestModeLive
 */
@property (nonatomic) FWRequestMode requestMode;

/**
	A list of acceptable alternative dimensions for video ads. Each dimension in the array must be a `NSDictionary` object with key "width" and "height", the value of should be a positive integer. `nil` by default. Example:
 `@@[@@{@@"width": @@800, @@"height": @@600}, @@{@@"width": @@640, @@"height": @@480}]`
 */
@property (strong, nonatomic, readwrite, nonnull) NSArray *videoDisplayCompatibleDimensions;

/**
	Player profile used in ad selection

	Please consult your FreeWheel solution engineer for the value to be used
 */
@property (strong, nonatomic, readonly, nonnull) NSString *playerProfile;

/**
	Player Dimensions used for building Ad Request Configuration Key Value Pair. It must include "width" and "height" with positive integer value (in points, not pixels).
 **/
@property (nonatomic) CGSize playerDimensions;

/**
	Profile used in ad selection for temporal slots. Overrides `playerProfile`

	Please consult your FreeWheel solution engineer for the value to be used
 */
@property (strong, nonatomic, nonnull) NSString *defaultTemporalSlotProfile;

@property (strong, nonatomic, nullable) NSString *defaultVideoPlayerSlotProfile DEPRECATED_MSG_ATTRIBUTE("Please use defaultNonTemporalSlotProfile instead");

@property (strong, nonatomic, nullable) NSString *defaultSiteSectionSlotProfile DEPRECATED_MSG_ATTRIBUTE("Please use defaultNonTemporalSlotProfile instead");

/**
 	Profile used in ad selection for non temporal slots

 	Please consult your FreeWheel solution engineer for the value to be used
 */
@property (strong, nonatomic, nullable) NSString *defaultNonTemporalSlotProfile;

/**
	Visitor Configuration used for ad request

	This configuration passes information regarding the user to FreeWheel SDK, eventually used in ad selection

	@see `FWVisitorConfiguration`
 */
@property (strong, nonatomic, nullable) FWVisitorConfiguration *visitorConfiguration;

@property (strong, nonatomic, nullable) FWSiteSectionConfiguration *siteSectionConfiguration;

@property (strong, nonatomic, nullable) FWVideoAssetConfiguration *videoAssetConfiguration;

@property (strong, nonatomic, nullable) FWPlayerConfiguration *playerConfiguration;

/**
	Consent Configuration used for ad request
 
	This configuration passes consent information provided by the user to FreeWheel SDK, eventually used in ad selection.
 
	Please note, FWRequestConfiguration can automatically retrieve consent configuration information if the user stores this information in [NSUserDefaults standardUserDefaults]. The information from consentConfiguration is added to the AdRequest when executing submitWithTimeout on an AdRequest. Any changes to consentConfiguration following submitWithTimeout will not be added to the AdRequest.
 
	@see `FWConstants`, `FWConsentConfiguration`, and `FWGDPRConsentConfiguration`.
 */
@property (strong, nonatomic, nullable) FWConsentConfiguration *consentConfiguration;

- (nonnull instancetype)initWithServerURL:(nonnull NSString *)serverURL playerProfile:(nonnull NSString *)playerProfile DEPRECATED_MSG_ATTRIBUTE("Use `[FWRequestConfiguration initWithServerURL: playerProfile: playerDimensions:]` instead");

/**
	Initialize the request configuration with server URL and player profile

	Please consult your FreeWheel solution engineer for the values to be used.

	@param serverURL URL to be used for making server calls like ad request etc.
	@param playerProfile Player (global) profile to be used by the ad server for ad decisioning.
	@param playerDimensions Dimensions of the player when playing in its default mode (in points, not pixels)
 */
- (nonnull instancetype)initWithServerURL:(nonnull NSString *)serverURL playerProfile:(nonnull NSString *)playerProfile playerDimensions:(CGSize)playerDimensions;

/**
	Set capability supported by player

	@param status indicates where to enable or disable the capability
	@param capability Capability name, see `FWCapability*`
 */
- (void)setStatus:(FWCapabilityStatus)status forCapability:(nonnull NSString *)capability;

/**
	Add a key-value pair used in ad targeting. If called with same key multiple times, all the values will be added to the same key.

	@param value value in the key-value pair
	@param key key in the key-value pair, cannot be empty string
 */
- (void)addValue:(nonnull NSString *)value forKey:(nonnull NSString *)key;

/**
	Add a slot configuration. Please note, `FWSlotConfiguration` is an abstract class. Please use `FWTemporalSlotConfiguration` or `FWNonTemporalSlotConfiguration` for constructing slot configuration accordingly.
	Please note, duplicate slot configuration with same custom Id will be ignored.

	@param slotConfiguration A `FWTemporalSlotConfiguration` or `FWNonTemporalSlotConfiguration` object describing the slot
 */
- (void)addSlotConfiguration:(nonnull FWSlotConfiguration *)slotConfiguration;

/**
	Retrieve all temporal slot configurations added on the request configuration

	@return An immutable array copy of all the temporal slot configuration objects
 */
- (nonnull NSArray<FWTemporalSlotConfiguration *> *)temporalSlotConfigurations;

/**
	Retrieve all non-temporal slot configurations added on the request configuration

	@return An immutable array copy of all the non-temporal slot configuration objects
 */
- (nonnull NSArray<FWNonTemporalSlotConfiguration *> *)nonTemporalSlotConfigurations;

@end
