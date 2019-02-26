//
//  JWAVPlayerAnalyticsDelegate.h
//  JWPlayer-iOS-SDK
//
//  Created by Kateryna Obertynska on 9/10/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

/*!
 @protocol JWAVPlayerAnalyticsDelegate
 @discussion The JWAVPlayerAnalyticsDelegate protocol defines properties that a analyticsDelegate of a JWPlayerController object can implement to observe AVPlayer values.
 */
@protocol JWAVPlayerAnalyticsDelegate <NSObject>

/*!
 playbackRateDidChange
 @discussion Called when the player rate has changed.
 @param rate AVPlayer rate.
 */
- (void)playbackRateDidChange:(CGFloat)rate;
/*!
 playerStatusDidChange
 @discussion Called when the player status has changed.
 @param status The value of AVPlayerStatus that indicates whether the receiver can be used for playback.
 */
- (void)playerStatusDidChange:(AVPlayerStatus)status;
/*!
 playerItemDidChange
 @discussion Called when the player item has changed.
 @param item The AVPlayerItem that will become the player's current item.
 @see AVPlayerItem.
 */
- (void)playerItemDidChange:(AVPlayerItem *_Nullable)item;
/*!
 playerErrorDidChange
 @discussion Called when the player error has changed.
 @param error Object containing the error message under property localizedDescription.
 */
- (void)playerErrorDidChange:(NSError *_Nullable)error;
/*!
 playerErrorDidChange
 @discussion Called when the player layer video rect has changed.
 @param videoRect The current size and position of the video image as displayed within the receiver's bounds.
 */
- (void)playerLayerVideoRectDidChange:(CGRect)videoRect;

@end
