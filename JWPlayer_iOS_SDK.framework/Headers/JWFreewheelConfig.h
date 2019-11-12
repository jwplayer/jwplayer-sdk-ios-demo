//
//  JWFreewheelConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Anton Holub on 4/14/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
    Configuration settings for freewheel ads.
 */
@interface JWFreewheelConfig : NSObject

@property (nonatomic, nullable, copy) NSString *serverId;
@property (nonatomic, nullable, copy) NSString *profileId;
@property (nonatomic, nullable, copy) NSString *sectionId;
@property (nonatomic, nullable, copy) NSString *mediaId;
@property (nonatomic) NSUInteger networkId;
@property (nonatomic) CGFloat duration;
@property (nonatomic, nullable) NSDictionary *custom;

@end
NS_ASSUME_NONNULL_END
