//
//  JWLogo.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 4/30/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, JWLogoPosition) {
    JWLogoPositionTopRight = 0,
    JWLogoPositionTopLeft,
    JWLogoPositionBottomRight,
    JWLogoPositionBottomLeft,
    JWLogoPositionControlbar
};

/*!
 Configures a clickable watermark that is overlayed on the video.
 */
@interface JWLogo : NSObject

/*!
 The file path of a JPG, PNG, SVG or GIF image to be used as watermark (e.g. /assets/logo.png). We recommend using 24 bit PNG images with transparency.
 @discussion Can be either an external URL or the resource path in the bundle.
 */
@property (nonatomic, retain) NSString *file;

/*!
 When this option is set to true, the logo will automatically show and hide along with the other player controls. Defaults to NO.
 */
@property (nonatomic) BOOL hide;

/*!
 The URL to visit when the watermark image is clicked. Clicking a logo will have no effect unless this is configured.
 */
@property (nonatomic, retain) NSString *link;

/*!
 The distance, in pixels, of the logo from the edges of the display. Defaults to 20;
 */
@property (nonatomic) NSUInteger margin;

/*!
 This sets the corner in which to display the watermark. JWControlbar adds the logo as the leftmost icon in the right grouping of buttons in the control bar.
 */
@property (nonatomic) JWLogoPosition position;

/*!
 Factory method that creates a logo with a local file by specifying the file name and its extension.
 @param name The name of the resource file.
 @param fileType The file's extension (i.e. png).
 */
+ (instancetype)logoNamed:(NSString *)name withExtension:(NSString *)fileType;

@end
