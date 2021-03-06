//
//  UMGSMMAP_OldRoutingInfoForSM_Arg.h
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

#import "UMGSMMAP_ISDN_AddressString.h"
#import "UMGSMMAP_AddressString.h"
#import "UMGSMMAP_ExtensionContainer.h"
#import "UMGSMMAP_SM_RP_MTI.h"
#import "UMGSMMAP_SM_RP_SMEA.h"

@interface UMGSMMAP_OldRoutingInfoForSM_Arg : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_ISDN_AddressString *msisdn;
	UMASN1Boolean *sm_RP_PRI;
	UMGSMMAP_AddressString *serviceCentreAddress;
	UMGSMMAP_ExtensionContainer *extensionContainer;
	BOOL gprsSupportIndicator;
	UMGSMMAP_SM_RP_MTI *sm_RP_MTI;
	UMGSMMAP_SM_RP_SMEA *sm_RP_SMEA;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_ISDN_AddressString *msisdn;
@property(readwrite,strong)	UMASN1Boolean *sm_RP_PRI;
@property(readwrite,strong)	UMGSMMAP_AddressString *serviceCentreAddress;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;
@property(readwrite,assign)	BOOL gprsSupportIndicator;
@property(readwrite,strong)	UMGSMMAP_SM_RP_MTI *sm_RP_MTI;
@property(readwrite,strong)	UMGSMMAP_SM_RP_SMEA *sm_RP_SMEA;


- (void)processBeforeEncode;
- (UMGSMMAP_OldRoutingInfoForSM_Arg *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
