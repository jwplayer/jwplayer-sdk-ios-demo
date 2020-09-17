#import <Foundation/Foundation.h>

/**
 * \file FWProtocols.h
 * \brief Protocols in FreeWheel AdManager SDK
 */
@class UIView;
@class AVPlayer;
@class CLLocation;
@class UIViewController;
@class AVPlayerItem;
@class FWCTSRequestConfiguration;
@class FWRequestConfiguration;

@protocol FWAdManager;
@protocol FWContext;
@protocol FWSlot;
@protocol FWIABUniversalAdId;
@protocol FWAdInstance;
@protocol FWCreativeRendition;
@protocol FWCreativeRenditionAsset;
@protocol FWRendererController;
@protocol FWRenderer;
@protocol FWVideoAdDelegate;
@protocol FWStreamStitcherContext;
@protocol FWCTSContext;

#pragma clang arc_cf_code_audited begin
/** 
	Create a new AdManager instance

	@return a new AdManager instance
	- See: `FWAdManager`
 */
FW_EXTERN id<FWAdManager> newAdManager(void);

/**
	Set logging preference

	- Parameter: `level` - See `FWLogLevel`
 */
FW_EXTERN void FWSetLogLevel(FWLogLevel level);

/**
	AdManager registers `NSSetUncaughtExceptionHandler()` to report uncaught exception.
	If app needs to perform last-minute logging before the program terminates, use this function instead of NSSetUncaughtExceptionHandler.

	- Parameter: `handler` - Your `NSUncaughtExceptionHandler` instance
 */
FW_EXTERN void FWSetUncaughtExceptionHandler(NSUncaughtExceptionHandler *handler);

/**
	Clear all cookies from fwmrm.net domains.
 */
FW_EXTERN void FWClearCookie(void);

/**
	Opt-out cookies from fwmrm.net domains.

	- Parameter: `value` - `YES` to opt-out, `NO` to opt-in.
 */
FW_EXTERN void FWSetCookieOptOutState(BOOL value);

/**
	Get fwmrm.net domains cookie opt-out state.
 
	@return boolean indicator of the opt-out state.
 */
FW_EXTERN BOOL FWGetCookieOptOutState(void);

/**
	Link a third party renderer framework.
 
	- Note: When you include a third party renderer framework in your project, during the compilation it could be stripped by the compiler because it is likely to appear unused in the project. To avoid this, either add "-all_load" to Other Linker Flags in your project's Build Settings, or call `FWLinkRenderer(RendererClass)` in your AppDelegate.m.
	
	@param rendererClass The third party renderer class.
 */
FW_EXTERN void FWLinkRenderer(Class rendererClass);

/**
	FWAdManager protocol.
 
	`FWAdManager` is a factory for `FWContext` objects. Use `newContext` to create a new FWContext object.
	Normally, a single instance of `FWAdManager` is recommended for each app. With each session, a `FWContext` should be created to handle ad request / response, and the delivered slots. Destroy your `FWAdManager` instance only when your app exits.

	- See: `newAdManager`
 */
@protocol FWAdManager <NSObject>
#pragma mark - Properties
/**
	Get major version of AdManager

	@return Version of AdManager, e.g. 0x02060000 for v2.6
 */
- (NSUInteger)version;

#pragma mark - Methods
/**
	Set application's current view controller. 

	You are required to call this method if using any of the following third party components:

	- FWAdMobRenderer
	- FWMillennialDisplayAdRenderer
	- FWMillennialTakeoverAdRenderer
	- FWTremorAdRenderer
 
	Otherwise optional.

	- Note: Once set, the view controller will be retained by AdManager.

	@param viewController   current view controller
 */
- (void)setCurrentViewController:(UIViewController *)viewController;

/**
	Set the network ID. Required. Consult your FreeWheel solution engineer for the value to set.

	@param value	network ID
 */
- (void)setNetworkId:(NSUInteger)value;

/**
	Set the current location of the device. This value will only be used for geo targeting purposes.

	@param value	device's current location, `CLLocation`. nil by default.
 */
- (void)setLocation:(CLLocation *)value;

/**
	Create a new `FWContext` instance.

	A `FWContext` instance is used to set ad request information for a particular ad or ad set.  Multiple contexts can be created throughout the lifecycle of the FreeWheel AdManager and may exist simultaneously without consequence. Multiple simultaneous contexts are useful to optimize user experience in the network-resource limited environment.

	@return A new `FWContext` instance
 */
- (id<FWContext>)newContext;

/**
 *	Create a new `FWStreamStitcherContext` instance.
 *
 *  @param url Your Stream Stitcher URL provided by FreeWheel.
 *  @param avPlayer The AVPlayer instance that the app uses to play the live stream.
 *  @return A new `FWStreamStitcherContext` instance.
 */
- (id<FWStreamStitcherContext>)newStreamStitcherContextWithStreamUrl:(NSURL *)streamUrl player:(AVPlayer *)avPlayer;

/**
 *	Create a new `FWCTSContext` instance to submit ad requests and fire FreeWheel beacons for CTS SSAI integration.
 */
- (id<FWCTSContext>)newCTSContext;

/**
	Disable FreeWheel crash reporter. By default AdManager will send a crash report to ad server when an app crash is detected.
 */
- (void)disableFWCrashReporter;
@end

/**
	Protocol for AdManager context
 */
@protocol FWContext <NSObject>

