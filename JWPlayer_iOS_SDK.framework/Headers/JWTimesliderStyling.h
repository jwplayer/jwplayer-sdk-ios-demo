//
//  JWTimesliderStyling.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/26/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface JWTimesliderStyling : NSObject

/*!
 The color of the bar in the time slider filled in from the beginning of the video through the current position. The buffer region of the control bar is 50% of the opacity of this color.
 The color of the volume slider is also controlled by this option.
 */
@property (nonatomic, retain) UIColor *progress;

/*!
 The color of the base of the timeslider, known as the rail.
 */
@property (nonatomic, retain) UIColor *rail;

@end
