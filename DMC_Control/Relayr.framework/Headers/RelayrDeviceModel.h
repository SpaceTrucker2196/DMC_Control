@class RelayrUser;                      // Relayr (Public)
@class RelayrReading;                   // Relayr (Public/IoTs)
#import <Relayr/NSSet+RelayrID.h>       // Relayr (Utilities/Collections)
@import Foundation;                     // Apple

/*!
 *  @abstract Specifies the basic functionality of a device.
 */
@interface RelayrDeviceModel : NSObject <NSCopying,NSMutableCopying>

/*!
 *  @abstract The User currently "using" this device.
 *  @discussion A public device can be owned by another Relayr user, but being used by your <code>RelayrUser</code> entity.
 *  All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 */
@property (readonly,weak,nonatomic) RelayrUser* user;

/*!
 *  @abstract The identifier of the device model within the relayr Cloud.
 *  @discussion Inmutable
 */
@property (readonly,nonatomic) NSString* modelID;

/*!
 *  @abstract Device-Model name.
 *  @discussion Inmutable
 */
@property (readonly,nonatomic) NSString* modelName;

/*!
 *  @abstract The manufacturer of the device.
 */
@property (readonly,nonatomic) NSString* manufacturer;

/*!
 *  @abstract An array containing all possible firmware models (<code>RelayrFirmwareModel</code>) for the current <code>RelayrDeviceModel</code>.
 */
@property (readonly,nonatomic) NSArray* firmwaresAvailable;

/*!
 *  @abstract Returns an array of all possible readings the device can collect.
 *  @discussion Each item in this array is an object of type <code>RelayrReading</code>. 
 *      Each reading represents a different kind of reading.
 *      That is, a <code>RelayrDevice</code> can have a luminosity sensor and a gyroscope;
 *      Therefore, this array would have two different readings.
 *
 *  @see RelayrReading
 */
@property (readonly,nonatomic) NSSet* readings;

/*!
 *  @abstract Returns an array of possible Commands a Device is capable of receiving.
 *  @discussion By 'command' we refer to an object with commands or configuration settings sent to a Device.
 *	These are usually infrarred commands, ultrasound pulses etc.
 *	Each item in this array is an object of type <code>RelayrCommand</code>.
 *
 *  @see RelayrCommand
 */
@property (readonly,nonatomic) NSSet* commands;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible <code>RelayrReading</code> objects that are capable of <i>read</i> the meanings passed as argument.
 *  @discussion If no readings are found, an empty set is returned.
 *
 *  @param meanings The specific meanings that the readings must be capable to <i>read</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrDevice</code> objects.
 *
 *  @see RelayrReading
 */
- (NSSet*)readingsWithMeanings:(NSArray*)meanings;

/*!
 *  @abstract It returns an <code>NSSet</code> grouping all possible <code>RelayrCommand</code> objects that are capable of <i>sending</i> the meanings passed as argument.
 *  @discussion If no commands are found, an empty set is returned.
 *
 *  @param meanings The specific meanings that the command must be capable to <i>read</i>.
 *	@return <code>NSSet</code> grouping all capable <code>RelayrDevice</code> objects.
 *
 *  @see RelayrCommand
 */
- (NSSet*)commandsWithMeanings:(NSArray*)meanings;

@end
