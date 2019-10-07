//
//  JWConfig+PrivateContent.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 5/4/15.
//  Copyright (c) 2015 JWPlayer. All rights reserved.
//

#import "JWConfig.h"
#import "JWSideLoadedPlayerJs.h"

@interface JWConfig (PrivateContent)

@property (nonatomic) NSString *xmlAdvertising;
@property (nonatomic) NSArray *tracksList;
@property (nonatomic) NSArray *xmlPlayList;
@property (nonatomic) NSString *xmlStretching;
@property (nonatomic) NSDictionary *xmlCaptions;
@property (nonatomic) NSDictionary *xmlRelated;

@end
