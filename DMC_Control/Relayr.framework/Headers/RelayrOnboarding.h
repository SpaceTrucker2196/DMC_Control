@import Foundation;             // Apple
@class RelayrTransmitter;       // Relayr (Public)
@class RelayrDevice;            // Relayr (Public)

/*!
 *  @abstract Describes the basic methods required to support the relayr Onboarding process.
 */
@protocol RelayrOnboarding <NSObject>

@required
/*!
 *  @abstract This method will launch a process to onboard a specific <code>RelayrTransmitter</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrTransmitter</code> entity passed as an argument.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity used to represent a physical transmitter.
 *  @param timeout The maximum duration of the onboarding process in seconds. 
 *	If the onboarding process doesn't finish within the specified timeout, the completion block is executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. 
 *	If a negative number is passed, the block is returned with a respective error.
 *  @param options Specific options for the transmitter onboarded. 
 *	The specific <code>RelayrOnboarding</code> class will list all additional variables required for successful onboarding.
 *  @param completion A Block indicating whether the onboarding process was successful or not.
 *
 *  @see RelayrTransmitter
 */
+ (void)launchOnboardingProcessForTransmitter:(RelayrTransmitter*)transmitter
                                      timeout:(NSNumber*)timeout
                                      options:(NSDictionary*)options
                                   completion:(void (^)(NSError* error))completion;

@required
/*!
 *  @abstract This method will launch a process to onboard a specific <code>RelayrDevice</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrDevice</code> entity passed as an argument.
 *
 *  @param device <code>RelayrDevice</code> entity used to represent a physical device.
 *  @param timeout The maximum duration of the onboarding process in seconds. 
 *	If the onboarding process doesn't finish within the specified timeout, the completion block is executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. 
 *	If a negative number is passed, the block is returned with a respective error.
 *  @param options Specific options for the device onboarded. 
 *	The specific <code>RelayrOnboarding</code> class will list all additional variables required for successful onboarding.
 *  @param completion A Block indicating whether the onboarding process was successful or not.
 *
 *  @see RelayrDevice
 */
+ (void)launchOnboardingProcessForDevice:(RelayrDevice*)device
                                 timeout:(NSNumber*)timeout options:(NSDictionary*)options
                              completion:(void (^)(NSError* error))completion;

@end
