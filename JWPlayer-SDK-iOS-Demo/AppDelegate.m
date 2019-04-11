//
//  AppDelegate.m
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Max Mikheyenko on 1/7/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import "AppDelegate.h"
#import <JWPlayer_iOS_SDK/JWPlayerController.h>
#import <AVKit/AVKit.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    NSLog(@"SDK version: %@", JWPlayerController.SDKVersion);
    
    NSError *error;
    [AVAudioSession.sharedInstance setCategory:AVAudioSessionCategoryPlayback mode:AVAudioSessionModeMoviePlayback options:AVAudioSessionCategoryOptionDefaultToSpeaker error:&error];
    if (error) { NSLog(@"\nERROR setting AVAudioSession category:\n%@", error.localizedDescription); }
    [AVAudioSession.sharedInstance setActive:YES error:&error];
    if (error) { NSLog(@"\nERROR activating AVAudioSession:\n%@", error.localizedDescription); }
    
    if (AVAudioSession.sharedInstance.category == AVAudioSessionCategoryPlayback) {
        NSLog(@"\n *** AVAudioSession's category is: Playback");
    }
    if (AVAudioSession.sharedInstance.mode == AVAudioSessionModeMoviePlayback) {
        NSLog(@"\n *** AVAudioSession's mode is: MoviePlayback");
    }

    return YES;
}

@end
