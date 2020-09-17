//
//  FWPlayerConfiguration.h
//  AdManager
//
//  Created by Elijah Valenciano on 4/3/19.
//  Copyright © 2019 FreeWheel Media Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 	A class used for configuring the player settings
 
 	See also `-[FWRequestConfiguration setPlayerConfiguration:]`
 */
@interface FWPlayerConfiguration : NSObject

/**
 	Parse XML response on background thread instead of the main thread
 */
@property (nonatomic) BOOL parseResponseOnBackgroundThread;

@end
