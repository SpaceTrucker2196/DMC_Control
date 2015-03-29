@class RelayrUser;                      // Relayr (Public)
#import <Relayr/RelayrID.h>             // Relayr (Public)
@import Foundation;                     // Apple

/*!
 *  @abstract Represents a relayr Application which allows interaction with the relayr Cloud.
 *  @discussion An app is a basic entity in the relayr platform. 
 *	The relayr platform relates to apps in two manners: Publisher Apps and User Apps.
 *	Publisher apps are apps which are purchasable on an app store and are owned by a publisher.
 *	User apps are apps which have been approved to receive the data of an end user. This approval has been granted by the user.
 *
 *  All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 */
@interface RelayrApp : NSObject <RelayrID,NSCopying,NSMutableCopying>

#pragma mark Characteristics

/*!
 *  @abstract The relayr application name.
 *  @discussion This value should first be retrieved asynchronously, from the relayr server. 
 *	If the server is not queried, this property is <code>nil</code>.
 */
@property (readonly,nonatomic) NSString* name;

/*!
 *  @abstract Changes the relayr application name and pushes the change to the server.
 *  @discussion If the server is not reachable or in case of a problem, an error will be returned in the completion block and the name won't be changed;
 *
 *  @param name A new name to identify the application with.
 *  @param user To set up an application's name, a user with the appropriate credentials for the setup is required.
 *  @param completion A block indicating the result of the server push.
 */
- (void)setName:(NSString*)name
withUserCredentials:(RelayrUser*)user
         completion:(void (^)(NSError* error, NSString* previousName))completion;

/*!
 *  @abstract The relayr application description.
 *  @discussion This value should first be retrieved asynchronously, from the relayr server. If the server is not queried, this property is <code>nil</code>.
 */
@property (readonly,nonatomic) NSString* appDescription;

/*!
 *  @abstract Changes the relayr application's description and pushes the change to the server.
 *  @discussion If the server is not reachable or in case of a problem, an error will be returned in the completion block and the name won't be changed;
 *
 *  @param description The new description string given to the application.
 *  @param user To set the description, a user with the appropriate credentials for the setup is required.
 *  @param completion A block indicating the result of the server push.
 */
- (void)setDescription:(NSString*)description
   withUserCredentials:(RelayrUser*)user
                completion:(void (^)(NSError* error, NSString* previousDescription))completion;

/*!
 *  @abstract The ID of the app's Publisher.
 *  @discussion This value should first be retrieved asynchronously, from the relayr server. 
 *	If the server is not queried, this property is <code>nil</code>.
 */
@property (readonly,nonatomic) NSString* publisherID;

/*!
 *  @abstract OAuth client (app) secret.
 */
@property (readonly,nonatomic) NSString* oauthClientSecret;

/*!
 *  @abstract The OAuth redirect URI.
 *  @discussion The URI of the page where the user is redirected upon successful login. The URI must include the protocol used e.g. 'http'. 
 *	The redirect URI is set when an application is registered on the relayr Platform. 
 *	@see <a href="https://developer.relayr.io/documents/Authorization/OAuthAndRelayr">The OAuth section on the Develooper Dashboard.</a>
 */
@property (readonly,nonatomic) NSString* redirectURI;

/*!
 *  @abstract Queries the server for missing application properties. A User with credentials is required to retrieve this information.
 *  @discussion The method is called asynchronously. 
 *	If the request is successful, old values will be written as block arguments, and new ones will be set in the <code>RelayrApp</code> instance. Not only name and description are queried, but also publisher info and other security measures are tested.
 *
 *  @param completion A block with the status of the request.
 */
- (void)queryForAppInfoWithUserCredentials:(RelayrUser*)user
                                completion:(void (^)(NSError* error, NSString* previousName, NSString* previousDescription))completion;

#pragma mark Lifecycle

