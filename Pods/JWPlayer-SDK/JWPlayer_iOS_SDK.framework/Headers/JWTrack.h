//
//  JWTrack.h
//  JWPlayer-iOS-SDK
//
//  Created by Max Mikheyenko on 10/20/14.
//  Copyright (c) 2014 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 An object providing info about captions or thumbnails. Supports DFXP (TTML), SRT, WebVTT formats.
 */
@interface JWTrack : NSObject


/* ========================================*/
/** @name Accessing Captions Track Attributes
 */

/**
 Path to the captions or thumbnails track file.
 @note Captions accept WEBVTT, SRT, and DFXP format, though JW Player strongly suggests using WEBVTT if possible. Thumbnail files must be in WEBVTT format, these VTT files contain links to the actual thumbnail images, which can be in JPG, PNG or GIF format.
 */
@property (nonatomic, copy) NSString *file;

/**
 Label to be shown in the player in captions popup.
 @note Only for captions. Not shown if only 1 captions track provided.
 */
@property (nonatomic, copy) NSString *label;

/**
 String representing kind of track.
 @note 'captions' and 'thumbnails' are currently supported.
 */
@property (nonatomic, nullable, copy) NSString *kind;

/**
 If set to yes the player shows this captions track upon launch.
 @note Only for captions.
 */
@property (nonatomic) BOOL defaultTrack;

/* ========================================*/
/** @name Creating Captions Track Object
 */


/**
 Factory method that creates JWTrack object with provided file and label.
 @param file Path to the captions file.
 @param label Label to be shown in the player in captions popup.
 */
+ (instancetype)trackWithFile:(NSString *)file label:(NSString *)label;

/**
 Factory method that creates JWTrack object with provided file and label and sets current captions track as default.
 @param file Path to the captions file.
 @param label Label to be shown in the player in captions popup.
 @param def If set to yes the player shows this captions track upon launch.
 */
+ (instancetype)trackWithFile:(NSString *)file label:(NSString *)label isDefault:(BOOL)def;

/* ========================================*/
/** @name Creating Thumbnails Track Object
 */


/**
 Factory method that creates JWTrack object with provided thumbnails file.
 @param file Path to the thumbnails file.
 @see file
 */
+ (instancetype)trackWithThumbnailsFile:(NSString *)file;

/* ========================================*/
/** @name Initializing Captions Track Object
 */


/**
 Inits JWTrack object with provided file and label.
 @param file Path to the captions file.
 @param label Label to be shown in the player in captions popup.
 */
- (instancetype)initWithFile:(NSString *)file label:(NSString *)label;

/**
 Inits JWTrack object with provided file and label and sets current captions track as default.
 @param file Path to the captions file.
 @param label Label to be shown in the player in captions popup.
 @param def If set to yes the player shows this captions track upon launch.
 */
- (instancetype)initWithFile:(NSString *)file label:(NSString *)label isDefault:(BOOL)def;

/**
 Inits JWTrack object with provided thumbnails file.
 @param file Path to the thumbnails file.
 @see file
 */
- (instancetype)initWithThumbnailsFile:(NSString *)file;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

@end
NS_ASSUME_NONNULL_END
