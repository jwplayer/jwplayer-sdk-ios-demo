//
//  FWSiteSectionConfiguration.h
//  AdManager
//
//  Created by Ravi Vooda on 6/8/17.
//  Copyright © 2017 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FWConstants.h"

/**
	A class used for configuring the ad request with site section information.
 
	See also `-[FWRequestConfiguration setSiteSectionConfiguration:]`
 */
@interface FWSiteSectionConfiguration : NSObject

/**
	ID of the site section
 */
@property (nonnull, nonatomic, copy, readonly) NSString *siteSectionId;

/**
	Site section ID to fall back to. When ad server fails to find the site section specified by siteSectionId, this ID will be used (0 by default)
 */
@property (nullable, nonatomic, copy) NSString *fallbackId;

/**
	Random number generated everytime a user visits the current site section
 */
@property (nonatomic) NSUInteger pageViewRandom;

/**
	ID of the network the site section belongs to (0 by default)
 */
@property (nonatomic) NSUInteger siteNetworkId;

/**
	Initialize the site section configuration
 
	@param siteSectionId	ID of the site section
	@param idType			Type of the site section id (see `FWIdType`)
 */
- (nonnull instancetype)initWithSiteSectionId:(nonnull NSString *)siteSectionId idType:(FWIdType)idType;

/**
	Set the site section ID
 
	@param siteSectionId	ID of the site section
	@param idType			Type of the site section id (see `FWIdType`)
 */
- (void)setSiteSectionId:(nonnull NSString *)siteSectionId idType:(FWIdType)idType;

@end
