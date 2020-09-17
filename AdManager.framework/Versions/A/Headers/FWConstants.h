/**
 Constants in FreeWheel AdManager SDK
 */

#import <Foundation/NSObjCRuntime.h>

#ifndef FW_EXTERN
#ifdef __cplusplus
#define FW_EXTERN			extern "C"
#define FW_PRIVATE_EXTERN   FW_EXTERN __attribute__((visibility("hidden")))
#else
#define FW_EXTERN			extern
#define FW_PRIVATE_EXTERN   FW_EXTERN __attribute__((visibility("hidden")))
#endif

#define FW_LINK_RENDERER(r) \
@class r; \
@interface r : NSObject { \
} \
@end; \
extern void FWAdManager_Force_Link_##r (void) __attribute__ ((constructor)); \
void FWAdManager_Force_Link_##r (void) { \
@autoreleasepool{ \
NSLog(@"AdManager: registering renderer class: %@", [r description]); \
} \
}

#endif

#pragma mark - Enums

/**
	Enumeration of FreeWheel log levels
	
	- See: `FWSetLogLevel`
 */
typedef NS_ENUM(NSUInteger, FWLogLevel) {
	/** Log nothing */
	FWLogLevelQuiet = 0,
	/** Log something, default log level */
	FWLogLevelInfo = 3,
	/** Log everything */
	FWLogLevelVerbose = 5,
};

/**
	Enumeration of non-temporal slot ad initial options
 
	- See: 
		- <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)addSiteSectionNonTemporalSlot:adUnit:width:height:slotProfile:acceptCompanion:initialAdOption:acceptPrimaryContentType:acceptContentType:compatibleDimensions:">-addSiteSectionNonTemporalSlot:adUnit:width:height:slotProfile:acceptCompanion:initialAdOption:acceptPrimaryContentType:acceptContentType:compatibleDimensions:</a> of `FWContext`
		- <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)addVideoPlayerNonTemporalSlot:adUnit:width:height:slotProfile:acceptCompanion:initialAdOption:acceptPrimaryContentType:acceptContentType:compatibleDimensions:">-addVideoPlayerNonTemporalSlot:adUnit:width:height:slotProfile:acceptCompanion:initialAdOption:acceptPrimaryContentType:acceptContentType:compatibleDimensions:</a> of `FWContext`
 */
typedef NS_ENUM(NSUInteger, FWSlotInitialAdOption) {
	/** Display an ad in the non-temporal slot */
	FWSlotInitialAdOptionStandAlone = 0,
	
	/** Keep the original ad in the non-temporal slot */
	FWSlotInitialAdOptionKeepOriginal = 1,
	
	/** Use the non-temporal ad in the first companion ad package */
	FWSlotInitialAdOptionFirstCompanionOnly = 2,

	/** Either FWSlotInitialAdOptionFirstCompanionOnly or FWSlotInitialAdOptionStandAlone  */
	FWSlotInitialAdOptionFirstCompanionOrStandAlone = 3,

	/** Fill this slot with the first companion ad, or display a new stand alone ad if there is no companion ad */
	FWSlotInitialAdOptionFirstCompanionThenStandAlone = 4,

	/** Fill this slot with the first companion ad, but never deliver a standalone ad if there is no companion ad */
	FWSlotInitialAdOptionFirstCompanionOrNoStandAlone = 5,

	/** Fill this slot only with the PREROLL slot’s companion ad if there is one */
	FWSlotInitialAdOptionNoStandAlone = 6,
	
	/** Fill this slot with a standalone ad only when no temporal ad will be delivered, if there is any temporal ad selected, let this slot stay unfilled */
	FWSlotInitialAdOptionNoStandAloneIfTemporal = 7,
	
	/** Fill this slot with a stand alone ad only when no temporal ad will be delivered, if there is any temporal ad selected, let this slot stay unfilled; however if there is companion, can use this companion to initialize this slot */
	FWSlotInitialAdOptionFirstCompanionOrNoStandAloneIfTemporal = 8
};

/**
	Enumeration of capability status
 
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
typedef NS_ENUM(NSInteger, FWCapabilityStatus) {
	/** Capability status is off */
	FWCapabilityStatusOff = 0,
	
	/** Capability status is on */
	FWCapabilityStatusOn = 1,
	
	/** Default capability status. The default value can be either on or off for each individual capability. */
	FWCapabilityStatusDefault = -1
};

/**
	Enumeration of id types
 
	- See: 
		- <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setVideoAssetId:idType:duration:durationType:location:autoPlayType:videoPlayRandom:networkId:fallbackId:">-setVideoAssetId:idType:duration:durationType:location:autoPlayType:videoPlayRandom:networkId:fallbackId:</a> of `FWContext`
		- <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setSiteSectionId:idType:pageViewRandom:networkId:fallbackId:">-setSiteSectionId:idType:pageViewRandom:networkId:fallbackId:</a> of `FWContext`
 */
typedef NS_ENUM(NSUInteger, FWIdType) {
	/** Custom id provided by non-FreeWheel parties */
	FWIdTypeCustom = 0,
	
	/** Unique id provided by FreeWheel */
	FWIdTypeFreeWheel = 1,
	
	/** Unique group id provided by FreeWheel */
	FWIdTypeFreeWheelGroup = 2
};

/**
	Enumeration of current video states
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setVideoState:">-setVideoState:</a> of `FWContext`
 */
typedef NS_ENUM(NSUInteger, FWVideoState) {
	/** Current video is playing */
	FWVideoStatePlaying = 1,
	
	/** Current video is paused */
	FWVideoStatePaused = 2,
	
	/** Current video is stopped */
	FWVideoStateStopped = 3,
	
	/** Current video is completed */
	FWVideoStateCompleted = 4
};

/**
	Enumeration of time position classes
 
	- See:
		- <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)getSlotsByTimePositionClass:">-getSlotsByTimePositionClass:</a> of `FWContext`
		- <a href="Protocols/FWSlot.html#/c:objc(pl)FWSlot(im)timePositionClass">-timePositionClass</a> of `FWSlot`
 */
typedef NS_ENUM(NSUInteger, FWTimePositionClass) {
	/** Time position class type: preroll */
	FWTimePositionClassPreroll = 1,
	
	/** Time position class type: midroll */
	FWTimePositionClassMidroll = 2,
	
	/** Time position class type: postroll */
	FWTimePositionClassPostroll = 3,
	
	/** Time position class type: overlay */
	FWTimePositionClassOverlay = 4,
	
	/** Time position class type: display */
	FWTimePositionClassDisplay = 5,
	
	/** Time position class type: pause_midroll */
	FWTimePositionClassPauseMidroll = 6
};

/**
	Enumeration of slot types
 
	- See: <a href="Protocols/FWSlot.html#/c:objc(pl)FWSlot(im)type">-type</a> of `FWSlot`
 */
