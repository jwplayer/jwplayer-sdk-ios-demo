//
//  ObjCViewController.m
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

#import "ObjCViewController.h"
#import "JWPlayer_SDK_iOS_Demo-Swift.h"
#import <JWPlayer_iOS_SDK/JWPlayerController.h>
#import <AVKit/AVRoutePickerView.h>
#import <MediaPlayer/MPVolumeView.h>

@interface ObjCViewController ()

@property (weak, nonatomic) IBOutlet UIView *playerContainerView;
@property (nonatomic) JWPlayerController *player;

@end

@implementation ObjCViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    JWConfig *config = [JWConfig configWithContentURL:@"http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4"];
    self.player = [[JWPlayerController alloc]initWithConfig:config];
    
    [self setupAirPlayButton];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    UIView *playerView = self.player.view;
    [self.playerContainerView addSubview:playerView];
    [playerView constrainToSuperview];
}

- (void)setupAirPlayButton {
    UIBarButtonItem *barButtonItem = nil;
    
    if (@available(iOS 11.0, *)) {
        AVRoutePickerView *routePickerView = [[AVRoutePickerView alloc] init];
        barButtonItem = [[UIBarButtonItem alloc] initWithCustomView:routePickerView];
    } else {
        MPVolumeView *airPlayView = [[MPVolumeView alloc] init];
        [airPlayView setShowsVolumeSlider:NO];
        barButtonItem = [[UIBarButtonItem alloc] initWithCustomView:airPlayView];
    }
    
    if (barButtonItem) {
        [self.navigationItem setRightBarButtonItem:barButtonItem];
    }
}

@end
