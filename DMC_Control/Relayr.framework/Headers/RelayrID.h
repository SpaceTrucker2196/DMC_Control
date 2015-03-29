@import Foundation;     // Apple

/*!
 *  @abstract This protocol gives an object an unique identifier to be used in the Relayr "sphere of influence".
 */
@protocol RelayrID <NSObject>

/*!
 *  @abstract A unique idenfier for the current instance.
 *  @discussion This property does not change during the life cycle of the object and it is never <code>nil</code>.
 */
@property (readonly,nonatomic) NSString* uid;

@end
