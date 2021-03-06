//
//  UMGSMMAP_AbsentSubscriberSM_Param.h
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

#import "UMGSMMAP_AbsentSubscriberDiagnosticSM.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_AbsentSubscriberSM_Param : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_AbsentSubscriberDiagnosticSM *absentSubscriberDiagnosticSM;
	UMGSMMAP_ExtensionContainer *extensionContainer;
	UMGSMMAP_AbsentSubscriberDiagnosticSM *additionalAbsentSubscriberDiagnosticSM;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_AbsentSubscriberDiagnosticSM *absentSubscriberDiagnosticSM;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;
@property(readwrite,strong)	UMGSMMAP_AbsentSubscriberDiagnosticSM *additionalAbsentSubscriberDiagnosticSM;


- (void)processBeforeEncode;
- (UMGSMMAP_AbsentSubscriberSM_Param *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
