//
//  FWVisitorConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 6/6/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
	A class used for configuring the ad request with visitor information.

	See also `-[FWRequestConfiguration setVisitorConfiguration:]`
 */
@interface FWVisitorConfiguration : NSObject

/**
	Custom ID of the visitor
 */
@property (copy, nonatomic, nullable) NSString *customId;

/**
	IP address of the visitor in IPv4 format
 */
@property (copy, nonatomic, nullable) NSString *ipV4Address;

/**
	Bandwidth of the visitor in Kbps (Kilo bits per second)
 */
@property (nonatomic) unsigned long bandwidth;

/**
	Source of bandwidth provider
 */
@property (copy, nonatomic, nullable) NSString *bandwidthSource;


/**
	Adds a given key-value pair for appending headers in the Ad Request.
	Deletes matching key-value pair, if exists, when called with null value.

	@param field Header name. Overrides previous value for field
	@param value The value for field.
 */
- (void)setValue:(nullable NSString *)value forHTTPHeaderField:(nonnull NSString *)field;

/**
	Copy of HTTP headers hash map of the visitor
 */
- (nonnull NSDictionary *)httpHeaders;

@end
