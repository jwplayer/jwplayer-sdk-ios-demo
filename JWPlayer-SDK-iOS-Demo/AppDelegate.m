//
//  AppDelegate.m
//  JWPlayer-SDK-iOS-Demo
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

    return YES;
}

@end
