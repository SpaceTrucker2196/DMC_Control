#import "RLAAPIService.h"
@class RelayrTransmitter;

@interface RLAAPIService (Wunderbar)

/*!
 *  @abstract Creates/Registers a transmitter entity and six devices on the server.
 *
 *  @param completion Block indicating whether the operation was successful or not.
 *
 *  @see RLAAPIService
 */
- (void)registerWunderbar:(void (^)(NSError* error, RelayrTransmitter* transmitter))completion;

/*!
 *  @abstract Deletes a transmitter entity and it six paired devices on the server.
 *
 *  @param completion Block indicating whether the operation was successful or not.
 *
 *  @see RLAAPIService
 */
- (void)deleteWunder:(RelayrTransmitter*)trasnmitter
          completion:(void (^)(NSError* error))completion;

@end