#pragma mark - Properties
/**
	The delegate to handle video ads.
 
	- See: `FWVideoAdDelegate`
 */
@property (nonatomic, weak) id<FWVideoAdDelegate> videoAdDelegate;

/**
	Get all temporal slots

	@return An `NSArray` of `FWSlot` objects
 */
- (NSArray * /* id<FWSlot> */)temporalSlots;

/**
	Get all video player non-temporal slots

	@return An `NSArray` of `FWSlot` objects
 */
- (NSArray * /* id<FWSlot> */)videoPlayerNonTemporalSlots;

/**
	Get all site section non-temporal slots

	@return An `NSArray` of `FWSlot` objects
 */
- (NSArray * /* id<FWSlot> */)siteSectionNonTemporalSlots;

/**
	Get video asset's location URL

	@return video asset's URL, `nil` if not set
 */
- (NSString *)videoLocation;

/**
	Get the AdManager instance for this context

	@return The `FWAdManager` instance
 */
- (id<FWAdManager>)adManager;

/**
	Return the object [NSNotificationCenter defaultCenter]
 */
- (NSNotificationCenter *)notificationCenter;

#pragma mark - Methods
/**
	Set video display base `UIView`. REQUIRED. Video ads are rendered within the base view in the same frame.

	When video display base view changes, app needs to call this method again with the new video display to notify AdManager to render video ads in the updated video display. App does not need to call this method when video display view's frame changes.

	@param value Video display base `UIView`
 */
- (void)setVideoDisplayBase:(UIView *)value;


- (void)addCandidateAdId:(NSUInteger)candidateAdId DEPRECATED_ATTRIBUTE;

/**
	Notify the SDK about the current state of the content video

	@param videoState	See `FWVideoState`
 */
- (void)setVideoState:(FWVideoState)videoState;

/**
	Set the current playhead time of the content video

	@param playheadTime  video playhead time
 */
- (void)setVideoPlayheadTime:(NSTimeInterval *)playheadTime;

/**
	Get all slots of a specified time position class.

	@param timePositionClass Time position class, see `FWTimePositionClass`
	@return An `NSArray` of `FWSlot` objects
 */
- (NSArray * /* id<FWSlot> */)getSlotsByTimePositionClass:(FWTimePositionClass)timePositionClass;

/**
	Get a slot by its custom ID

	@param customId	Custom ID of the slot
	@return An `FWSlot` object, or `nil` if not found
 */
- (id<FWSlot>)getSlotByCustomId:(NSString *)customId;

/**
	Submit an ad request to FreeWheel Ad Server
 
	@param configuration Configuration to be used for building ad request, see `FWRequestConfiguration`
	@param timeoutInterval ad request timeout value in seconds. 10 by default.
 */
- (void)submitRequestWithConfiguration:(FWRequestConfiguration*)configuration timeout:(NSTimeInterval)timeoutInterval;

/**
	Add renderer class to context which takes higher priority than renderers configured in the profile.

	@param className	The class name of the renderer. Please note, class name is expected to have prefix "class://". In swift projects, please include appropriate namespace
	@param contentType	The content types that the renderer can support, separated by comma.
	@param creativeAPI The creative APIs that the renderer can support, separated by comma.
	@param slotType	The slot types that the renderer can support, separated by comma.
	@param baseAdUnit	The base ad units that the renderer can support, separated by comma.
	@param soldAsAdUnit	The soldAs ad unit that the renderer can support, separated by comma.
	@param parameters	The parameters set on renderer level.
 */
- (void)addRendererClass:(NSString *)className forContentType:(NSString *)contentType creativeAPI:(NSString *)creativeAPI slotType:(NSString *)slotType baseUnit:(NSString *)baseAdUnit adUnit:(NSString *)soldAsAdUnit withParameters:(NSDictionary *)parameters;

/**
	Set a parameter on a specified level. 
	
	@param name	parameter name
	@param value	parameter value
	@param level	level of the parameter, must be `FWParameterLevelGlobal` or `FWParameterLevelOverride`
 */
- (void)setParameter:(NSString *)name withValue:(id)value forLevel:(FWParameterLevel)level;

/**
	Retrieve the value of a parameter

	@param name  The name of the parameter
	@return The value of the parameter
 */
- (id)getParameter:(NSString *)name;

/**
	Notify the SDK about user actions
	@param userAction User action, see `FWUserAction`
 */
- (void)notifyUserAction:(FWUserAction)userAction;

/**
	Load player extension by its class name

	@param extensionName The class name of the extension

	- SeeAlso: `FWExtensionLoadedNotification`
 */
- (void)loadExtension:(NSString *)extensionName;

/**
	Request timeline to pause. The timeline consists of the content video and all linear slots.

	When the renderer or extension requires the timeline to be temporarily paused, e.g. when expanding to a fullscreen view that covers the whole player and other ads, calling this method will result in the notification FWContentPauseRequestNotification being dispatched from the current FWContext instance if content video is currently playing, and send pause requests to all active temporal slots.
 */
- (void)requestTimelinePause;

/**
	Request timeline to resume. The timeline consists of the content video and all linear slots.

	When the renderer or extension requires the timeline to be resumed, e.g. when dismissing a fullscreen view that covers the whole player and other ads, calling this method will result in the notification FWContentResumeRequestNotification being dispatched from the current FWContext instance if content video is currently paused, and send resume requests to all active temporal slots.
 */