typedef NS_ENUM(NSUInteger, FWSlotType) {
	/** Type of slot: temporal slot */
	FWSlotTypeTemporal = 1,
	
	/** Type of slot: non-temporal slot in site section */
	FWSlotTypeSiteSectionNonTemporal = 3,
	
	/*!
	 @internal
	 */
	FWSlotTypeVideoPlayerNonTemporal DEPRECATED_MSG_ATTRIBUTE("Use FWSlotTypeSiteSectionNonTemporal instead") = 2
};

/**
	Enumeration of parameter level
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setParameter:withValue:forLevel:">-setParameter:withValue:forLevel:</a> of `FWContext`
 */
typedef NS_ENUM(NSUInteger, FWParameterLevel) {
	/** profile level param */
	FWParameterLevelProfile = 0,
	
	/** global level param */
	FWParameterLevelGlobal = 1,
	
	/** slot level param */
	FWParameterLevelSlot = 2,
	
	/** creative level param */
	FWParameterLevelCreative = 3,
	
	/** rendition level param */
	FWParameterLevelRendition = 4,
	
	/** override level param, highest priority */
	FWParameterLevelOverride = 5
};

/**
	Enumeration of FWRendererState types
 
	- See: <a href="Protocols/FWRendererController.html#/c:objc(pl)FWRendererController(im)handleStateTransition:info:">-handleStateTransition:info:</a> of `FWRendererController`
 */
typedef NS_ENUM(NSUInteger, FWRendererStateType) {
	/** Renderer State: Preloaded. Renderer should transit to this state as soon as it finishes preloading. */
	FWRendererStatePreloaded = 2,
	/** Renderer State: Started. Renderer should transit to this state as soon as it starts. */
	FWRendererStateStarted = 3,
	/** Renderer State: Completed. Renderer should transit to this state when it has completed all its workflow and ready to be destroyed. */
	FWRendererStateCompleted = 5,
	/** Renderer State: Failed. Renderer should transit to this state when the workflow is interrupted due to some errors. */
	FWRendererStateFailed = 6
};

/**
	Enumeration of RequestMode types
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setRequestMode:">-setRequestMode:</a> of `FWContext`
 */
typedef NS_ENUM(NSUInteger, FWRequestMode) {
	/** Request Mode: On demand */
	FWRequestModeOnDemand,
	/** Request Mode: Live */
	FWRequestModeLive
};

/**
	Enumeration of video asset duration types. 
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setVideoAssetId:idType:duration:durationType:location:autoPlayType:videoPlayRandom:networkId:fallbackId:">-setVideoAssetId:idType:duration:durationType:location:autoPlayType:videoPlayRandom:networkId:fallbackId:</a> of `FWContext`
 */
typedef NS_ENUM(NSUInteger, FWVideoAssetDurationType) {
	/** Video asset duration type: Exact. This value should be used for video asset whose exact duration is known. */
	FWVideoAssetDurationTypeExact,
	
	/** Video asset duration type: Variable. This value should be used for live stream video asset whose exact duration is not available. */
	FWVideoAssetDurationTypeVariable
};

/**
	Enumeration of video asset auto play types
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setVideoAssetId:idType:duration:durationType:location:autoPlayType:videoPlayRandom:networkId:fallbackId:">-setVideoAssetId:idType:duration:durationType:location:autoPlayType:videoPlayRandom:networkId:fallbackId:</a> of `FWContext`
 */
typedef NS_ENUM(NSUInteger, FWVideoAssetAutoPlayType) {
	/** Video asset auto play type: None */
	FWVideoAssetAutoPlayTypeNone = 0,
	
	/** Video asset auto play type: Attended*/
	FWVideoAssetAutoPlayTypeAttended = 1,
	
	/** Video asset auto play type: Unattended */
	FWVideoAssetAutoPlayTypeUnattended = 2
};

/**
	Enumeration of user actions. 
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)notifyUserAction:">-notifyUserAction:</a> of `FWContext`
 	- See: <a href="Protocols/FWStreamStitcherContext.html#/c:objc(pl)FWStreamStitcherContext(im)notifyUserAction:">-notifyUserAction:</a> of `FWStreamStitcherContext`
 */
typedef NS_ENUM(NSUInteger, FWUserAction) {
	/** User action: video player's pause button is clicked */
	FWUserActionPauseButtonClicked,
	
	/** User action: video player's resume button is clicked */
	FWUserActionResumeButtonClicked,

	/** User action: airplay is activated */
	FWUserActionActivateAirPlay,

	/** User action: airplay is deactivated */
	FWUserActionDeactivateAirPlay,
	
	/** User action: the video ad is clicked by the user. Used only in Stream Stitcher integrations. */
	FWUserActionClick,
	
	/** User action: the video ad is seeked by the user. Used only in Stream Stitcher integrations. */
	FWUserActionSeek
};

/**
	Enumeration of module types.
 */
typedef NS_ENUM(NSUInteger, FWModuleType) {
	/** Module type: renderer */
	FWModuleTypeRenderer,
	/** Module type: translator */
	FWModuleTypeTranslator
};

/**
	Enumeration for defining the applicability of user consent.
 
 	- See: `FWGDPRConsentConfiguration`
 */
typedef NS_ENUM(NSUInteger, FWConsentApplicable) {
	FWConsentIsApplicable = 1,
	FWConsentNotApplicable = 0,
};

#pragma mark - Notifications

/**
	Notification broadcast when ad request has been initiated.
 
 */
FW_EXTERN NSString *const FWRequestInitiatedNotification;

/**
	Notification broadcast when ad request has completed.
	`object` is the FWContext instance used to send the request;

	Check `userInfo` with `FWInfoKeyError` for errors; will get `nil` if request has been successful.
 */
FW_EXTERN NSString *const FWRequestCompleteNotification;

/**
	Notification broadcast when a slot has finished preloading.
	Check `userInfo` with `FWInfoKeySlotCustomId` for the slot's custom ID.
 
	- SeeAlso: 
		- `FWSlotStartedNotification`
		- `FWSlotEndedNotification`
 */
FW_EXTERN NSString *const FWSlotPreloadedNotification;

/**
	Notification broadcast when a slot has started.
	Check `userInfo` with `FWInfoKeySlotCustomId` for the slot's custom ID.
 
	- SeeAlso:
		- `FWSlotPreloadedNotification`
		- `FWSlotEndedNotification`
 */
FW_EXTERN NSString *const FWSlotStartedNotification;

/**
 	Notification broadcast when a slot has ended.
 	Check userInfo with FWInfoKeySlotCustomId for the slot's custom ID.

	- SeeAlso:
		- `FWSlotStartedNotification`
		- `FWSlotPreloadedNotification`
 */
FW_EXTERN NSString *const FWSlotEndedNotification;

/**
	Notification broadcast when inAppView is opened.
 
	- SeeAlso:
		- `FWInAppViewDidCloseNotification`
		- `FWInAppViewWillOpenMediaDocumentNotification`
 */
