//
//  JWSkinStyling.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/26/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWControlbarStyling.h"
#import "JWTimesliderStyling.h"
#import "JWMenusStyling.h"
#import "JWTooltipsStyling.h"

@interface JWSkinStyling : NSObject


/*!
 If using an external CSS file to style your player, this must be specified here.
 */
@property (nonatomic, retain) NSString *url;

/*!
 The name of your custom skin to use for styling the player.
 If you are specifying a URL, you must set the name property to match the class name in your CSS file.
 */
@property (nonatomic, retain) NSString *name;

/*!
 The customization options for the control bar.
 */
@property (nonatomic, retain) JWControlbarStyling *controlbar;

/*!
 The customization options for the time slider.
 */
@property (nonatomic, retain) JWTimesliderStyling *timeslider;

/*!
 The customization options for the menus.
 */
@property (nonatomic, retain) JWMenusStyling *menus;

/*!
 The customization options for the tooltips.
 */
@property (nonatomic, retain) JWTooltipsStyling *tooltips;

/*!
 General Customization options.
 The following customization options apply to all UI elements except the timeslider's rail option. Customization set to specific UI elements will take precedence over the general customization.
 */

/*!
 Customizes the active color for all UI elements.
 */
@property (nonatomic, retain) UIColor *active;

/*!
 Customizes the inactive color for all UI elements.
 */
@property (nonatomic, retain) UIColor *inactive;

/*!
 Customizes the background color for all applicable UI elements.
 */
@property (nonatomic, retain) UIColor *background;

@end