- (void)requestTimelineResume;

/**
	Set volume for current and subsequent ad playback
 
	- Note: A VPAID creative not implementing setAdVolume VPAID spec will not change its volume.

	@param volume Volume for ad playback. Note: volume is expected to be in the range of [0,1]
 */
- (void)setAdVolume:(float)volume;

/**
	Get volume for ad playback
 
	Ad playback volume is influenced by several components including player, renderer, creative etc. The value from the latest update is returned by this method

	@return volume for ad playback. Note: volume is expected to be in the range of [0,1]
 */
- (float)adVolume;

/**
	Add friendly obstruction which should be excluded from all ad session viewability calculations for Open Measurement SDK. This method will have no effect if called after the ad session has finished.
 
	@param view to be excluded from all ad session viewability calculations.
 */
- (void)addFriendlyObstruction:(UIView *)obstruction;

/**
	Remove a registered friendly obstruction view for Open Measurement SDK. This method will have no effect if called after the ad session has finished.
 
	@param view to be removed from the list of registered friendly obstructions.
 */
- (void)removeFriendlyObstruction:(UIView *)obstruction;

@end

/**
	Protocol for AdManager context for Stream Stitcher integrations
 */
@protocol FWStreamStitcherContext <NSObject>

#pragma mark - Methods

/**
 *	Call this method when configuration is done for the Stream Stitcher integration before the stream starts playing.
 */
- (void)start;


/**
 *	Add a non-temporal slot.
 *	@param	customId					Unique custom ID of the slot. If slot with specified ID already exists, the function call will be ignored.
 *	@param	container					Container UIView instance of the slot.
 *	@param	width						width of the slot
 *	@param	height						height of the slot
 */
- (void)addNonTemporalSlot:(NSString *)customId containerView:(UIView *)container width:(NSUInteger)width height:(NSUInteger)height;

/**
 *	Set the video display base view so that the FreeWheel SDK can render overlay ads onto the view automatically. Usually the view should be the one on which the video is rendered.
 *	@param view		The video display base view
 */
- (void)setVideoDisplayBase:(UIView *)view;

/**
	Notify the SDK about click and seek actions from the user.
	@param userAction User action, see `FWUserAction`
 */
- (void)notifyUserAction:(FWUserAction)userAction;

@end

/**
 Protocol for FreeWheel CTS context
 */
@protocol FWCTSContext <FWContext>

/**
 *	Set the AVPlayer instance used for the stream playback.
 *	The FWCTSContext instance maintains a weak reference to the AVPlayer instance to track the progress of the playback.
 *	Please note, your app is responsible for maintaining a strong reference to the AVPlayer instance.

 *	@param player the AVPlayer instance used for stream playback

 */
- (void)setPlayer:(AVPlayer *)player;

@end


/**
	Protocol for slot 
 */
@protocol FWSlot <NSObject>

#pragma mark - Properties

/**
	Get the slot's custom ID

	@return Custom ID of the slot
 */
- (NSString *)customId;  

/**
	Get the slot's type

	@return Type of the slot, See `FWSlotType`
 */
- (FWSlotType)type;				

/**
	Get the slot's time position
	@return Time position of the slot
 */
- (NSTimeInterval)timePosition;	 

/**
	Get slot's time position class

	@return Time position class of the slot, see `FWTimePositionClass`
 */
- (FWTimePositionClass)timePositionClass;	   

/**
	Get the slot's embedded ads duration

	@return The embeded ads duration of the temporal slot. -1 if not available.
 */
- (NSTimeInterval)embeddedAdsDuration;

/**
	Get the slot's end time position

	@return The end time position of the temporal slot. -1 if not available.
 */
- (NSTimeInterval)endTimePosition;

/**
	Get the ad instances in the slot

	@return An array of id<FWAdInstance>
 */
- (NSArray * /* <id>FWAdInstance */)adInstances;

/**
	Get the width of the slot in pixels as returned in ad response.

	@return Width in pixels
 */
- (NSInteger)width;

/**
	Get the height of the slot in pixels as returned in ad response.

	@return Height in pixels
 */
- (NSInteger)height;

/**
	Get slot's visibility. Only applicable to non-temporal slots. YES by default.

	@return `YES` for visible, otherwise `NO`
 */
- (BOOL)visible;

/**
	Get slot base `UIView` object.

	For nontemporal slots, the returned `UIView` should be added to a parent `UIView` that is already in your apps view hierarchy.

	For temporal slot, return value is the object set by `-[FWContext setVideoDisplayBase:]`.

	@return The slot base `UIView`
 */
- (UIView *)slotBase;

/**
	Get the slot's duration

	@return The duration in seconds, greater than or equal to 0
 */
- (NSTimeInterval)totalDuration;

/**
	Get the slot's playhead time

	@return The playhead time in seconds, greater than or equal to 0
 */
- (NSTimeInterval)playheadTime;

/**
	Get the currently playing ad instance

	@return The `FWAdInstance` object of the currently playing ad in this slot. Return `nil` if no ad instance is currently playing.
 */
- (id<FWAdInstance>)currentAdInstance;

/**
 	Get the signal Id of the slot. Applicable in Linear TV Integrations
 
 	@return The string value of signal ID of the slot. Returns `nil` if not available.
 */
- (NSString *)signalId;

#pragma mark - Methods

