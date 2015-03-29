@class RelayrDeviceModel;   // Relayr (Public/IoTs)
@import Foundation;         // Apple

/*!
 *  @abstract Represents a type of information a relayr device (for example, a sensor) can send to the outside.
 *  @discussion All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 */
@interface RelayrCommand : NSObject <NSCopying,NSMutableCopying>

/*!
 *  @abstract The type of object owner of this command.
 *  @discussion This property will never be <code>nil</code>.
 */
@property (readonly,weak,nonatomic) RelayrDeviceModel* deviceModel;

/*!
 *  @abstract The name of the type of command the <code>RelayrDevice</code> can send.
 *  @discussion Currently only two types of meanings are accepted: "led" and <code>nil</code>.
 */
@property (readonly,nonatomic) NSString* meaning;

/*!
 *  @abstract The path where the command is located.
 */
@property (readonly,nonatomic) NSString* path;

/*!
 *  @abstract The unit in which the command value is measured.
 *  @discussion If this property is <code>nil</code>, no unit is specified.
 */
@property (readonly,nonatomic) NSString* unit;

/*!
 *  @abstract The maximum value for the command value measured in the unit specified by the <code>unit</code> property.
 *  @discussion If this property is <code>nil</code>, no maximum is specified.
 */
@property (readonly,nonatomic) id maximum;

/*!
 *  @abstract The minimum value for the command value measured in the unit specified by the <code>unit</code> property.
 *  @discussion If this property is <code>nil</code>, no minimum is specified.
 */
@property (readonly,nonatomic) id minimum;

/*!
 *  @abstract Sends the value to the device containing this <code>RelayrCommand</code>.
 *  @discussion Currently only <code>NSString</code> values are accepted. This will change in future releases.
 *
 *  @param value NSString in UTF8 format to send to the <code>RelayrDevice</code>
 *  @param completion A Block indicating whether the value was received by the server (<code>error</code> is <code>nil</code>) or not.
 */
- (void)sendValue:(id)value
   withCompletion:(void (^)(NSError* error))completion;

@end
