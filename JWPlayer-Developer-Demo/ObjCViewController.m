//
//  ObjCViewController.m
//  JWPlayer-Developer-Guide
//
//  Created by Amitai Blickstein on 2/26/19.
//  Copyright © 2019 JWPlayer. All rights reserved.
//

#import "ObjCViewController.h"
#import "JWPlayer_Developer_Guide-Swift.h"

@interface ObjCViewController ()

@property (strong, nonatomic) SwiftObjcViewModel *viewModel;
@property (weak, nonatomic) IBOutlet UITextView *callbacksTextView;
@property (weak, nonatomic) IBOutlet UITextView *callbacksDetailsTextView;
@property (weak, nonatomic) IBOutlet UIView *playerContainerView;

@end

@implementation ObjCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
}

- (void)viewDidAppear:(BOOL)animated
{
    
}

- (void)layout:(UIView *)playerView
{
    [self.playerContainerView addSubview:playerView];
    playerView.frame = self.playerContainerView.bounds;
    playerView.autoresizingMask = UIViewAutoresizingFlexibleWidth & UIViewAutoresizingFlexibleHeight;
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