FW_EXTERN NSString *const FWInAppViewDidOpenNotification;

/**
	Notification broadcast when inAppView is closed.

	- SeeAlso: 
		- `FWInAppViewDidOpenNotification`
		- `FWInAppViewWillOpenMediaDocumentNotification`
 */
FW_EXTERN NSString *const FWInAppViewDidCloseNotification;

/**
	Notification broadcast when inAppView will open a media document from URI.

	- SeeAlso:
		- `FWInAppViewDidOpenNotification`
		- `FWInAppViewDidCloseNotification`
 */
FW_EXTERN NSString *const FWInAppViewWillOpenMediaDocumentNotification;

/**
	Notification broadcast when AdManager needs your content video player to pause.
	It could be due to a midroll slot being about to start, or when the user taps on an ad that needs to interrupt the main video.

	You can query `userInfo` with `FWInfoKeySlotCustomId` to find out the slot that has caused the interruption.

	- SeeAlso: `FWContentResumeRequestNotification`
 */
FW_EXTERN NSString *const FWContentPauseRequestNotification;

/**
	Notification broadcast when AdManager needs your content video player to resume.
	It could be due to a midroll slot has ended, or an interruptive ad has been closed.
 
	You can query `userInfo` with `FWInfoKeySlotCustomId` to find out the slot that has caused the interruption.
 
	- SeeAlso: `FWContentPauseRequestNotification`
*/
FW_EXTERN NSString *const FWContentResumeRequestNotification;

/**
	Notification broadcast when a user action occurs.
	Query `userInfo` with `FW_INFO_KEY_USER_ACTION` to find out the user action type.
 
	- SeeAlso: `FWUserAction`
*/
FW_EXTERN NSString *const FWUserActionNotification;

/**
	Notification broadcast when an ad event occurs. An ad event will trigger a corresponding event callback request to FreeWheel ad server. For example, when an ad starts, a `FWAdEventNotification` with event name `FWAdImpressionEvent` will be broadcast, the corresponding impression beacon will fire at the same time.

	`userInfo` payloads:

	- `FWInfoKeyAdEventName`: Name of the event, see `FWAd*Event`
	- `FWInfoKeySlot`: Corresponding slot
	- `FWInfoKeyAdInstance`: Corresponding ad instance
 
	- SeeAlso: 
		- <a href="Protocols/FWAdInstance.html#/c:objc(pl)FWAdInstance(im)getEventCallbackUrlsByEventName:eventType:">-getEventCallbackUrlsByEventName:eventType:</a>
		- <a href="Protocols/FWAdInstance.html#/c:objc(pl)FWAdInstance(im)setEventCallbackUrls:forEventName:eventType:">-setEventCallbackUrls:forEventName:eventType:</a>
		- `FWEventType*`
 */
FW_EXTERN NSString *const FWAdEventNotification;

/**
	Notification broadcast when the video display base is changed.
	`userInfo` payload:
		
	- `FWInfoKeyVideoDisplayBase`: the new video display base UIView.
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)setVideoDisplayBase:">-setVideoDisplayBase:</a> of `FWContext`
 */
FW_EXTERN NSString *const FWVideoDisplayBaseDidChangeNotification;

/**
	Notification broadcast when the video display's frame has been changed.
	`userInfo` payload:
 
	- `FWInfoKeyVideoDisplayBase`: the new video display base `UIView`.
 */
FW_EXTERN NSString *const FWVideoDisplayBaseFrameDidChangeNotification;

/**
	Notification broadcast when an extension is loaded.
	If `notification.userInfo` has key `FWInfoKeyError`, the extension has failed to load with an error message.
 */
FW_EXTERN NSString *const FWExtensionLoadedNotification;

/**
	Notification broadcast when the user presses Apple Remote's Menu button while an ad is AirPlaying.
	
	- Remark: Player/App should pause the current playing slot with `[slot pause]`, and provide a way to resume the ad playback using `[slot resume]`, for example, draw a play button on top of the paused ad.
 */
FW_EXTERN NSString *const FWExternalPlaybackInterruptedNotification;

#pragma mark - Ad Units

/**
	Ad unit: Preroll
 
	- See: <a href="Protocols/FWContext.html#/c:objc(pl)FWContext(im)addTemporalSlot:adUnit:timePosition:slotProfile:cuePointSequence:minDuration:maxDuration:acceptPrimaryContentType:acceptContentType:">-addTemporalSlot:adUnit:timePosition:slotProfile:cuePointSequence:minDuration:maxDuration:acceptPrimaryContentType:acceptContentType:</a>

	- SeeAlso:
		- `FWAdUnitMidroll`
		- `FWAdUnitPostroll`
		- `FWAdUnitOverlay`
		- `FWAdUnitStreamPreroll`
		- `FWAdUnitStreamPostroll`
		- `FWAdUnitPauseMidroll`
 */
FW_EXTERN NSString *const FWAdUnitPreroll;

/**
	Ad unit: Midroll

	- SeeAlso:
		- `FWAdUnitPreroll`
		- `FWAdUnitPostroll`
		- `FWAdUnitOverlay`
		- `FWAdUnitStreamPreroll`
		- `FWAdUnitStreamPostroll`
		- `FWAdUnitPauseMidroll`
 */
FW_EXTERN NSString *const FWAdUnitMidroll;

/**
	Ad unit: Postroll

	- SeeAlso:
		- `FWAdUnitPreroll`
		- `FWAdUnitMidroll`
		- `FWAdUnitOverlay`
		- `FWAdUnitStreamPreroll`
		- `FWAdUnitStreamPostroll`
		- `FWAdUnitPauseMidroll`
 */
FW_EXTERN NSString *const FWAdUnitPostroll;

/**
	Ad unit: Overlay

	- SeeAlso:
		- `FWAdUnitPreroll`
		- `FWAdUnitMidroll`
		- `FWAdUnitPostroll`
		- `FWAdUnitStreamPreroll`
		- `FWAdUnitStreamPostroll`
		- `FWAdUnitPauseMidroll`
 */
FW_EXTERN NSString *const FWAdUnitOverlay;


/**
	Ad unit: Pause-Midroll
 
	- SeeAlso:
		- `FWAdUnitPreroll`
		- `FWAdUnitMidroll`
		- `FWAdUnitPostroll`
		- `FWAdUnitOverlay`
		- `FWAdUnitStreamPreroll`
		- `FWAdUnitStreamPostroll`
 */
FW_EXTERN NSString *const FWAdUnitPauseMidroll;

/**
	Ad unit: Stream Preroll
 
	- SeeAlso:
		- `FWAdUnitPreroll`
		- `FWAdUnitMidroll`
		- `FWAdUnitPostroll`
		- `FWAdUnitOverlay`
		- `FWAdUnitStreamPostroll`
		- `FWAdUnitPauseMidroll`
 */
FW_EXTERN NSString *const FWAdUnitStreamPreroll;

