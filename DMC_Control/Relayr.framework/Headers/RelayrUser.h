@class RelayrApp;                       // Relayr (Public)
@class RelayrPublisher;                 // Relayr (Public)
@class RelayrTransmitter;               // Relayr (Public/IoTs)
@class RelayrDevice;                    // Relayr (Public/IoTs)
#import <Relayr/RelayrID.h>             // Relayr (Public)
#import <Relayr/RelayrIDSubscripting.h> // Relayr (Utilities/Collections)
#import <Relayr/NSSet+RelayrID.h>       // Relayr (Utilities/Collections)
@import Foundation;                     // Apple

/*!
 *  @abstract The very basic entity in the relayr platform is the user. 
 *	@discussion Every user registers with an email address, a respective name and password and is assigned a unique userId. 
 *	A user can be both an application owner (a publisher) and an end user. 
 *	A user is required in order to add other entities to the relayr platform.
 *
 *  All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 */
@interface RelayrUser : NSObject <RelayrID,RelayrIDSubscripting,NSCopying,NSMutableCopying>

/*!
 *  @abstract The relayr application the user has signed in to.
 */
@property (readonly,weak,nonatomic) RelayrApp* app;

/*!
 *  @abstract A representation of a relayr user and their relayr application.
 *  @discussion This property does not change during the life cycle of the <code>RelayrUser</code> and it is never <code>nil</code>.
 */
@property (readonly,nonatomic) NSString* token;

/*!
 *  @abstract A user name for a specific <code>RelayrUser</code> instace.
 *  @discussion It can can be changed in a successful <code>queryCloudForUserInfo:</code> call.
 *      If <code>nil</code>, the name is unknown. If an empty string is returned, the name is not set on the server.
 */
@property (readonly,nonatomic) NSString* name;

/*!
 *  @abstract Sets a new user name.
 *  @discussion This method atttempts to push the new name to the server , if it is not successful, the local name is not changed.
 *
 *  @param name The new user name.
 *  @param completion A block indicating the result of the server push.
 */
- (void)setNameWith:(NSString*)name
         completion:(void (^)(NSError* error, NSString* previousName))completion;

/*!
 *  @abstract The user email for the specific <code>RelayrUser</code> instace.
 *  @discussion It can can be changed with a successful <code>queryCloudForUserInfo:</code> call.
 *      If <code>nil</code>, the email is unknown. If an empty string is returned, the email is not set in the server.
 */
@property (readonly,nonatomic) NSString* email;

/*!
 *  @abstract Sets a user's email to a new value.
 *  @discussion This method attempts to push the new email to the server, if it is not successful, the local name is not changed.
 *
 *  @param email The new user email.
 *  @param completion A block indicating the result of the server push.
 */
- (void)setEmail:(NSString*)email
      completion:(void (^)(NSError* error, NSString* previousEmail))completion;

/*!
 *  @abstract Queries the relayr platform for the user information.
 *  @discussion Every time this method is called a server query is launched.
 *	Once the response is returned successfuly, all the <i>readonly</i> user related properties are populated with the respective values.
 *
 *  @param completion A block indiciating whether the server query was successful or not.
 *
 *  @see queryCloudForIoTs:
 */
- (void)queryCloudForUserInfo:(void (^)(NSError* error, NSString* previousName, NSString* previousEmail))completion;

/*!
 *  @abstract The relayr applications installed (authorized) for the specific <code>RelayrUser</code> instace.
 *  @discussion It can can be changed with a successful <code>queryCloudForUserInfo:</code> call.
 *      If <code>nil</code>, the authorised apps are unknown. If an empty set is returned, there are no authorised apps.
 */
@property (readonly,nonatomic) NSSet <RelayrIDSubscripting>* authorisedApps;

/*!
 *  @abstract A set of <code>publisher</code>s listed under the specific user.
 *  @discussion It can be changed with a successful <code>queryCloudForUserInfo:</code> call.
 *      If <code>nil</code>, the publishers are unknown. If an empty set is returned, there are no publishers set in the server.
 */
@property (readonly,nonatomic) NSSet <RelayrIDSubscripting>* publishers;

/*!
 *  @abstract Queries the relayr platform for all the application and publisher entities owned by the user.
 *  @discussion Every time this method is called a server query is launched.
 *	Once the response is returned successfully, the <i>readonly</i> app and publisher properties are populated with the respective values.
 *
 *  @param completion A block indicating whether the server query was successful or not.
 */
- (void)queryCloudForPublishersAndAuthorisedApps:(void (^)(NSError* error))completion;

/*!
 *  @abstract A set of the Transmitter entities owned by the specific <code>RelayrUser</code> instace.
 *  @discussion It can be changed with a successful <code>queryCloudForUserInfo:</code> call.
 *      If <code>nil</code>, the transmitters are unknown. If an empty set is returned, there are no transmitters owned by the user in the server.
 */
@property (readonly,nonatomic) NSSet <RelayrIDSubscripting>* transmitters;

/*!
 *  @abstract A set of the Device entities owned by the specific <code>RelayrUser</code> instace
 *  @discussion It can be changed with a successful <code>queryCloudForUserInfo:</code> call.
 *      If <code>nil</code>, the devices are unknwon. If an empty set is returned, there are no devices owned by this user in the server.
 */
@property (readonly,nonatomic) NSSet <RelayrIDSubscripting>* devices;

