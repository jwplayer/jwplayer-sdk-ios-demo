//
//  JWControlbarStyling.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/26/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface JWControlbarStyling : NSObject

/*!
 The color of any plain text in the control bar, such as the time.
 */
@property (nonatomic, nullable, retain) UIColor *text;

/*!
 The default, inactive color of all icons in the control bar. This option also controls the color of the play, pause, and replay icons in the inactive and complete states.
 */
@property (nonatomic, nullable, retain) UIColor *icons;

/*!
 The color of tapped or selected icons in the control bar.
 */
@property (nonatomic, nullable, retain) UIColor *iconsActive;

/*!
 The background color of the control bar and the volume slider. The default background is transparent.
 */
@property (nonatomic, nullable, retain) UIColor *background;

@end
NS_ASSUME_NONNULL_END
