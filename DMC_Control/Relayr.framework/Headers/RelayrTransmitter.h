@class RelayrUser;                      // Relayr (Public)
@protocol RelayrOnboarding;             // Relayr (Public/IoTs/Processes)
@protocol RelayrFirmwareUpdate;         // Relayr (Public/IoTs/Processes)
#import <Relayr/RelayrID.h>             // Relayr (Public)
#import <Relayr/RelayrIDSubscripting.h> // Relayr (Utilities/Collections)
#import <Relayr/NSSet+RelayrID.h>       // Relayr (Utilities/Collections)
@import Foundation;                     // Apple

/*!
 *  @abstract An instance of this class represents a relayr Transmitter. a basic entity on the relayr platform.
 *  @discussion A transmitter contrary to a device does not gather data but is only used to relay the data from the devices to the relayr platform. The transmitter is also used to authenticate the different devices that transmit data via it.
 *
 *  All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 */
@interface RelayrTransmitter : NSObject <RelayrID,RelayrIDSubscripting,NSCopying,NSMutableCopying>

/*!
 *  @abstract User currently "using" this transmitter.
 *  @discussion A public device can be owned by another Relayr user, but being used by your <code>RelayrUser</code> entity.
 */
@property (readonly,weak,nonatomic) RelayrUser* user;

/*!
 *  @abstract Transmitter name.
 */
@property (readonly,nonatomic) NSString* name;

/*!
 *  @abstract Changes the transmitter's name and pushes the change to the server.
 *  @discussion If the server is not reachable or in case of a problem, an error will be returned in the completion block and the name won't be changed;
 *
 *  @param name A new name to identify the transmitter with.
 *  @param completion Block indicating the result of the server push.
 */
- (void)setNameWith:(NSString*)name
         completion:(void (^)(NSError* error, NSString* previousName))completion;

/*!
 *  @abstract The owner ID of the specific transmitter, a relayr user.
 */
@property (readonly,nonatomic) NSString* owner;

/*!
 *  @abstract The secret for MQTT comminucation with the relayr <a href="https://developer.relayr.io/documents/Welcome/Platform">Cloud Platform</a>.
 *  @discussion It can be seen as the transmitter's password.
 */
@property (readonly,nonatomic) NSString* secret;

/*!
 *  @abstract Returns all devices related to the specific transmitter.
 *  @discussion Links to <code>RelayrDevice</code>s owned by the <code>RelayrUser</code>, which owns the Transmitter.
 *      If this property is <code>nil</code>, the number of devices managed by this transmitter is unknown. 
 *		You should query the server for more information. 
 *		If this property is an empty set, the transmitter doesn't manage any devices.
 */
@property (readonly,nonatomic) NSSet <RelayrIDSubscripting>* devices;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible transmitter's devices that are capable of read the meanings passed as argument.
 *  @discussion If no devices are found, <code>nil</code> is returned.
 *
 *  @param meanings The specific meanings that the readings must be capable to <i>read</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrDevice</code> objects.
 *
 *  @see RelayrDevice
 */
- (NSSet <RelayrIDSubscripting>*)devicesWithReadingMeanings:(NSArray*)meanings;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible <code>RelayrReading</code> objects that are capable of <i>read</i> the meanings passed as argument.
 *  @discussion If no readings are found, <code>nil</code> is returned.
 *
 *  @param meanings The specific meanings that the readings must be capable to <i>read</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrDevice</code> objects.
 *
 *  @see RelayrReading
 */
- (NSSet <RelayrIDSubscripting>*)readingsWithMeanings:(NSArray*)meanings;

#pragma mark Processes

/*!
 *  @abstract Initialises a physical transmitter with the properties of this <code>RelayrTransmitter</code> entity.
 *  @discussion During the onboarding process the properties needed for the transmitter to be added to the relayr cloud are written to the physical memory of the targeted transmitter.
 *
 *  @param onboardingClass Responsible for the onboarding process. This class "knows" how to talk to the specific transmitter.
 *  @param timeout The maximum duration of the onboarding process in seconds. 
 *	If the onboarding process does not finish within this time span, the completion block is executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. 
 *	If a negative number is passed, the block is returned with a respective error.
 *  @param options Specific options for the transmitter onboarded. The specific <code>RelayrOnboarding</code> class will list all the additional variables needed for a correct onboarding.
 *  @param completion A Block indicating whether the onboarding process was successful or not.
 */
- (void)onboardWithClass:(Class <RelayrOnboarding>)onboardingClass
                 timeout:(NSNumber*)timeout
                 options:(NSDictionary*)options
              completion:(void (^)(NSError* error))completion;

/*!
 *  @abstract Performs a firmware update on the specific transmitter.
 *
 *  @param updateClass Responsible for the firmware update process. This class "knows" how to communicate with the specific transmitter.
 *  @param timeout The maximum duration of the onboarding process in seconds. 
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

@end
