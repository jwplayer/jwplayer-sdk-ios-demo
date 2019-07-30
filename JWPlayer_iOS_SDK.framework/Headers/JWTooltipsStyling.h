//
//  JWTooltipsStyling.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/26/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface JWTooltipsStyling : NSObject

/*!
 The text color of tooltips.
 */
@property (nonatomic, nullable, retain) UIColor *text;

/*!
 The background color of tooltips.
 */
@property (nonatomic, nullable, retain) UIColor *background;

@end
NS_ASSUME_NONNULL_END
