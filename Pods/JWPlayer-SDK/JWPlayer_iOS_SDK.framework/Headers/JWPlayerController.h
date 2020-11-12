//
//  JWPlayerViewController.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 8/14/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JWConfig.h"
#import "JWPlayerDelegate.h"
#import "JWAVPlayerAnalyticsDelegate.h"
#import "JWCastController.h"
#import "JWDrmDataSource.h"
#import "JWExperimentalAPI.h"
#import "JWFriendlyAdObstructions.h"
#import "JWButton.h"
#import "JWPlaylistItemDelegate.h"

#define JWPlayerAllNotification @"JWPlayerAllNotification"
#define JWMetaDataAvailableNotification @"JWMetaDataAvailableNotification"
#define JWPlayerStateChangedNotification @"JWPlayerStateChangedNotification"
#define JWPlaybackPositionChangedNotification @"JWPlaybackPositionChangedNotification"
#define JWFullScreenStateChangedNotification @"JWFullScreenStateChangedNotification"
#define JWAdActivityNotification @"JWAdActivityNotification"
#define JWAdPlaybackProgressNotification @"JWAdPlaybackProgressNotification"
#define JWAdClickNotification @"JWAdClickNotification"
#define JWErrorNotification @"JWErrorNotification"
#define JWWarningNotification @"JWWarningNotification"
#define JWCaptionsNotification @"JWCaptionsNotification"
#define JWVideoQualityNotification @"JWVideoQualityNotification"
#define JWPlaylistNotification @"JWPlaylistNotification"
#define JWAudioTrackNotification @"JWAudioTrackNotification"
#define JWRelatedActivityNotification @"JWRelatedActivityNotification"

NS_ASSUME_NONNULL_BEGIN
/**
 A class that encapsulates JW Player and provides control over the playback as well as holds the state of the player and notifies about status updates.
 */
@interface JWPlayerController : NSObject

/* ========================================*/
/** @name Accessing Player Controller Attributes */

/**
 Player view.
 @note to be added to the application view hierarchy.
 */
@property (nonatomic, nullable, retain, readonly) UIView *view;

/**
The object that acts as the delegate of the JWPlayerController.
 @note The delegate must adopt the JWPlayerDelegate protocol. The delegate is not retained.
 @see JWPlayerDelegate
 */
@property (nonatomic, nullable, weak) id<JWPlayerDelegate> delegate;

/**
 The object that acts as the analyticsDelegate of the JWPlayerController. Data provided by this object can be used by 3rd-party analytics libraries.
 @note The analyticsDelegate must adopt the JWAVPlayerAnalyticsDelegate protocol. The analyticsDelegate is not retained.
 @see JWAVPlayerAnalyticsDelegate
 */
@property (nonatomic, nullable, weak) id<JWAVPlayerAnalyticsDelegate> analyticsDelegate;

/**
 The JWDrmDataSource is adopted by an object that mediates the application's data model and key server. The data source provides the JWPlayerController object with the data needed to reproduce encrypted content.
 @note The drmDataSource must adopt the JWDrmDataSource protocol. The drmDataSource is not retained.
 @see JWDrmDataSource
 */
@property (nonatomic, nullable, weak) id<JWDrmDataSource> drmDataSource;

/**
 The object that acts as a playlist item delegate to the JWPlayerController.
 The playlistItemDelegate will be notified when a playlist item is about to transition. At this point the playlistItemDelegate can choose to either proceed with the playlist item's load, make modifications to it, load an entirely different item, or skip the item's load.
 @note The playlistItemDelegate is used for intercepting item loads. To be notified when a playlistItem successfully loads, use the JWPlayerController's delegate.
 @note The delegate must adopt the JWPlaylistItemDelegate protocol. The delegate is not retained.
 @see JWPlaylistItemDelegate
 */
@property (nonatomic, nullable, weak) id<JWPlaylistItemDelegate> playlistItemDelegate;

/**
 An interface for exposing experimental features.
 @note These features are very likely to be deprecated in the future, and will either be entirely dropped or replaced.
 */
@property (nonatomic, readonly) JWExperimentalAPI *experimentalAPI DEPRECATED_MSG_ATTRIBUTE("Use JWFriendlyAdObstructions class instead.");

/**
 Returns the version of google IMA framework compatible with the JWPlayer SDK.
 */
