//
//  JWConfigObject.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 8/25/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JWAdConfig.h"
#import "JWFreewheelConfig.h"
#import "JWAdBreak.h"
#import "JWTrack.h"
#import "JWSource.h"
#import "JWPlaylistItem.h"
#import "JWCaptionStyling.h"
#import "JWRelatedConfig.h"
#import "JWSkinStyling.h"
#import "JWLogo.h"

typedef enum {
    JWStretchingUniform = 0,
    JWStretchingExactFit,
    JWStretchingFill,
    JWStretchingNone
}JWStretching;

typedef enum {
    JWPreloadAuto = 0,
    JWPreloadNone
}JWPreload;

@class JWAdConfig;

/*!
 Configuration object used to create JW Player instance.
 */
@interface JWConfig : NSObject

/* ========================================*/
/** @name Accessing Config Attributes */


/*!
 Video URL to play using JW Player.
 */
@property (nonatomic, retain) NSString *file;

/*!
 An array of JWSource objects representing multiple quality levels of a video.
 @see JWSource
 */
@property (nonatomic, retain) NSArray <JWSource *> *sources;

/*!
 An array of JWPlaylistItem objects containing information about different video items to be reproduced in a sequence.
 @see JWPlaylistItem
 */
@property (nonatomic, retain) NSArray <JWPlaylistItem *> *playlist;

/*!
 Title of the video
 @discussion Shown in the play button container in the center of the screen, before the video starts to play.
 */
@property (nonatomic, retain) NSString *title;

/*!
 The URL of the thumbnail image.
 */
@property (nonatomic, retain) NSString *image;

/*!
 A description of your video or audio item.
 */
@property (nonatomic, retain, readwrite) NSString *desc;

/*!
 Unique identifier of this item. Used by advertising, analytics and discovery services
 */
@property (nonatomic, retain) NSString *mediaId;

/*!
 An array of JWTrack objects providing captions for different languages.
 @see JWTrack
 */
@property (nonatomic, retain) NSArray <JWTrack *> *tracks;

/*!
 A dictionary containing asset initialization options.
 */
@property (nonatomic) NSDictionary *assetOptions;

/*!
 The image you wish to display if the user gets disconnected from the internet. If this is nil, your thumbnail image will be displayed.
 */
@property (nonatomic, retain) UIImage *offlinePoster;

/*!
 The message you wish to display if the user gets disconnected from the internet. If this is nil, "Internet Lost" will be displayed.
 */
@property (nonatomic, retain) NSString *offlineMessage;

/*!
 Player view size.
 */
@property (nonatomic) CGSize size;

/*!
 Configures when the Next Up card displays during playback. Defaults to -10.
 @discussion A positive value is an offset from the start of the video. A negative number is an offset from the end of the video
 */
@property (nonatomic) NSInteger nextupOffset;

/*!
 adConfig object providing info about ad handling.
 @see JWAdConfig
 */
@property (nonatomic, retain) JWAdConfig *advertising;

/*!
 Config object containing related settings.
 @see JWRelatedConfig
 */
@property (nonatomic) JWRelatedConfig *related;

/*!
 A boolean value that determines whether player controls are shown.
 */
@property (nonatomic) BOOL controls;

/*!
 A boolean value that determines whether video should repeat after it's done playing.
 */
@property (nonatomic) BOOL repeat;

/*!
 Configures if the title of a media file should be displayed. Defaults to YES.
 */
@property (nonatomic) BOOL displayTitle;

/*!
 Configures if the description title of a media file should be displayed. Defaults to YES.
 */
@property (nonatomic) BOOL displayDescription;

/*!
 A boolean value that determines whether video should start automatically after loading.
 */
@property (nonatomic) BOOL autostart;

/*!
 Tells the player if content should be loaded prior to playback. Defaults to JWPreloadAuto.
 @discussion JWPreloadAuto — Loads the manifest before playback is requested. Default value.
 @discussion JWPreloadNone — Player will explicitly not preload content. (Recommended if you are concerned about excess content usage.)
 */
@property (nonatomic) JWPreload preload;

/*!
 Enables the display of a settings menu to adjust the playback speed. Defaults to NO.
 @discussion When set to YES, the pre-defined options available in the menu are 0.5x, 1x, 1.25x, 1.5x, and 2x. 
 @discussion Use the playbackRates array to customize the menu options.
 */
@property (nonatomic) BOOL playbackRateControls;

/*!
 Custom playback rate options to display in the settings menu.
 @discussion Only accepts value in the 0.0 to 4.0 range.
 */
@property (nonatomic, retain) NSArray <NSNumber *> *playbackRates;

/*!
 Provides an option to stretch the video.
 @discussion JWStretchingUniform (default) - Will fit JW Player dimensions while maintaining original aspect ratio (Black bars)
 @discussion JWStretchingExactFit - Will fit JW Player dimensions without maintaining aspect ratio
 @discussion JWStretchingFill - Will stretch and zoom video to fill dimensions, while maintaining aspect ratio
 @discussion JWStretchingNone - Displays the actual size of the video file. (Black borders)
 */
@property (nonatomic) JWStretching stretching;

/*!
 Sets the maximum bitrate that can be reached during automatic quality switching.
 @discussion If network bandwidth usage cannot be reduced to meet the bitRateUpperBound, it will be lowered as much as possible while continuing playback.
 @discussion Useful in limiting bandwith consumption for viewers.
 */
@property (nonatomic) CGFloat bitRateUpperBound;

/*!
 Set to false to disable the “Next Up” tooltip. Defaults to true.
 */
@property (nonatomic) BOOL nextUpDisplay;

/*!
 The customization options for the player's skin.
 */
@property (nonatomic, retain) JWSkinStyling *skin;

/*!
 The configuration options for a clickable watermark that is overlayed on the video.
 */
@property (nonatomic, retain) JWLogo *logo;

/*!
 Configuration object used to customize the captions.
 */
@property (nonatomic, retain) JWCaptionStyling *captions;

/*!
 Prevents the JW Player SDK from overriding application level audio settings. Defaults to true.
 @discussion setting to false will break AirPlay and background playback.
*/
@property (nonatomic) BOOL audioSwitchingEnabled;

/* ========================================*/
/** @name Creating Config Object */

/*!
 Inits a JWConfig object with provided video url.
 @param contentUrl URL of the video content.
 */
+ (instancetype)configWithContentURL:(NSString *)contentUrl;

/* ========================================*/
/** @name Initializing Config Object */

/*!
 Factory method that creates a JWConfig object with url of video content.
 @param contentUrl URL of the video content.
 */
- (instancetype)initWithContentUrl:(NSString *)contentUrl;

@end
