//
//  UMGSMMAP_Ss_InvocationNotificationArg.h
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

#import "UMGSMMAP_IMSI.h"
#import "UMGSMMAP_ISDN_AddressString.h"
#import "UMGSMMAP_SS_Code.h"
#import "UMGSMMAP_SS_EventSpecification.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_Ss_InvocationNotificationArg : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_IMSI *imsi;
	UMGSMMAP_ISDN_AddressString *msisdn;
	UMGSMMAP_SS_Code *ss_Event;
	UMGSMMAP_SS_EventSpecification *ss_EventSpecification;
	UMGSMMAP_ExtensionContainer *extensionContainer;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_IMSI *imsi;
@property(readwrite,strong)	UMGSMMAP_ISDN_AddressString *msisdn;
@property(readwrite,strong)	UMGSMMAP_SS_Code *ss_Event;
@property(readwrite,strong)	UMGSMMAP_SS_EventSpecification *ss_EventSpecification;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;


- (void)processBeforeEncode;
- (UMGSMMAP_Ss_InvocationNotificationArg *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
