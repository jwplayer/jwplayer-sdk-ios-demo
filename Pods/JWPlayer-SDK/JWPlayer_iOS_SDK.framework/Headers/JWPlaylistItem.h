//
//  JWPlaylistItem.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 12/8/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JWSource.h"
#import "JWAdBreak.h"
#import "JWTrack.h"
#import "JWFreewheelConfig.h"
#import "JWGoogimaDaiConfig.h"
#import "JWExternalMetadata.h"

@class JWConfig;

NS_ASSUME_NONNULL_BEGIN
/**
 An object providing info about playlist items.
 */
@interface JWPlaylistItem : NSObject

/* ========================================*/
/** @name Accessing Playlist Item Attributes
 */


/**
 An array of JWSource objects representing multiple quality levels of a video.
 @see JWSource
 */
@property (nonatomic, nullable, retain) NSArray <JWSource *> *sources;

/**
 Video URL to a single video file, to be played using JW Player.
 */
@property (nonatomic, nullable, copy) NSString *file;

/**
 URL to a poster image. The image is displayed before and after playback, and in the listbar. For audio-only media, the poster image stays visible during playback.
 */
@property (nonatomic, nullable, copy) NSString *image;

/**
 Title of the video.
 @note Shown in the listbar and in the play button container in the center of the screen before the video starts to play.
 */
@property (nonatomic, nullable, copy) NSString *title;

/**
 A dictionary containing asset initialization options.
 */
@property (nonatomic, nullable) NSDictionary *assetOptions;

/**
 An array of JWAdBreak objects that proivide info about ad breaks.
 @see JWAdBreak
 */
@property (nonatomic, nullable, retain) NSArray <JWAdBreak *> *adSchedule;

/**
 The JWGoogimaDaiConfig class stores the Google IMA DAI settings.
 */
@property (nonatomic, nullable) JWGoogimaDaiConfig *googimaDaiSettings;

/**
 The JWFreewheelConfig class stores the Freewheel SDK settings. The settings defined here will apply only to ads associated with this playlist item.
 @note When setting a Freewheel config, config.advertising.adClient should be set to JWAdClientFreewheel, where config is an instance of JWConfig.
 @note if nil, fallsback to config.advertising.freewheel.
 @note Properties that are nil will fallback to the equivalent in config.advertising.freewheel. You may therefore use config.advertising.freewheel to define common settings.
 */
@property (nonatomic, nullable) JWFreewheelConfig *freewheel;

/**
 An array of JWTrack objects providing captions for different languages or thumbnails images.
 @see JWTrack
 */
@property (nonatomic, nullable, retain) NSArray <JWTrack *> *tracks;

/**
 Short description of the item. It is displayed in the listbar.
 */
@property (nonatomic, nullable, copy) NSString *desc;

/**
 The playlist item's Media ID.
 */
@property (nonatomic, nullable, copy) NSString *mediaId;

/**
 URL to a feed that contains related items for a particular playlist item.
 */
@property (nonatomic, nullable, copy) NSString *recommendations;

/**
 Number of seconds from the start of a media asset when playback should begin.
 */
@property (nonatomic, assign) CGFloat startTime;

/**
 Array of metadata that can be passed externally to supplement the encoded metadata of the underlying media asset.
 @discussion Supersedes the externalMetada specified in the JWConfig, for this playlist item.
 @note Capped at 5 metadata instances; the instances in excess will be excluded.
 @see JWExternalMetadata
 */
@property (nonatomic, nullable, copy) NSArray <JWExternalMetadata *> *externalMetadata;

/* ========================================*/
/** @name Creating Playlist Item Object
 */

/**
 Inits a JWPlaylistItem object with provided JWConfig.
 @param config configuration object.
 */
+ (instancetype)playlistItemWithConfig:(JWConfig *)config;

@end
NS_ASSUME_NONNULL_END
