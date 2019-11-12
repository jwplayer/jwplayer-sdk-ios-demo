//
//  JWPlayerController+Private.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 5/20/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import "JWPlayerController.h"
#import "JWSDKRouter.h"
#import "JWWebPlayerFactory.h"
#import "JWOfflineHandler.h"
#import "JWRotationHandler.h"
#import "JWFullScreenHandler.h"
#import "JWGoogimaPlaylistHandler.h"
#import "JWSDKRouter.h"
#import "JWWebViewDelegate.h"
#import "JWLockScreenController.h"
#import "JWFeatureSegmenter.h"
#import "JWAnalyticsHandler.h"
#import "JWErrorCodes.h"
#import "JWAdsProviderHandler.h"
#import "JWFriendlyAdObstructionsDataSource.h"

static NSString * webPlayerVersion;

#define JWPlayerCallbackTestNotification @"JWPlayerCallbackTestNotification"
#define JWPlayerRotatedWhileInFullscreen @"rotatedOnFS"
#define JWRedColor [UIColor colorWithRed:1 green:0 blue:70.0/255.0 alpha:1]
#define FALLBACKPLAYERVERSION @"8.4.0"

@class JWAVContainer;

@interface JWPlayerController (Private)<JWEditionProvider>

@property (nonatomic) JWPWebView *webPlayer;
@property (nonatomic) JWAVContainer *avContainer;
@property (nonatomic) IMAAdsManager *googimaAdsManager;
@property (nonatomic, readwrite) JWConfig *config;

@property (nonatomic) JWGoogimaPlaylistHandler *googimaAdapter;
@property (nonatomic) JWFullScreenHandler *fullScreenHandler;
@property (nonatomic) JWSDKRouter *sdkRouter;
@property (nonatomic) JWOfflineHandler *offlineHandler;
@property (nonatomic) JWRotationHandler *rotationHandler;
@property (nonatomic) JWPictureInPictureHandler *pictureInpictureHandler;
@property (nonatomic) JWWebPlayerFactory *webPlayerFactory;
@property (nonatomic) JWWebViewDelegate *webLoadFilter;
@property (nonatomic) JWLockScreenController *lockScreenController;
@property (nonatomic) JWFeatureSegmenter *segmenter;
@property (nonatomic) JWAnalyticsHandler *analyticsHandler;
@property (nonatomic) id<JWAdsProviderHandler> freewheelHandler;
@property (nonatomic, weak) id<JWFriendlyAdObstructionsDataSource> friendlyAdObstructionsDataSource;

@property (nonatomic) BOOL queuedForFullscreen;
@property (nonatomic) BOOL isPreparingToPlay;
@property (nonatomic) BOOL isReady;
@property (nonatomic) BOOL webPlayerLoadFailed;
@property (nonatomic, readonly) BOOL googimaAdInReproduction;
@property (nonatomic) NSURL *customCacheFolder;

@property (nonatomic, readwrite) CGFloat duration;

- (void)toggleFullScreen:(BOOL)fullScreen;
- (NSString *)playerToken;

+ (NSString *)webPlayerVersion;
+ (void)setWebPlayerVersion:(NSString *)version;
+ (NSString *)webPlayerUrlForFile:(NSString *)file;

@end