/**
	Preload the slot.
	The notification `FWSlotPreloadedNotification` will be dispatched when the slot has finished preloading.

	- Note: The preload behaviour may differ due to different ad types. Based on the current implementation, it only supports VAST ad.
 */
- (void)preload;

/**
	Play the slot.
 */
- (void)play;

/**
	Stop the slot
 */
- (void)stop;

/**
	Pause the slot.
 */
- (void)pause;

/**
	Resume the slot.
 */
- (void)resume;

/**
	Skips the current ad in the slot.
	
	- Note: The fallback ads associated with the skipped ad will not be played.
 */
- (void)skipCurrentAd;

/**
	Set the visibility for a nontemporal slot. 

	If a nontemporal slot view should not be visible, call set the visibility to `NO` before the slot starts. In this case there will be no impression sent to FreeWheel ad server, even if `[slot play]` is called afterwards.

	If a nontemporal slot has already started when it is invisible, setting the visibility to `YES` will display the slot and send an impression.

	- Note: This method has no effect on temporal slots. This method has no effect anymore if an impression has been sent.

	@param value `YES` for visible, `NO` for otherwise
 */
- (void)setVisible:(BOOL)value;

/**
	Set a parameter on the slot level

	@param name	Name of the parameter
	@param value Value of the parameter
 */
- (void)setParameter:(NSString *)name withValue:(id)value;

/**
	Get the value of a parameter by its name

	@param name	Parameter name
	@return Value of the parameter
 */
- (id)getParameter:(NSString *)name;

@end

/**
 An abstraction of the IAB definition of Universal Ad ID. For more details on the IAB Universal Ad ID, please refer to section 3.7.1 in the VAST 4.0 spec: https://www.iab.com/guidelines/digital-video-ad-serving-template-vast-4-0/.
 */
@protocol FWIABUniversalAdId <NSObject>

#pragma mark - Properties

/**
    Get the registry of the universal ad ID, which is a string used to identify the URL for the registry website where the unique
    creative ID is cataloged.
 
    @return the registry string.
 */
- (NSString *)idRegistry;

/**
    Get the value of the universal ad ID, which is a string for the unique creative ID.
 
    @return the value string.
 */
- (NSString *)idValue;

@end

/**
 An abstraction of the IAB definition of Extension. Extensions enable custom integrations which cannot be covered in the scope of VAST spec. For more details on the VAST Extensions, please refer to https://www.iab.com/wp-content/uploads/2015/11/VAST-2_0-FINAL.pdf
 */
@protocol FWVastExtension <NSObject>

/**
 Get the type of the extension. Returns a nil string if key is absent in the VAST response

 @return A string
 */
- (NSString *)type;


/**
 Get the value of the extension. Returns the insides of the Extension

 @return The insides of the VAST Extension as a string
 */
- (NSString *)value;

/**
 Get the owner of the extension who generated or handled it last in the request chain. Returns a nil string if not available.

 @return A string
 */
- (NSString *)owner;

@end

/**
	Protocol for ad instance
 */
@protocol FWAdInstance <NSObject>

#pragma mark - Properties

/**
	Get the ad ID of the ad instance. This value can also be found in the advertising module of the FreeWheel MRM UI.

	@return ID of the ad instance
 */
- (NSUInteger)adId;

/**
 	Get a uniquely identifiable ID of the ad instance. For ads from third party or external sources, via SSVT, this ID includes externalAdId to reflect the true uniquely identifiable ID.
 
 	@return A uniquely identifiable ID of the ad instance
 */
- (NSString *)adUniqueId;

/**
    Get the replica ID of the ad instance.
 
    @return Replica ID of the ad instance
 */
- (NSString *)replicaId;

/**
	Get the external ad ID of the ad instance for ads from third party or external sources, via SSVT. Please note, this will return an empty string for first party ads or if the external ad ID is not available via the third party owner

	@return External ad ID of the ad instance
 */
- (NSString *)externalAdId;

/**
	Get the creative ID of the ad instance
	This is the creative ID associated with this ad. The value can also be found in the advertising module of the FreeWheel MRM UI.

	@return Creative ID as an unsigned int
 */
- (NSUInteger)creativeId;

/**
	Get the primary rendition of the ad instance

	@return A `FWCreativeRendition` instance
 */
- (id<FWCreativeRendition>)primaryCreativeRendition;

/**
	Get the renderer controller of the ad instance

	@return A `FWRendererController` instance
 */
- (id<FWRendererController>)rendererController;

/**
	Get the companion slots of the ad instance

	@return An array of `FWSlot`
 */
- (NSArray *)companionSlots;

/**
	Get the playable companion ad instances

	@return An array of `FWAdInstance`
 */
- (NSArray *)companionAdInstances;

/**
 Get the vast extensions matching the input type

 @param key A string used for looking up
 @return An array of vast extensions matching the type. Returns an empty array if no extensions match the key
 */
- (NSArray<id<FWVastExtension>> *)vastExtensionsWithType:(NSString *)type;

/**
	Whether the ad is required to be shown by law, usually the ad is a companion ad

	@return `YES` if this ad is required to be shown, `NO` if otherwise
 */
- (BOOL)isRequiredToShow;

/**
	Get all creative renditions of the ad instance

	@return An array of `FWCreativeRendition`
 */
- (NSArray* /*id<FWCreativeRendition>*/)creativeRenditions;

/**
	Get the slot that contains this ad instance
 */
