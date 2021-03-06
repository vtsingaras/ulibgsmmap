//
//  UMGSMMAP_SS_SubscriptionOption.m
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import "UMGSMMAP_SS_SubscriptionOption.h"

@implementation UMGSMMAP_SS_SubscriptionOption


@synthesize	operationName;
@synthesize	cliRestrictionOption;
@synthesize	overrideCategory;


- (void) processBeforeEncode
{
	[super processBeforeEncode];
	BOOL isImplicit = YES;
	if(self.asn1_tag.tagClass == UMASN1Class_ContextSpecific)
	{
		isImplicit = NO;
		asn1_tag.isConstructed=YES;
		asn1_list = [[NSMutableArray alloc]init];
	}
	if(cliRestrictionOption)
	{
		[cliRestrictionOption processBeforeEncode];
		if(isImplicit)
		{
			self.asn1_tag.tagNumber = 2;
			self.asn1_tag.tagClass = UMASN1Class_ContextSpecific;
			self.asn1_tag.isConstructed = cliRestrictionOption.asn1_tag.isConstructed;
			if(self.asn1_tag.isConstructed)
			{
				self.asn1_list = [cliRestrictionOption.asn1_list copy];
			}
			else
			{
				self.asn1_data = [cliRestrictionOption.asn1_data copy];
			}
		}
		else
		{
			cliRestrictionOption.asn1_tag.tagNumber = 2;
			cliRestrictionOption.asn1_tag.tagClass = UMASN1Class_ContextSpecific;
			[asn1_list addObject:cliRestrictionOption];
		}
	}
	else if(overrideCategory)
	{
		[overrideCategory processBeforeEncode];
		if(isImplicit)
		{
			self.asn1_tag.tagNumber = 1;
			self.asn1_tag.tagClass = UMASN1Class_ContextSpecific;
			self.asn1_tag.isConstructed = overrideCategory.asn1_tag.isConstructed;
			if(self.asn1_tag.isConstructed)
			{
				self.asn1_list = [overrideCategory.asn1_list copy];
			}
			else
			{
				self.asn1_data = [overrideCategory.asn1_data copy];
			}
		}
		else
		{
			overrideCategory.asn1_tag.tagNumber = 1;
			overrideCategory.asn1_tag.tagClass = UMASN1Class_ContextSpecific;
			[asn1_list addObject:overrideCategory];
		}
	}
	else
	{
	    @throw([NSException exceptionWithName:@"PARAMETER_MISSING"
	                                   reason:@"UMGSMMAP_SS_SubscriptionOption choice missing"
	                                userInfo:@{    @"backtrace": UMBacktrace(NULL,0)}]);
	}
}


- (UMGSMMAP_SS_SubscriptionOption *) processAfterDecodeWithContext:(id)context
{
	int p=0;
	UMASN1Object *o;
	BOOL isImplicit = YES;
	if(self.asn1_tag.tagClass == UMASN1Class_ContextSpecific)
	{
		isImplicit = NO;
		o = [self getObjectAtPosition:p++];
	}
	else
	{
		o = self;
	}
	
	if((o) && (o.asn1_tag.tagNumber == 2) && (o.asn1_tag.tagClass == UMASN1Class_ContextSpecific))
	{
		cliRestrictionOption = [[UMGSMMAP_CliRestrictionOption alloc]initWithASN1Object:o context:context];
	}
	else if((o) && (o.asn1_tag.tagNumber == 1) && (o.asn1_tag.tagClass == UMASN1Class_ContextSpecific))
	{
		overrideCategory = [[UMGSMMAP_OverrideCategory alloc]initWithASN1Object:o context:context];
	}
	return self;
}

- (NSString *) objectName
{
	return @"SS-SubscriptionOption";
}
- (id) objectValue
{
	UMSynchronizedSortedDictionary *dict = [[UMSynchronizedSortedDictionary alloc]init];
	if(cliRestrictionOption)
	{
		dict[@"cliRestrictionOption"] = cliRestrictionOption.objectValue;
	}
	if(overrideCategory)
	{
		dict[@"overrideCategory"] = overrideCategory.objectValue;
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

