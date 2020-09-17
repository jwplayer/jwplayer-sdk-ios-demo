//
//  FWNonTemporalSlotConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 6/13/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import "FWSlotConfiguration.h"
#import "FWConstants.h"

/**
	A class used for configuring the ad request with non-temporal slot information.
 
	See also `-[FWRequestConfiguration addSlotConfiguration:]`
 */
@interface FWNonTemporalSlotConfiguration : FWSlotConfiguration

/**
	The width of the non-temporal slot
 */
@property (nonatomic) NSUInteger width;

/**
	The height of the non-temporal slot
 */
@property (nonatomic) NSUInteger height;

/**
	The configuration of the initial ad delivered into the slot (See `FWSlotInitialAdOption`)
 */
@property (nonatomic) FWSlotInitialAdOption initialAdOption;

/**
	An array of compatible dimensions for the non-temporal slot. Each of the dimension must be a NSDictionary object with key "width" and "height", the value of should be a positive integer. `nil` by default. Example:
 `@@[@@{@@"width": @@800, @@"height": @@600}, @@{@@"width": @@640, @@"height": @@480}]`
 */
@property (copy, nonatomic, nullable) NSArray *compatibleDimensions;

/**
	Whether companion ads are accepted by the slot
 */
@property (nonatomic) BOOL acceptsCompanion;

/**
	Initialize a non-temporal slot configuration.
 
	@param customId Custom ID of the slot. If slot with specified ID already exists, the function call will be ignored.
	@param adUnit Ad unit supported by the slot
	@param width Width of the slot
	@param height Height of the slot
 */
- (nonnull instancetype)initWithCustomId:(nonnull NSString *)customId adUnit:(nonnull NSString *)adUnit width:(NSUInteger)width height:(NSUInteger)height;

@end
