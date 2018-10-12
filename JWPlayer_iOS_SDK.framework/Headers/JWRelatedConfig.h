//
//  JWRelatedConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Rik Heijdens on 9/1/16.
//  Copyright © 2016 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    JWRelatedOnCompleteShow = 0,
    JWRelatedOnCompleteHide,
    JWRelatedOnCompleteAutoplay
}JWRelatedOnComplete;

typedef enum {
    JWRelatedMethodApi = 0,
    JWRelatedMethodComplete,
    JWRelatedMethodInteraction
}JWRelatedMethod;

typedef enum {
    JWRelatedDisplayModeShelf = 0,
    JWRelatedDisplayModeOverlay
}JWRelatedDisplayMode;

typedef enum {
    JWRelatedOnClickPlay = 0,
    JWRelatedOnClickLink,
}JWRelatedOnClick;

/*!
 An object providing information about the way related videos are handled by the player.
 */
@interface JWRelatedConfig : NSObject

/* ========================================*/
/** @name Configuring the related overlay */

/*!
 (Required) Location of an RSS or JSON file containing a feed of related videos.
 @discussion Must be an url to a RSS or JSON file containing a feed of related videos. See: https://support.jwplayer.com/customer/portal/articles/1483102#implementing-related
*/
@property (nonatomic) NSString *file;

/*!
 Configure the recommendations user interface. Does not apply to manual playlists. Defaults to the shelf (JWRelatedDisplayModeShelf).
 @discussion JWRelatedDisplayModeShelf Adds a horizontal bar of thumbnails above the control bar, which allows viewers to browse recommended videos throughout the playback experience. The shelf can be collapsed into a "More Videos" button, which appears above the control bar. Due to size constraints, small players fall back to JWRelatedDisplayModeOverlay mode.
 @discussion JWRelatedDisplayModeOverlay Adds a "more videos" icon to the control bar. When clicked, an overlay takes over the player, pausing playback.
 */
@property (nonatomic) JWRelatedDisplayMode displayMode;

/*!
 The behavior of our related videos overlay when a single video or playlist is completed. Defaults to Show (JWRelatedOnCompleteShow).
 @discussion JWRelatedOnCompleteShow Display the related overlay (default).
 @discussion JWRelatedOnCompleteHide Replay button and related icon will appear.
 @discussion JWRelatedOnCompleteAutoplay Automatically play the next video in your related feed after 10 seconds.
 */
@property (nonatomic) JWRelatedOnComplete onComplete;

/*!
 The behavior when a related video is selected. Defaults to play (JWRelatedOnClickPlay).
 @discussion JWRelatedOnClickPlay Plays the next video within the current player.
 @discussion JWRelatedOnClickLink Redirects the page to the url specified in the related item's link field.
 */
@property (nonatomic) JWRelatedOnClick onClick;

/*!
 Single line heading displayed above the grid with related videos. Generally contains a short call-to-action.
 Default: "Next up"
 */
@property (nonatomic) NSString *heading;

/*!
 The number of seconds to wait before playing the next related video in your content list. Defaults to 10 seconds.
 Set to 0 to have your next related content to play immediately.
 */
@property (nonatomic) NSUInteger autoplayTimer;

/*!
 A custom message that appears during autoplay. Defaults to "__title__ will play in xx seconds".
 Note: xx will be replaced by the countdown timer
 Note: __title__ will be replaced by the next title in the related feed.
 */
@property (nonatomic) NSString *autoplayMessage;

@end