/**
	Ad unit: Stream Postroll

	- SeeAlso:
		- `FWAdUnitPreroll`
		- `FWAdUnitMidroll`
		- `FWAdUnitPostroll`
		- `FWAdUnitOverlay`
		- `FWAdUnitStreamPreroll`
		- `FWAdUnitPauseMidroll`
 */
FW_EXTERN NSString *const FWAdUnitStreamPostroll;

#pragma mark - Capabilities

/**
	Capability: Player expects template-based slots generated by ad server.

	- Default: On (`FWCapabilityStatusOn`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilitySlotTemplate;

/**
	Capability: Ad unit in multiple slots.

	- Default: On (`FWCapabilityStatusOn`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityAdUnitInMultipleSlots;

/**
	Capability: Bypass commercial ratio restriction.

	- Default: Off (`FWCapabilityStatusOff`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityBypassCommercialRatioRestriction;

/**
	Capability: Player expects ad server to check companion for candidate ads.

	- Default: On (`FWCapabilityStatusOn`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityCheckCompanion;

/**
	Capability: Player expects ad server to check targeting for candidate ads.

	- Default: On (`FWCapabilityStatusOn`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityCheckTargeting;

/**
	Capability: Implicitly record video view.

	- Default: Off (`FWCapabilityStatusOff`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityRecordVideoView;

/**
	Capability: Player expects ad server synchronize the request state between multiple requests.

	- Default: Off (`FWCapabilityStatusOff`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilitySyncMultipleRequests;

/**
	Capability: Reset the exclusivity scope. Player can turn on/off this capability before making any request.

	- Default: Off (`FWCapabilityStatusOff`)
	- Note: Once the capability is turned on, all subsequent requests will all carry this capability and reset the exclusivity scope until it's turned off again.
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityResetExclusivity;

/**
	Capability: Player expects the ad server to return fallback alternatives for every ad delivered if possible.

	- Default: On (`FWCapabilityStatusOn`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityFallbackAds;

/**
	Capability: Player expects multiple creative renditions for an ad.
 
	- Default: On (`FWCapabilityStatusOn`)
	- See: <a href="Classes/FWRequestConfiguration.html#/c:objc(cs)FWRequestConfiguration(im)setStatus:forCapability:">-setStatus:forCapability:</a> of `FWRequestConfiguration`
 */
FW_EXTERN NSString *const FWCapabilityMultipleCreativeRenditions;

#pragma mark - Ad Events

/**
	FWAdPreInitEvent is dispatched when an AdInstance has started either playback attempt or preloading in background, whichever comes first.

	Please note, PreInit is not dispatched when replaying a slot (or the adInstance in it). Also, multiple PreInit's will be dispatched when unwrapping multiple wrappers of VAST

	See: `FWAdEventNotification`
*/
FW_EXTERN NSString *const FWAdPreInitEvent;

/**
	Ad event: ad impression. Ad starts.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdImpressionEvent;

/**
	Ad event: ad end impression. Ad ends.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdImpressionEndEvent;


FW_EXTERN NSString *const FWAdQuartileEvent;

/**
	Ad event: first quartile. Ad progress reaches 25%.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdFirstQuartileEvent;

/**
	Ad event: mid point. Ad progress reaches 50%.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdMidpointEvent;

/**
	Ad event: third quartile. Ad progress reaches 75%.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdThirdQuartileEvent;

/**
	Ad event: complete. Ad progress reaches 100%.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdCompleteEvent;

/**
	Ad event: click. Ad is clicked.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdClickEvent;

/**
	Ad event: mute. Ad is muted.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdMuteEvent;

/**
	Ad event: unmute. Ad is unmuted.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdUnmuteEvent;

/**
	Ad event: volume changed. Ad volume is changed.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdVolumeChangedEvent;

/**
	Ad event: collapse. Ad is collapsed.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdCollapseEvent;

/**
	Ad event: expand. Ad is expanded.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdExpandEvent;

/**
	Ad event: pause. Ad is paused.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdPauseEvent;

/**
	Ad event: resume. Ad is resumed.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdResumeEvent;

/**
	Ad event: rewind. Ad is rewound.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdRewindEvent;

/**
	Ad event: accept invitation. User accepts invitation.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdAcceptInvitationEvent;

/**
	Ad event: close. Ad is closed.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdCloseEvent;

/**
	Ad event: minimize. Ad is minimized.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdMinimizeEvent;

/**
	Ad event: skipped. Ad has been skipped by the user.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdSkippedByUserEvent;

/**
	Ad event: reseller no ad. AdManager fails to get any playable ad from a 3rd party reseller.
 
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdResellerNoAdEvent;

/**
	Ad event: an error has occurred. When an error occurs, a `FWAdEventNotification` will be broadcast with the following `userInfo` payload:
	
	- `FWInfoKeyErrorCode`: Error code, see `FWError*`.
	- `FWInfoKeyErrorInfo`: Error info. Brief description of the error.
	- `FWInfoKeyErrorModule`: The module that reported this error.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWAdErrorEvent;

/**
	Ad event: concrete event (for CPx integrations only)
 
	- See: 
		- `FWAdEventNotification`
		- `FWInfoKeyConcreteEventId`
 */
FW_EXTERN NSString *const FWAdMeasurementEvent;

/*!
	internal use only
 */
FW_EXTERN NSString *const FW_EVENT_ERROR;

/**
	Ad event: Ad buffering has started. Player can use this event to start displaying a buffering animation.

	- See:
		- `FWAdEventNotification`
	- SeeAlso:
		- `FWAdBufferingEndEvent`
 */
FW_EXTERN NSString *const FWAdBufferingStartEvent;

/**
	Ad event: Ad buffering has ended. Player can use this event to remove the buffering animation.

	- See:
		- `FWAdEventNotification`
	- SeeAlso:
		- `FWAdBufferingStartEvent`
 */
FW_EXTERN NSString *const FWAdBufferingEndEvent;

#pragma mark - Ad Event Types

/**
	Event type: Click tracking

	- See: `[FWAdInstance getEventCallbackUrlsByEventName:eventType:]`
	- SeeAlso:
		- `FWEventTypeImpression`
		- `FWEventTypeClick`
		- `FWEventTypeStandard`
		- `FWEventTypeCustom`
 */
FW_EXTERN NSString *const FWEventTypeClickTracking;

/**
	Event type: Impression

	- See: `[FWAdInstance getEventCallbackUrlsByEventName:eventType:]`
	- SeeAlso:
		- `FWEventTypeClickTracking`
		- `FWEventTypeClick`
		- `FWEventTypeStandard`
		- `FWEventTypeCustom`
 */
FW_EXTERN NSString *const FWEventTypeImpression;

/**
	Event type: Click (through)

	- See: `[FWAdInstance getEventCallbackUrlsByEventName:eventType:]`
	- SeeAlso:
		- `FWEventTypeClickTracking`
		- `FWEventTypeImpression`
		- `FWEventTypeStandard`
		- `FWEventTypeCustom`

 */
