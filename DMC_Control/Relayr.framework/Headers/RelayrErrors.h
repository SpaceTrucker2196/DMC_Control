@import Foundation; // Apple

/*!
 *  @abstract It specifies the error domain of relayr.
 */
FOUNDATION_EXPORT NSString* const kRelayrErrorDomain;

/*!
 *  @abstract The string file that contains the translation of all Relayr.framework error messages.
 */
FOUNDATION_EXPORT NSString* const kRelayrErrorStringFile;

#pragma mark Error codes

/*!
 *  @abstract Enumeration of all the error codes inside the relayr error domain.
 *
 *  @constant kRelayrErrorCodeUnknown Error Unknown.
 *  @constant kRelayrErrorCodeMissingArgument Method missing an argument.
 *  @constant kRelayrErrorCodeMissingObjectPointer An object with weak reference is <code>nil</code> when was expected to be a full-fledge object.
 *  @constant kRelayrErrorCodeMissingExpectedValue Missing an expected value.
 *  @constant kRelayrErrorCodeSystemNotSupported The specific system you are running onto is not supported.
 *  @constant kRelayrErrorCodeNoServiceAvailable No service available.
 *  @constant kRelayrErrorCodeTimeoutExpired The timeout expired before the process was completed.
 *  @constant kRelayrErrorCodeUserStoppedProcess Process was stopped by the user.
 *  @constant kRelayrErrorCodeWrongRelayrUser The passed user doesn't have authorization enough to ask for the request.
 *  @constant kRelayrErrorCodeWebRequestFailure The HTTP web request failed.
 *  @constant kRelayrErrorCodeRequestParsingFailure Parsing process failed.
 *  @constant kRelayrErrorCodeSigningFailure Authentication process failed.
 *  @constant kRelayrErrorCodeTryingToUseRelayrModel A RelayrModel is being used as if it was a <code>RelayrDevice</code> or <code>RelayrTransmitter</code>
 *  @constant kRelayrErrorCodeInternetPoweredOff The antenna/"ethernet cable module" that allow access to the internet seems to be powered off (or no cable is connected).
 *  @constant kRelayrErrorCodeInternetUnauthorized Access to the internet is prohibed by the system.
 *  @constant kRelayrErrorCodeInternetUnsupported The platform doesn't support internet connection.
 *  @constant kRelayrErrorCodeInternetResetting The intenet module is being resetted.
 *  @constant kRelayrErrorCodeInternetProblemUnknown There is a problem with the internet connection, but the source is unknown.
 *  @constant kRelayrErrorCodeBLEModulePoweredOff The Bluetooth Low Energy module is powered off.
 *  @constant kRelayrErrorCodeBLEModuleUnauthorized There is not authorization for using the Bluetooth Low Energy module.
 *  @constant kRelayrErrorCodeBLEUnsupported Bluetooth Low Energy is not supported by your system.
 *  @constant kRelayrErrorCodeBLEModuleResetting The Bluetooth Low Energy module is being resetted.
 *  @constant kRelayrErrorCodeBLEProblemUnknown An unknown problem with the Bluetooth Low Energy module happened.
 *  @constant kRelayrErrorCodeMQTTUnableToConnect A connection to the broker could not be made.
 *  @constant kRelayrErrorCodeMQTTConnectionLost The connection with the broker failed.
 *  @constant kRelayrErrorCodeMQTTSubscriptionFailed The subscription could not be made.
 *  @constant kRelayrErrorCodeMQTTProblemUnknown An unkwnon problem related to the MQTT service occurred.
 */
typedef NS_ENUM(NSInteger, RelayrErrorCode) {
    kRelayrErrorCodeUnknown                 = 1,
    kRelayrErrorCodeMissingArgument         = 2,
    kRelayrErrorCodeMissingObjectPointer    = 3,
    kRelayrErrorCodeMissingExpectedValue    = 4,
    kRelayrErrorCodeSystemNotSupported      = 5,
    kRelayrErrorCodeNoServiceAvailable      = 6,
    kRelayrErrorCodeTimeoutExpired          = 7,
    kRelayrErrorCodeUserStoppedProcess      = 8,
    kRelayrErrorCodeWrongRelayrUser         = 9,
    kRelayrErrorCodeWebRequestFailure       = 10,
    kRelayrErrorCodeRequestParsingFailure   = 11,
    kRelayrErrorCodeSigningFailure          = 12,
    kRelayrErrorCodeTryingToUseRelayrModel  = 13,
    kRelayrErrorCodeInternetPoweredOff      = 20,
    kRelayrErrorCodeInternetUnauthorized    = 21,
    kRelayrErrorCodeInternetUnsupported     = 22,
    kRelayrErrorCodeInternetResetting       = 23,
    kRelayrErrorCodeInternetProblemUnknown  = 24,
    kRelayrErrorCodeBLEModulePoweredOff     = 25,
    kRelayrErrorCodeBLEModuleUnauthorized   = 26,
    kRelayrErrorCodeBLEUnsupported          = 27,
    kRelayrErrorCodeBLEModuleResetting      = 28,
    kRelayrErrorCodeBLEProblemUnknown       = 29,
    kRelayrErrorCodeMQTTUnableToConnect     = 30,
    kRelayrErrorCodeMQTTConnectionLost      = 31,
    kRelayrErrorCodeMQTTSubscriptionFailed  = 32,
    kRelayrErrorCodeMQTTProblemUnknown      = 33
};

