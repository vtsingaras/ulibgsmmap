//
//  UMGSMMAP_LCSClientName.h
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

#import "UMGSMMAP_USSD_DataCodingScheme.h"
#import "UMGSMMAP_NameString.h"

@interface UMGSMMAP_LCSClientName : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_USSD_DataCodingScheme *dataCodingScheme;
	UMGSMMAP_NameString *nameString;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_USSD_DataCodingScheme *dataCodingScheme;
@property(readwrite,strong)	UMGSMMAP_NameString *nameString;


- (void)processBeforeEncode;
- (UMGSMMAP_LCSClientName *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end
