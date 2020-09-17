//
//  FWSlotConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 6/12/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FWConstants.h"

/**
	Abstract class for slot configuration. Please use `FWTemporalSlotConfiguration` or `FWNonTemporalSlotConfiguration` instead
 */
@interface FWSlotConfiguration : NSObject

/**
	Custom identifier for the slot
 */
@property (copy, nonatomic, nonnull) NSString *customId;

/**
	Type of the slot (See `FWSlotType`)
 */
@property (nonatomic, readonly) FWSlotType slotType;

/**
	Ad unit of the ads allowed to be delivered into this slot
 */
@property (copy, nonatomic, nonnull) NSString *adUnit;

/**
	Slot profile used for ad selection. Slot profile, if set, will override player profile during ad selection.
 
	Please consult your FreeWheel solution engineer for the value to be used.
 */
@property (copy, nonatomic, nullable) NSString *slotProfile;

/**
	Primary content types allowed for ads delivered into the slot.
 
	Multiple content types are separated using "," as delimiter.
 */
@property (copy, nonatomic, nonnull) NSString *acceptPrimaryContentTypes;

/**
	Content types allowed for ads delivered into the slot
 
	Multiple content types are separated using "," as delimeter.
 */
@property (copy, nonatomic, nonnull) NSString *acceptContentTypes;

@end