#define RelayrErrorUserInfoLocal   @{ \
    @"file"     : [NSString stringWithCString:__FILE__ encoding:NSUTF8StringEncoding], \
    @"function" : [NSString stringWithFormat:@"%i", __LINE__], \
    @"line"     : [NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding] }

#pragma mark Error messages

#define dRelayrErrorMessageUnknown                  NSLocalizedStringFromTable(@"An unknown error occurred.", kRelayrErrorStringFile, @"An error occurred and the procedence is unknown.")
#define dRelayrErrorMessageMissingArgument          NSLocalizedStringFromTable(@"Missing one or more arguments.", kRelayrErrorStringFile, @"It happens when a method is expecting an argument which is not there.")
#define dRelayrErrorMessageMissingObjectPointer     NSLocalizedStringFromTable(@"An object with weak reference is <code>nil</code> when was expected to be a full-fledge object.", kRelayrErrorStringFile, @"It happens when an object referenced weakly has disappeared suddenly, provely because not a strong reference was hold.")
#define dRelayrErrorMessageMissingExpectedValue     NSLocalizedStringFromTable(@"The value is not the expected one (probably nil).", kRelayrErrorStringFile, @"It happens when a value is received and it wasn't the expected.")
#define dRelayrErrorMessageSystemNotSupported       NSLocalizedStringFromTable(@"The system your are running on doesn't support the Relayr framework.", kRelayrErrorStringFile, @"It happens when your system is not supported.")
#define dRelayrErrorMessageNoServiceAvailable       NSLocalizedStringFromTable(@"No service was found for the prerequisites given.", kRelayrErrorStringFile, @"No services were found capable of supporting your demands.")
#define dRelayrErrorMessageTimeoutExpired           NSLocalizedStringFromTable(@"The timeout to perform a certain task has expired.", kRelayrErrorStringFile, @"It happens when the the time ellapsed given to a specific task has been completed without the task been able to be completelly performed.")
#define dRelayrErrorMessageUserStoppedProcess       NSLocalizedStringFromTable(@"The user has stopped the current process.", kRelayrErrorStringFile, @"It happens when an user has canceled somehow the current process.")
#define dRelayrErrorMessageWrongRelayrUser          NSLocalizedStringFromTable(@"The user passed or selected is not a valid Relayr user.", kRelayrErrorStringFile, @"It occurs when trying to perform operations on an invalid Relayr user.")
#define dRelayrErrorMessageWebRequestFailure        NSLocalizedStringFromTable(@"The web request could not be satisfied.", kRelayrErrorStringFile, @"It happens when a web request could not be routed or the answer was not the expected.")
#define dRelayrErrorMessageRequestParsingFailure    NSLocalizedStringFromTable(@"The web request could not be successfully parsed.", kRelayrErrorStringFile, @"It happens when the message from the server could not be parsed.")
#define dRelayrErrorMessageSigningFailure           NSLocalizedStringFromTable(@"The OAuth user signing process failed.", kRelayrErrorStringFile, @"It happens when an OAuth signing process failed.")
#define dRelayrErrorMessageTryingToUseRelayrModel   NSLocalizedStringFromTable(@"A Relayr Model is trying to be used as a full Relayr Object.", kRelayrErrorStringFile, @"It occurs when a Relayr Model is used as it was the Relayr Object is intend to define.")
#define dRelayrErrorMessageInternetPoweredOff       NSLocalizedStringFromTable(@"The antenna or ethernet cable module that allow access to the internet seems to be powered off (or no cable is connected).", kRelayrErrorStringFile, @"The system that allows internet connection seems to be powered off. Prompt the user for wifi activation or to connect a cable.")
#define dRelayrErrorMessageInternetUnauthorized     NSLocalizedStringFromTable(@"Access to the internet is prohibed by the system.", kRelayrErrorStringFile, @"The system has prohibite the use of the internet to the running program.")
#define dRelayrErrorMessageInternetUnsupported      NSLocalizedStringFromTable(@"The platform doesn't support internet connection.", kRelayrErrorStringFile, @"The system doesn't offer any module to connect to the internet.")
#define dRelayrErrorMessageInternetResetting        NSLocalizedStringFromTable(@"The intenet module is being resetted.", kRelayrErrorStringFile, @"The internet hardware provider is being resetted.")
#define dRelayrErrorMessageInternetProblemUnknwon   NSLocalizedStringFromTable(@"There is a problem with the internet connection, but the source is unknown.", kRelayrErrorStringFile, @"There is a problem with the internet connection, but its source is unknown.")
#define dRelayrErrorMessageBLEModulePowerOff        NSLocalizedStringFromTable(@"The BLE module is powered off.", kRelayrErrorStringFile, @"It appears when trying to use the BLE module and the user has it powered off.")
#define dRelayrErrorMessageBLEModuleUnauthorized    NSLocalizedStringFromTable(@"The application is not authorised to use the BLE module.", kRelayrErrorStringFile, @"It happens when the application tries to use the Bluetooth module and the user has actively unathorise the application.")
#define dRelayrErrorMessageBLEUnupported            NSLocalizedStringFromTable(@"The current system doesn't support Bluetooth Low Energy.", kRelayrErrorStringFile, @"It happens when the system running the SDK doesn't have a BLE transceiver.")
#define dRelayrErrorMessageBLEModuleResetting       NSLocalizedStringFromTable(@"The BLE module is being resetted.", kRelayrErrorStringFile, @"It happens when the BLE is being resetted by the system or the user.")
#define dRelayrErrorMessageBLEProblemUnknwon        NSLocalizedStringFromTable(@"BLE error unknown.", kRelayrErrorStringFile, @"There was a problem with the BLE Module, but it is unknown.")
#define dRelayrErrorMessageMQTTUnableToConnect      NSLocalizedStringFromTable(@"It was not possible to make a connection with the MQTT broker.", kRelayrErrorStringFile, @"A connection with the broker could not be made.")
#define dRelayrErrorMessageMQTTConnectionLost       NSLocalizedStringFromTable(@"The connection between the host and the MQTT broker was lost.", kRelayrErrorStringFile, @"The connection with the broker was lost.")
#define dRelayrErrorMessageMQTTSubscriptionFailed   NSLocalizedStringFromTable(@"A subscription with the MQTT broker could not be established.", kRelayrErrorStringFile, @"A subscription for a topic was tried, but it wasn't successful.")
#define dRelayrErrorMessageMQTTProblemUnknown       NSLocalizedStringFromTable(@"An unkwnon problem related to the MQTT service occured.", kRelayrErrorStringFile, @"MQTT problem of unkwnon source.")

