//
//  UMGSMMAP_Ext_BasicServiceCode.h
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

#import "UMGSMMAP_Ext_BearerServiceCode.h"
#import "UMGSMMAP_Ext_TeleserviceCode.h"

@interface UMGSMMAP_Ext_BasicServiceCode : UMASN1Choice<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_Ext_BearerServiceCode *ext_BearerService;
	UMGSMMAP_Ext_TeleserviceCode *ext_Teleservice;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_Ext_BearerServiceCode *ext_BearerService;
@property(readwrite,strong)	UMGSMMAP_Ext_TeleserviceCode *ext_Teleservice;


- (void)processBeforeEncode;
- (UMGSMMAP_Ext_BasicServiceCode *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
