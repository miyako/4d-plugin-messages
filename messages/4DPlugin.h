/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.h
 #	source generated by 4D Plugin Wizard
 #	Project : Messages
 #	author : miyako
 #	2016/05/25
 #
 # --------------------------------------------------------------------------------*/

#import <ScriptingBridge/ScriptingBridge.h>

@class MessagesApplication, MessagesItem, MessagesBuddy, MessagesService;

@interface MessagesApplication : SBApplication
- (void) send:(id)x to:(id)to;  // Sends a message or file to a buddy or to a chat.
- (SBElementArray *) buddies; // <MessagesBuddy *>
- (SBElementArray *) services; // <MessagesService *>
@end

@protocol MessagesGenericMethods
//- (void) closeSaving:(MessagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.
@end

@interface MessagesItem : SBObject <MessagesGenericMethods>
@property (copy) NSDictionary *properties;  // All of the object's properties.
@end

enum MessagesAccountStatus {
	MessagesAccountStatusAvailable = 'aval',
	MessagesAccountStatusAway = 'away',
	MessagesAccountStatusOffline = 'offl',
	MessagesAccountStatusInvisible = 'invs',
	MessagesAccountStatusIdle = 'idle',
	MessagesAccountStatusUnknown = 'unkn'
};
typedef enum MessagesAccountStatus MessagesAccountStatus;

@interface MessagesBuddy : MessagesItem
- (NSString *) id;  // The buddy's service and handle. For example: AIM:JohnDoe007
@property (copy, readonly) MessagesService *service;  // The service on which this buddy exists.
@property (copy, readonly) NSString *name;  // The buddy's name as it appears in the buddy list.
@property (copy, readonly) NSString *handle;  // The buddy's online account name.
@property (readonly) MessagesAccountStatus status;  // The buddy's current status.
@property (copy, readonly) NSString *statusMessage;  // The buddy's current status message.
@property (readonly) NSInteger idleTime;  // The time in seconds the buddy has been idle.
@property (copy, readonly) NSImage *image;  // The buddy's custom image.
@end

enum MessagesConnectionStatus {
	MessagesConnectionStatusDisconnecting = 'dcng',
	MessagesConnectionStatusConnected = 'conn',
	MessagesConnectionStatusConnecting = 'cong',
	MessagesConnectionStatusDisconnected = 'dcon'
};
typedef enum MessagesConnectionStatus MessagesConnectionStatus;

enum MessagesMyStatus {
	MessagesMyStatusAway = 'away',
	MessagesMyStatusAvailable = 'aval',
	MessagesMyStatusOffline = 'offl',
	MessagesMyStatusInvisible = 'invs'
};
typedef enum MessagesMyStatus MessagesMyStatus;

enum MessagesServiceType {
	MessagesServiceTypeAIM = 'saim',
	MessagesServiceTypeBonjour = 'ssub',
	MessagesServiceTypeJabber = 'sjab',
	MessagesServiceTypeIMessage = 'sims'
};
typedef enum MessagesServiceType MessagesServiceType;

@interface MessagesService : MessagesItem
- (SBElementArray *) buddies; // <MessagesBuddy *>
- (NSString *) id;  // A guid identifier for this service.
@property (copy) NSString *name;  // The name of this service as defined in Account preferences description field
@property BOOL enabled;  // Is the service enabled?
@property (readonly) MessagesConnectionStatus connectionStatus;  // The connection status for this account.
@property MessagesMyStatus status;  // My status on this service.
@property (copy) NSString *statusMessage;  // My status message, visible to other people on this service while I am online.
@property (readonly) MessagesServiceType serviceType;  // The type of protocol for this service
- (void) logIn;  // Log in to the specified service, or all services if none is specified. If the account password is not in the keychain the user will be prompted to enter one.
- (void) logOut;  // Logs out of a service, or all services if none is specified.
@end

// --- Messages
void MESSAGE_SERVICE_LIST(sLONG_PTR *pResult, PackagePtr pParams);
void MESSAGE_SERVICE_BUDDY_LIST(PA_PluginParameters params);
void MESSAGE_SERVICE_LOGIN(sLONG_PTR *pResult, PackagePtr pParams);
void MESSAGE_SERVICE_LOGOUT(sLONG_PTR *pResult, PackagePtr pParams);
void MESSAGE_SEND(sLONG_PTR *pResult, PackagePtr pParams);
