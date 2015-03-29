#import "RelayrFirmwareModel.h" // Parent class
@import Foundation;             // Apple

/*!
 *  @abstract Represents the firmware running on a <code>RelayrDevice</code> or a <code>RelayrTransmitter</code>.
 *  @discussion All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 *
 *  @see RelayrDevice
 *  @see RelayrTransmitter
 */
@interface RelayrFirmware : RelayrFirmwareModel <NSCopying,NSMutableCopying>

@end
