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
#import "JWCastController.h"
#import "JWDrmDataSource.h"

#define JWPlayerAllNotification @"JWPlayerAllNotification"
#define JWMetaDataAvailableNotification @"JWMetaDataAvailableNotification"
#define JWPlayerStateChangedNotification @"JWPlayerStateChangedNotification"
#define JWPlaybackPositionChangedNotification @"JWPlaybackPositionChangedNotification"
#define JWFullScreenStateChangedNotification @"JWFullScreenStateChangedNotification"
#define JWAdActivityNotification @"JWAdActivityNotification"
#define JWAdPlaybackProgressNotification @"JWAdPlaybackProgressNotification"
#define JWAdClickNotification @"JWAdClickNotification"
#define JWErrorNotification @"JWErrorNotification"
#define JWCaptionsNotification @"JWCaptionsNotification"
#define JWVideoQualityNotification @"JWVideoQualityNotification"
#define JWPlaylistNotification @"JWPlaylistNotification"
#define JWAudioTrackNotification @"JWAudioTrackNotification"
#define JWRelatedActivityNotification @"JWRelatedActivityNotification"

/*!
 A class that encapsulates JW Player and provides control over the playback as well as holds the state of the player and notifies about status updates.
 */
@interface JWPlayerController : NSObject

/* ========================================*/
/** @name Accessing Player Controller Attributes */

/*!
 Player view.
 @discussion to be added to the application view hierarchy.
 */
@property (nonatomic, retain, readonly) UIView *view;

/*!
The object that acts as the delegate of the jwPlayerController.
 @discussion The delegate must adopt the JWPlayerDelegate protocol. The delegate is not retained.
 @see JWPlayerDelegate
 */
@property (nonatomic, weak) id<JWPlayerDelegate> delegate;

/*!
 The JWDrmDataSource is adopted by an object that mediates the application's data model and key server. The data source provides the JWPlayerController object with the data needed to reproduce encrypted content.
 @discussion The drmDataSource must adopt the JWDrmDataSource protocol. The drmDataSource is not retained.
 @see JWDrmDataSource
 */
@property (nonatomic, weak) id<JWDrmDataSource> drmDataSource;

/*!
 Returns the version of google IMA framework used by the SDK.
 */
@property (nonatomic, retain, readonly) NSString *googleIMAVersion;

/*!
 Returns the version of google ChromeCast framework used by the SDK.
*/
@property (nonatomic, retain, readonly) NSString *googleChromeCastVersion;

/*!
 Returns current state of the player.
 @discussion Can be idle, playing, paused and buffering, error, complete.
 */
@property (nonatomic, readonly) JWPlayerState state;

/*!
 Metadata associated with the current video. Usually includes dimensions and duration of the video.
 @discussion becomes available shortly after the video starts playing. There is a notification JWMetaDataAvailableNotification posted right after metadata is available.
 */
@property (nonatomic, retain, readonly) NSDictionary *metadata;

/*!
 Dimensions of the current video. Becomes available shortly after the video starts to play as a part of metadata.
 */
@property (nonatomic, readonly) CGSize naturalSize;


/*!
 JWConfig object that was used to setup the player.
 @discussion Check JWConfig documentation for more info.
 */
@property (nonatomic, retain, readonly) JWConfig *config;


/*!
 Returns the current PlaylistItem's filled buffer, as a percentage (0 to 100) of the total video's length.
 @discussion This only applies to progressive downloads of media (MP4/FLV/WebM and AAC/MP3/Vorbis); streaming media (HLS/RTMP/YouTube/DASH) do not expose this behavior.
 */
@property (nonatomic, readonly) NSUInteger buffer;

/*!
 Enable the built-in controls by setting them true, disable the controls by setting them false.
 */
@property (nonatomic) BOOL controls;

/*!
 When enabled, the user will be able to control playback of the current video (play, pause, and when applicable next/previous) from the device's Lock Screen and some information (title, playback position, duration, poster image) will be presented on the lockscreen. Defaults to YES.
 @discussion In order for the lock screen controls to appear, background audio must be enabled and the audio session must be set to AVAudioSessionCategoryPlayback.
 */