//kRelayrErrorCodeMQTTUnableToConnect     = 30,
//kRelayrErrorCodeMQTTConnectionLost      = 31,
//kRelayrErrorCodeMQTTSubscriptionFailed  = 32,
//kRelayrErrorCodeMQTTProblemUnknown      = 33

#pragma mark Error objects

#define RelayrErrorUnknwon                  [RelayrErrors errorWithCode:kRelayrErrorCodeUnknown localizedDescription:dRelayrErrorMessageUnknown userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorMissingArgument          [RelayrErrors errorWithCode:kRelayrErrorCodeMissingArgument localizedDescription:dRelayrErrorMessageMissingArgument userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorMissingObjectPointer     [RelayrErrors errorWithCode:kRelayrErrorCodeMissingObjectPointer localizedDescription:dRelayrErrorMessageMissingObjectPointer userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorMissingExpectedValue     [RelayrErrors errorWithCode:kRelayrErrorCodeMissingExpectedValue localizedDescription:dRelayrErrorMessageMissingExpectedValue userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorSystemNotSupported       [RelayrErrors errorWithCode:kRelayrErrorCodeSystemNotSupported localizedDescription:dRelayrErrorMessageSystemNotSupported userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorNoServiceAvailable       [RelayrErrors errorWithCode:kRelayrErrorCodeNoServiceAvailable localizedDescription:dRelayrErrorMessageNoServiceAvailable userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorTimeoutExpired           [RelayrErrors errorWithCode:kRelayrErrorCodeTimeoutExpired localizedDescription:dRelayrErrorMessageTimeoutExpired userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorUserStoppedProcess       [RelayrErrors errorWithCode:kRelayrErrorCodeUserStoppedProcess localizedDescription:dRelayrErrorMessageUserStoppedProcess userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorWrongRelayrUser          [RelayrErrors errorWithCode:kRelayrErrorCodeWrongRelayrUser localizedDescription:dRelayrErrorMessageWrongRelayrUser userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorWebRequestFailure        [RelayrErrors errorWithCode:kRelayrErrorCodeWebRequestFailure localizedDescription:dRelayrErrorMessageWebRequestFailure userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorRequestParsingFailure    [RelayrErrors errorWithCode:kRelayrErrorCodeRequestParsingFailure localizedDescription:dRelayrErrorMessageRequestParsingFailure userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorSigningFailure           [RelayrErrors errorWithCode:kRelayrErrorCodeSigningFailure localizedDescription:dRelayrErrorMessageSigningFailure userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorTryingToUseRelayrModel   [RelayrErrors errorWithCode:kRelayrErrorCodeTryingToUseRelayrModel localizedDescription:dRelayrErrorMessageTryingToUseRelayrModel userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorInternetPoweredOff       [RelayrErrors errorWithCode:kRelayrErrorCodeInternetPoweredOff localizedDescription:dRelayrErrorMessageInternetUnauthorized userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorInternetUnauthorized     [RelayrErrors errorWithCode:kRelayrErrorCodeInternetUnauthorized localizedDescription:dRelayrErrorMessageInternetUnsupported userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorInternetUnsupported      [RelayrErrors errorWithCode:kRelayrErrorCodeInternetUnsupported localizedDescription:dRelayrErrorMessageInternetUnsupported userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorInternetResetting        [RelayrErrors errorWithCode:kRelayrErrorCodeInternetResetting localizedDescription:dRelayrErrorMessageInternetResetting userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorInternetProblemUnknwon   [RelayrErrors errorWithCode:kRelayrErrorCodeInternetProblemUnknown localizedDescription:dRelayrErrorMessageInternetProblemUnknwon userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorBLEModulePowerOff        [RelayrErrors errorWithCode:kRelayrErrorCodeBLEModulePoweredOff localizedDescription:dRelayrErrorMessageBLEModulePowerOff userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorBLEModuleUnauthorized    [RelayrErrors errorWithCode:kRelayrErrorCodeBLEModuleUnauthorized localizedDescription:dRelayrErrorMessageBLEModuleUnauthorized userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorBLEModuleResetting       [RelayrErrors errorWithCode:kRelayrErrorCodeBLEModuleResetting localizedDescription:dRelayrErrorMessageBLEModuleResetting userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorBLEUnsupported           [RelayrErrors errorWithCode:kRelayrErrorCodeBLEUnsupported localizedDescription:dRelayrErrorMessageBLEUnupported userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorBLEProblemUnknown        [RelayrErrors errorWithCode:kRelayrErrorCodeBLEProblemUnknown localizedDescription:dRelayrErrorMessageBLEProblemUnknwon userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorMQTTUnableToConnect      [RelayrErrors errorWithCode:kRelayrErrorCodeMQTTUnableToConnect localizedDescription:dRelayrErrorMessageMQTTUnableToConnect userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorMQTTConnectionLost       [RelayrErrors errorWithCode:kRelayrErrorCodeMQTTConnectionLost localizedDescription:dRelayrErrorMessageMQTTConnectionLost userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorMQTTSubscriptionFailed   [RelayrErrors errorWithCode:kRelayrErrorCodeMQTTSubscriptionFailed localizedDescription:dRelayrErrorMessageMQTTSubscriptionFailed userInfo:RelayrErrorUserInfoLocal]
#define RelayrErrorMQTTProblemUnknown       [RelayrErrors errorWithCode:kRelayrErrorCodeMQTTProblemUnknown localizedDescription:dRelayrErrorMessageMQTTProblemUnknown userInfo:RelayrErrorUserInfoLocal]

