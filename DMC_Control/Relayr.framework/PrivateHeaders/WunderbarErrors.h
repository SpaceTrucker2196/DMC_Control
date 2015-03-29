#pragma once

@import Foundation;         // Apple
#import "RelayrErrors.h"    // Relayr (Utilities)

/*!
 *  @abstract The string file that contains the translation of all Wunderbar error messages.
 */
#define kWunderbarErrorStringFile = @"WunderbarErrors"

#pragma mark Error codes

/*!
 *  @abstract Enumeration of all the error codes for Wunderbar related actions.
 *
 *  @constant kWunderbarErrorCodeTimeoutTooLow The timeout given for the Wunderbar
 */
typedef NS_ENUM(NSInteger, WunderbarErrorCode) {
    kWunderbarErrorCodeTimeoutTooLow            = 680,
    kWunderbarErrorCodeNoTransmittersDetected   = 681,
    kWunderbarErrorCodeNoDevicesDetected        = 682,
    kWunderbarErrorCodeNoSetupServiceDetected   = 683,
    kWunderbarErrorCodeNoSetupCharacteristicDetected = 684
};

#pragma mark Error messages

#define dWunderbarErrorMessageTimeoutTooLow             NSLocalizedStringFromTable(@"The timeout provided is too low for the given process", kRelayrErrorStringFile, @"It happens when the system consider that the timeout passed as argument is too low for the process about to run.")
#define dWunderbarErrorMessageNoTransmittersDetected    NSLocalizedStringFromTable(@"No transmitters have been detected during the onboarding process", kRelayrErrorStringFile, @"It happens when trying to onboard a transmitter, none of them where found.")
#define dWunderbarErrorMessageNoDevicesDetected         NSLocalizedStringFromTable(@"No devices have been detected during the onboarding process", kRelayrErrorStringFile, @"It happens when trying to onboard a specific device, none of them where found.")
#define dWunderbarErrorMessageNoSetupServiceDetected    NSLocalizedStringFromTable(@"No setup BLE service detected.", kRelayrErrorStringFile, @"It happens when trying to setup a device trough BLE, but the service is nowhere to be found.")
#define dWunderbarErrorMessageNoSetupCharacteristicDetected NSLocalizedStringFromTable(@"No setup BLE service's characteristics detected.", kRelayrErrorStringFile, @"It happens when trying to setup a device trough BLE, but the service's characteristics are nowhere to be found.")

#pragma mark Error objects

#define WunderbarErrorTimeoutTooLow             [RelayrErrors errorWithCode:kWunderbarErrorCodeTimeoutTooLow localizedDescription:dWunderbarErrorMessageTimeoutTooLow userInfo:RelayrErrorUserInfoLocal]
#define WunderbarErrorNoTransmittersDetected    [RelayrErrors errorWithCode:kWunderbarErrorCodeNoTransmittersDetected localizedDescription:dWunderbarErrorMessageNoTransmittersDetected userInfo:RelayrErrorUserInfoLocal]
#define WunderbarErrorNoDevicesDetected         [RelayrErrors errorWithCode:kWunderbarErrorCodeNoDevicesDetected localizedDescription:dWunderbarErrorMessageNoDevicesDetected userInfo:RelayrErrorUserInfoLocal]
#define WunderbarErrorNoSetupServiceDetected    [RelayrErrors errorWithCode:kWunderbarErrorCodeNoSetupServiceDetected localizedDescription:dWunderbarErrorMessageNoSetupServiceDetected userInfo:RelayrErrorUserInfoLocal]
#define WunderbarErrorNoSetupCharacteristicDetected [RelayrErrors errorWithCode:kWunderbarErrorCodeNoSetupCharacteristicDetected localizedDescription:dWunderbarErrorMessageNoSetupCharacteristicDetected userInfo:RelayrErrorUserInfoLocal]
