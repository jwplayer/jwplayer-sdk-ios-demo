//
//  JWButton.h
//  JWPlayer-iOS-SDK
//
//  Created by karim on 1/7/20.
//  Copyright © 2020 JWPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class JWButton;

/**
 The JWButtonDelegate protocol defines methods that a delegate of a JWButton object can implement to be aware when the JWButton is interacted with.
 */
@protocol JWButtonDelegate <NSObject>

@required

/**
 Called when the JWButton is interacted with by the viewer.
 */
- (void)onButtonTouched:(JWButton *)button;

@end

/**
 An object containing the necessary information required to create a custom control bar button.
 @note Buttons are added to the control bar using the JWPlayerController's addButton method.
 @see JWPlayerController
 */
@interface JWButton : NSObject

/**
 The content of an SVG in string, used as the button icon.
 @note We recommend using this property instead of imageUrl because it ensure the control bar's style applies to your button.
 */
@property (nonatomic, nullable, readonly, copy) NSString *svgContent;

/**
 The URL of the image that will be used as the button icon. Can be a local or external path.
 @note Monochromatic, white icons of 24x24 pixels work well.
 */
@property (nonatomic, nullable, readonly, copy) NSString *imageUrl;

/**
 The button's name announced by voice over and accessibility readers.
 */
@property (nonatomic, readonly, copy) NSString *accessibilityLabel;

/**
 The button's delegate who will be notified when the viewer interacts with the button.
 @note Must conform to the JWButtonDelegate protocol.
 */
@property (nonatomic, nullable, weak) id<JWButtonDelegate> delegate;

/**
 The id used when styling your button using CSS.
 @note Must be unique across all buttons.
 @see JWSkinStyling
 */
@property (nonatomic, nullable, readonly, copy) NSString *cssId;

/**
 The class used when styling your button using CSS.
 @see JWSkinStyling
 */
@property (nonatomic, nullable, readonly, copy) NSString *cssClass;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)buttonWithSvgContent:(NSString *)svgContent
                  accessibilityLabel:(NSString *)accessibilityLabel
                               cssId:(NSString *_Nullable)cssId
                            cssClass:(NSString *_Nullable)cssClass;

- (instancetype)initWithSvgContent:(NSString *)svgContent
                accessibilityLabel:(NSString *)accessibilityLabel
                             cssId:(NSString *_Nullable)cssId
                          cssClass:(NSString *_Nullable)cssClass;

+ (instancetype)buttonWithImageUrl:(NSString *)imageUrl
                accessibilityLabel:(NSString *)accessibilityLabel
                             cssId:(NSString *_Nullable)cssId
                          cssClass:(NSString *_Nullable)cssClass;

- (instancetype)initWithImageUrl:(NSString *)imageUrl
              accessibilityLabel:(NSString *)accessibilityLabel
                           cssId:(NSString *_Nullable)cssId
                        cssClass:(NSString *_Nullable)cssClass;

@end

NS_ASSUME_NONNULL_END
