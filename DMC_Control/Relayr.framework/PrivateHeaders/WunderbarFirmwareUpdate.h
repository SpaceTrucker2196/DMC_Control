@import Foundation;                         // Apple
#import "Relayr/RelayrFirmwareUpdate.h"     // Relayr

/*!
 *  @abstract Performs the firmware update process for Relayr Wunderbars.
 *
 *  @see RelayrFirmwareUpdate
 */
@interface WunderbarFirmwareUpdate : NSObject

/*!
 *  @abstract This method will launch a process to update the firmware of a specific <code>RelayrTransmitter</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrTransmitter</code> entity passed as an argument.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the physical transmitter that will be updated.
 *  @param timeout The seconds that the onboarding process can span. If the firmware update process hasn't finished by the specified seconds, the completion block will be executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. If a negative number is passed, then the block is returned with a proper error.
 *  @param completion Block indicating whether the onboarding process was successful or not.
 *
 *  @see RelayrTransmitter
 */
+ (void)launchFirmwareUpdateProcessForTransmitter:(RelayrTransmitter*)transmitter timeout:(NSNumber*)timeout completion:(void (^)(NSError* error))completion;

/*!
 *  @abstract This method will launch a process to update the firmware of a specific <code>RelayrDevice</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrDevice</code> entity passed as an argument.
 *
 *  @param device <code>RelayrDevice</code> entity representing the physical transmitter that will be updated.
 *  @param timeout The seconds that the onboarding process can span. If the firmware update process hasn't finished by the specified seconds, the completion block will be executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. If a negative number is passed, then the block is returned with a proper error.
 *  @param completion Block indicating whether the onboarding process was successful or not.
 *
 *  @see RelayrDevice
 */
+ (void)launchFirmwareUpdateProcessForDevice:(RelayrDevice*)device timeout:(NSNumber*)timeout completion:(void (^)(NSError* error))completion;

@end
