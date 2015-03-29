@class RelayrUser;          // Relayr (Public)
#import <Relayr/RelayrID.h> // Relayr (Public)
@import Foundation;         // Apple

/*!
 *  @abstract Every instance of this class represents a <i>publisher</i> entity.
 *  @discussion A Publisher is a basic entity in the relayr platform. 
 *	Each user can choose to have the option to publish apps on the relayr platform and they are then assigned a publisherId.
 *
 *  All RelayrSDK objects (except when explicitly said otherwise) will return the same instance when copied (e.g.: when added to a dictionary). Thus the <code>NSCopying</code> method <code>-copyWithZone:</code> will return the same instance. Same happening with <code>NSMutableCopying</code> method <code>-mutableCopyWithZone:</code>.
 *
 *  @see RelayrUser
 *  @see RelayrApp
 */
@interface RelayrPublisher : NSObject <RelayrID,NSCopying,NSMutableCopying>

/*!
 *  @abstract The owner of the publisher entity. This is the User by whom the Publisher was created.
 */
@property (readonly,nonatomic) NSString* owner;

/*!
 *  @abstract Represents the publisher name. 
 *  @discussion Can be <code>nil</code>.
 */
@property (readonly,nonatomic) NSString* name;

/*!
 *  @abstract relayr apps owned by this publisher entity.
 *  @discussion An <code>NSSet</code> containing <code>RelayrApp</code> entities.
 */
@property (readonly,nonatomic) NSSet* apps;

@end
