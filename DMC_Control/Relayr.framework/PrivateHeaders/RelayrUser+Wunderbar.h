#import <Relayr/RelayrUser.h>   // Relayr (Public)

@interface RelayrUser (Wunderbar)

/*!
 *  @abstract It creates/register a transmitter entity in the Relayr Cloud and six Relayr devices.
 *
 *  @param name The given name to identify this wunderbar (which is a transmitter). This parameter is required.
 *  @param completion Block indicating whether the server registration call was successful or not. It can be <code>nil</code>.
 *
 *  @see RelayrUser
 */
- (void)registerWunderbarWithName:(NSString*)name
                       completion:(void (^)(NSError* error, RelayrTransmitter* transmitter))completion;

/*!
 *  @abstract It deletes a transmitter entity and all their associated devices entities.
 *
 *  @param transmitter The transmitter to be deleted.
 *  @param completion Block indicating whether the server registration call was successful or not. It can be <code>nil</code>.
 *
 *  @see RelayrTransmitter
 */
- (void)deleteWunderbar:(RelayrTransmitter*)transmitter
             completion:(void (^)(NSError* error))completion;

@end
