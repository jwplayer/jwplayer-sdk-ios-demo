//
//  ObjCViewController.m
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 9/1/20.
//  Copyright © 2020 JWPlayer. All rights reserved.
//

#import "ObjCViewController.h"
//#import "JWPlayer_SDK_iOS_Demo-Swift.h"
#import "JWP_FreeWheel_Demo-Swift.h"
#import <JWPlayer_iOS_SDK/JWPlayerController.h>

@interface ObjCViewController ()
@property (weak, nonatomic) IBOutlet UIView *playerContainerView;
@property (nonatomic) JWPlayerController *player;

@end

@implementation ObjCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    JWConfig *config = [JWConfig configWithContentURL:@"http://content.bitsontherun.com/videos/3XnJSIm4-injeKYZS.mp4"];
    self.player = [[JWPlayerController alloc]initWithConfig:config];
    
    self.title = [NSString stringWithFormat:@"JWP SDK ver: %@", JWPlayerController.SDKVersionToMinor];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    if (self.player.view == nil) { return; }
    
    [self.playerContainerView addSubview:self.player.view];
    [self.player.view constrainToSuperview];
}

@end
