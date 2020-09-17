//
//  FWGDPRConsentConfiguration.h
//  AdManager
//
//  Created by Floam, Scott on 4/11/19.
//  Copyright © 2019 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FWConstants.h"

/**
 A class used for configuring FWConsentConfiguration with user GDPR consent information.
 
 See also `FWConsentConfiguration`.
 */
@interface FWGDPRConsentConfiguration : NSObject <NSCopying>

/**
 FWConsentApplicable ENUM used to identify if GDPR consent applies to the user. Valid values are FWConsentIsApplicable or FWConsentNotApplicable.
 */
@property (nonatomic, readonly) FWConsentApplicable fwGDPR;

/**
 String used to identify what information and which vendors were granted consent by the user.
 */
@property (nullable, nonatomic, copy, readonly) NSString* fwGDPRConsent;

/**
 A constructor used for manually instantiating GDPR consent information provided by the user.
  
 @param ConsentApplicable FWConsentApplicable ENUM used to identify if GDPR consent applies to the user. Valid values are FWConsentIsApplicable or FWConsentNotApplicable.
 @param GDPRConsentString NSString to identify what information and which vendors the user consented to.
 
 See also `FWConstants`.
 */
- (nullable instancetype)initWithConsentApplicable:(FWConsentApplicable)consentApplicable GDPRConsentString:(nullable NSString *)GDPRConsentString;

@end