/*!
 *  @abstract Utility class which provides convenience methods for initializing errors as well as internal framework error codes.
 */
@interface RelayrErrors : NSObject

/*!
 *  @abstract Convenience method for initializing framework specific errors.
 *
 *  @param code The predefined <code>RelayrErrorCode</code> for the error.
 *  @param localizedDescription Localised string with the description of the error.
 *  @param userInfo A dictionary of information for the error. This parameter may be <code>nil</code>.
 *	@return An <code>NSError</code> object for the error domain with the specified error code and a dictionary of error user information.
 *
 *  @seealso RelayrErrorCode
 */
+ (NSError*)errorWithCode:(NSInteger)code
     localizedDescription:(NSString*)localizedDescription
                 userInfo:(NSDictionary*)userInfo;

/*!
 *  @abstract Convenience method for initializing framework specific errors.
 *
 *  @param code The predefined RelayrErrorCode for the error.
 *  @param localizedDescription Localised string with the description of the error.
 *  @param failureReason A string specifying the reason for the failure.
 *	@return An NSError object for the error domain with the specified error code and a dictionary of error user information.
 *
 *  @seealso RelayrErrorCode
 */
+ (NSError*)errorWithCode:(NSInteger)code
     localizedDescription:(NSString*)localizedDescription
            failureReason:(NSString*)failureReason
                 userInfo:(NSDictionary*)userInfo;

@end
