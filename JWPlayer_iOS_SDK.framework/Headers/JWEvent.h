//
//  JWEvent.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 5/14/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
    Type of player state.
 */
typedef NS_ENUM(NSInteger, JWPlayerState) {
    /// Player is currently playing
    JWPlayerStatePlaying = 0,
    /// Player is currently paused
    JWPlayerStatePaused,
    /// Player is currently buffering
    JWPlayerStateBuffering,
    /// Player is currently idle
    JWPlayerStateIdle,
    /// Player has completed playback of content
    JWPlayerStateComplete,
    /// Player has encountered an unrecoverable error
    JWPlayerStateError
};

@class JWTrack, JWSource, JWPlaylistItem, JWPlayerError, JWAdCompanion;

NS_ASSUME_NONNULL_BEGIN

/**
    JWEvent is the base class for all events emitted by the player.
 */
@interface JWEvent : NSObject

@end

/**
    JWFirstFrameEvent is emitted after the first frame of the video is displayed.
 */
@protocol JWFirstFrameEvent <NSObject>

/**
 The amount of time (In milliseconds) it takes for the player to transition from a play attempt to a firstFrame event.
 */
@property (nonatomic) NSUInteger loadTime;

@end

/**
    JWStateChangeEvent contains the state information before the state is changed. This is a base class for other events.
 */
@protocol JWStateChangeEvent <NSObject>

/**
 The old state of the player.
 */
@property (nonatomic) JWPlayerState oldState;

@end

/**
    JWBufferEvent is emitted when the video is buffering.
 */
@protocol JWBufferEvent <JWStateChangeEvent>

/**
 The new state of the player.
 */
@property (nonatomic) JWPlayerState newState;

/**
 The reason why a buffer event occurred.
 */
@property (nonatomic, copy) NSString *reason;

@end

/**
    JWReadyEvent is emitted when the player is ready to play.
 */
@protocol JWReadyEvent <NSObject>

/**
 The amount of time (in milliseconds) for the player to go from setup to ready.
 */
@property (nonatomic) NSUInteger setupTime;

@end

/**
    JWTimeEvent is emitted perdiodically when the video is playing.
 */
@protocol JWTimeEvent <NSObject>

/**
 Playback position in seconds.
 */
@property (nonatomic) CGFloat position;

/**
 Duration of the current playlist item in seconds.
 */
@property (nonatomic) CGFloat duration;

@end

/**
    JWBufferChangeEvent is emitted periodically with a buffer percentage update.
 */
@protocol JWBufferChangeEvent <JWTimeEvent>

/**
 Percentage between 0 and 100 of the current media that is buffered.
 */
@property (nonatomic) CGFloat bufferPercent;

@end

/**
    JWSeekEvent is emitted when a seek operation is requested.
 */
@protocol JWSeekEvent <NSObject>

/**
 The user requested position to seek to (in seconds). Note the actual position the player will eventually seek to may differ.
 */
@property (nonatomic) CGFloat offset;

/**
 The position of the player before the player seeks (in seconds).
 */
@property (nonatomic) CGFloat position;

@end

/**
    JWMetaEvent is emitted when metadata is retrieved from the current playlist item.
 */
@protocol JWMetaEvent <NSObject>

/**
 Object containing the new metadata. This can be metadata hidden in the media (DATERANGE, ID3, XMP, keyframes) or metadata broadcasted by the playback provider (bandwidth, quality switches).
 */
@property (nonatomic) NSDictionary *metadata;

@end

/**
    JWTrackChangeEvent is emitted when a new caption track is selected.
 */
@protocol JWTrackChangedEvent <NSObject>

/**
 Index of the new active track. In the case of captions, currentTrack of 0 means captions are turned off.
 */
@property (nonatomic) NSUInteger currentTrack;

@end

/**
    JWCaptionsListEvent is emitted when a list of captions tracks are retrieved.
 */
@protocol JWCaptionsListEvent <NSObject>

/**
 The full array of caption tracks.
 */
@property (nonatomic) NSArray <JWTrack *> *tracks;

@end

/**
 JWLevelsEvent is emitted when the qualify levels or audio tracks information are available.
 */
@protocol JWLevelsEvent <NSObject>

/**
 The full array of quality levels in the case of onLevels. The full array of audio tracks in the case of onAudioTracks.
 Returns nil in the case of an HLS stream.
 */
@property (nonatomic) NSArray *levels;

@end

/**
    JWLevelsChangedEvent is emitted when the quality level is changed.
 */
@protocol JWLevelsChangedEvent <NSObject>

/**
 Index of the new quality level in the player's qualityLevels array.
 */
@property (nonatomic) NSUInteger currentQuality;

@end

/**
    JWPlaylistEvent is emitted when a new playlist is loaded.
 */
@protocol JWPlaylistEvent <NSObject>

/**
 The new playlist, an array of playlist items.
 */
@property (nonatomic) NSArray <JWPlaylistItem *> *playlist;

@end

/**
    JWPlaylistItemEvent is emitted when a new playlist item is started.
 */
@protocol JWPlaylistItemEvent <NSObject>

/**
 The current playlist item.
 */
@property (nonatomic) JWPlaylistItem *item;

/**
 Zero-based index into the playlist array (e.g. 0 is the first item).
 */
@property (nonatomic) NSUInteger index;

@end

/**
    JWFullScreenEvent is emitted when a transition occurs to and fro fullscreen.
 */
@protocol JWFullscreenEvent <NSObject>

/**
 Whether or not video is in fullscreen mode.
 */
@property (nonatomic) BOOL fullscreen;

@end

/**
    JWRezieEvent is emitted when a resize of the player occurs.
 */
@protocol JWResizeEvent <NSObject>

/**
 The new dimensions of the player.
 */
@property (nonatomic) CGSize size;

@end

/**
    JWControlEvent is emitted when the player controls are enabled or disabled.
 */
@protocol JWControlsEvent <NSObject>

/**
 New state of the controls.
 */
@property (nonatomic) BOOL controls;

@end

/**
    JWPlaybackRateEvent is emitted when the playback rate of the player changes.
 */
@protocol JWPlaybackRateEvent <NSObject>

/**
 New playback rate of the video.
 */
@property (nonatomic) CGFloat playbackRate;

@end

/**
    JWErrorEvent is emitted when there is an unrecoverable error from the player.
 */
@protocol JWErrorEvent <NSObject>
/**
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
NS_ASSUME_NONNULL_END
