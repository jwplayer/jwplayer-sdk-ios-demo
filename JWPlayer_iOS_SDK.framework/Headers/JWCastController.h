//
//  JWCastController.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 12/3/15.
//  Copyright © 2015 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JWCastingDelegate.h"
#import "JWCastingDevice.h"

NS_ASSUME_NONNULL_BEGIN
@class JWPlayerController;

/**
 Controller for enabling casting using the `JWPlayerController`.
 */
@interface JWCastController : NSObject

/**
 Player instance.
 @note the instance of `JWPlayerController` in use.
 */
@property (nonatomic, weak) JWPlayerController *player;

/**
 Chromecast Application ID of the receiver application to which you wish to cast.
 @note Set this property to a receiver's Application ID before scanning for devices in order to restrict the scan to Chromecast devices that support the receiver. Leaving this value nil results in scanning for all Chromecast devices.
 */
@property (nonatomic, copy) NSString *chromeCastReceiverAppID;

/**
 Delegate of the `JWCastController`.
 @note Delegate must adopt the `JWCastingDelegate protocol`. The delegate is not retained.
 */
@property (nonatomic, nullable, weak) id<JWCastingDelegate> delegate;

/**
 Casting device currently connected to the player.
 @note Set to nil if not connected to any casting devices.
 */
@property (nonatomic, nullable, readonly) JWCastingDevice *connectedDevice;

/**
 List of casting devices that are currently online.
 @note `scanForDevices` must be called in order to start listening for devices.
 */
@property (nonatomic, readonly) NSArray <JWCastingDevice *> *availableDevices;

- (instancetype)init NS_UNAVAILABLE;

/**
 Initialize the controller with a player.
 @param player `JWPlayerController` object currently in use.
 */
- (instancetype)initWithPlayer:(JWPlayerController *)player NS_DESIGNATED_INITIALIZER;

/**
 Scans for casting devices.
 @see `chromeCastReceiverAppID`.
 */
- (void)scanForDevices;

/**
 Connects the `castController` to a casting device.
 @param device The casting device to which the user would like to cast. A list of available devices can be obtained from the availableDevices property.
 @see `availableDevices`.
 @see `JWCastingDevice`.
 */
- (void)connectToDevice:(JWCastingDevice *)device;

/**
 Disconnects the `castController` from the connected casting device.
 */
- (void)disconnect;

/**
 Casts the file being currently reproduced by the linked `JWPlayerController` instance.
 @note You must be connected to a casting device in order to cast.
 */
- (void)cast;

/**
 Stops the casting and resumes on the `JWPlayerController` instance when the cast reproduction left off.
 @note Calling this method does not disconnect from the casting device.
 */
- (void)stopCasting;

@end
NS_ASSUME_NONNULL_END