FW_EXTERN NSString *const FWEventTypeClick;

/**
	Event type: Standard IAB

	- See: `[FWAdInstance getEventCallbackUrlsByEventName:eventType:]`
	- SeeAlso:
		- `FWEventTypeClickTracking`
		- `FWEventTypeImpression`
		- `FWEventTypeClick`
		- `FWEventTypeCustom`
 */
FW_EXTERN NSString *const FWEventTypeStandard;

/**
	Event type: User custom

	- See: `[FWAdInstance getEventCallbackUrlsByEventName:eventType:]`
	- SeeAlso:
		- `FWEventTypeClickTracking`
		- `FWEventTypeImpression`
		- `FWEventTypeClick`
		- `FWEventTypeStandard`
 */
FW_EXTERN NSString *const FWEventTypeCustom;

#pragma mark - Parameters
/**
	Parameter: `NSString` representing the timeout value of playing a video ad in seconds.
 
	Default value: `@"5"`
 
	- Note: When a timeout occurs, a `FWAdEventNotification` with error code `FWErrorTimeout` will be dispatched. The ad will be terminated on this error. 
	- SeeAlso: `FWAdEventNotification`
	- Note: Ad traffickers should use `renderer.video.timeout` instead of `FWParameterVideoAdRendererTimeout` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */

FW_EXTERN NSString *const FWParameterVideoAdRendererTimeout;

/**
	Parameter: Open click through url in inAppView or external app. See <a href="http://hub.freewheel.tv/display/techdocs/iOS+InAppView+Extension" target="_blank">inAppView</a> for more information.
 
	Valid values:
		- `@"YES"`: Open in inAppView (default)
		- `@"NO"`: Open in external app
 
	- Note: Ad traffickers should use `tapOpensInApplication` instead of `FWParameterOpenClickThroughInApp` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterOpenClickThroughInApp;

/**
	Parameter: `NSString` representing the timeout value of loading a url in inAppView in seconds.

	Default value: `@"3"`

	- Note: After the timeout, inAppView's close button will be enabled which allows the user to close the inAppView.
	- Note: Ad traffickers should use `loadTimeOutSecond` instead of `FWParameterInAppViewLoadingTimeout` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterInAppViewLoadingTimeout;

/**
	Parameter: inAppView navigation bar HTML.
	The value of the parameter is a HTML snippet that renders a toolbar inside the inAppView. The toolbar HTML snippet should contain a back button, a forward button and a close button.
	
	For example:
	```<div><img id="FW_IN_APP_VIEW_CONTROL_BAR_BACK_BUTTON"  src="data:image/png;base64,PNG_BASE64_STRING" width="" height=""/><img id="FW_IN_APP_VIEW_CONTROL_BAR_FORWARD_BUTTON"  src="data:image/png;base64,PNG_BASE64_STRING" width="" height=""/><img id="FW_IN_APP_VIEW_CONTROL_BAR_CLOSE_BUTTON"  src="data:image/png;base64,PNG_BASE64_STRING" width="" height=""/></div>```

	The `FW_IN_APP_VIEW_CONTROL_BAR_BACK_BUTTON`, `FW_IN_APP_VIEW_CONTROL_BAR_FORWARD_BUTTON` and `FW_IN_APP_VIEW_CONTROL_BAR_CLOSE_BUTTON` IDs have to be kept as such for handling event.
	`PNG_BASE64_STRING` should be replaced by the png images' base64 hash.

	All mobile Safari mobile compatible html5 tags are supported, for example, you can use `<table>` tags to manage the layout instead of `<div>` tags shown in the example.
 
	- Note: Ad traffickers should use `extension.inAppView.toolbarSurfaceRender` instead of `FWParameterInAppViewNavigationBarHtml` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`

 */
FW_EXTERN NSString *const FWParameterInAppViewNavigationBarHtml;

/**
	Parameter: inAppView navigation bar background color.

	Valid values: NSString representing an integer/hexadecimal from 0 to 0xffffff, for example `@"256"`, `@"0xffffff"`
 
	- Note: Ad traffickers should use `extension.inAppView.navigationBarBackgroundColor` instead of `FWParameterInAppViewNavigationBarBackgroundColor` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`

 */
FW_EXTERN NSString *const FWParameterInAppViewNavigationBarBackgroundColor;

