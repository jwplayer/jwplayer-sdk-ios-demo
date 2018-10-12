//
//  JWControlbarStyling.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/26/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface JWControlbarStyling : NSObject

/*!
 The color of any plain text in the control bar, such as the time.
 */
@property (nonatomic, retain) UIColor *text;

/*!
 The default, inactive color of all icons in the control bar. This option also controls the color of the play, pause, and replay icons in the inactive and complete states.
 */
@property (nonatomic, retain) UIColor *icons;

/*!
 The color of tapped or selected icons in the control bar.
 */
@property (nonatomic, retain) UIColor *iconsActive;

/*!
 The background color of the control bar and the volume slider. The default background is transparent.
 */
@property (nonatomic, retain) UIColor *background;

@end
