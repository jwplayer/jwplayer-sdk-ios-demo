//
//  FWVideoAssetConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 6/9/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FWConstants.h"

/**
	A class used for configuring the ad request with video asset information.
 
	See also `-[FWRequestConfiguration setVideoAssetConfiguration:]`
 */
@interface FWVideoAssetConfiguration : NSObject

/**
	ID of the video asset
 */
@property (nonnull, nonatomic, copy, readonly) NSString *videoAssetId;

/**
	Duration of the whole video asset in seconds
 */
@property (nonatomic, readonly) double duration;

/**
	The duration of the content segment that this ad request is sent for in seconds.
 	
 	Note that this should only be set when the request mode is FWRequestModeLive.
 */
@property (nonatomic) double requestDuration;

/**
	Type of the video asset's duration, see `FWVideoAssetDurationType`
 */
@property (nonatomic, readonly) FWVideoAssetDurationType durationType;

/**
	Whether the video starts playing automatically without user interaction. See `FWVideoAssetAutoPlayType`
 */
@property (nonatomic) FWVideoAssetAutoPlayType autoPlayType;

/**
	Random number generated every time a user watches the video asset
 */
@property (nonatomic) NSUInteger videoPlayerRandom;

/**
	Location(URI) of the video asset, nil by default
 */
@property (nullable, nonatomic, copy) NSString *videoLocation;

/**
	Video ID to fallback to. When ad server fails to find the video asset specified by videoAssetId, this ID will be used. nil by default
 */
@property (nullable, nonatomic, copy) NSString *fallbackId;

/**
	The current time position of the content asset in seconds.
	Note: If the stream is broken into multiple distinct files, this should be the time position within the asset as a whole.
 */
@property (nonatomic) double currentTimePosition;

/**
	ID of the network the video belongs to, 0 by default
 */
@property (nonatomic) NSUInteger networkId;

/**
	Initialize a video asset configuration for the ad request.
 
	@param videoAssetId	ID of the video asset
	@param idType		Type of the video asset id, see `FWIdType`
	@param duration		Duration of the video asset in seconds
	@param durationType	Type of the video asset's duration, see `FWVideoAssetDurationType`
	@param autoPlayType	Whether the video starts playing automatically without user interaction. See `FWVideoAssetAutoPlayType`
 */
- (nonnull instancetype)initWithVideoAssetId:(nonnull NSString *)videoAssetId idType:(FWIdType)idType duration:(double)duration durationType:(FWVideoAssetDurationType)durationType autoPlayType:(FWVideoAssetAutoPlayType)autoPlayType;

/**
	Set the ID of the video asset.
 
	@param videoAssetId	ID of the video asset
	@param idType		Type of the video asset id, see `FWIdType`
 */
- (void)setVideoAssetId:(nonnull NSString *)videoAssetId idType:(FWIdType)idType;

/**
	Set the duration of the video asset.
 
	@param duration		Duration of the video asset in seconds
	@param durationType	Type of the video asset's duration, see `FWVideoAssetDurationType`
 */
- (void)setVideoAssetDuration:(double)videoAssetDuration durationType:(FWVideoAssetDurationType)durationType;

@end
