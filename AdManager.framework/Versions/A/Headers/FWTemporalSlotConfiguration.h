//
//  FWTemporalSlotConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 6/13/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import "FWSlotConfiguration.h"
#import "FWConstants.h"

/**
	A class used for configuring the ad request with temporal slot information.
 
	See also `-[FWRequestConfiguration addSlotConfiguration:]`
 */
@interface FWTemporalSlotConfiguration : FWSlotConfiguration

/**
	Time position of the slot with respect to content playback timeline
 */
@property (nonatomic) NSTimeInterval timePosition;

/**
	Cue Point Sequence indicates the sequence number of a midroll break
 */
@property (nonatomic) NSUInteger cuePointSequence;

/**
	Maximum duration allowed for the slot. 0 indicates no limit
 */
@property (nonatomic) NSTimeInterval maximumDuration;

/**
	Minumum duration allowed for the slot. 0 indicates no limit
 */
@property (nonatomic) NSTimeInterval minimumDuration;

/**
 	Signal ID, only applicable in Linear TV Streams, of the break
 */
@property (nullable, nonatomic) NSString *signalId;

/**
	Init `FWTemporalSlotConfiguration` object

	@param customId Custom identifier for the slot
	@param adUnit Ad unit supported by the slot
	@param timePosition Time position of the content where the slot will be inserted
 */
- (nonnull instancetype)initWithCustomId:(nonnull NSString *)customId adUnit:(nonnull NSString *)adUnit timePosition:(NSTimeInterval)timePosition;

@end
