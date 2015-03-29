@class RelayrDeviceModel;   // Relayr (Public)
@import Foundation;         // Apple

/*!
 *  @abstract Specifies the basic functionality of a device.
 */
@interface RelayrFirmwareModel : NSObject <NSCopying,NSMutableCopying>

/*!
 *  @abstract The <code>RelayrDeviceModel</code> targeted by the firmware.
 *  @discussion This property will never be <code>nil</code>.
 *  All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 */
@property (readonly,weak,nonatomic) RelayrDeviceModel* deviceModel;

/*!
 *  @abstract <code>NSString</code> representing the current version of the firmware.
 */
@property (readonly,nonatomic) NSString* version;

/*!
 *  @abstract <code>NSDictionary</code> incorporating all the properties of the current firmware.
 *  @discussion This dictionary includes all firmware properties, such as the Reading frequency.
 */
@property (readonly,nonatomic) NSDictionary* configuration;

/*!
 *  @abstract Queries the relayr platform for the current firmware properties.
 *  @discussion Every time this method is called a server query is launched.
 *	Once a response is returned successfuly, all the <i>readonly</i> user related properties are populated with respective values.
 *
 *  @param completion A block indiciating whether the server query was successful or not.
 *
 *  @see queryCloudForIoTs:
 */
- (void)queryCloudForDefaultConfigurationValues:(void (^)(NSError* error))completion;

@end