@property (nonatomic, copy, readonly) NSString *googleIMAVersion;

/**
 Returns the version of google ChromeCast framework compatible with the JWPlayer SDK.
*/
@property (nonatomic, copy, readonly) NSString *googleChromeCastVersion;

/**
 Returns current state of the player.
 @note Can be idle, playing, paused and buffering, error, complete.
 */
@property (nonatomic, readonly) JWPlayerState state;

/**
 Metadata associated with the current video. Usually includes dimensions and duration of the video.
 @note becomes available shortly after the video starts playing. There is a notification JWMetaDataAvailableNotification posted right after metadata is available.
 */
@property (nonatomic, nullable, retain, readonly) NSDictionary *metadata;

/**
 Dimensions of the current video. Becomes available shortly after the video starts to play as a part of metadata.
 */
@property (nonatomic, readonly) CGSize naturalSize;


/**
 JWConfig object that was used to setup the player.
 @note Check JWConfig documentation for more info.
 */
@property (nonatomic, retain, readonly) JWConfig *config;


/**
 Returns the current PlaylistItem's filled buffer, as a percentage (0 to 100) of the total video's length.
 @note This only applies to progressive downloads of media (MP4/FLV/WebM and AAC/MP3/Vorbis); streaming media (HLS/RTMP/YouTube/DASH) do not expose this behavior.
 */
@property (nonatomic, readonly) NSUInteger buffer;

/**
 Enable the built-in controls by setting them true, disable the controls by setting them false.
 */
@property (nonatomic) BOOL controls;

/**
 When enabled, the user will be able to control playback of the current video (play, pause, and when applicable next/previous) from the device's Lock Screen and some information (title, playback position, duration, poster image) will be presented on the lockscreen. Defaults to YES.
 @note In order for the lock screen controls to appear, background audio must be enabled and the audio session must be set to AVAudioSessionCategoryPlayback.
 @note Instantiating more than one player simultaneously can potentially cause
 undesirable behavior regarding lock screen controls, as they are enabled by default for each player.
 To enable lock screen controls for only a specific player: after all the players have been instantiated, explicitly set 'displayLockScreenControls' to YES on the desired player,
 and make sure 'displayLockScreenControls' is set to NO for the undesired player(s).
 */
@property (nonatomic) BOOL displayLockScreenControls;

/**
 Returns the region of the display not used by the controls. You can use this information to ensure your visual assets don't overlap with the controls.
 */
@property (nonatomic, readonly) CGRect safeRegion;

/* ========================================*/
/** @name Managing Video Quality Levels */

/**
 The index of the object in quality levels list currently used by the player.
 @note When playing an adaptive stream, an index of 0 will always be "Auto".
 */
@property (nonatomic) NSUInteger currentQuality;

/**
 List of quality levels available for the current media expressed as an array of dictionaries.
 @note Use the following link to review the format of the dictionaries: https://developer.jwplayer.com/jwplayer/docs/jw8-javascript-api-reference#section-jwplayer-get-quality-levels
 */
@property (nonatomic, retain, readonly) NSArray *qualityLevels;

/* ========================================*/
/** @name Managing Closed Captions */

/**
 The index of the caption object in captions list currently used by the player.
 @note index 0 stands for no caption.
 @see captionsList
 */
@property (nonatomic) NSUInteger currentCaptions;

/**
 List of all the captions supplied in the config
 @note Use currentCaptions to activate one of the captions programmatically.
 Object at index 0 is "off".
 @see currentCaptions
 */
@property (nonatomic, retain, readonly) NSArray <JWTrack *> *captionsList;

/* ========================================*/
/** @name Managing Audio Tracks */


/**
 The index of the currently active audio track.
 */
@property (nonatomic) NSUInteger currentAudioTrack;

/**
 Array with audio tracks from the player.
 */
@property (nonatomic, retain, readonly) NSArray *audioTracks;

/* ========================================*/
/** @name Managing Playlists */

/**
 The index of the currently active item in the playlist.
 */
@property (nonatomic) NSInteger playlistIndex;

/**
 Returns the playlist item at a specific index.
 */
- (JWPlaylistItem *)getPlaylistItem:(NSInteger)index;

/**
 Returns the playlist.
 */
- (NSArray <JWPlaylistItem *> *)getPlaylist;

