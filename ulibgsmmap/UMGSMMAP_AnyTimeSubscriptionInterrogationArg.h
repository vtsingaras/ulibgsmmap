//
//  UMGSMMAP_AnyTimeSubscriptionInterrogationArg.h
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

#import "UMGSMMAP_SubscriberIdentity.h"
#import "UMGSMMAP_RequestedSubscriptionInfo.h"
#import "UMGSMMAP_ISDN_AddressString.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_AnyTimeSubscriptionInterrogationArg : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_SubscriberIdentity *subscriberIdentity;
	UMGSMMAP_RequestedSubscriptionInfo *requestedSubscriptionInfo;
	UMGSMMAP_ISDN_AddressString *gsmSCF_Address;
	UMGSMMAP_ExtensionContainer *extensionContainer;
	BOOL longFTN_Supported;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_SubscriberIdentity *subscriberIdentity;
@property(readwrite,strong)	UMGSMMAP_RequestedSubscriptionInfo *requestedSubscriptionInfo;
@property(readwrite,strong)	UMGSMMAP_ISDN_AddressString *gsmSCF_Address;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;
@property(readwrite,assign)	BOOL longFTN_Supported;


- (void)processBeforeEncode;
- (UMGSMMAP_AnyTimeSubscriptionInterrogationArg *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