/*!
 *  @abstract Retrieves an applicationID from the relayr server or creates one and queries the server for its authenticity.
 *
 *  @param appID <code>NSString</code> representing the relayr Application ID. Generated when creating an app on the relayr developer dashboard.
 *  @param clientSecret <code>NSString</code> representing the OAuth client secret. Generated when creating an app on the relayr developer dashboard.
 *  @param redirectURI <code>NSString</code> representing the redirect URI entered when creating an app on the relayr developer dashboard.
 *  @param completion A block indicating the result of the initialization. Note: This method is potentially asynchronous, if it does need to talk to the server.
 *
 *  @see RelayrCloud
 */
+ (void)appWithID:(NSString*)appID
OAuthClientSecret:(NSString*)clientSecret
      redirectURI:(NSString*)redirectURI
       completion:(void (^)(NSError* error, RelayrApp* app))completion;

/*!
 *  @abstract Persist a <code>RelayrApp</code> and its logged users in the File System.
 *
 *  @param app The relayr application to be stored.
 *	@return Boolean indicating whether the operation was successful or not.
 */
+ (BOOL)persistAppInFileSystem:(RelayrApp*)app;

/*!
 *  @abstract Retrieves a previously stored relayr application from the File System..
 *
 *  @param appID The ID of the application.
 *	@return A fully initialized <code>RelayrApp</code> or <code>nil</code>.
 */
+ (RelayrApp*)retrieveAppWithIDFromFileSystem:(NSString*)appID;

/*!
 *  @abstract Removes a previously stored relayr application from the File System.
 *
 *  @param app The relayr application to be removed.
 *	@return If the object is successfully removed or not found, <code>YES</code> is returned. If the remove operation could not be performed, the method will return <code>NO</code>.
 */
+ (BOOL)removeAppFromFileSystem:(RelayrApp*)app;

#pragma mark Users

/*!
 *  @abstract An Array containing all logged in <code>RelayrUser</code>s.
 *  @discussion By logged in, we refer to user credentials which are stored by the application. 
 *	Calling the sign out method, will remove those credential from the application.
 */
@property (readonly,nonatomic) NSArray* loggedUsers;

/*!
 *  @abstract Retrieves a logged in user (<code>loggedUsers</code>) according to their Id. 
 *  @discussion This is a convenience method. It replaces having to iterate through the <code>loggedUsers</code> array searching for the relevant user.
 *	If the user is not logged in or not valid, <code>nil</code> is returned.
 *
 *  @param relayrID The ID that identifies the user on the relayr platform.
 *	@return <code>nil</code> or the <code>RelayrUser</code> with the specific <code>relayrID</code>.
 *
 *  @see RelayrUser
 */
- (RelayrUser*)loggedUserWithRelayrID:(NSString*)relayrID;

/*!
 *  @abstract Signs a relayr user in to the current relayr application and returns an object representing the user (in the completion block).
 *  @discussion The user will be prompted with a modal webview asking for their relayr credentials. 
 *	If the sign in process is successful, a fully formed <code>RelayrUser</code> object will be returned in the <code>completion</code> block.
        Start by querying loggedUsers. 
        This method should only be used when looking for credentials of a relayr User not already in the <code>loggedUsers</code> array
        or when you wish to register a new user on the relayr platform.
        If the user is already logged in and a part of the <code>loggedUsers</code> array, you will receive the <code>RelayrUser</code> in that array rather than a new instance.
 *
 *  @param completion An Asynchronous block with the status of the sign in process.
 *
 *  @see RelayrUser
 */
- (void)signInUser:(void (^)(NSError* error, RelayrUser* user))completion;

/*!
 *  @abstract Signs a user out of the application.
 *  @discussion What this method actually does is to remove the user from the stored users array. 
 *	The <code>RelayrUser</code> reference is kept, so you can still use it.
 *
 *  @param user A representaton of a relayr user. 
 *	If the <code>RelayrUser</code> is not valid or <code>nil</code>, this method will not perform anything.
 *
 *  @see RelayrUser
 */
- (void)signOutUser:(RelayrUser*)user;

@end
