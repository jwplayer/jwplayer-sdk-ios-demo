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

@interface ObjCViewController ()

@property (weak, nonatomic) IBOutlet UIView *playerContainerView;
@property (nonatomic) JWPlayerController *player;

@end

@implementation ObjCViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    self.player = [JWPlayerFactory newPlayerWithDelegate:nil];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self layoutPlayerView:self.player.view];
}

- (void)layoutPlayerView:(UIView *)playerView
{
    [self.playerContainerView addSubview:playerView];
    
    if (JWPlayerController.supportsAutolayout) {
        [playerView constrainToSuperview];
    } else {
        playerView.frame = self.playerContainerView.bounds;
        playerView.autoresizingMask = UIViewAutoresizingFlexibleWidth & UIViewAutoresizingFlexibleHeight;
    }
}

@end