- (id<FWSlot>)slot;

/**
	Get duration of the ad instance

	@return Duration in seconds
 */
- (NSTimeInterval)duration;

/**
	Get the ad instance's playhead

	@return the playhead time in seconds, greater than or equal to 0
 */
- (NSTimeInterval)playheadTime;

#pragma mark - Methods

/**
	Get the callback urls for the specified event
 
	Valid eventName, eventType pairs:

	- (`FWAdImpressionEvent`， `FWEventTypeImpression`): ad impression
	- (`FWAdFirstQuartileEvent`, `FWEventTypeImpression`): firstQuartile
	- (`FWAdMidpointEvent`, `FWEventTypeImpression`): midpoint
	- (`FWAdThirdQuartileEvent`, `FWEventTypeImpression`): 3rd quartile
	- (`FWAdCompleteEvent`, `FWEventTypeImpression`): complete
	- (`FWAdClickEvent`, `FWEventTypeClick`): click through
	- (`FWAdClickEvent`, `FWEventTypeClickTracking`): click tracking
	- (`"custom_click_name"`, `FWEventTypeClick`): custom click through
	- (`"custom_click_name"`, `FWEventTypeClickTracking`): custom click tracking
	- (`FWAdPauseEvent`, `FWEventTypeStandard`): IAB metric, pause
	- (`FWAdResumeEvent`, `FWEventTypeStandard`): IAB metric, resume
	- (`FWAdRewindEvent`, `FWEventTypeStandard`): IAB metric, rewind
	- (`FWAdMuteEvent`, `FWEventTypeStandard`): IAB metric, mute
	- (`FWAdUnmuteEvent`, `FWEventTypeStandard`): IAB metric, unmute
	- (`FWAdCollapseEvent`, `FWEventTypeStandard`): IAB metric, collapse
	- (`FWAdExpandEvent`, `FWEventTypeStandard`): IAB metric, expand
	- (`FWAdMinimizeEvent`, `FWEventTypeStandard`): IAB metric, minimize
	- (`FWAdCloseEvent`, `FWEventTypeStandard`): IAB metric, close
	- (`FWAdAcceptInvitationEvent`, `FWEventTypeStandard`): IAB metric, accept invitation

	@param eventName	Name of the event, see `FWAd*Event`
	@param eventType	Type of the event, see `FWEventType*`
	@return Array of urls in `NSString`
 */
- (NSArray *)getEventCallbackUrlsByEventName:(NSString *)eventName eventType:(NSString *)eventType;

/**
	Set callback urls for the specified event

	Valid eventName, eventType pairs:

	- (`FWAdImpressionEvent`， `FWEventTypeImpression`): ad impression
	- (`FWAdFirstQuartileEvent`, `FWEventTypeImpression`): firstQuartile
	- (`FWAdMidpointEvent`, `FWEventTypeImpression`): midpoint
	- (`FWAdThirdQuartileEvent`, `FWEventTypeImpression`): 3rd quartile
	- (`FWAdCompleteEvent`, `FWEventTypeImpression`): complete
	- (`FWAdClickEvent`, `FWEventTypeClick`): click through
	- (`FWAdClickEvent`, `FWEventTypeClickTracking`): click tracking
	- (`"custom_click_name"`, `FWEventTypeClick`): custom click through
	- (`"custom_click_name"`, `FWEventTypeClickTracking`): custom click tracking
	- (`FWAdPauseEvent`, `FWEventTypeStandard`): IAB metric, pause
	- (`FWAdResumeEvent`, `FWEventTypeStandard`): IAB metric, resume
	- (`FWAdRewindEvent`, `FWEventTypeStandard`): IAB metric, rewind
	- (`FWAdMuteEvent`, `FWEventTypeStandard`): IAB metric, mute
	- (`FWAdUnmuteEvent`, `FWEventTypeStandard`): IAB metric, unmute
	- (`FWAdCollapseEvent`, `FWEventTypeStandard`): IAB metric, collapse
	- (`FWAdExpandEvent`, `FWEventTypeStandard`): IAB metric, expand
	- (`FWAdMinimizeEvent`, `FWEventTypeStandard`): IAB metric, minimize
	- (`FWAdCloseEvent`, `FWEventTypeStandard`): IAB metric, close
	- (`FWAdAcceptInvitationEvent`, `FWEventTypeStandard`): IAB metric, accept invitation
 
 	@param urls		NSArray of urls to ping
	@param eventName	Name of the event, see `FWAd*Event`
	@param eventType	Type of the event, see `FWEventType*`
 */
- (void)setEventCallbackUrls:(NSArray *)urls forEventName:(NSString *)eventName eventType:(NSString *)eventType;

/**
	Add a creative rendition to the ad instance

	@return the `FWCreativeRendition` object added to the ad instance
 */
- (id<FWCreativeRendition>)addCreativeRendition;

/**
	Retrieve the parameter from the ad instance.

	The parameter value will be retrieved from levels in the following order: 
	override, creative rendition, creative, slot, profile, global.

	@param name  Parameter name
	@return The value of the parameter
 */
- (id)getParameter:(NSString *)name;

/**
   Get the universal ad ID of the ad instance.
   For more information on the IAB Universal Ad ID, please refer to section 3.7.1 in the VAST 4.0 spec: https://www.iab.com/guidelines/digital-video-ad-serving-template-vast-4-0/.
 
   @return an IABUniversalAdId object that contains the id registry and id value.
 */