/**
	Parameter: inAppView navigation bar alpha.

	Valid values: NSString representing a float from 0.0 to 1.0, where `@"0.0"` represents completely transparent and `@"1.0"` represents completely opaque.

	Default value: `@"1.0"`
 
	- Note: Ad traffickers should use `extension.inAppView.navigationBarAlpha` instead of `FWParameterInAppViewNavigationBarAlpha` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterInAppViewNavigationBarAlpha;

/**
	Parameter: inAppView navigation bar height.

	Valid values: NSString representing a percentage in the range 0% to 100%, compared to screen height, e.g., `@"10%"`.

	Default value: `@"8.3%"` for iPhone and `@"3.9%"` for iPad

	- Note: Ad traffickers should use `extension.inAppView.navigationBarHeight` instead of `FWParameterInAppViewNavigationBarHeight` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterInAppViewNavigationBarHeight;

/**
	Parameter: inAppView background color.

	Valid values: NSString representing an integer/hexadecimal from 0 to 0xffffff, for example `@"256"`, `@"0xffffff"`

	Default value: `@"0xffffff"`
 
	- Note: Ad traffickers should use `extension.inAppView.webViewBackgroundColor` instead of `FWParameterInAppViewWebViewBackgroundColor` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterInAppViewWebViewBackgroundColor;

/**
	Parameter: inAppView webview alpha.

	Valid values: NSString representing a float from 0.0 to 1.0, where `@"0.0"` represents completely transparent and `@"1.0"` represents completely opaque.

	Default value: `@"1.0"`

	- Note: Ad traffickers should use `extension.inAppView.webViewAlpha` instead of `FWParameterInAppViewWebViewAlpha` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterInAppViewWebViewAlpha;

/**
	Parameter: enable countdown timer for applicable ads.

	Valid values: NSString `@"YES"`, `@"NO"`

	Default value: `@"NO"`
	
	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.display` instead of `FWParameterEnableCountdownTimer` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterEnableCountdownTimer;

/**
	Parameter: countdown timer refresh interval, in milliseconds.

	Valid values: NSString representing an integer from 1 to 1000.

	Default value: `@"300"`
	
	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.refreshInterval` instead of `FWParameterCountdownTimerRefreshInterval` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerRefreshInterval;

/**
	Parameter: javascript function to call when the countdown timer is updated, NSString.
	The javascript function should be available in the value defined by parameter `FWParameterCountdownTimerHtml` (see `FWParameterCountdownTimerHtml` for details). By default the function called is `updateTimer`. The function will be called with two parameters: the current playhead time of the slot in seconds; the total duration of the slot in seconds: `function updateTimer(playheadTime, duration);`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.updateCallback` instead of `FWParameterCountdownTimerUpdateCallback` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerUpdateCallback;

/**
	Parameter: countdown timer position.

	Valid values: NSString `@"bottom"`, `@"top"`, and `@"x,y"`, for example `@"10,20"`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.updateCallback` instead of `FWParameterCountdownTimerUpdateCallback` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerPosition;

/**
	Parameter: countdown timer alpha.

	Valid values: NSString representing a float in the range 0.0 to 1.0, where `@"0.0"` represents completely transparent and `@"1.0"` represents completely opaque.

	Default value: @"1.0".

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.updateCallback` instead of `FWParameterCountdownTimerUpdateCallback` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerAlpha;

/**
	Parameter: countdown timer height in pixels.

	Valid values: NSString representing an integer greater than 0.

	Default value: `@"20"`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.height` instead of `FWParameterCountdownTimerHeight` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerHeight;

/**
	Parameter: countdown timer width in pixels.

	Valid values: NSString representing an integer greater than 0.

	Default value: width of the video display base

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.width` instead of `FWParameterCountdownTimerWidth` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerWidth;

/**
	Parameter: countdown timer font size in css syntax.

	Valid values: css-valid font-size values, for example, `@"medium"`, `@"12px"`

	Default value: `@"medium"`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.textSize` instead of `FWParameterCountdownTimerTextSize` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerTextSize;

/**
	Parameter: countdown timer background color.

	Valid values: NSString representing an integer/hexadecimal from 0 to 0xffffff, for example `@"256"`, `@"0xffffff"`

	Default value: `@"0x4a4a4a"`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.bgColor` instead of `FWParameterCountdownTimerBackgroundColor` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerBackgroundColor;

/**
	Parameter: countdown timer font color.

	Valid values: NSString representing an integer/hexadecimal from 0 to 0xffffff, for example `@"256"`, `@"0xffffff"`
	
	Default value: `@"0xffffff"`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.fontColor` instead of `FWParameterCountdownTimerFontColor` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerFontColor;

/**
	Parameter: countdown timer font family in css syntax.

	Valid values: css-valid font-family values

	Default value: `@"Arial"`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.textFont` instead of `FWParameterCountdownTimerTextFont` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerTextFont;

/**
	Parameter: countdown timer html.

	Valid values: html snippet displaying a countdown timer, NSString.

	Default value: a default timer display html will be provided by default. If you set this parameter by yourself, there should also be a javascript function that updates it periodically. See `FWParameterCountdownTimerUpdateCallback` for details.

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.countdown.html` instead of `FWParameterCountdownTimerHtml` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCountdownTimerHtml;

/**
	Parameter: Enable / disable automatic visibility tracking of nontemporal slots. When enabled, non-temporal slots will be played automatically once they are visible on the device screen.

	Valid values: NSString `@"YES"`(enable), `@"NO"`(disable)

	Default value: `@"NO"`

	- Note: This parameter should be set before slot starts, otherwise it will have no effect.
	- Note: Ad traffickers should use `FW_PARAMETER_NONTEMPORAL_SLOT_VISIBILITY_AUTO_TRACKING` instead of `FWParameterNonTemporalSlotVisibilityAutoTracking` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterNonTemporalSlotVisibilityAutoTracking;

/**
	Parameter: Enable the <a href="http://hub.freewheel.tv/display/publicdrafts/iOS+PauseAd+Extension" target="_blank">Pause Ad Extension</a>.

	Valid values: NSString `@"YES"`(enable), `@"NO"`(disable)
	
	Default value: `@"NO"`

	- Note: This parameter should be set before sending the ad request, otherwise it will have no effect.
	- Note: Ad traffickers should use `extension.pausead.enable` instead of `FWParameterEnablePauseAd` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterEnablePauseAd;

/**
	Parameter: indicates whether AdManager should show buffering animation when a video ad is buffering.
 
	Valid values: NSString `@"YES"`, `@"NO"`
 
	Default value: `@"YES"`
 
	- Note: if the value is set to @"NO", the app itself should implement the buffering animation by listening to FreeWheel ad events `FWAdBufferingStartEvent` and `FWAdBufferingEndEvent`.
	- Note: Ad traffickers should use `renderer.video.showBufferIndicator` instead of `FWParameterVideoAdRendererShowBufferIndicator` when setting this parameter in MRM UI.
	- See:
 - `[FWContext setParameter:withValue:forLevel:]`
 - `[FWSlot setParameter:withValue:]`
 - `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterVideoAdRendererShowBufferIndicator;

/**
	Parameter: indicates whether AdManager should handle user tappings on a video ad.

	Valid values: NSString `@"YES"`, `@"NO"`

	Default value: `@"YES"`

	- Note: if the value is set to @"NO", app should handle the ad click by itself, for example, opening the click through url in a WKWebView.
	- Note: Ad traffickers should use `renderer.video.clickDetection` instead of `FWParameterDetectClick` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterDetectClick;

/**
	Parameter: desired bitrate. Current viewer's available bandwidth.

	Valid values: NSString representing a positive decimal float.

	Default value: `@"1000.0"`

	- Note: the value is used in creative rendition selection. AdManager will automatically choose the best fit rendition according to current view's bandwidth.
	- Note: Ad traffickers should use `desiredBitrate` instead of `FWParameterDesiredBitrate` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterDesiredBitrate;

/**
	Parameter: Whether to automatically retrieve and send the Apple IDFA when it is available.

	Valid values: NSString `@"YES"`, `@"NO"`

	Default value: `@"YES"`

	- Note: Ad traffickers should use `_fw_did_idfa` instead of `FWParameterCollectIDFA` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterCollectIDFA;

/**
	Parameter: Anchor point of image in overlay slots.
 
	Valid values: NSString `tc`, `bc`, `ml`, `mr`, `tl`, `tr`, `bl`, `br`. Here 't' means 'top', 'l' means 'left', 'b' means 'bottom', 'r' means 'right', 'c' means 'center', 'm' means 'middle'
 
	Default value: `bc`
 
	- Note: Ad traffickers should use `renderer.image.primaryAnchor` instead of `FWParameterImageRendererPrimaryAnchor` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterImageRendererPrimaryAnchor;

/**
	Parameter: X axis offset relative to the anchor point of image in overlay slots.
 
	Valid values: NSString representing a positive integer. Negative values will be considered as 0 instead.
 
	Default value: `0`
 
	- Note: Ad traffickers should use `renderer.image.marginWidth` instead of `FWParameterImageRendererMarginWidth` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterImageRendererMarginWidth;

/**
	Parameter: Y axis offset relative to the anchor point of image in overlay slots.
 
	Valid values: NSString representing a positive integer. Invalid values will be considered as 0 instead.
 
	Default value: `0`
 
	- Note: Ad traffickers should use `renderer.image.marginHeight` instead of `FWParameterImageRendererMarginHeight` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterImageRendererMarginHeight;

/**
	Parameter: Timeout in seconds for downloading an image to display
 
	Valid values: NSString representing a positive integer. Invalid values will be considered as the default value instead.
 
	Default value: `30`
 
	- Note: Ad traffickers should use `renderer.image.timeout` instead of `FWParameterImageRendererTimeout` when setting this parameter in MRM UI.
	- See:
		- `[FWContext setParameter:withValue:forLevel:]`
		- `[FWSlot setParameter:withValue:]`
		- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterImageRendererTimeout;

/**
	Parameter: Anchor point of html in overlay slots.
 
	Valid values: NSString `tc`, `bc`, `ml`, `mr`, `tl`, `tr`, `bl`, `br`. Here 't' means 'top', 'l' means 'left', 'b' means 'bottom', 'r' means 'right', 'c' means 'center', 'm' means 'middle'
 
	Default value: `bc`
 
	- Note: Ad traffickers should use `renderer.html.primaryAnchor` instead of `FWParameterHTMLRendererPrimaryAnchor` when setting this parameter in MRM UI.
	- See:
	- `[FWContext setParameter:withValue:forLevel:]`
	- `[FWSlot setParameter:withValue:]`
	- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterHTMLRendererPrimaryAnchor;

/**
	Parameter: X axis offset relative to the anchor point of html in overlay slots.
 
	Valid values: NSString representing a positive integer. Negative values will be considered as 0 instead.
 
	Default value: `0`
 
	- Note: Ad traffickers should use `renderer.html.marginWidth` instead of `FWParameterHTMLRendererMarginWidth` when setting this parameter in MRM UI.
	- See:
	- `[FWContext setParameter:withValue:forLevel:]`
	- `[FWSlot setParameter:withValue:]`
	- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterHTMLRendererMarginWidth;

/**
	Parameter: Y axis offset relative to the anchor point of html in overlay slots.
 
	Valid values: NSString representing a positive integer. Invalid values will be considered as 0 instead.
 
	Default value: `0`
 
	- Note: Ad traffickers should use `renderer.html.marginHeight` instead of `FWParameterHTMLRendererMarginHeight` when setting this parameter in MRM UI.
	- See:
	- `[FWContext setParameter:withValue:forLevel:]`
	- `[FWSlot setParameter:withValue:]`
	- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterHTMLRendererMarginHeight;

/**
	Parameter: indicate if html renderer is a transparent background
 
	Valid values: NSString `@"YES"`, `@"NO"`
 
	Default value: `@"NO"`
 
 */