/* ========================================*/
/** @name Initializing Player Controller Object */

/**
 Inits the player with config object in JWConfig format.
 @param config  JWConfig object that is used to setup the player.
 */
- (nullable instancetype)initWithConfig:(JWConfig *)config;

/**
 Inits the player with config object in JWConfig format and sets the object that acts as the delegate of the JWPlayerController.
  @param config JWConfig object that is used to setup the player.
 @param delegate The object that acts as the delegate of the jwPlayerController.
 @see JWPlayerDelegate
 */
- (nullable instancetype)initWithConfig:(JWConfig *)config delegate:(nullable id<JWPlayerDelegate>)delegate;

/**
 Inits the player with a JWConfig object and sets the object that acts as a DRM data source, as well as the delegate of the JWPlayerController.
 @param config JWConfig object that is used to setup the player.
 @param delegate The object that acts as the delegate of the jwPlayerController.
 @param drmDataSource The object that acts as a data source for reproducing drm encrypted content.
 @see JWPlayerDelegate, JWDrmDataSource
 */
- (nullable instancetype)initWithConfig:(JWConfig *)config delegate:(nullable id<JWPlayerDelegate>)delegate drmDataSource:(nullable id<JWDrmDataSource>)drmDataSource NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/* ========================================*/
/** @name Managing Playback */


/**
 Starts to play video from current position.
 @note If there is a paused ad, this method will resume the ad playback.
 */
- (void)play;

/**
 Pauses video.
 @note If there is an ad playing, this method will pause the ad playback.
 */
- (void)pause;

/**
 Stops the player (returning it to the idle state) and unloads the currently playing media file.
 */
- (void)stop;

/**
 Tells the player to immediately play the next playlist item.
 */
- (void)next;

/**
 @param position Time in the video to seek to
 @see duration
 */
- (void)seek:(NSInteger)position;

/**
 Playback position of the current video.
 @note gets updated as the video plays. JWPlaybackProgressNotification is posted every time position changes. KVO compliant.
 */
@property (nonatomic, readonly) CGFloat position;

/**
 Duration of the current video. Becomes available shortly after the video starts to play as a part of metadata.
 */
@property (nonatomic, readonly) CGFloat duration;

/**
 The volume of the JWPlayerController's audio. At 0.0 the player is muted, at 1.0 the player's volume is as loud as the device's volume.
 @note This property should be used to control the volume of the player (including Google IMA ads) relative to other audio output, not for volume control by viewers. This property will have no effect when casting. Viewers can control volume when casting by changing the device's volume.
 */
@property (nonatomic) CGFloat volume;

/**
 The rate at which media is being reproduced.
 @note Setting this property to 1.0 will play the media at its natural rate. Ability to set a different value is limited to the rates supported by the media item; if an unsupported rate is requested, playbackRate will not change. Rates between 0.0 and 1.0 will slow forward, rates greater than 1.0 will fast forward, rates between 0.0 and -1.0 will slow reverse, and rates lower than -1.0 will fast reverse. This property will have no effect when ads are being played, or when casting. Cannot be set to 0; to pause playback, please call the pause method.
 */
@property (nonatomic) CGFloat playbackRate;


/* ========================================*/
/** @name Managing Full Screen */

/**
 The setter toggles the player's fullscreen mode; the getter returns a boolean value that determines whether the video is in full screen.
 @warning *Note:* If your app uses fullscreen mode, and will run on iPads running iOS 11 or higher, select *Requires full screen* in the *General* tab of your target's settings to avoid unwanted triggering of [Split View](https://developer.apple.com/design/human-interface-guidelines/ios/views/split-views/) mode.
 */
@property (nonatomic) BOOL fullscreen;

/**
 A Boolean value that determines whether the video should go to full screen mode when the device rotates to landscape.
 @note Make sure your app supports landscape to make this property work.
 */
@property (nonatomic) BOOL forceFullScreenOnLandscape;

/**
 A Boolean value that determines whether the video should rotate to landscape when the fullscreen button is pressed.
 @note Make sure your app supports landscape to make this property work.
 */
@property (nonatomic) BOOL forceLandscapeOnFullScreen;

/* ========================================*/
/** @name Custom Buttons */

