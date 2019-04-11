//
//  JWEvent.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 5/14/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

typedef NS_ENUM(NSInteger, JWPlayerState) {
    JWPlayerStatePlaying = 0,
    JWPlayerStatePaused,
    JWPlayerStateBuffering,
    JWPlayerStateIdle,
    JWPlayerStateComplete,
    JWPlayerStateError
};

@class JWTrack, JWSource, JWPlaylistItem, JWPlayerError, JWAdCompanion;

@interface JWEvent : NSObject

@end


@protocol JWFirstFrameEvent <NSObject>

/*!
 The amount of time (In milliseconds) it takes for the player to transition from a play attempt to a firstFrame event.
 */
@property (nonatomic) NSUInteger loadTime;

@end


@protocol JWStateChangeEvent <NSObject>

/*!
 The old state of the player.
 */
@property (nonatomic) JWPlayerState oldState;

@end


@protocol JWBufferEvent <JWStateChangeEvent>

/*!
 The new state of the player.
 */
@property (nonatomic) JWPlayerState newState;

/*!
 The reason why a buffer event occurred.
 */
@property (nonatomic) NSString *reason;

@end


@protocol JWReadyEvent <NSObject>

/*!
 The amount of time (in milliseconds) for the player to go from setup to ready.
 */
@property (nonatomic) NSUInteger setupTime;

@end


@protocol JWTimeEvent <NSObject>

/*!
 Playback position in seconds.
 */
@property (nonatomic) CGFloat position;

/*!
 Duration of the current playlist item in seconds.
 */
@property (nonatomic) CGFloat duration;

@end


@protocol JWBufferChangeEvent <JWTimeEvent>

/*!
 Percentage between 0 and 100 of the current media that is buffered.
 */
@property (nonatomic) CGFloat bufferPercent;

@end


@protocol JWSeekEvent <NSObject>

/*!
 The user requested position to seek to (in seconds). Note the actual position the player will eventually seek to may differ.
 */
@property (nonatomic) CGFloat offset;

/*!
 The position of the player before the player seeks (in seconds).
 */
@property (nonatomic) CGFloat position;

@end


@protocol JWMetaEvent <NSObject>

/*!
 Object containing the new metadata. This can be metadata hidden in the media (ID3, XMP, keyframes) or metadata broadcasted by the playback provider (bandwidth, quality switches).
 */
@property (nonatomic) NSDictionary *metadata;

@end

@protocol JWTrackChangedEvent <NSObject>

/*!
 Index of the new active track. In the case of captions, currentTrack of 0 means captions are turned off.
 */
@property (nonatomic) NSUInteger currentTrack;

@end


@protocol JWCaptionsListEvent <NSObject>

/*!
 The full array of caption tracks.
 */
@property (nonatomic) NSArray <JWTrack *> *tracks;

@end

@protocol JWLevelsEvent <NSObject>

/*!
 The full array of quality levels in the case of onLevels; The full array with audio tracks in the case of onAudioTracks.
 */
@property (nonatomic) NSArray *levels;

@end


@protocol JWLevelsChangedEvent <NSObject>

/*!
 Index of the new quality level in the player's qualityLevels array.
 */
@property (nonatomic) NSUInteger currentQuality;

@end


@protocol JWPlaylistEvent <NSObject>

/*!
 The new playlist, an array of playlist items.
 */
@property (nonatomic) NSArray <JWPlaylistItem *> *playlist;

@end


@protocol JWPlaylistItemEvent <NSObject>

/*!
 The current playlist item.
 */
@property (nonatomic) JWPlaylistItem *item;

/*!
 Zero-based index into the playlist array (e.g. 0 is the first item).
 */
@property (nonatomic) NSUInteger index;

@end


@protocol JWFullscreenEvent <NSObject>

/*!
 Whether or not video is in fullscreen mode.
 */
@property (nonatomic) BOOL fullscreen;

@end


@protocol JWResizeEvent <NSObject>

/*!
 The new dimensions of the player.
 */
@property (nonatomic) CGSize size;

@end


@protocol JWControlsEvent <NSObject>

/*!
 New state of the controls.
 */
@property (nonatomic) BOOL controls;

@end

@protocol JWPlaybackRateEvent <NSObject>

/*!
 New playback rate of the video.
 */
@property (nonatomic) CGFloat playbackRate;

@end

@protocol JWErrorEvent <NSObject>
/*!
 Object containing the error message under property localizedDescription.
 For onAdError, The following error messages are possible:
 -invalid ad tag (e.g. invalid XML, broken VAST)
 -ad tag empty (e.g. no ad available after chasing the wrappers)
 -no compatible creatives (e.g. only FLV video in HTML5)
 -error playing creative (e.g. a 404 on the MP4 video)
 -error loading ad tag (for all else)
 When applicable, the userInfo (NSDictionary) property of error will contain the ad tag that is currently playing (key: tag), and/or the vmap (key: vmap). If Google IMA is being used as the ad Client, the imaErrorType will be included (key: imaErrorType) and not the vmap.
 */
@property (nonatomic) JWPlayerError *error;

@end
