@import Foundation;                 // Apple
#import "Relayr/RelayrOnboarding.h" // Relayr

/*!
 *  @abstract Performs the onboarding for Relayr Wunderbars.
 *
 *  @see RelayrOnboarding
 */
@interface WunderbarOnboarding : NSObject <RelayrOnboarding>

/*!
 *  @abstract This method will launch a process to onboard a specific <code>RelayrTransmitter</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrTransmitter</code> entity passed as an argument.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity use to configure a physical transmitter.
 *  @param timeout The seconds that the onboarding process can span. If the onboarding process hasn't finished by the specified seconds, the completion block will be executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. If a negative number is passed, then the block is returned with a proper error.
 *  @param options Specific options for the transmitter you are onboarding. The specific <code>RelayrOnboarding</code> class will list all the additional variables needed for a correct onboarding.
 *  @param completion Block indicating whether the onboarding process was successful or not.
 *
 *  @see RelayrTransmitter
 */
+ (void)launchOnboardingProcessForTransmitter:(RelayrTransmitter*)transmitter
                                      timeout:(NSNumber*)timeout
                                      options:(NSDictionary*)options
                                   completion:(void (^)(NSError* error))completion;

/*!
 *  @abstract This method will launch a process to onboard a specific <code>RelayrDevice</code>.
 *  @discussion The method MUST not modify the primal characteristics of the <code>RelayrDevice</code> entity passed as an argument.
 *
 *  @param device <code>RelayrDevice</code> entity use to configure a physical device.
 *  @param timeout The seconds that the onboarding process can span. If the onboarding process hasn't finished by the specified seconds, the completion block will be executed.
 *      If <code>nil</code> is passed, a timeout defined by the manufacturer is used. If a negative number is passed, then the block is returned with a proper error.
 *  @param options Specific options for the device you are onboarding. The specific <code>RelayrOnboarding</code> class will list all the additional variables needed for a correct onboarding.
 *  @param completion Block indicating whether the onboarding process was successful or not.
 *
 *  @see RelayrDevice
 */
+ (void)launchOnboardingProcessForDevice:(RelayrDevice*)device
                                 timeout:(NSNumber*)timeout
                                 options:(NSDictionary*)options
                              completion:(void (^)(NSError* error))completion;

@end