- (id<FWIABUniversalAdId>)universalAdId;

/**
	Set the primary creative rendition

	@param primaryCreativeRendition	 a pointer to the primary creative rendition
 */
- (void)setPrimaryCreativeRendition:(id<FWCreativeRendition>)primaryCreativeRendition;

- (void)play2 DEPRECATED_ATTRIBUTE;

@end


/**
	Protocol for creative rendition
 */
@protocol FWCreativeRendition <NSObject>

#pragma mark - Properties

/**
	Get content type of the rendition

	@return  Content type in string
 */
- (NSString *)contentType;

/**
	Get wrapper type of the rendition

	@return  Wrapper type in string
 */
- (NSString *)wrapperType;

/**
	Get wrapper url of the rendition

	@return  Wrapper url in string
 */
- (NSString *)wrapperUrl;

/**
	Get creativeAPI of the rendition

	@return  creativeAPI in string
 */
- (NSString *)creativeAPI;

/**
	Get base unit of the rendition

	@return Base unit in a string
 */
- (NSString *)baseUnit;

/**
	Get preference of the rendition

	@return A number, the higher is preferred among all renditions in the creative
 */
- (int)preference;

/**
	Get width of the rendition

	@return Width in pixels
 */
- (NSUInteger)width;

/**
	Get height of the rendition

	@return Height in pixels
 */
- (NSUInteger)height;

/**
	Get duration of the rendition

	@return Duration in seconds
 */
- (NSTimeInterval)duration;

/**
	Get primary asset of the rendition

	@return An `FWCreativeRenditionAsset` instance
 */
- (id<FWCreativeRenditionAsset>)primaryCreativeRenditionAsset;

/**
	Get all non-primary assets of the rendition

	@return An array of `FWCreativeRenditionAsset`
 */
- (NSArray * /* <id>FWCreativeRenditionAsset */)otherCreativeRenditionAssets;

#pragma mark - Methods

/**
	Set content type of the rendition
 */
- (void)setContentType:(NSString *)value;

/**
	Set wrapper type of the rendition

	@param value Wrapper type of the creative rendition
 */
- (void)setWrapperType:(NSString *)value;

/**
	Set wrapper url of the rendition

	@param value Wrapper URL in string
 */
- (void)setWrapperUrl:(NSString *)value;

/**
	Set creativeAPI of the rendition

	@param: Creative API in string
 */
- (void)setCreativeAPI:(NSString *)value;

/**
	Set preference of the rendition

	@param value Rendition's preference
 */
- (void)setPreference:(int)value;

/**
	Set width of the rendition

	@param value Width of the rendition in pixels.
 */
- (void)setWidth:(NSUInteger)value;

/**
	Set height of the rendition

	@param value	Height of the rendition in pixels.
 */
- (void)setHeight:(NSUInteger)value;

/**
	Set duration of the rendition

	@return Duration in seconds
 */
- (void)setDuration:(NSTimeInterval)value;

/**
	Set parameter on the rendition

	@param name Name of the parameter
	@param value Value of the parameter
 */
- (void)setParameter:(NSString *)name withValue:(NSString *)value;

/**
	Add an asset to the rendition
 */
- (id<FWCreativeRenditionAsset>)addCreativeRenditionAsset;
@end


/**
	Protocol for creative rendition asset
 */
@protocol FWCreativeRenditionAsset <NSObject>

#pragma mark - Properties

/**
	Get name of the asset

	@return Name in a string
 */
- (NSString *)name;

/**
	Get URL of the asset

	@return URL in a string
 */
- (NSString *)url;

/**
	Get content of the asset

	@return Content in a string
 */
- (NSString *)content;

/**
	Get mime type of the asset

	@return Mime type in a string
 */
- (NSString *)mimeType;

/**
	Get content type of the asset

	@return Content type in a string
 */
- (NSString *)contentType;

/**
	Get size of the asset

	@return Size in bytes, or -1 if unknown
 */
- (NSInteger)bytes;

#pragma mark - Methods

/**
	Set name of the asset

	@param value Name of the asset
 */
- (void)setName:(NSString *)value;

/**
	Set URL of the asset

	@param value URL of the asset
 */
- (void)setUrl:(NSString *)value;

/**
	Set the content of the asset

	@param value Content of the asset
 */
- (void)setContent:(NSString *)value;

/**
	Set mime type of the asset

	@param value MIME type of the asset
 */
- (void)setMimeType:(NSString *)value;

/**
	Set content type of the asset

	@param value	Content type of the asset
 */
- (void)setContentType:(NSString *)value;

/**
	Set size of the asset

	@return Size in bytes, or -1 if unknown
 */
- (void)setBytes:(NSInteger)value;
@end


@protocol FWNotificationContext

- (void)postNotificationName:(NSString *)notificationName userInfo:(NSDictionary *)userInfo;

@end


/**
	Protocol for renderer controller

	The FWRendererController class provides methods for reporting metric events and changing renderer states.
 */
@protocol FWRendererController <NSObject>

#pragma mark - Properties

/**
	Return the current location.

	- SeeAlso: `setLocation:`

	@return current location
 */
- (CLLocation *)location;

/**
	Return application's current view controller. 

	- SeeAlso: `setCurrentViewController:`

	@return current view controller
 */
- (UIViewController *)currentViewController;