FW_EXTERN NSString *const FWParameterHTMLRendererIsBackgroundTransparent;

/**
	Parameter: Timeout for loading VPAID creative in milliseconds
 
	Valid values: NSString representing an integer
 
 */
FW_EXTERN NSString *const FWParameterVPAIDRendererCreativeTimeoutDelay;

/*! internal */
FW_EXTERN NSString *const FW_PARAMETER_REQUEST_TEMPLATE_VARIABLES;
FW_EXTERN NSString *const FW_PARAMETER_REQUEST_ALTERNATIVE_URL;

/**
	Parameter: Enable the body element in VPAID creative loading iframe

	Valid values: NSString `@"YES"`, `@"NO"`

	Default value: `@"NO"`
	- Note: This parameter should be set before VPAID creative asset is loaded.
	- Note: Ad traffickers should use `renderer.vpaid.enableBodyInIframe` instead of `FWParameterEnableBodyElementInVPAIDIframe` when setting this parameter in MRM UI.
	- See:
	- `[FWContext setParameter:withValue:forLevel:]`
	- `[FWSlot setParameter:withValue:]`
	- `[FWCreativeRendition setParameter:withValue:]`
 */
FW_EXTERN NSString *const FWParameterEnableBodyElementInVPAIDIframe;

/**
	Parameter: Used to set whether the ad is subject to GDPR regulations in the application. This key should be set in [NSUserDefaults standardUserDefaults].
 
	Valid values: NSString `@"1"`, `@"0"`, `nil`.
 
	Default value: `nil`
 
	- Note: For AdManager to automatically retrieve GDPR regulations, this parameter should be set before initializing FWRequestConfiguration. If the value needs to be set after initializing FWRequestConfiguration, please assign FWRequestConfiguration's consentConfiguration to a new FWConsentConfiguration object. Changes made to consentConfiguration after an AdRequest calls submitWithTimeout will be ignored.
	- Note: GDPR consent information can also be manually set using FWGDPRConsentConfiguration.
	- See:
		- `[FWRequestConfiguration setConsentConfiguration:]`
		- `[FWAdRequest submitWithTimeout:]`
		- `[FWGDPRConsentConfiguration: initWithConsentApplicable]`
 */
FW_EXTERN NSString *const FWParameterIABConsentSubjectToGDPRKey;

/**
	Parameter: Used to set what information and which vendors the user consented to in the application. This key should be set in [NSUserDefaults standardUserDefaults].
 
	Valid values: NSString representing the GDPR consent string.
 
	Default value: `nil`
 
	- Note: For AdManager to automatically retrieve the GDPR consent string, this parameter should be set before initializing FWRequestConfiguration. If the value needs to be set after initializing FWRequestConfiguration, please assign FWRequestConfiguration's consentConfiguration to a new FWConsentConfiguration object. Changes made to consentConfiguration after an AdRequest calls submitWithTimeout will be ignored.
	- Note: GDPR consent information can also be manually set using FWGDPRConsentConfiguration.
	- See:
		- `[FWRequestConfiguration setConsentConfiguration:]`
		- `[FWAdRequest submitWithTimeout:]`
		- `[FWGDPRConsentConfiguration: initWithConsentApplicable]`
 */
FW_EXTERN NSString *const FWParameterIABConsentConsentStringKey;

#pragma mark - Request Keys

/**
	Ad request key: Postal code of the current viewer.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyPostalCode;

/**
	Ad request key: Area code of the current user.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyAreaCode;

/**
	Ad request key: User's date of birth.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyDateOfBirth;

/**
	Ad request key: User's gender.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyGender;

/**
	Ad request key: Keywords.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyKeywords;

/**
	Ad request key: Search string.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeySearchString;

/**
	Ad request key: Marital status of the current user.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyMarital;

/**
	Ad request key: Ethnicity of the current user.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyEthnicity;

/**
	Ad request key: Orientation of the current user.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyOrientation;

/**
	Ad request key: User's income.

	- See: `[FWContext addValue:forKey:]`
 */
FW_EXTERN NSString *const FWRequestKeyIncome;

#pragma mark - Dictionary Keys

/**
	Notification `userInfo` dictionary key: url. 
	- Definition:
		- In CTS Integrations:
			- The content video url for the player to use.
		- In Ad Click event handlers:
			- The click through url of an ad click event.

	- See:
		- `FWAdEventNotification`
		- `FWAdClickEvent`
		- `FWRequestCompleteNotification`
 */
