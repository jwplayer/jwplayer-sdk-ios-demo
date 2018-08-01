//
//  JWMenusStyling.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/26/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface JWMenusStyling : NSObject

/*!
 The color of inactive, default text in menus and the Next Up overlay.
 */
@property (nonatomic, retain) UIColor *text;

/*!
 The color of hovered or selected text in menus. This option also controls the text color in the Discover overlay and the hover state text color in the Next Up overlay.
 */
@property (nonatomic, retain) UIColor *textActive;

/*!
 The background color of menus and the Next Up overlay.
 */
@property (nonatomic, retain) UIColor *background;

@end