@property (nonatomic) BOOL displayLockScreenControls;

/*!
 Returns the region of the display not used by the controls. You can use this information to ensure your visual assets don't overlap with the controls.
 */
@property (nonatomic, readonly) CGRect safeRegion;

/* ========================================*/
/** @name Managing Video Quality Levels */

/*!
 The index of the object in quality levels list currently used by the player.
 */
@property (nonatomic) NSUInteger currentQuality;

/*!
 List of quality levels available for the current media.
 */
@property (nonatomic, retain, readonly) NSArray *qualityLevels;

/* ========================================*/
/** @name Managing Closed Captions */

/*!
 The index of the caption object in captions list currently used by the player.
 @discussion index 0 stands for no caption.
 @see captionsList
 */
@property (nonatomic) NSUInteger currentCaptions;

/*!
 List of all the captions supplied in the config
 @discussion Use currentCaptions to activate one of the captions programmatically.
 Object at index 0 is "off".
 @see currentCaptions
 */
@property (nonatomic, retain, readonly) NSArray <JWTrack *> *captionsList;

/* ========================================*/
/** @name Managing Audio Tracks */


/*!
 The index of the currently active audio track.
 */
@property (nonatomic) NSUInteger currentAudioTrack;

/*!
 Array with audio tracks from the player.
 */
@property (nonatomic, retain, readonly) NSArray *audioTracks;

/* ========================================*/
/** @name Managing Playlists */

/*!
 The index of the currently active item in the playlist.
 */
@property (nonatomic) NSInteger playlistIndex;

/* ========================================*/
/** @name Initializing Player Controller Object */

/*!
 Inits the player with config object in JWConfig format.
 @param config  JWConfig object that is used to setup the player.
 */
- (instancetype)initWithConfig:(JWConfig *)config;

/*!
 Inits the player with config object in JWConfig format and sets the object that acts as the delegate of the JWPlayerController.
  @param config JWConfig object that is used to setup the player.
 @param delegate The object that acts as the delegate of the jwPlayerController.
 @see JWPlayerDelegate
 */
- (instancetype)initWithConfig:(JWConfig *)config delegate:(id<JWPlayerDelegate>)delegate;

/*!
 Inits the player with a JWConfig object and sets the object that acts as a DRM data source, as well as the delegate of the JWPlayerController.
 @param config JWConfig object that is used to setup the player.
 @param delegate The object that acts as the delegate of the jwPlayerController.
 @param drmDataSource The object that acts as a data source for reproducing drm encrypted content.
 @see JWPlayerDelegate, JWDrmDataSource
 */
- (instancetype)initWithConfig:(JWConfig *)config delegate:(id<JWPlayerDelegate>)delegate drmDataSource:(id<JWDrmDataSource>)drmDataSource;

/* ========================================*/
/** @name Managing Playback */


/*!
 Starts to play video from current position.
 */
- (void)play;

/*!
 Pauses video.
 */
- (void)pause;

/*!
 Stops the player (returning it to the idle state) and unloads the currently playing media file.
 */
- (void)stop;

/*!
 Tells the player to immediately play the next playlist item.
 */
- (void)next;

/*!
 @param position Time in the video to seek to
 @see duration
 */
- (void)seek:(NSUInteger)position;

/*!
 Playback position of the current video.
 @discussion gets updated as the video plays. JWPlaybackProgressNotification is posted every time position changes. KVO compliant.
 */
@property (nonatomic, readonly) CGFloat position;

/*!
 Duration of the current video. Becomes available shortly after the video starts to play as a part of metadata.
 */
@property (nonatomic, readonly) CGFloat duration;

/*!
 The volume of the JWPlayerController's audio. At 0.0 the player is muted, at 1.0 the player's volume is as loud as the device's volume.
 @discussion This property should be used to control the volume of the player relative to other audio output, not for volume              control by viewers. This property will have no effect when ads are played using Google IMA, or when casting. Viewers can control volume when casting by changing the device's volume.
 */
@property (nonatomic) CGFloat volume;

