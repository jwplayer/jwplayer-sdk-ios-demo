//
//  JWPlaylistItem.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 12/8/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JWConfig;
@class JWSource;
@class JWAdBreak;
@class JWTrack;

NS_ASSUME_NONNULL_BEGIN
/*!
 An object providing info about playlist items.
 */
@interface JWPlaylistItem : NSObject

/* ========================================*/
/** @name Accessing Playlist Item Attributes */


/*!
 An array of JWSource objects representing multiple quality levels of a video.
 @see JWSource
 */
@property (nonatomic, nullable, retain) NSArray <JWSource *> *sources;

/*!
 Video URL to a single video file, to be played using JW Player.
 */
@property (nonatomic, nullable, copy) NSString *file;

/*!
 URL to a poster image. The image is displayed before and after playback, and in the listbar. For audio-only media, the poster image stays visible during playback.
 */
@property (nonatomic, nullable, copy) NSString *image;

/*!
 Title of the video.
 @discussion Shown in the listbar and in the play button container in the center of the screen before the video starts to play.
 */
@property (nonatomic, nullable, copy) NSString *title;

/*!
 A dictionary containing asset initialization options.
 */
@property (nonatomic, nullable) NSDictionary *assetOptions;

/*!
 An array of JWAdBreak objects that proivide info about ad breaks.
 @see JWAdBreak
 */
@property (nonatomic, nullable, retain) NSArray <JWAdBreak *> *adSchedule;

/*!
 An array of JWTrack objects providing captions for different languages.
 @see JWTrack
 */
@property (nonatomic, nullable, retain) NSArray <JWTrack *> *tracks;

/*!
 Short description of the item. It is displayed in the listbar.
 */
@property (nonatomic, nullable, copy) NSString *desc;

/*!
 The playlist item's Media ID.
 */
@property (nonatomic, nullable, copy) NSString *mediaId;

/*!
 URL to a feed that contains related items for a particular playlist item.
 */
@property (nonatomic, nullable, copy) NSString *recommendations;

/* ========================================*/
/** @name Creating Playlist Item Object */

/*!
 Inits a JWPlaylistItem object with provided JWConfig.
 @param config configuration object.
 */
+ (instancetype)playlistItemWithConfig:(JWConfig *)config;

@end
NS_ASSUME_NONNULL_END