FW_EXTERN NSString *const FWInfoKeyUrl;


/**
	Notification `userInfo` dictionary key: error. Error message of a failed ad request or failed extension load.

	- See:
		- `FWRequestCompleteNotification`
		- `FWExtensionLoadedNotification`
 */
FW_EXTERN NSString *const FWInfoKeyError;

/**
	Notification `userInfo` dictionary key: slot custom ID. Custom ID of the related slot

	- See: 
		- `FWSlotStartedNotification`
		- `FWSlotEndedNotification`
		- `FWSlotPreloadedNotification`
		- `FWContentPauseRequestNotification`
		- `FWContentResumeRequestNotification`
 */
FW_EXTERN NSString *const FWInfoKeySlotCustomId;

/**
	Notification `userInfo` dictionary key: concrete event ID

	Concrete event ID of the related ad, should be used to pass the concrete event ID in `FWAdMeasurementEvent`'s details dictionary. Example:
```[rendererController processEvent:FWAdMeasurementEvent info:[NSDictionary dictionaryWithObject:@"concreteEventId" forKey:FWInfoKeyConcreteEventId]];```

	The concrete event ID should be a `NSString`.
 */
FW_EXTERN NSString *const FWInfoKeyConcreteEventId;

/**
	Notification `userInfo` dictionary key: slot. The `FWSlot` instance of the relevant slot.
	
	- See:
		- `FWAdEventNotification`
 
	TODO: unify notification payloads
 */
FW_EXTERN NSString *const FWInfoKeySlot;

/**
	Notification `userInfo` dictionary key: adInstance. The `FWAdInstance` instance of the relevant ad instance.
	
	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWInfoKeyAdInstance;

/**
	Notification `userInfo` dictionary key: ad ID. ID of the relevant ad.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWInfoKeyAdId;

/**
	Notification `userInfo` dictionary key: replica ID. Replica ID of the relevant ad.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWInfoKeyReplicaId;

/**
	Notification `userInfo` dictionary key: creative ID. ID of the relevant creative.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWInfoKeyCreativeId;

/**
	Notification `userInfo` dictionary key: user action type. Type of the relevant user action.

	- See: 
		- `FWUserActionNotification`
		- `FWUserAction`
 */
FW_EXTERN NSString *const FWInfoKeyUserAction;

/**
	Notification `userInfo` dictionary key: module name. Name of relevant module that triggered the notification.

	- See: `FWExtensionLoadedNotification`
 */
FW_EXTERN NSString *const FWInfoKeyModuleName;

/**
	Renderer `moduleInfo` dictionary key: module type, renderer or translator.

	- See: `FWModuleType`
 */
FW_EXTERN NSString *const FWInfoKeyModuleType;

/**
	Renderer `moduleInfo` dictionary key: required SDK version. Expects a NSNumber.

	Optional. If present, the value should be the lowest SDK version the renderer supports. For example: `0x02060000` for v2.6
 */
FW_EXTERN NSString *const FWInfoKeyRequiredSDKVersion;

/**
	Use this key in the `details` dictionary to provide the error code when the renderer/translator transits to `FWRendererStateFailed`.

	Example usage:
	```[rendererController handleStateTransition:FWRendererStateFailed info:[NSDictionary dictionaryWithObjectsAndKeys:FWErrorIO, FWInfoKeyErrorCode, ..., nil]];```
	
	- See: `FWError*`
 */
FW_EXTERN NSString *const FWInfoKeyErrorCode;

/**
	Use this key in the `details` dictionary to provide detailed error info when the renderer/translator transits to `FWRendererStateFailed`. Expects NSString.
 
	Example usage:
	```[rendererController handleStateTransition:FWRendererStateFailed info:[NSDictionary dictionaryWithObjectsAndKeys:@"failed to load ad from url", FWInfoKeyErrorInfo, ..., nil]];```
 */
FW_EXTERN NSString *const FWInfoKeyErrorInfo;

/**
	Use this key in the `details` dictionary to provide the error'ed module's name when the renderer/translator transits to `FWRendererStateFailed`. Expects NSString.

	Example usage: 
	```[rendererController handleStateTransition:FWRendererStateFailed info:[NSDictionary dictionaryWithObjectsAndKeys:@"MyCustomRenderer", FWInfoKeyErrorModule, ..., nil]];```
 */
FW_EXTERN NSString *const FWInfoKeyErrorModule;

/**
	Notification `userInfo` dictionary key: ad event name. Name of the ad event.

	- See: `FWAd*Event`
 */
FW_EXTERN NSString *const FWInfoKeyAdEventName;

/**
	Notification `userInfo` dictionary key: custom event name. Name of the custom event in NSString.

	- See: `FWAdEventNotification`
 */
FW_EXTERN NSString *const FWInfoKeyCustomEventName;

/**
	Ad event `details` dictionary key: show browser. Should the click event result in the opening of a url. Expects `@"YES"` or `@"NO"`.

	- See:
		- `[FWRendererController processEvent:info:]`
		- `FWAdClickEvent`
 */
FW_EXTERN NSString *const FWInfoKeyShowBrowser;

/**
	Notification `userInfo` dictionary key: video display base.

	- See:
		- `FWVideoDisplayBaseDidChangeNotification`
		- `FWVideoDisplayBaseFrameDidChangeNotification`
 */
FW_EXTERN NSString *const FWInfoKeyVideoDisplayBase;

/**
	Notification `userInfo` dictionary key: ad volume
 
	- See: `FWAdVolumeChangedEvent`
 */
FW_EXTERN NSString *const FWInfoKeyAdVolume;


#pragma mark - Error Codes

/**
	Error code: IO error.

	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorIO;

/**
	Error code: timeout error.

	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorTimeout;

/**
	Error code: creative rendition asset is null.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorNullAsset;

/**
	Error code: ad instance is unavailable.

	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorAdInstanceUnavailable;

/**
	Error code: unknown.

	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorUnknown;

/**
	Error code: missing parameter.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorMissingParameter;

/**
	Error code: no ad is available from 3rd party ad source.

	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorNoAdAvailable;

/**
	Error code: parsing error.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorParse;

/**
	Error code: invalid value.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorInvalidValue;

/**
	Error code: invalid slot.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorInvalidSlot;

/**
	Error code: no renderer.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorNoRenderer;

/**
	Error code: `preload` is not implemented by the translator.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorPreloadNotImplementedByTranslator;

/**
	Error code: inAppView error.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorInAppView;

/**
	Error code: third party component error.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorThirdPartyComponent;

/**
	Error code: unsupported third party feature.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorUnsupportedThirdPartyFeature;

/**
	Error code: device limitation.
 
	- See: `FWInfoKeyErrorCode`
 */
FW_EXTERN NSString *const FWErrorDeviceLimitation;