/*!
 The rate at which media is being reproduced.
 @discussion Setting this property to 1.0 will play the media at its natural rate. Ability to set a different value is limited to the rates supported by the media item; if an unsupported rate is requested, playbackRate will not change. Rates between 0.0 and 1.0 will slow forward, rates greater than 1.0 will fast forward, rates between 0.0 and -1.0 will slow reverse, and rates lower than -1.0 will fast reverse. This property will have no effect when ads are being played, or when casting. Cannot be set to 0; to pause playback, please call the pause method.
 */
@property (nonatomic) CGFloat playbackRate;


/* ========================================*/
/** @name Managing Full Screen / Picture in Picture */

/*!
 The setter toggles the player's fullscreen mode; the getter returns a boolean value that determines whether the video is in full screen.
 */
@property (nonatomic) BOOL fullscreen;

/*!
 A Boolean value that determines whether the video should go to full screen mode when the device rotates to landscape.
 @discussion Make sure your app supports landscape to make this property work.
 */
@property (nonatomic) BOOL forceFullScreenOnLandscape;

/*!
 A Boolean value that determines whether the video should rotate to landscape when the fullscreen button is pressed.
 @discussion Make sure your app supports landscape to make this property work.
 */
@property (nonatomic) BOOL forceLandscapeOnFullScreen;

/* ========================================*/
/** @name Loading New Media */

/*!
 Loads a new playlist into the player.
 @param playlist An array containing playlist items.
 */
- (void)load:(NSArray <JWPlaylistItem *> *)playlist;

/*!
 Loads a new playlist feed into the player.
 @param feedUrl A URL referencing the location of an RSS/XML/JSON file
 */
- (void)loadFeed:(NSString *)feedUrl;

/* ========================================*/
/** @name Injecting Ads */


/*!
 Immediately starts to play an ad using the vast plugin.
 @param tag Xml file with info about the ad.
 @discussion Usually used to inject an ad in streams where you can't schedule an ad. If you wish to play the ad with the Google IMA Client, please use playAd:onClient: instead and specify JWAdClientGoogima as your ad client.
 */
- (void)playAd:(NSString *)tag;

/*!
 Immediately starts to play an ad.
 @param tag Xml file with info about the ad.
 @param adClient Set to JWAdClientGoogima if you wish to use google IMA; set to JWAdClientVast if not. Setting to nil defaults to vast. Note: Due to the fact that Google IMA's iOS SDK is still in Beta mode, we suggest using the vast plugin.
 @discussion Usually used to inject an ad in streams where you can't schedule an ad.
 @see JWAdClient
 */
- (void)playAd:(NSString *)tag onClient:(JWAdClient)adClient;

/*!
 Used to pause or resume ad playback.
 @param state Indicates whether or not the ad playback should be paused.
 @discussion If the state is YES, ad playback will be paused.
 */
- (void)pauseAd:(BOOL)state;

/*!
 If set to YES will open Safari after the user clicks the ad.
 */
@property (nonatomic) BOOL openSafariOnAdClick;

/* ========================================*/
/** @name Related */

/*!
 Opens the related overlay. This will pause content if it is currently playing.
 */
- (void)openRelatedOverlay;

/*!
 Closes the related plugin overlay. This will resume content.
 */
- (void)closeRelatedOverlay;

/* ========================================*/
/** @name Accessing SDK Info */

/*!
 Version of underlying web player
 */
@property (nonatomic, retain, readonly) NSString *playerVersion;

/*!
 Player edition based on the provided JW License key
 */
@property (nonatomic, retain, readonly) NSString *playerEdition;

/*!
 Version of the iOS SDK
 */
+ (NSString *)SDKVersion;

/*!
 Version of the iOS SDK, truncated. 
 (i.e.: if SDKVersion returns 1.001, SDKVersionToMinor returns 1.).
 */
+ (NSString *)SDKVersionToMinor;

/*!
 Sets the Player Key programmatically instead of having to type it into the application's info.plist. We recommend setting the key in the AppDelegate's application:didFinishLaunchingWithOptions: method.
 @discussion If a different key is entered in the info.plist, the key set with this method will supersede. Use this method before instantiating the JWPlayerController, ideally in the AppDelegate's application:didFinishLaunchingWithOptions: method.
 */
+ (void)setPlayerKey:(NSString *)key;

@end
