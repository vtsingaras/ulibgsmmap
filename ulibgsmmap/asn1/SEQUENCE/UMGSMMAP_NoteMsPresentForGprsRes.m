//
//  UMGSMMAP_NoteMsPresentForGprsRes.m
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
//

#import "UMGSMMAP_NoteMsPresentForGprsRes.h"

@implementation UMGSMMAP_NoteMsPresentForGprsRes


@synthesize	operationName;
@synthesize	extensionContainer;


- (void) processBeforeEncode
{
	[super processBeforeEncode];
	[asn1_tag setTagIsConstructed];
	asn1_list = [[NSMutableArray alloc]init];
	if(extensionContainer)
	{
		[asn1_list addObject:extensionContainer];
	}
}


- (UMGSMMAP_NoteMsPresentForGprsRes *) processAfterDecodeWithContext:(id)context
{
	[self setMagic:@"UMGSMMAP_NoteMsPresentForGprsRes"];
	int p=0;
	UMASN1Object *o = [self getObjectAtPosition:p++];
	if(o)
	{
		extensionContainer = [[UMGSMMAP_ExtensionContainer alloc]initWithASN1Object:o context:context];
		o = [self getObjectAtPosition:p++];
	}
	while(o)
	{
	}
	return self;
}

- (NSString *) objectName
{
	return @"NoteMsPresentForGprsRes";
}
- (id) objectValue
{
	UMSynchronizedSortedDictionary *dict = [[UMSynchronizedSortedDictionary alloc]init];
	if(extensionContainer)
	{
		dict[@"extensionContainer"] = extensionContainer.objectValue;
	}
	return dict;
}

- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context
{
    return self;
}


@end