/*!
 *  @abstract Devices that the specific <code>RelayrUser</code> instace has bookmarked. Only public devices can be bookmarked devices.
 *  @discussion It can be changed with a successful <code>queryCloudForUserInfo:</code> call. 
 *      By Bookmarking a device you are indicating that you have a particular interest in it.
 *      In the relayr context, a bookmarked device will appear on a user's Developer Dashboard.
 *      If <code>nil</code>, the devices bookmarked are unknwon. If an empty set is returned, there are no devices bookmarked by this user.
 */
@property (readonly,nonatomic) NSSet <RelayrIDSubscripting>* devicesBookmarked;

/*!
 *  @abstract Queries the relayr platform for all devices, transmitters, and bookmarked devices under the specific <code>RelayUser</code> instance.
 *  @discussion Every time this method is called a server query is launched. 
 *	Once the response is returned successfuly, all the <i>readonly</i> device related properties are populated with the respective values.
 *
 *  @param completion A block indicating whether the server query was successful or not.
 *
 *  @see queryCloudForUserInfo:
 */
- (void)queryCloudForIoTs:(void (^)(NSError* error))completion;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible user's transmitter connected to devices that are capable of read the meanings passed as argument.
 *  @discussion If no transmitters are found, <code>nil</code> is returned.
 *
 *  @param meanings The specific meanings that the readings must be capable to <i>read</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrTransmitter</code> objects.
 *
 *  @see RelayrTransmitter
 */
- (NSSet <RelayrIDSubscripting>*)transmittersWithReadingMeanings:(NSArray*)meanings;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible user's devices that are capable of read the meanings passed as argument.
 *  @discussion If no devices are found, <code>nil</code> is returned.
 *
 *  @param meanings The specific meanings that the readings must be capable to <i>read</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrDevice</code> objects.
 *
 *  @see RelayrDevice
 */
- (NSSet <RelayrIDSubscripting>*)devicesWithReadingMeanings:(NSArray*)meanings;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible user's devices that are capable of sending the meanings passed as argument.
 *  @discussion If no devices are found, <code>nil</code> is returned.
 *
 *  @param meanings The specific meanings that the command must be capable to <i>send</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrDevice</code> objects.
 *
 *  @see RelayrDevice
 */
- (NSSet <RelayrIDSubscripting>*)devicesWithCommandMeanings:(NSArray*)meanings;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible <code>RelayrReading</code> objects that are capable of <i>read</i> the meanings passed as argument.
 *  @discussion If no devices are found, <code>nil</code> is returned.
 *
 *  @param meanings The specific meanings that the readings must be capable to <i>read</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrDevice</code> objects.
 *
 *  @see RelayrReading
 */
- (NSSet <RelayrIDSubscripting>*)readingsWithMeanings:(NSArray*)meanings;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible <code>RelayrCommand</code> objects that are capable of <i>sending</i> the meanings passed as argument.
 *  @discussion If no devices are found, <code>nil</code> is returned.
 *
 *  @param meanings The specific meanings that the readings must be capable to <i>send</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrCommand</code> objects.
 *
 *  @see RelayrReading
 */
- (NSSet <RelayrIDSubscripting>*)commandsWithMeanings:(NSArray*)meanings;

/*!
 *  @abstract Creates/registers a Transmitter entity on the Relayr cloud.
 *  @discussion If this call is successful a <code>RelayrTransmitter</code> object is created and is added to the <code>transmitters</code> array.
 *
 *  @param modelID Idetifier for the newly created transmittter instance. Currently, this argument must be <code>nil</code>. 
 *  @param firmwareVersion The version of the firmware running on the transmitter. Currently, this argument must be <code>nil</code>.
 *  @param name The given name to identify the transmitter. This parameter is required.
 *  @param completion A Block indicating whether the server registration call was successful or not. It can be <code>nil</code>.
 *
 *  @see RelayrTransmitter
 */
- (void)registerTransmitterWithModelID:(NSString*)modelID
                        firmwareVerion:(NSString*)firmwareVersion
                                  name:(NSString*)name
                            completion:(void (^)(NSError* error, RelayrTransmitter* transmitter))completion;

/*!
 *  @abstract Deletes a transmitter entity from the relayr platform as well as from the iOS/OSX client.
 *
 *  @param transmitter the relayr transmitter to be deleted.
 *  @param completion A block indicating whether the server call was successful or not. It can be <code>nil</code>
 *
 *  @see RelayrTransmitter
 */
- (void)deleteTransmitter:(RelayrTransmitter*)transmitter
               completion:(void (^)(NSError* error))completion;

/*!
 *  @abstract Creates/registers a device entity on the relayr cloud.
 *  @discussion If this call is successful a <code>RelayrDevice</code> object is created and is added to the <code>devices</code> array.
 *
 *  @param modelID Identifier for the newly created device instance. This parameter is required.
 *  @param firmwareVersion The version of the firmware running on the device. This parameter is required.
 *  @param name The given name to identify this device. This parameter is required.
 *  @param completion A block indicating whether the server registration call was successful or not. It can be <code>nil</code>.
 *
 *  @see RelayrDevice
 */
- (void)registerDeviceWithModelID:(NSString*)modelID
                   firmwareVerion:(NSString*)firmwareVersion
                             name:(NSString*)name
                       completion:(void (^)(NSError* error, RelayrDevice* device))completion;

/*!
 *  @abstract Deletes a device entity from the relayr platform as well as from the iOS/OSX client.
 *
 *  @param device The relayr device to be deleted.
 *  @param completion A block indicating whether the server call was successful or not. It can be <code>nil</code>
 *
 *  @see RelayrDevice
 */
- (void)deleteDevice:(RelayrDevice*)device
          completion:(void (^)(NSError* error))completion;

@end
