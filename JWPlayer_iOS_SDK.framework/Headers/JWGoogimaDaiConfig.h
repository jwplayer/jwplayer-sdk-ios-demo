//
//  JWGoogimaDaiConfig.h
//  JWPlayer-iOS-SDK
//
//  Created by Michael Salvador on 1/26/20.
//  Copyright © 2020 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
    Configuration settings for Google IMA DAI.
 */
@interface JWGoogimaDaiConfig : NSObject

/**
 The stream request API key. This is used to verify applications attempting to access their content.
 */
@property (nonatomic, nullable, copy) NSString *apiKey;

/**
 The video identifier for this stream.
 @note Used for VOD.
 */
@property (nonatomic, nullable, copy, readonly) NSString *videoID;

/**
 The content source ID for this stream.
 @note Used for VOD.
 */
@property (nonatomic, nullable, copy, readonly) NSString *cmsID;

/**
 The stream assetKey
 @note Used for live streams.
 */
@property (nonatomic, nullable, copy, readonly) NSString *assetKey;

/**
Initialize for VOD.
*/
- (instancetype)initWithVideoID:(NSString *)videoID cmsID:(NSString *)cmsID;

/**
Initialize for live stream.
*/
- (instancetype)initWithAssetKey:(NSString *)assetKey;

@end
NS_ASSUME_NONNULL_END