/**
	Return all renderable renditions for Renderer

	@return an array of `FWCreativeRendition`
*/
- (NSArray * /* id<FWCreativeRendition> */)renderableCreativeRenditions;

/**
	Return the Major version of AdManager, e.g. 0x02060000 for v2.6

	@return version as NSUInteger
 */
- (NSUInteger)version;

/**
	Get the current ad instance

	@return the current `FWAdInstance`
 */
- (id<FWAdInstance>)adInstance;

/**
	Returns the sender of all FreeWheel related notifications.
 */
- (id<FWNotificationContext>)notificationContext;

#pragma mark - Methods

/**
	Process an ad event

	@param eventName Ad event to be processed, see `FWAd*Event`
	@param details  Additional information. Available keys: `FWInfoKeyCustomEventName`: Optional. Name of the custom event. `FWInfoKeyShowBrowser`: Optional. Force opening / not opening click through url in WebView or Mobile Safari. If this key is not provided, AdManager will use the setting booked in MRM UI (recommended). `FWInfoKeyUrl`: Optional. URL to open or used as redirect url on FWAdClickEvent. If this key is not provided, the URL booked in MRM UI will be used.

 	- Note: This method should not be used to process `FWAdImpressionEvent` or `FWAdImpressionEndEvent`. Please use `[_rendererController handleStateTransition:FW_RENDERER_STATE_* info:nil]` for these events.
 */
- (void)processEvent:(NSString *)eventName info:(NSDictionary *)details;

/**
	Declare a capability of the renderer

	@param adEventName One of `FWAd*Event` excluding `FWAdImpressionEvent`, `FWAdFirstQuartileEvent`, `FWAdMidPointEvent`, `FWAdThirdQuartileEvent`, `FWAdCompleteEvent`
	@param supported `YES` if renderer is able to process the specified ad event

	- Note: Changing renderer capability after renderer starts playing may result in undefined behaviour.
 */
- (void)setSupportedAdEvent:(NSString *)adEventName supported:(BOOL)supported;

/**
	Retrieve a parameter

	@param name  Parameter name
 */
- (id)getParameter:(NSString *)name;

/**
	Transit renderer state

	@param state	Destination transition state to attempt, see `FWRendererState`
	@param details	Detailed info
	
	- Note: For `FWRendererStateFailed`: `FWInfoKeyErrorCode` are required. `FWInfoKeyErrorInfo` is optional.
 */
- (void)handleStateTransition:(FWRendererStateType)state info:(NSDictionary *)details;

/**
	Schedule ad instances for the given slots.

	@param slots	`NSArray` of `FWSlot`, slots to schedule ads for
	@return `NSArray` of scheduled `FWAdInstance` in the same sequence of the passed in slot. `nil` if no ad instance can be scheduled for the corresponding slot.
 */
- (NSArray * /* id<FWAdInstance> */)scheduleAdInstancesInSlots:(NSArray * /* id<FWSlot> */)slots;

/**
	Request timeline to pause. The timeline consists of the content video and all linear slots.

	When the renderer or extension requires the timeline to be temporarily paused, e.g. when expanding to a fullscreen view that covers the whole player and other ads, calling this method will result in the notification FWContentPauseRequestNotification being dispatched from the current FWContext instance if content video is currently playing, and pause requests sent to all active temporal slots.
 */
- (void)requestTimelinePause;

/**
	Request timeline to resume. The timeline consists of the content video and all linear slots.

	When the renderer or extension requires the timeline to be resumed, e.g. when dismissing a fullscreen view that covers the whole player and other ads, calling this method will result in the notification FWContentResumeRequestNotification being dispatched from the current FWContext instance if content video is currently paused, and send resume requests to all active temporal slots.
 */
- (void)requestTimelineResume;

/**
	Renderer should use this API to trace all logs
 
	@param msg Message to print in the log
 */
- (void)log:(NSString *)msg;

/**
	Get Initial Ad Volume

	@return initial ad volume at which the renderer should start the ad. Note: volume is expected to be in the range of [0,1]
 */
- (float)initialAdVolume;

@end


/**
	Protocol for FWRenderer
 */
@protocol FWRenderer <NSObject>

#pragma mark - Properties

/**
	Get module info. The returned dictionary should contain key `FWInfoKeyModuleType` with `FWModuleType*` value,
	and should contain key `FWInfoKeyRequiredSDKVersion` with the FreeWheel RDK version when the component is compiled.
 */
- (NSDictionary *)moduleInfo;


/**
	Get duration of the ad

	@return a positive number in seconds as `NSTimeInterval`, or -1 if the duration is N/A
 */
- (NSTimeInterval)duration;

/**
	Get playheadTime of the ad

	@return a positive number in seconds as `NSTimeInterval`, or -1 if the playhead time is N/A
 */
- (NSTimeInterval)playheadTime;

#pragma mark - Required Methods

/**
	Initialize the renderer with a renderer controller. 
	
	@param rendererController	reference to `FWRendererController`
		
	- Note: Typically the renderer declares all available capabilities and events when this method is called.
 	- See: `-[FWRendererController setSupportedAdEvent:supported:]`
 */
- (id)initWithRendererController:(id<FWRendererController>)rendererController;

/**
	Start ad playback.
	
	- Note: The renderer should start the ad playback when this method is called,
		and transit to `FWRendererStateStarted` state as soon as the ad has started.
		
		When the ad stops (either interrupted or reached the end), the renderer should
		transit to `FWRendererStateCompleted` state.
 */
