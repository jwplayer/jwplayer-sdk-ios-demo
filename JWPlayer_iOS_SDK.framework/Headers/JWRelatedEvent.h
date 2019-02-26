//
//  JWRelatedEvent.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 5/16/18.
//  Copyright © 2018 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWRelatedConfig.h"

@class JWPlaylistItem;

@interface JWRelatedEvent : NSObject

@end

@protocol JWRelatedInteractionEvent

/*!
 The method used to close the overlay. (api, complete, or click)/
 */
@property (nonatomic) JWRelatedMethod method;

@end


@protocol JWRelatedOpenEvent <JWRelatedInteractionEvent>

/*!
 The URL of the feed that was loaded into the player.
 */
@property (nonatomic) NSString *url;

/*!
 An array of all items that have been loaded into the related plugin.
 */
@property (nonatomic) NSArray<JWPlaylistItem *> *items;

@end


@protocol JWRelatedPlayEvent <NSObject>

/*!
 the chosen item specified in the feed.
 */
@property (nonatomic) JWPlaylistItem *item;

/*!
 Returns true if started via autoplay; false if manually started.
 */
@property (nonatomic) BOOL autostart;

/*!
 Ordinal position of the related video that has been chosen.
 */
@property (nonatomic) NSInteger position;

@end
