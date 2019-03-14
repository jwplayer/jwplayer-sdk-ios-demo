//
//  ObjCViewController.m
//  JWPlayer-SDK-iOS-Demo
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

#import "ObjCViewController.h"
#import "JWPlayer_SDK_iOS_Demo-Swift.h"

@interface ObjCViewController ()
    
@property (strong, nonatomic) SwiftObjcViewModel *viewModel;
    
@property (weak, nonatomic) IBOutlet UITextView *callbacksTextView;
@property (weak, nonatomic) IBOutlet UITextView *callbacksDetailsTextView;
@property (weak, nonatomic) IBOutlet UIView *playerContainerView;

@end

@implementation ObjCViewController

    
- (void)viewDidLoad {
    self.viewModel = SwiftObjcViewModel.shared;
    
    self.viewModel.outputTextView = self.callbacksTextView;
    self.viewModel.outputDetailsTextView = self.callbacksDetailsTextView;
}
    
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self layoutPlayerView:self.viewModel.player.view];
}

    - (void)viewWillDisappear:(BOOL)animated
    {
        [self.viewModel.player pause];
        [super viewWillDisappear:animated];
    }

- (void)layoutPlayerView:(UIView *)playerView
{
    [self.playerContainerView addSubview:playerView];
    playerView.frame = self.playerContainerView.bounds;
    playerView.autoresizingMask = UIViewAutoresizingFlexibleWidth & UIViewAutoresizingFlexibleHeight;
}
    
- (IBAction)outputToggleTapped:(UISwitch *)sender {
    [self.view bringSubviewToFront:
     (sender.isOn ? self.callbacksDetailsTextView : self.callbacksTextView)];
}
    

    
@end
