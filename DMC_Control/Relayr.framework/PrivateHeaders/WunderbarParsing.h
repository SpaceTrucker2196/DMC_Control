@import Foundation;             // Apple
#import "RelayrConnection.h"    // Relayr (Public/IoTs)

@interface WunderbarParsing : NSObject

/*!
 *  @abstract It calibrates the color members received from the Wunderbar.
 */
+ (NSArray*)calibrateColorWithRed:(NSNumber*)red green:(NSNumber*)green blue:(NSNumber*)blue;

@end
