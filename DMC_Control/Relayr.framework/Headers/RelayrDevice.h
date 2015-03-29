#import <Relayr/RelayrDeviceModel.h>    // Parent class
@class RelayrTransmitter;               // Relayr (Public/IoTs)
@class RelayrFirmware;                  // Relayr (Public/IoTs)
@class RelayrConnection;                // Relayr (Public/IoTs)
#import <Relayr/RelayrReading.h>        // Relayr (Public/IoTs)
#import <Relayr/RelayrCommand.h>        // Relayr (Public/IoTs)
@protocol RelayrOnboarding;             // Relayr (Public)
@protocol RelayrFirmwareUpdate;         // Relayr (Public)
#import <Relayr/RelayrID.h>             // Relayr (Public)
@import Foundation;                     // Apple

/*!
 *  @abstract An instance of this class represents a Device. A basic relayr entity
 *	@discussion A device is any external entity capable of producing measurements and sending them to a transmitter to be further sent to the relayr cloud, or one which is capable of receiving information from the relayr platform. 
 *	Examples would be a thermometer, a gyroscope or an infrared sensor.
 *
 *  All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 */
@interface RelayrDevice : RelayrDeviceModel <RelayrID,NSCopying,NSMutableCopying>

/*!
 *  @abstract Device name.
 *  @discussion Can be updated using a server call.
 */
@property (readonly,nonatomic) NSString* name;

/*!
 *  @abstract Changes the Device's name and pushes it to the server.
 *  @discussion If the server is not reachable or in case of a problem, and error will be returned in the completion block and the name won't be changed;
 *
 *  @param name A new name to identify the device with.
 *  @param completion Block indicating the result of the server push.
 */
- (void)setNameWith:(NSString*)name
         completion:(void (^)(NSError* error, NSString* previousName))completion;

/*!
 *  @abstract The transmitter that the Device is associated with.
 *  @discussion Note: using this property implies a deep search on the IoT tree. Only use it when necessary.
 *
 *  @return A fully initialised transmitter or <code>nil</code>.
 */
@property (readonly,weak,nonatomic) RelayrTransmitter* transmitter;

/*!
 *  @abstract The ID of the owner of the Device.
 *  @discussion A relayr User Id.
 */
@property (readonly,nonatomic) NSString* owner;

/*!
 *  @abstract Indicates whether the data gathered by the device is public (available to all users) or not (available to the Device owner only).
 *  @discussion An <code>NSNumber</code> wrapping a boolean value (use <code>.boolValue</code> to unwrap it). 
 */
@property (readonly,nonatomic) NSNumber* isPublic;

/*!
 *  @abstract Indicates the firmware attributes of the device instance being called.
 *  @discussion A device may have many different firmware versions. This indicates the firmware version of the device called.
 */
@property (readonly,nonatomic) RelayrFirmware* firmware;

/*!
 *  @abstract The secret for MQTT comminucation with the relayr Cloud Platform
 *  @discussion Could be seen as the Device's password.
 */
@property (readonly,nonatomic) NSString* secret;

/*!
 *  @abstract Represents the connection via which data is received.
 *  @discussion Abstraction of the connection between the system running the SDK and the source data. 
 *  Thus, if you are connecting directly to a specific device (through BLE, NFC, etc.), this object will specify it. 
 *  However, if the data is coming from the relayr Cloud the connection will be of type <i>cloud</i>. 
 *  The actual connection between the device and the cloud is not specified by this object.
 *      This object is never <code>nil</code>.
 */
@property (readonly,nonatomic) RelayrConnection* connection;

#pragma mark Processes

/*!
 *  @abstract Denotes a physical device with the properties of this <code>RelayrDevice</code> entity.
 *  @discussion During the onboarding process the properties required for the device to be added to the relayr cloud are written 
 *	to the physical memory of the targeted device. 
 *	
 *
 *
 *  @param onboardingClass In charge of the onboarding process. This class "knows" how to communicate with the specific device.
 *  @param timeout The maximum duration of the onboarding process in seconds. 
 *	If the onboarding process doesn't finish within the specified timeout, the completion block is executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. 
 *	If a negative number is passed, the block is returned with a respective error.
 *  @param options Specific options for the device onboarded. The specific <code>RelayrOnboarding</code> class will list all additional variables required for a successful onboarding.
 *  @param completion A Block indicating whether the onboarding process was successful or not.
 */
- (void)onboardWithClass:(Class <RelayrOnboarding>)onboardingClass
                 timeout:(NSNumber*)timeout
                 options:(NSDictionary*)options
              completion:(void (^)(NSError* error))completion;

