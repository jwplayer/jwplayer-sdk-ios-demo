//
//  PlayerViewController.m
//  JWPlayerSDKDemo
//
//  Created by Max Mikheyenko on 1/5/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import "ObjCPlayerViewController.h"
#import <JWPlayer_iOS_SDK/JWPlayerController.h>

@interface ObjCPlayerViewController () <JWPlayerDelegate>

@property (nonatomic) JWPlayerController *player;
@property (nonatomic) IBOutlet UITextView *callbacksView;
@property (nonatomic) IBOutlet UILabel *playbackTime;
@property (nonatomic) IBOutlet UIButton *playButton;

@end

@implementation ObjCPlayerViewController

//MARK: Life Cycle Methods
- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationItem.title = @"Objective C Implementation";
    self.view.backgroundColor = [UIColor whiteColor];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self createPlayer];
    [self setupNotifications];
    [self.view addSubview:self.player.view];
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)createPlayer
{
    //MARK: JWConfig
    
    /* JWConfig can be created with a single file reference */
    //     JWConfig *config = [JWConfig configWithContentURL:@"http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4"];
    
    JWConfig *config = [JWConfig new];
    config.sources = @[[JWSource sourceWithFile:@"http://content.bitsontherun.com/videos/bkaovAYt-injeKYZS.mp4" label:@"180p Streaming" isDefault:YES],
                       [JWSource sourceWithFile:@"http://content.bitsontherun.com/videos/bkaovAYt-52qL9xLP.mp4" label:@"270p Streaming"],
                       [JWSource sourceWithFile:@"http://content.bitsontherun.com/videos/bkaovAYt-DZ7jSYgM.mp4" label:@"720p Streaming"]];
    
    config.image = @"http://content.bitsontherun.com/thumbs/bkaovAYt-480.jpg";
    config.title = @"JWPlayer Demo";
    config.controls = YES;  //default
    config.repeat = NO;   //default
    config.premiumSkin = JWPremiumSkinRoundster;
    
    /* custom css skin can be applied using */
    //     config.cssSkin = @"http:p.jwpcdn.com/iOS/Skins/ethan.css";
    
    //MARK: JWTrack (captions)
    config.tracks = @[[JWTrack trackWithFile:@"http://playertest.longtailvideo.com/caption-files/sintel-en.srt" label:@"English" isDefault:YES],
                      [JWTrack trackWithFile:@"http://playertest.longtailvideo.com/caption-files/sintel-sp.srt" label:@"Spanish"],
                      [JWTrack trackWithFile:@"http://playertest.longtailvideo.com/caption-files/sintel-ru.srt" label:@"Russian"]];
    
    
    //MARK: JWCaptionStyling
    JWCaptionStyling* captionStyling = [JWCaptionStyling new];
    captionStyling.font = [UIFont fontWithName:@"Zapfino" size:20];
    captionStyling.edgeStyle = raised;
    captionStyling.windowColor = [UIColor orangeColor];
    captionStyling.backgroundColor = [UIColor colorWithRed:0.3 green:0.6 blue:0.3 alpha:0.7];
    captionStyling.fontColor = [UIColor blueColor];
    config.captionStyling = captionStyling;
    
    //MARK: JWAdConfig
    JWAdConfig *adConfig = [JWAdConfig new];
    adConfig.adMessage = @"Ad duration countdown xx";
    adConfig.skipMessage = @"Skip in xx";
    adConfig.skipText = @"Move on";
    adConfig.skipOffset = 3;
    adConfig.adClient = vastPlugin;
    config.adConfig = adConfig;
    
//    config.autostart = YES;
    
    //MARK: Waterfall Tags
    NSArray *waterfallTags = @[@"bad tag", @"another bad tag", @"http://playertest.longtailvideo.com/adtags/preroll_newer.xml"];
    
    //MARK: JWAdBreak
    config.adSchedule = @[[JWAdBreak adBreakWithTags:waterfallTags offset:@"pre"],
                          [JWAdBreak adBreakWithTag:@"http://playertest.longtailvideo.com/adtags/preroll_newer.xml" offset:@"0:00:05"],
                          [JWAdBreak adBreakWithTag:@"http://demo.jwplayer.com/player-demos/assets/overlay.xml" offset:@"7" nonLinear:YES],
//                          [JWAdBreak adBreakWithTag:@"http://playertest.longtailvideo.com/adtags/preroll_newer.xml" offset:@"5"],
                          [JWAdBreak adBreakWithTag:@"http://playertest.longtailvideo.com/adtags/preroll_newer.xml" offset:@"50%"],
                          [JWAdBreak adBreakWithTag:@"http://playertest.longtailvideo.com/adtags/preroll_newer.xml" offset:@"post"]];
    
    self.player = [[JWPlayerController alloc] initWithConfig:config];
    self.player.delegate = self;
    
    CGRect frame = self.view.bounds;
    frame.origin.y = 64;
    frame.size.height /= 2;
    frame.size.height -= 44 + 64;
    self.player.view.frame = frame;
    self.player.view.autoresizingMask = UIViewAutoresizingFlexibleBottomMargin|UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleRightMargin|UIViewAutoresizingFlexibleTopMargin|UIViewAutoresizingFlexibleWidth;
    
    self.player.openSafariOnAdClick = YES;
    self.player.forceFullScreenOnLandscape = YES;
    self.player.forceLandscapeOnFullScreen = YES;
}