- (void)start;

/**
	Stop ad playback.

	- Note: Typically the renderer will dispose playing images/videos from screen when receive this notification, and transit to `FWRendererStateCompleted` state as soon as the ad is stopped.
 */
- (void)stop;

/**
	Return the primary view on which the ad is rendered
 
	- Note: Please note, this method will be called immediately after the renderer transits to `FWRendererStateStarted`.
 */
- (UIView *)adView;

#pragma mark - Optional Methods
/**
	Preload the ad.

	- Note: Renderers should start preloading the ad asynchronously when this method is called, and transit to `FWRendererStatePreloaded` state when the ad finishes preloading. Translators should translate and schedule ads in the preloading stage.
 */
@optional
- (void)preload;

/**
	User intended pause. Should pause ad playback and send IAB _pause callback by calling `[rendererController processEvent:FWAdPauseEvent info:nil]`
 */
- (void)pause;

/**
	User intended resume. Should resume ad playback and send IAB _resume callback by calling `[rendererController processEvent:FWAdResumeEvent info:nil]`
 */
- (void)resume;

/**
	Set volume for current ad playback.
 
	When called, Renderer is expected to update the volume for the current ad playback and dispatch `FWAdVolumeChangedEvent` by calling `[_rendererController processEvent:FWAdVolumeChangedEvent info:[NSDictionary dictionaryWithObjectsAndKeys:@volume, FWInfoKeyAdVolume, nil]];` if the ad volume is changed

	@param volume. Volume for ad playback. Note: volume is expected to be in the range of [0,1]
 */
- (void)setVolume:(float)volume;

/**
	Return all potential friendly obstructions added by the renderer in the playback lifecycle.
 
	- Note: This method will be called immediately after the renderer transits to `FWRendererStateStarted`. The renderer should instantiate all the views it might ever add in the ad playback lifecycle. Failure to do so might result in OMSDK reporting the ad as not viewed by the user.
 */
- (NSArray *)getFriendlyObstructions;

@end

/**
	Protocol for FWExtension
 */
@protocol FWExtension <NSObject>

#pragma mark - Methods
/**
	Initialize the extension with a id<FWContext> instance.

	@param context	reference to id<FWContext>

	- Note: The constructor of the extension. AdManager will use this method to get an object of the extension.
 */
- (id)initWithFWContext:(id<FWContext>)context;

/**
	Stop the extension.

	- Note: Extension should stop all its work and do cleanup in the method.
 */
- (void)stop;

@end

/**
	FWVideoAdDelegate Protocol
 
	When your app needs to support AirPlay when app is backgrounded, you can no longer rely on the default Video Ad Renderer to render video ads since iOS only allows one AVPlayer instance to run in the background. Instead, your player should implement `FWVideoAdDelegate` protocol, and set itself as the `videoAdDelegate` of the current `FWContext` instance. When a video ad needs to be played / paused, the corresponding delegation method will be called and supplied with the video ad wrapped in a loaded `AVPlayerItem` instance.
 */
@protocol FWVideoAdDelegate <NSObject>

#pragma mark - Methods
/**
	The app should insert the provided `AVPlayerItem` object after another item in the item queue of an AVQueuePlayer instance.
	
	@param playerItem An `AVPlayerItem` object prepared by AdManager.
			item The `AVPlayerItem` object after which the object playerItem will be inserted. Nil value means that the object playerItem should be inserted at the end of the queue.
 
 	@return whether the provided AVPlayerItem instance can be inserted into the specified position in the current queue.
 
	- See: `videoAdDelegate`
 */
- (BOOL)playerShouldInsertItem:(AVPlayerItem *)playerItem afterItem:(AVPlayerItem *)item;

/**
	The app should start playing the provided `AVPlayerItem` object.
	
	@param playerItem An `AVPlayerItem` object that was prepared by AdManager and has been added to the queue. If the item hasn't started playing, start playing the item. If the item has started playing but has been paused during the playback, resume the item.
 
	- See: `videoAdDelegate`
 */
- (void)playerShouldPlayItem:(AVPlayerItem *)playerItem;

/**
	The app should pause the provided `AVPlayerItem` object if it's the currently playing item in the AVQueuePlayer instance.

	@param playerItem An `AVPlayerItem` object prepared by AdManager.

	- See: `videoAdDelegate`
 */
- (void)playerShouldPauseItem:(AVPlayerItem *)playerItem;

/**
	The app should remove the provided `AVPlayerItem` object from the item queue in the AVQueuePlayer instance that the app maintains. Note that the app should pause the player if the item is the current playing item in the AVQueuePlayer instance.
 
	@param playerItem The `AVPlayerItem` object that is to be removed from the queue.
 
	- See: `videoAdDelegate`
 */
- (void)playerShouldRemoveItem:(AVPlayerItem *)playerItem;

/**
    The app should set the player's volume to the value as specified. This method is required to be implemented by the app if the app would like the IAB mute and unmute events to be reported in AirPlay mode.

    @param volume the volume that the delegate should set on the AVQueuePlayer instance during playback
 
    @return whether the app was able to set the volume as expected

    - See: `videoAdDelegate`
 */
@optional
- (BOOL)playerShouldSetVolume:(float)volume;

@end

#pragma clang arc_cf_code_audited end
