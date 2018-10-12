//
//  JWPlayerDelegate.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 5/1/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWPlaylistItem.h"
#import "JWAdEvent.h"
#import "JWRelatedEvent.h"

@protocol JWFirstFrameEvent, JWReadyEvent;
/*!
 @protocol JWPlayerDelegate
 @discussion The JWPlayerDelegate protocol defines methods that a delegate of a JWPlayerController object can optionally implement to intervene when player callbacks are captured.
 */
@protocol JWPlayerDelegate <NSObject>

@optional

/*!
 onAll(callback)
 @discussion This singular API call can be used to gather all information from the player's API. Note: This will output a large amount of information and may degrade performance if it is used for an extended period of time.
 */
- (void)onAll;

/* ========================================*/
/** @name Playback */

/*!
 onPlayAttempt(callback)
 @discussion Useful for QOE tracking - Triggered the instant a user attempts to play a file. This event fires before both the onPlay and onBeforePlay events.
 */
- (void)onPlayAttempt;

/*!
 onBeforePlay(callback)
 @discussion Fired just before the player begins playing. Unlike the onPlay event, the player will not have begun playing or buffering when triggered, which makes this the right moment to insert preroll ads using playAd().
 */
- (void)onBeforePlay;

/*!
 onFirstFrame(callback)
 @discussion Useful for QOE tracking - Triggered by a video's first frame event (Or the instant an audio file begins playback). This event pinpoints when content playback begins.
 */
- (void)onFirstFrame:(JWEvent<JWFirstFrameEvent> *)event;

/*!
 onPlay(callback)
 @discussion Fired when the player enters the 'playing' state.
 */
- (void)onPlay:(JWEvent<JWStateChangeEvent> *)event;

/*!
 onPause(callback)
 @discussion Fired when the player enters the 'paused' state.
 */
- (void)onPause:(JWEvent<JWStateChangeEvent> *)event;

/*!
 onIdle(callback)
 @discussion Fired when the player enters the 'idle' state.
 */
- (void)onIdle:(JWEvent<JWStateChangeEvent> *)event;

/*!
 onReady(callback)
 @discussion Fired when the player has initialized in either Flash or HTML5 and is ready for playback.
 */
- (void)onReady:(JWEvent<JWReadyEvent> *)event;

/*!
 onBeforeComplete(callback)
 @discussion Fired just before the player completes playing. Unlike the onComplete event, the player will not have moved on to either showing the replay screen or advancing to the next playlistItem, which makes this the right moment to insert post-roll ads using playAd().
 */
- (void)onBeforeComplete;

/*!
 onComplete(callback)
 @discussion Fired when an item completes playback.
 */
- (void)onComplete;

/* ========================================*/
/** @name Buffer */

/*!
 onBuffer(callback)
 @discussion Fired when the player enters the 'buffering' state.
 */
- (void)onBuffer:(JWEvent<JWBufferEvent> *)event;

/*!
 onBuffer(callback)
 @discussion Fired when the currently playing item loads additional data into its buffer.
 */
- (void)onBufferChange:(JWEvent<JWBufferChangeEvent> *)event;

/* ========================================*/
/** @name Playback Position */

/*!
 onTime(callback)
 @discussion While the player is playing, this event is fired as the playback position gets updated. This may occur as frequently as 10 times per second.
 */
- (void)onTime:(JWEvent<JWTimeEvent> *)event;

/*!
 onSeek(callback)
 @discussion Fired after a seek has been requested either by scrubbing the controlbar or through the API.
 */
- (void)onSeek:(JWEvent<JWSeekEvent> *)event;

/*!
 onSeeked(callback)
 @discussion Triggered when content playback resumes after seeking. As opposed to onSeek, this API listener will only trigger when playback actually continues.
 */
- (void)onSeeked;

/* ========================================*/
/** @name Metadata */

/*!
 onMeta(callback)
 @discussion Fired when new metadata has been broadcasted by the player.
 */
- (void)onMeta:(JWEvent<JWMetaEvent> *)event;

/* ========================================*/
/** @name Caption */

/*!
 onCaptionsList(callback)
 @discussion Fired when the list of available captions tracks is updated. Happens shortly after a playlist item starts playing.
 */
