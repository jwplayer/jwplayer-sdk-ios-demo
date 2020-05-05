//
//  JWRelatedConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Rik Heijdens on 9/1/16.
//  Copyright © 2016 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
    Type of related video playback behavior of Recommendations UI upon completion of the current playlist item.
 */
typedef NS_ENUM(NSInteger, JWRelatedOnComplete) {
    /// Show Recommendations UI after completion
    JWRelatedOnCompleteShow = 0,
    /// Hide Recommendations UI after completion
    JWRelatedOnCompleteHide,
    /// Play related video automatically after completion
    JWRelatedOnCompleteAutoplay
};

/**
    Describes the action that caused the dismissal of the Recommendations UI.
 */
typedef NS_ENUM(NSInteger, JWRelatedMethod) {
    JWRelatedMethodApi = 0,
    JWRelatedMethodComplete,
    JWRelatedMethodInteraction
};

/**
    Type of display mode for the related content.
 */
typedef NS_ENUM(NSInteger, JWRelatedDisplayMode) {
    /// display as a shelf
    JWRelatedDisplayModeShelf = 0,
    /// display as an overlay
    JWRelatedDisplayModeOverlay
};

/**
    Type of click-through behavior for the related video.
 */
typedef NS_ENUM(NSInteger, JWRelatedOnClick) {
    /// Play the video after a click
    JWRelatedOnClickPlay = 0,
    /// Open the link in a browser after a click
    JWRelatedOnClickLink,
};

NS_ASSUME_NONNULL_BEGIN
/**
 An object providing information about the way related videos are handled by the player.
 */
@interface JWRelatedConfig : NSObject

/* ========================================*/
/** @name Configuring the related overlay
 */

/**
 (Required) Location of an RSS or JSON file containing a feed of related videos.
 @note Must be an url to a RSS or JSON file containing a feed of related videos. See: https://support.jwplayer.com/customer/portal/articles/1483102#implementing-related
*/
@property (nonatomic, copy) NSString *file;

/**
 Configure the recommendations user interface. Does not apply to manual playlists. Defaults to the shelf (JWRelatedDisplayModeShelf).
 @note JWRelatedDisplayModeShelf Adds a horizontal bar of thumbnails above the control bar, which allows viewers to browse recommended videos throughout the playback experience. The shelf can be collapsed into a "More Videos" button, which appears above the control bar. Due to size constraints, small players fall back to JWRelatedDisplayModeOverlay mode.
 @note JWRelatedDisplayModeOverlay Adds a "more videos" icon to the control bar. When clicked, an overlay takes over the player, pausing playback.
 */
@property (nonatomic) JWRelatedDisplayMode displayMode;

/**
 The behavior of our related videos overlay when a single video or playlist is completed. Defaults to Show (JWRelatedOnCompleteShow).
 @note JWRelatedOnCompleteShow Display the related overlay (default).
 @note JWRelatedOnCompleteHide Replay button and related icon will appear.
 @note JWRelatedOnCompleteAutoplay Automatically play the next video in your related feed after 10 seconds.
 */
@property (nonatomic) JWRelatedOnComplete onComplete;

/**
 The behavior when a related video is selected. Defaults to play (JWRelatedOnClickPlay).
 @note JWRelatedOnClickPlay Plays the next video within the current player.
 @note JWRelatedOnClickLink Redirects the page to the url specified in the related item's link field.
 */
@property (nonatomic) JWRelatedOnClick onClick;

/**
 Single line heading displayed above the grid with related videos. Generally contains a short call-to-action.
 Default: "Next up"
 */
@property (nonatomic, nullable, copy) NSString *heading;

/**
 The number of seconds to wait before playing the next related video in your content list. Defaults to 10 seconds.
 Set to 0 to have your next related content to play immediately.
 */
@property (nonatomic) NSUInteger autoplayTimer;

/**
 A custom message that appears during autoplay. Defaults to "__title__ will play in xx seconds".
 Note: xx will be replaced by the countdown timer
 Note: __title__ will be replaced by the next title in the related feed.
 */
@property (nonatomic, nullable, copy) NSString *autoplayMessage;

@end
NS_ASSUME_NONNULL_END