/*!
 *  @abstract Performs a firmware update on the specific device.
 *
 *  @param updateClass In charge of the firmware update process. This class "knows" how to communicate with the specific device.
 *  @param timeout The maximum duration of the update process in seconds. 
 *	If the update process doesn't finish within the specified timeout, the completion block is executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. 
 *	If a negative number is passed, the block is returned with a respective error.
 *  @param options Specific options for the device updated. The specific <code>RelayrFirmwareUpdate</code> class will list all additional variables required for a successful firmware update.
 *  @param completion A Block indicating whether the update process was successful or not.
 */
- (void)updateFirmwareWithClass:(Class <RelayrFirmwareUpdate>)updateClass
                        timeout:(NSNumber*)timeout
                        options:(NSDictionary*)options
                     completion:(void (^)(NSError* error))completion;

#pragma mark Subscriptions

/*!
 *  @abstract A virtual property indicating whether there are ongoing subscriptions (connections, readings, etc.).
 *  @discussion Every time this property is called, a calculation is made to check if there are ongoing subscriptions.
 */
@property (readonly,nonatomic) BOOL hasOngoingSubscriptions;

/*!
 *  @abstract A virtual property indicating whether there are ongoing reading subscriptions.
 *  @discussion Every time this property is called, a calculation is made to check if there are ongoing reading subscriptions.
 */
@property (readonly,nonatomic) BOOL hasOngoingReadingSubscriptions;

/*!
 *  @abstract Subscribes a block to the data sent from the <code>RelayrDevice</code>.
 *  @discussion Regardless of how the device is connected (Web/Cloud, Bluetooth, etc.),
 *	The action is called as soon as data is available.
 *
 *  @param block This block will be executed everytime data is available (and it is compulsory). The block contains three parameters:
 *      - <code>device</code>. The device producing the reading.
 *      - <code>reading</code>. The reading value received.
 *      - <code>unsubscribe</code>. A Boolean variable, that when set to <code>NO</code>, will stop the subscription.
 *  @param errorBlock A Block executed every time an error occurs. 
 *	The error could be received because the subscription could not be completed, or because the subscription is stopped by an external factor. 
 *	If this block is defined, a boolean must be returned, indicating if a subscription retry should be attempted.
 *
 *  @note If the method doesn't provide the block argument, the <code>errorBlock</code> won't give the option to retry to subscribe.
 *
 *  @see RelayrReading
 */
- (void)subscribeToAllReadingsWithBlock:(RelayrReadingDataReceivedBlock)block
                                  error:(RelayrReadingErrorReceivedBlock)errorBlock;

/*!
 *  @abstract Subscribes the target object to all data (all readings) sent from the <code>RelayrDevice</code>.
 *  @discussion Regardless of how the device is connected (Web/Cloud, Bluetooth, etc.), 
 *	The action is called as soon as the data is available.
 *
 *  @param target The object where the <code>action</code> is called onto.
 *  @param action The method to be called. It can have two modes:
 *      - No parameters.
 *      - One parameter. The parameter must be a <code>RelayrReading</code> object, otherwise this method will return a subscription error.
 *  @param errorBlock A Block executed every time an error occurs. 
 *	The error could be received because the subscription could not be completed, or because the subscription is stopped by an external factor. 
 *	If this block is defined, a boolean must be returned, indicating if a subscription retry should be attempted.
 *
 *  @note If the method doesn't provide the target or the target cannot perform the action, the <code>errorBlock</code> won't give the option to retry to subscribe.
 *
 *  @see RelayrReading
 */
- (void)subscribeToAllReadingsWithTarget:(id)target
                                  action:(SEL)action
                                   error:(RelayrReadingErrorReceivedBlock)errorBlock;

/*!
 *  @abstract Removes all subscriptions for the device (including readings and connection subscriptions).
 *  @discussion All subscriptions, whether blocks or target objects are removed.
 */
- (void)unsubscribeToAll;

#pragma mark - Temporal functionality (to be deleted soon)

/*!
 *  @abstract It sends a command with the JSON body specified as an argument.
 *
 *  @param jsonDictionary An <code>NSDictionary</code> representing the JSON body send to the API as a command. You need to be sure that all attribute keys and values can be converted.
 *  @param completion Block indicating whether the command could be sent or not.
 *
 */
- (void)sendCommandWithJSON:(NSDictionary*)jsonDictionary completion:(void (^)(NSError* error))completion;

@end