//MARK: JW Player Delegates
-(void)onTime:(double)position ofDuration:(double)duration
{
    NSString *playbackPosition = [NSString stringWithFormat:@"%.01f/.01%f", position, duration];
    self.playbackTime.text = playbackPosition;
}
-(void)onPlay
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onPause
{
    [self.playButton setTitle:@"Play" forState:UIControlStateNormal];
}

-(void)onBuffer
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onIdle
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onReady
{
    [self.playButton setTitle:@"Play" forState:UIControlStateNormal];
}

-(void)onComplete
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onAdSkipped:(NSString *)tag
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onAdComplete:(NSString *)tag
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onAdImpression:(NSString *)tag
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onBeforePlay
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onBeforeComplete
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onAdPlay:(NSString *)tag
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

-(void)onAdPause:(NSString *)tag
{
    [self.playButton setTitle:@"Play" forState:UIControlStateNormal];
}

-(void)onAdError:(NSError *)error
{
    [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
}

#pragma mark - IBActions

- (IBAction)play:(id)sender
{
    NSLog(@"state %@", self.player.playerState);
    if([self.player.playerState isEqualToString:@"PAUSED"] ||
       [self.player.playerState isEqualToString:@"IDLE"]) {
        [self.player play];
        [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
    } else {
        [self.player pause];
        [self.playButton setTitle:@"Play" forState:UIControlStateNormal];
    }
}

- (void)playerStateChanged:(NSNotification*)info
{
    NSDictionary *userInfo = info.userInfo;
    if([userInfo[@"event"] isEqualToString:@"onPause"] ||
       [userInfo[@"event"] isEqualToString:@"onReady"] ||
       [userInfo[@"event"] isEqualToString:@"onAdPause"]) {
        [self.playButton setTitle:@"Play" forState:UIControlStateNormal];
    } else {
        [self.playButton setTitle:@"Pause" forState:UIControlStateNormal];
    }
}

- (IBAction)insertAd:(id)sender
{
    [self.player playAd:@"http://playertest.longtailvideo.com/adtags/preroll_newer.xml"];
}

#pragma mark - callbacks

- (void)setupNotifications
{
    NSArray *notifications = @[
                               JWPlayerStateChangedNotification,
                               JWMetaDataAvailableNotification,
                               JWAdActivityNotification,
                               JWErrorNotification,
                               JWCaptionsNotification,
                               JWVideoQualityNotification,
                               JWPlaybackPositionChangedNotification,
                               JWFullScreenStateChangedNotification,
                               JWAdClickNotification];
    
    NSNotificationCenter *center = [NSNotificationCenter defaultCenter];
    [notifications enumerateObjectsUsingBlock:^(NSString *obj, NSUInteger idx, BOOL *stop) {
        [center addObserver:self selector:@selector(handleNotification:) name:obj object:nil];
    }];
    [center addObserver:self selector:@selector(updatePlaybackTimer:) name:JWPlaybackPositionChangedNotification object:nil];
    [center addObserver:self selector:@selector(playerStateChanged:) name:JWPlayerStateChangedNotification object:nil];
    [center addObserver:self selector:@selector(playerStateChanged:) name:JWAdActivityNotification object:nil];
}

#pragma mark - callback notification handling

- (void)handleNotification:(NSNotification*)notificaiton
{
    NSDictionary *userInfo = notificaiton.userInfo;
    NSString *callback = userInfo[@"event"];
    
    if([callback isEqualToString:@"onTime"]) { return;}
    
    NSString *text = self.callbacksView.text;
    text = [text stringByAppendingFormat:@"\n%@ %@",callback, userInfo];
    self.callbacksView.text = text;
    CGSize size = [self.callbacksView sizeThatFits:CGSizeMake(self.callbacksView.frame.size.width, CGFLOAT_MAX)];
    self.callbacksView.contentSize = CGSizeMake(self.callbacksView.contentSize.width, size.height);
    if(self.callbacksView.contentSize.height > self.callbacksView.frame.size.height) {
        [self.callbacksView setContentOffset:CGPointMake(0, self.callbacksView.contentSize.height-self.callbacksView.frame.size.height) animated:YES];
    }
}

- (void)updatePlaybackTimer:(NSNotification*)notification
{
    NSDictionary *userinfo = notification.userInfo;
    if([userinfo[@"event"] isEqualToString:@"onTime"]) {
        NSString *position = [NSString stringWithFormat:@"%@/%@", userinfo[@"position"], userinfo[@"duration"]];
        self.playbackTime.text = position;
    }
}

@end
