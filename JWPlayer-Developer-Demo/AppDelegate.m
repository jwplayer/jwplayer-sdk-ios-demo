//
//  AppDelegate.m
//  JWPlayer-Developer-Demo
//
//  Created by Max Mikheyenko on 1/7/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import "AppDelegate.h"
#import <JWPlayer_iOS_SDK/JWPlayerController.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    NSLog(@"SDK version: %@", JWPlayerController.SDKVersion);
    
    NSError *error;
    [[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryPlayback                                                             withOptions:AVAudioSessionCategoryOptionMixWithOthers error:&error];
    
    [[AVAudioSession sharedInstance]setActive:YES error:&error];
    
    if (error) {
        NSLog(@"** ERROR: %@", error.localizedDescription);
    }
    
    return YES;
}

@end
