//
//  JWFreewheelConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Anton Holub on 4/14/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface JWFreewheelConfig : NSObject

@property (nonatomic) NSString *serverId;
@property (nonatomic) NSString *profileId;
@property (nonatomic) NSString *sectionId;
@property (nonatomic) NSString *mediaId;
@property (nonatomic) NSUInteger networkId;
@property (nonatomic) CGFloat duration;

@end
