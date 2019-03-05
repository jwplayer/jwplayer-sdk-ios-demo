//
//  ViewController.m
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Max Mikheyenko on 1/7/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import "ViewController.h"
#import "JWPlayer_Developer_Guide-Swift.h"

@interface ViewController ()

@property (nonatomic) IBOutlet UIButton *objc;
@property (nonatomic) IBOutlet UIButton *swift;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationItem.title = @"JW Player iOS SDK";
    
    self.objc.layer.borderColor = [UIColor whiteColor].CGColor;
    self.objc.layer.borderWidth = 1;
    self.objc.layer.cornerRadius = 3;
    self.swift.layer.borderColor = [UIColor whiteColor].CGColor;
    self.swift.layer.borderWidth = 1;
    self.swift.layer.cornerRadius = 3;
}

@end
