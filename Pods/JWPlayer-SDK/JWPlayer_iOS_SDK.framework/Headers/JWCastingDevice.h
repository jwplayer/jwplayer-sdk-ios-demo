//
//  JWCastingDevice.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 12/3/15.
//  Copyright © 2015 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
    Type of casting service
 */
typedef NS_ENUM(NSInteger, JWCastingService) {
    /// Google Chromecast 
    JWCastingServiceGoogleChromeCast = 1
};

/**
 A class that encapsulates a casting device and holds its identifiers and attributes.
 */
@interface JWCastingDevice : NSObject

/**
 The casting service supported the device. i.e. a chromeCast device returns googleChromeCast as its casting service.
 */
@property (nonatomic, readonly) JWCastingService castingService;

/**
 The casting device's friendly name; i.e. "Dining Room".
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 A unique identifier for the casting device.
 */
@property (nonatomic, copy, readonly) NSString *identifier;

- (instancetype)init NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
