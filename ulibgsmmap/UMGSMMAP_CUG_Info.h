//
//  UMGSMMAP_CUG_Info.h
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import <ulibasn1/ulibasn1.h>
#import "UMGSMMAP_asn1_protocol.h"

#import "UMGSMMAP_CUG_SubscriptionList.h"
#import "UMGSMMAP_CUG_FeatureList.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_CUG_Info : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_CUG_SubscriptionList *cug_SubscriptionList;
	UMGSMMAP_CUG_FeatureList *cug_FeatureList;
	UMGSMMAP_ExtensionContainer *extensionContainer;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_CUG_SubscriptionList *cug_SubscriptionList;
@property(readwrite,strong)	UMGSMMAP_CUG_FeatureList *cug_FeatureList;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;


- (void)processBeforeEncode;
- (UMGSMMAP_CUG_Info *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
