//
//  FWConsentConfiguration.h
//  AdManager
//
//  Created by Floam, Scott on 4/11/19.
//  Copyright © 2019 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FWGDPRConsentConfiguration.h"

/**
 A class used for configuring the ad request with user consent information.
 
 See also `-[FWRequestConfiguration setConsentConfiguration:]`.
 */
@interface FWConsentConfiguration : NSObject

/**
 GDPR consent configuration information.
 
 See also `FWGDPRConsentConfiguration`.
 */
@property (nullable, nonatomic) FWGDPRConsentConfiguration *gdprConsentConfiguration;

@end
