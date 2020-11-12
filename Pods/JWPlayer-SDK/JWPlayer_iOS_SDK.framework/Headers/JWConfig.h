//
//  JWConfigObject.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 8/25/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWAdConfig.h"
#import "JWPlaylistItem.h"
#import "JWCaptionStyling.h"
#import "JWRelatedConfig.h"
#import "JWSkinStyling.h"
#import "JWLogo.h"

/**
    Type of dimension manipulation of the video.
 */
typedef NS_ENUM(NSInteger, JWStretching) {
    /// Stretching out uniformly
    JWStretchingUniform = 0,
    /// Stretch out to fit the content dimenion exactly
    JWStretchingExactFit,
    /// Stretch to fill the the content area
    JWStretchingFill,
    /// Stretch is disabled
    JWStretchingNone
};

/**
    Type of preloading behavior for the video.
 */
typedef NS_ENUM(NSInteger, JWPreload) {
    /// Enable preloading
    JWPreloadAuto = 0,
    /// Disable preloading
    JWPreloadNone
};

@class JWAdConfig;

NS_ASSUME_NONNULL_BEGIN
/**
 Configuration object used to create JW Player instance.
 */
@interface JWConfig : NSObject

/* ========================================*/
/** @name Accessing Config Attributes
 */


/**
 Video URL to play using JW Player.
 */
@property (nonatomic, nullable, retain) NSString *file;

/**
 An array of JWSource objects representing multiple quality levels of a video.
 @see JWSource
 */
@property (nonatomic, nullable, retain) NSArray <JWSource *> *sources;

/**
 An array of JWPlaylistItem objects containing information about different video items to be reproduced in a sequence.
 @see JWPlaylistItem
 */
@property (nonatomic, nullable, retain) NSArray <JWPlaylistItem *> *playlist;

/**
 Item within a playlist to start playback.
 @discussion
 Within the playlist, the first index is 0. If the playlistIndex value is negative, the index starts counting from the end of the playlist.
 @warning
 A negative value cannot exceed the absolute number of playlist items. For example, in a playlist of 5 items, "playlistIndex": -5 is the lowest acceptable negative number.
 */
@property (nonatomic, assign) NSInteger playlistIndex;

/**
 Title (or name) of the video
 @note Shown in the play button container in the center of the screen, before the video starts to play, 
 in addition to the device lock screen and in the multimedia controls in the multitasking UI. 
 It will also be used in other relevant setups, such as when connecting to an Apple TV via AirPlay, or to an iPod accessory.
 @note If nil, the app name will be set as the title by default.
 @warning Trying to set the title directly via MPNowPlayingInfoCenter[MPMediaItemPropertyTitle] 
 can lead to unpredictable behavior.
 */
@property (nonatomic, nullable, retain) NSString *title;

/**
 The URL of the thumbnail image.
 */
@property (nonatomic, nullable, retain) NSString *image;

/**
 A description of your video or audio item.
 */
@property (nonatomic, nullable, retain, readwrite) NSString *desc;

/**
 Unique identifier of this item. Used by advertising, analytics and discovery services
 */
@property (nonatomic, nullable, retain) NSString *mediaId;

/**
 An array of JWTrack objects providing captions for different languages or thumbnails images.
 @see JWTrack
 */
@property (nonatomic, nullable, retain) NSArray <JWTrack *> *tracks;

/**
 A dictionary containing asset initialization options.
 */
@property (nonatomic, nullable) NSDictionary *assetOptions;

/**
 The image you wish to display if the user gets disconnected from the internet. If this is nil, your thumbnail image will be displayed.
 */
@property (nonatomic, nullable, retain) UIImage *offlinePoster;

/**
 The message you wish to display if the user gets disconnected from the internet. If this is nil, "Internet Lost" will be displayed.
 */
@property (nonatomic, nullable, retain) NSString *offlineMessage;

/**
 Player view size.
 */
@property (nonatomic) CGSize size;

/**
 Configures when the Next Up card displays during playback. Defaults to -10.
 @note A positive value is an offset from the start of the video. A negative number is an offset from the end of the video
 */
@property (nonatomic) NSInteger nextupOffset;

/**
 Configures when the Next Up card displays during playback, based on the percentage of the duration.
 @note A positive value is a percentage offset from the start of the video. A negative number is a percentage offset from the end of the video
 @note i.e. setting the value to 50 will result in the Next Up card showing when half of the video is played. Setting the value to -25 will result in the Next Up card showing when playback reaches 75% of the video duration.
 @note takes precedence over nextupOffset if both properties are set.
 */
