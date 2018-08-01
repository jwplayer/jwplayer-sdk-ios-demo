//
//  JWAdCompanion.h
//  JWPlayer-iOS-SDK
//
//  Created by Rik Heijdens on 9/19/16.
//  Copyright © 2016 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

typedef enum {
    JWAdCompanionTypeStatic,
    JWAdCompanionTypeIFrame,
    JWAdCompanionTypeHtml
}JWAdCompanionType;

@interface JWAdCompanion : NSObject

/*!
 URL to link to when clicking the companion. Only available if the type is static.
 */
@property (nonatomic, readonly) NSString *clickUrl;

/*!
 The dimensions of the companion in pixels.
 */
@property (nonatomic, readonly) CGSize dimensions;

/*!
 The URL to the static/iframe resource, or the raw HTML content.
 */
@property (nonatomic, readonly) NSString *resource;

/*!
 The type of the creative: static, IFrame, or HTML.
 */
@property (nonatomic, readonly) JWAdCompanionType type;

/*!
An array of included creativeview event tracking pixels
 */
@property (nonatomic, readonly) NSArray <NSString *> *creativeView;

@end
