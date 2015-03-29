#import "RelayrIDSubscripting.h"   // Relayr (Utilities/Collections)

/*!
 *  @abstract It gives a common <code>NSSet</code> collection the read-only keyed subscripting ability.
 *  @discussion When using read-only subscripting, the <code>NSSet</code> object will look for object matching the Relayr ID.
 *
 *  @see RelayrID
 *  @see RelayrIDSubscripting
 */
@interface NSSet (RelayrID) <RelayrIDSubscripting>

@end
