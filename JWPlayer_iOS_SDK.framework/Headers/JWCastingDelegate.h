//
//  JWCastingDelegate.h
//  JWPlayer-iOS-SDK
//
//  Created by Karim Mourra on 12/4/15.
//  Copyright © 2015 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class JWCastingDevice;

/**
 The JWCastingDelegate protocol defines methods that a delegate of a JWCastController object can optionally implement to receive callbacks from the casting device.
 @see JWCastController.
 */
@protocol JWCastingDelegate <NSObject>

/**
 Called whenever a casting device comes online. Note: scanForDevices must be called by the JWCastController object in order to start listening for devices.
 @param devices List of casting devices that are currently online.
 @see JWCastingDevice.
 */
- (void)onCastingDevicesAvailable:(NSArray <JWCastingDevice *> *)devices;

@optional

/**
 Called when a successful connection to a casting device is made.
 @param device The casting device to which the castController is connected to.
 @see JWCastingDevice.
 */
- (void)onConnectedToCastingDevice:(JWCastingDevice *)device;

/**
 Called when the castController is disconnected from the castDevice.
 @param error Object containing the error message under property localizedDescription. Value will be nil if disconnection was purposeful.
 */
- (void)onDisconnectedFromCastingDevice:(nullable NSError *)error;

/**
 Called when the connected casting device is temporarily disconnected. Video resumes on the mobile device until connection resumes.
 */
- (void)onConnectionTemporarilySuspended;

/**
 Called after connection is reestablished following a temporary disconnection. Video resumes on the casting device.
 */
- (void)onConnectionRecovered;

/**
 Called when an attempt to connect to a casting device is unsuccessful.
 @param error Object containing the error message under property localizedDescription.
 */
- (void)onConnectionFailed:(NSError *)error;

/**
 Called when casting session begins.
 */
- (void)onCasting;

/**
 Called when an attempt to cast to a casting device is unsuccessful.
 @param error Object containing the error message under property localizedDescription.
 */
- (void)onCastingFailed:(NSError *)error;

/**
 Called when casting session ends. Note: Application might still be connected to the casting device.
 @param error Object containing the error message under property localizedDescription. Can be nil if casting ended intentionally.
 */
- (void)onCastingEnded:(nullable NSError *)error;

@end
NS_ASSUME_NONNULL_END