- (void)onCaptionsList:(JWEvent<JWCaptionsListEvent> *)event;

/*!
 onCaptionsChanged (callback)
 @discussion Fired when the active captions track is changed. Happens in response to e.g. a user clicking the controlbar CC menu or a script calling setCurrentCaptions.
 */
- (void)onCaptionsChanged:(JWEvent<JWTrackChangedEvent> *)event;

/* ========================================*/
/** @name Quality */

/*!
 onLevels(callback)
 @discussion Fired when the list of available quality levels is updated. Happens e.g. shortly after a playlist item starts playing.
 */
- (void)onLevels:(JWEvent<JWLevelsEvent> *)event;

/*!
 onLevelsChanged(callback)
 @discussion Fired when the active quality level is changed. Happens in response to e.g. a user clicking the controlbar quality menu or a script calling setCurrentLevel.
 */
- (void)onLevelsChanged:(JWEvent<JWLevelsChangedEvent> *)event;

/* ========================================*/
/** @name Audio Track */

/*!
 onAudioTracks (callback)
 @discussion Fired when the list of available audio tracks is updated. Happens e.g. shortly after a playlist item starts playing.
 */
- (void)onAudioTracks:(JWEvent<JWLevelsEvent> *)event;

/*!
 onAudioTrackChanged (callback)
 @discussion Fired when the active audio track is changed. Happens in repsponse to e.g. a user clicking the audio tracks menu or setting the currentAudioTrack JWPlayerController property.
 */
- (void)onAudioTrackChanged:(JWEvent<JWTrackChangedEvent> *)event;

/* ========================================*/
/** @name Playlist */

/*!
 onPlaylist(callback)
 @discussion Fired when a new playlist has been loaded into the player. Note this event is not fired as part of the initial playlist load (playlist is loaded when onReady is called).
 */
- (void)onPlaylist:(JWEvent<JWPlaylistEvent> *)event;

/*!
 onPlaylistItem(callback)
 @discussion Fired when the playlist index changes to a new playlist item. This event occurs before the player begins playing the new playlist item.
 */
- (void)onPlaylistItem:(JWEvent<JWPlaylistItemEvent> *)event;

/*!
 onPlaylistComplete(callback)
 @discussion Fired when the player is done playing all items in the playlist. However, if the repeat option is set true, this is never fired.
 */
- (void)onPlaylistComplete;

/* ========================================*/
/** @name Resize */

/*!
 onFullscreen
 @discussion Fired when the player toggles to/from fullscreen. Preceded by a onFullscreenRequested callback.
 */
- (void)onFullscreen:(JWEvent<JWFullscreenEvent> *)event;

/*!
 onFullscreenRequested
 @discussion Fired when a request to toggle fullscreen is received by the player. Precedes a onFullscreen callback when successful.
 */
- (void)onFullscreenRequested:(JWEvent<JWFullscreenEvent> *)event;

/*!
 onResize
 @discussion Fired when the player's size changes.
 */
- (void)onResize:(JWEvent<JWResizeEvent> *)event;

/* ========================================*/
/** @name Controls */

/*!
 onControls
 @discussion Fired when controls are enabled or disabled by setting the JWPlayerController controls property to a boolean.
 */
- (void)onControls:(JWEvent<JWControlsEvent> *)event;

/*!
 onDisplayClick(callback)
 @discussion Fired when a user clicks the video display. Especially useful for wiring your own controls when the built-in ones are disabled. Note the default click action (toggling play/pause) will still occur if controls are enabled.
 */
- (void)onDisplayClick;

/*!
 onControlBarVisible
 @discussion Fired when player control bar appears/disappears. Would not be called if controls set to false.
 @discussion Especially useful for synchronizing custom controls visibility with player control bar. 
 */
- (void)onControlBarVisible:(JWEvent<JWControlsEvent> *)event;

/*!
 onPlaybackRateChanged
 @discussion Fired when the playback rate changes.
 */
- (void)onPlaybackRateChanged:(JWEvent<JWPlaybackRateEvent> *)event;

/* ========================================*/
/** @name Advertising */