@property (nonatomic) NSInteger nextupOffsetPercentage;

/**
 Set to false to disable the “Next Up” tooltip. Defaults to true.
 */
@property (nonatomic) BOOL nextUpDisplay;

/**
 Array of metadata that can be passed externally to supplement the encoded metadata of the underlying media asset.
 @discussion Applies to all playlist items that do not specify their own externalMetadata.
 @note Capped at 5 metadata instances; the instances in excess will be excluded.
 @see JWExternalMetadata
*/
@property (nonatomic, nullable, copy) NSArray <JWExternalMetadata *> *externalMetadata;

/**
 adConfig object providing info about ad handling.
 @see JWAdConfig
 */
@property (nonatomic, nullable, retain) JWAdConfig *advertising;

/**
 Config object containing related settings.
 @see JWRelatedConfig
 */
@property (nonatomic, nullable) JWRelatedConfig *related;

/**
 A boolean value that determines whether player controls are shown.
 */
@property (nonatomic) BOOL controls;

/**
 A boolean value that determines whether video should repeat after it's done playing.
 */
@property (nonatomic) BOOL repeat;

/**
 Configures if the title of a media file should be displayed. Defaults to YES.
 */
@property (nonatomic) BOOL displayTitle;

/**
 Configures if the description title of a media file should be displayed. Defaults to YES.
 */
@property (nonatomic) BOOL displayDescription;

/**
 A boolean value that determines whether video should start automatically after loading.
 */
@property (nonatomic) BOOL autostart;

/**
 Tells the player if content should be loaded prior to playback. Defaults to JWPreloadAuto.
 @note JWPreloadAuto — Loads the manifest before playback is requested. Default value.
 @note JWPreloadNone — Player will explicitly not preload content. (Recommended if you are concerned about excess content usage.)
 */
@property (nonatomic) JWPreload preload;

/**
 Enables the display of a settings menu to adjust the playback speed. Defaults to NO.
 @note When set to YES, the pre-defined options available in the menu are 0.5x, 1x, 1.25x, 1.5x, and 2x. 
 @note Use the playbackRates array to customize the menu options.
 */
@property (nonatomic) BOOL playbackRateControls;

/**
 Custom playback rate options to display in the settings menu.
 @note Only accepts value in the 0.0 to 4.0 range.
 */
@property (nonatomic, nullable, retain) NSArray <NSNumber *> *playbackRates;

/**
 Provides an option to stretch the video.
 @note JWStretchingUniform (default) - Will fit JW Player dimensions while maintaining original aspect ratio (Black bars)
 @note JWStretchingExactFit - Will fit JW Player dimensions without maintaining aspect ratio
 @note JWStretchingFill - Will stretch and zoom video to fill dimensions, while maintaining aspect ratio
 @note JWStretchingNone - Displays the actual size of the video file. (Black borders)
 */
@property (nonatomic) JWStretching stretching;

/**
 Sets the maximum bitrate that can be reached during automatic quality switching.
 @note If network bandwidth usage cannot be reduced to meet the bitRateUpperBound, it will be lowered as much as possible while continuing playback.
 @note Useful in limiting bandwith consumption for viewers.
 */
@property (nonatomic) CGFloat bitRateUpperBound;

/**
 The customization options for the player's skin.
 */
@property (nonatomic, nullable, retain) JWSkinStyling *skin;

/**
 The configuration options for a clickable watermark that is overlayed on the video.
 */
@property (nonatomic, nullable, retain) JWLogo *logo;

/**
 Configuration object used to customize the captions.
 */
@property (nonatomic, nullable, retain) JWCaptionStyling *captions;

/**
 Prevents the JW Player SDK from overriding application level audio settings. Defaults to true.
 @note setting to false will break AirPlay and background playback.
*/
@property (nonatomic) BOOL audioSwitchingEnabled;

/* ========================================*/
/** @name Creating Config Object
 */

/**
 Inits a JWConfig object with provided video url.
 @param contentUrl URL of the video content.
 */
+ (instancetype)configWithContentURL:(NSString *)contentUrl;

/* ========================================*/
/** @name Initializing Config Object
 */

/**
 Factory method that creates a JWConfig object with url of video content.
 @param contentUrl URL of the video content.
 */
- (instancetype)initWithContentUrl:(NSString *)contentUrl;

@end
NS_ASSUME_NONNULL_END
