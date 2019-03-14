//
//  ViewController.m
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Max Mikheyenko on 1/7/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import "InitialViewController.h"
#import "JWPlayer_SDK_iOS_Demo-Swift.h"


@interface InitialViewController ()

@property (nonatomic) IBOutlet UIButton *objc;
@property (nonatomic) IBOutlet UIButton *swift;

@end

@implementation InitialViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationItem.title     = @"JW Player iOS SDK";
    
    self.objc.layer.borderColor   = [UIColor whiteColor].CGColor;
    self.objc.layer.borderWidth   = 1;
    self.objc.layer.cornerRadius  = 3;
    self.swift.layer.borderColor  = [UIColor whiteColor].CGColor;
    self.swift.layer.borderWidth  = 1;
    self.swift.layer.cornerRadius = 3;
}

@end
