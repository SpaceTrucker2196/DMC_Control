@class RelayrUser;      // Relayr (Public)
@import Foundation;     // Apple

/*!
 *  @abstract This class object represents the relayr <a href="https://developer.relayr.io/documents/Welcome/Platform">Cloud Platform</a> (it does not accept instantiation).
 *  @discussion It allows high level interaction with the relayr platform. 
 *	For example: checking if the platform is available or if the connection is broken.
 */
@interface RelayrCloud : NSObject

#pragma mark Cloud information

/*!
 *  @abstract Checks if the relayr cloud platform is reachable and whether the service is up or not.
 *  @discussion The Relayr cloud may be unreachable for various reasons such as no internet connection, inability to resolve DNS, temporary unavailability of the relayr service. 
 *	Please note that you can still work with the SDK even when the relayr cloud is unavailable (in the unlikely case that this happens).
 *
 *  @param completion A block with a Boolean with the availability status of the service or an error in case of unavailibility
 */
+ (void)isReachable:(void (^)(NSError* error, NSNumber* isReachable))completion;

/*!
 *  @abstract Checks whether an email is registered on the relayr platform.
 *
 *  @param email <code>NSString</code> representing the user's email address.
 *  @param completion A block with the respective response.
 *
 *  @see RelayrUser
 */
+ (void)isUserWithEmail:(NSString*)email
             registered:(void (^)(NSError* error, NSNumber* isUserRegistered))completion;

/*!
 *  @abstract Returns an array with all public relayr applications on the relayr cloud.
 *  @discussion Since this array can be very long, the info returned is not very extended.
 *
 *  @param completion A block indicating the result of the query. If no error occurs, an <code>NSSet</code> will be returned with all public relayr applications
 */
+ (void)queryForAllRelayrPublicApps:(void (^)(NSError* error, NSSet* apps))completion;

#pragma mark Logging system

/*!
 *  @abstract Sends a log message to the relayr cloud on behalf of the relayr User.
 *  @discussion Logging messages allows for more information about the operation of an application. 
 *	You can log anything you want and later on check your adminastrator page and receive 
 *	statistical data from your application usage, or any other metrics.
 *
 *  @param message An <code>NSString</code> with the looging message of your choice. The string can be anything except for <code>nil</code> or an empty string..
 *  @param user A <code>RelayrUser</code>. If this parameter is <code>nil</code> or in case the user was incorrectly logged in, this method won't perform anything.
 *  @return Boolean indicating whether the message has been accepted to be sent by the server or not.
 */
+ (BOOL)logMessage:(NSString*)message onBehalfOfUser:(RelayrUser*)user;

#pragma mark System information

/*!
 *  @abstract Returns a <code>NSString</code> identifying the Relayr SDK version and machine.
 *  @discussion Typically used for adding an HTTP header.
 */
+ (NSString*)userAgentString;

/*!
 *  @abstract Returns the version number of the Relayr SDK currently used.
 */
+ (NSString*)sdkVersionNumber;

/*!
 *  @abstract Returns an <code>NSString</code> with the Operating system name (and version number) currently running the SDK.
 */
+ (NSString*)operatingSystem;

/*!
 *  @abstract Returns an <code>NSString</code> with the platform name or architecture currently running the SDK.
 */
+ (NSString*)platform;

@end
