#import "RelayrID.h"    // Relayr (Public)

/*!
 *  @abstract It specifies a <code>NSSet</code> collection that will only contain <code>id <RelayrID></code> objects.
 *  @discussion This protocol specifies subscript notification for <code>NSSet</code> containing only <code>RelayrID</code> capable objects.
 *
 *  @see RelayrID
 */
@protocol RelayrIDSubscripting <NSObject>

@required
/*!
 *  @abstract It gives a <code>NSSet</code> object the ability of keyed subscript notification (only for read-only values).
 *
 *  @param key <code>NSString</code> specifying the unique identifier of the object.
 *	@return It returns a <code>RelayrID</code>-capable object or <code>nil</code> if no object was found with the specified ID.
 */
- (id <RelayrID>)objectForKeyedSubscript:(NSString*)key;

@end