/*!
 onAdRequest(callback)
 @discussion VAST and IMA. Fired whenever an ad is requested by the player.
 */
- (void)onAdRequest:(JWAdEvent<JWAdRequestEvent> *)event;

/*!
 onAdSkipped(callback)
 @discussion VAST and IMA. Fired whenever an ad has been skipped.
 */
- (void)onAdSkipped:(JWAdEvent<JWAdDetailEvent> *)event;

/*!
 onAdComplete(callback)
 @discussion VAST and IMA. Fired whenever an ad has completed playback.
 */
- (void)onAdComplete:(JWAdEvent<JWAdDetailEvent> *)event;

/*!
 onAdClick(callback)
 @discussion VAST and IMA. Fired whenever a user clicks an ad to be redirected to its landing page.
 */
- (void)onAdClick:(JWAdEvent<JWAdDetailEvent> *)event;

/*!
 onAdCompanions(callback)
 @discussion VAST only. Fired whenever an ad contains companions.
 */
- (void)onAdCompanions:(JWAdEvent<JWAdCompanionsEvent> *)event;

/*!
 onAdSchedule(callback)
 @discussion VAST only. Fired whenever a VMAP tag is loaded.
 */
- (void)onAdSchedule:(JWAdEvent<JWAdScheduleEvent> *)event;

/*!
 onAdImpression(callback)
 @discussion VAST and IMA. Fired whenever an ad starts playing back. At this point, the VAST tag is loaded and the creative selected.
 */
- (void)onAdImpression:(JWAdEvent<JWAdImpressionEvent> *)event;

/*!
 onAdPlay(callback)
 @discussion VAST and IMA. Fired whenever an ad starts playing. Will fire after an ad is unpaused.
 */
- (void)onAdPlay:(JWAdEvent<JWAdStateChangeEvent> *)event;

/*!
 onAdPause(callback)
 @discussion VAST and IMA. Fired whenever an ad is paused.
 */
- (void)onAdPause:(JWAdEvent<JWAdStateChangeEvent> *)event;

/*!
 onAdTime(callback)
 @discussion VAST and IMA. Fired while ad playback is in progress.
 */
- (void)onAdTime:(JWAdEvent<JWAdTimeEvent> *)event;

/*!
 onAdError(callback)
 @discussion VAST and IMA. Fired whenever an error prevents the ad from playing.
 */
- (void)onAdError:(JWAdEvent<JWErrorEvent> *)event;

/*!
 onAdStarted(callback)
 @discussion VPAID-only. Will trigger when a VPAID ad creative signals to our player that it is starting. This differs from adImpression since the advertisement may not yet be visible.
 */
- (void)onAdStarted:(JWAdEvent<JWAdDetailEvent> *)event;

/*!
 onAdMeta(callback)
 @discussion Fired when new metadata has been broadcasted by the player during an Ad.
 */
- (void)onAdMeta:(JWAdEvent<JWMetaEvent> *)event;

/* ========================================*/
/** @name Related */

/*!
 onRelatedOpen(callback)
 @discussion Triggers when the related overlay is opened.
 */
- (void)onRelatedOpen:(JWRelatedEvent<JWRelatedOpenEvent> *)event;

/*!
 onRelatedClose(callback)
 @discussion Triggers when the related overlay is closed.
 */
- (void)onRelatedClose:(JWRelatedEvent<JWRelatedInteractionEvent> *)event;

/*!
 onRelatedPlay(callback)
 @discussion Triggers when a user selects an object in a related feed.
 */
- (void)onRelatedPlay:(JWRelatedEvent<JWRelatedPlayEvent> *)event;

/* ========================================*/
/** @name Error */

/*!
 onError(callback)
 @discussion Fired when a media error has occurred, causing the player to stop playback and go into 'idle' mode.
 @discussion See "Common error messages" on http://support.jwplayer.com/customer/portal/articles/1403682-troubleshooting-your-setup for a list of possible media errors.
*/
- (void)onError:(JWEvent<JWErrorEvent> *)event;

/*!
 onSetupError(callback)
 @discussion Fired when neither the Flash nor HTML5 player could be setup.
 */
- (void)onSetupError:(JWEvent<JWErrorEvent> *)event;

@end

