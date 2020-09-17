//
//  FWCTSRequestConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 2/20/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import "FWRequestConfiguration.h"

/**
	Encryption type used for URL. If URL is not encrypted, FWURLEncryptionTypeNone should be used

	- FWURLEncryptionTypeNone: URL is plain text, not encrypted
	- FWURLEncryptionTypeSHA256: URL is encrypted using SHA256 algorithms
 */
typedef NS_ENUM(NSUInteger, FWURLEncryptionType) {
	FWURLEncryptionTypeNone,
	FWURLEncryptionTypeSHA256
};


/**
	`FWCTSRequestConfiguration` is a subclass of `FWRequestConfiguration` with convenience methods for configuring values to be used in constructing and submitting an ad request.
 
	`-[FWCTSContext submitRequestWithConfiguration: timeout:]` expects a `FWCTSRequestConfiguration` object for constructing and submitting an ad request
 
	@see `-[FWCTSContext submitRequestWithConfiguration: timeout:]`
 */
@interface FWCTSRequestConfiguration : FWRequestConfiguration

/**
	Init Request Configuration for CTS Integration.
 
	Please consult your FreeWheel solution engineer for the values to be used.

	@param serverURL URL to be used for making server calls like ad request etc.
	@param playerProfile Player (global) profile to be used by the ad server for ad decisioning.
	@param accountId Account ID is unique identifier used in ad request construction.
	@param contentStreamURL Location of the content stream manifest (m3u8) URL. A cipher with SHA256 Encryption of the content URL is also supported.
	@param encryptionType Encryption type of the content stream manifest URL
 */
- (nonnull instancetype)initWithServerURL:(nonnull NSString *)serverURL playerProfile:(nonnull NSString *)playerProfile accountId:(nonnull NSString *)accountId contentStreamURL:(nonnull NSString *)contentStreamURL encryptionTypeForContentStreamURL:(FWURLEncryptionType)encryptionType;

/**
	Update content stream URL on configuration with encryptionType

	@param contentStreamURL Location of the content stream manifest (m3u8) URL used for stitching purposes
	@param encryptionType Encryption type of the content stream manifest URL
 */
- (void)setContentStreamURL:(nonnull NSString*)contentStreamURL withEncryptionType:(FWURLEncryptionType)encryptionType;


/**
	Location of the content stream URL used for stitching purposes
 
	@see `encryptionType`
 */
@property (readonly, strong, nonatomic, nonnull) NSString *contentStreamURL;


/**
	Encryption type of content stream URL provided
 
	@see `FWURLEncryptionType`
 */
@property (readonly, nonatomic) FWURLEncryptionType encryptionType;


/**
	Unique account ID used in constructing CTS ad request

	Please consult CTS for the value to use.
 */
@property (strong, nonatomic, nonnull) NSString *accountId;


/**
	Account PID used in constructing CTS ad request. The default value for this property is "g". If required, please update with the value provided by FreeWheel solution engineer
 */
@property (strong, nonatomic, nonnull) NSString *accountPid;


/**
	Time stamp used for validation purposes. Optional.
 */
@property (strong, nonatomic, nullable) NSDate *date;

@end
