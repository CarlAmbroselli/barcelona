//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class NSArray, NSString;

@interface CNAutocompleteResultTokenMatcher : NSObject
{
    NSArray *_tokens;
    NSString *_countryCode;
}

+ (id)normalizePhoneNumber:(id)arg1 countryCode:(id)arg2;
+ (id)tokenizePhoneNumber:(id)arg1;
+ (id)indexTokensFromPhoneNumber:(id)arg1;
+ (id)searchTokensFromString:(id)arg1;

- (id)representationsOfPhoneNumber:(id)arg1;
- (id)tokensForResultValue:(id)arg1;
- (id)tokensForResultName:(id)arg1;
- (id)nameTokensForResult:(id)arg1;
- (BOOL)evaluateTopLevelGroupResult:(id)arg1;
- (BOOL)evaluateSingleResult:(id)arg1;
- (BOOL)evaluateResult:(id)arg1;
- (id)filterAdapter;
- (id)initWithSearchString:(id)arg1 countryCode:(id)arg2;
- (id)initWithSearchString:(id)arg1;
- (id)init;

@end