/**
 Adds a custom button to the player's control bar.
 @note Buttons are added to the righthand-side grouping of icons in the control bar. Buttons are added all the way to the left of the grouping, except if there is a logo in the control bar. In this case, buttons will be added to the right of the logo. Multiple buttons are added from right to left in the order they are entered.
 @see JWButton
 */
- (void)addButton:(JWButton *)button;

/**
 Removes a custom button from the control bar.
 @see JWButton
 */
- (void)removeButton:(JWButton *)button;

/* ========================================*/
/** @name External Metadata */

/**
 Returns the external metadata applied to the current playlist item.
 @see JWPlaylistItem, JWConfig
 */
- (NSArray<JWExternalMetadata *> *)getExternalMetadata;

/**
 Sets external metadata to the current playlist item. Will not apply to the subsequent playlist items.
 @discussion We recommend using this method to add external metadata to playlist items loaded from a related feed. For items loaded in the config's playlist, set the external metadata directly on the playlist item before setting up the player.
 @note Capped at 5 metadata instances; the instances in excess will be excluded
 @note If you wish to apply the same external metadata to all playlist items, set the external metadata on the JWConfig.
 @see JWPlaylistItem, JWRelatedConfig
 */
- (void)setExternalMetadata:(NSArray<JWExternalMetadata *> *_Nonnull)externalMetadata;

/* ========================================*/
/** @name Loading New Media */

/**
 Loads a new playlist into the player.
 @param playlist An array containing playlist items.
 */
- (void)load:(NSArray <JWPlaylistItem *> *)playlist;

/**
 Loads a new playlist feed into the player.
 @param feedUrl A URL referencing the location of an RSS/XML/JSON file
 */
- (void)loadFeed:(NSString *)feedUrl;

/* ========================================*/
/** @name Injecting Ads */


/**
 Immediately starts to play an ad using the vast plugin.
 @param tag Xml file with info about the ad.
 @note Usually used to inject an ad in streams where you can't schedule an ad. If you wish to play the ad with the Google IMA Client, please use playAd:onClient: instead and specify JWAdClientGoogima as your ad client.
 */
- (void)playAd:(NSString *)tag;

/**
 Immediately starts to play an ad.
 @param tag Xml file with info about the ad.
 @param adClient Set to JWAdClientGoogima if you wish to use google IMA; set to JWAdClientVast if not. Setting to nil defaults to vast. Note: Due to the fact that Google IMA's iOS SDK is still in Beta mode, we suggest using the vast plugin.
 @note Usually used to inject an ad in streams where you can't schedule an ad.
 @see JWAdClient
 */
- (void)playAd:(NSString *)tag onClient:(JWAdClient)adClient;

/**
 Used to pause or resume ad playback.
 @param state Indicates whether or not the ad playback should be paused.
 @note If the state is YES, ad playback will be paused.
 */
- (void)pauseAd:(BOOL)state;

/**
 If set to YES will open Safari after the user clicks the ad.
 */
@property (nonatomic) BOOL openSafariOnAdClick;

/* ========================================*/
/** @name Related */

/**
 Opens the related overlay. This will pause content if it is currently playing.
 */
- (void)openRelatedOverlay;

/**
 Closes the related plugin overlay. This will resume content.
 */
- (void)closeRelatedOverlay;

/* ========================================*/
/** @name Accessing SDK Info */

/**
 Version of underlying web player
 */
@property (nonatomic, copy, readonly) NSString *playerVersion;

/**
 Player edition based on the provided JW License key
 */
@property (nonatomic, copy, readonly) NSString *playerEdition;

/**
 Version of the iOS SDK
 */
+ (NSString *)SDKVersion;

/**
 Version of the iOS SDK, truncated. 
 (i.e.: if SDKVersion returns 1.001, SDKVersionToMinor returns 1.).
 */
+ (NSString *)SDKVersionToMinor;

/**
 Sets the Player Key programmatically instead of having to type it into the application's info.plist. We recommend setting the key in the AppDelegate's application:didFinishLaunchingWithOptions: method.
 @note If a different key is entered in the info.plist, the key set with this method will supersede. Use this method before instantiating the JWPlayerController, ideally in the AppDelegate's application:didFinishLaunchingWithOptions: method.
 */
+ (void)setPlayerKey:(NSString *)key;

@end
NS_ASSUME_NONNULL_END
