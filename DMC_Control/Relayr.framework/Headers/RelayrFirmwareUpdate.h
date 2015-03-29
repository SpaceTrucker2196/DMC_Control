@import Foundation;             // Apple
@class RelayrTransmitter;       // Relayr (Public)
@class RelayrDevice;            // Relayr (Public)

/*!
 *  @abstract Describes the basic methods required to support the relayr firmware update process.
 */
@protocol RelayrFirmwareUpdate <NSObject>

@required
/*!
 *  @abstract This method will launch a process to update the firmware of a specific <code>RelayrTransmitter</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrTransmitter</code> entity 
 *	passed as an argument.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the physical transmitter that will be updated.
 *  @param timeout The maximum duration of the update process in seconds. 
 *	If the update process doesn't finish within the specified timeout, the completion block is executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. 
 *	If a negative number is passed, the block is returned with a respective error.
 *  @param completion A Block indicating whether the update process was successful or not.
 *
 *  @see RelayrTransmitter
 */
+ (void)launchFirmwareUpdateProcessForTransmitter:(RelayrTransmitter*)transmitter timeout:(NSNumber*)timeout options:(NSDictionary*)options completion:(void (^)(NSError* error))completion;

@required
/*!
 *  @abstract This method will launch a process to update the firmware of a specific <code>RelayrDevice</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrDevice</code> entity passed as an argument.
 *
 *  @param device <code>RelayrDevice</code> entity representing the physical device that will be updated.
 *  @param timeout The maximum duration of the update process in seconds. 
 *	If the update process doesn't finish within the specified timeout, the completion block is executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. 
 *	If a negative number is passed, the block is returned with a respective error.
 *  @param completion A Block indicating whether the update process was successful or not.
 *
 *  @see RelayrDevice
 */
+ (void)launchFirmwareUpdateProcessForDevice:(RelayrDevice*)device timeout:(NSNumber*)timeout options:(NSDictionary*)options completion:(void (^)(NSError* error))completion;

@end
