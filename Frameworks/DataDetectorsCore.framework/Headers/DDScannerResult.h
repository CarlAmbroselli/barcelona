//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>

@class NSArray, NSString, NSURL;

@interface DDScannerResult : NSObject
{
    // Error parsing type: ^{__DDResult={__CFRuntimeBase=QAQ}{__DDQueryRange={__DDQueryOffset=b32b32}{__DDQueryOffset=b32b32}}{?=qq}q^{__CFArray}^{__CFString}^{__CFString}^v^{__CFDictionary}qCf}, name: _coreResult
    NSArray *_subResultsCache;
    NSURL *_cachedURL;
    BOOL _hasCachedURL;
}

+ (id)scannerResultFromXML:(id)arg1 stringToScan:(id)arg2;
+ (id)scannerResultFromXML:(id)arg1;
+ (id)verboseXMLDescriptionFromElements:(id)arg1 stringToScan:(id)arg2;
+ (BOOL)supportsSecureCoding;
+ (id)resultsFromCoreResults:(struct __CFArray *)arg1;
@property(readonly, nonatomic) NSURL *url;
- (void)offsetRangeBy:(long long)arg1;
- (id)XMLDescription;
- (id)detailedDescription;
- (id)verboseElement;
- (id)elementWithQuery:(struct __DDScanQuery *)arg1 include:(int)arg2;
- (void)_addText:(id)arg1 currentPos:(struct __DDQueryOffset)arg2 newPos:(struct __DDQueryOffset)arg3 offset:(struct __DDQueryOffset)arg4 query:(struct __DDScanQuery *)arg5;
- (id)element;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (BOOL)getStreet:(id )arg1 city:(id )arg2 state:(id )arg3 zip:(id )arg4 country:(id )arg5;
- (BOOL)getIMScreenNameValue:(id )arg1 type:(id )arg2;
- (BOOL)getMailValue:(id )arg1 label:(id )arg2;
- (BOOL)getPhoneValue:(id )arg1 label:(id )arg2;
- (BOOL)extractStartDate:(id )arg1 startTimezone:(id )arg2 endDate:(id )arg3 endTimezone:(id )arg4 allDayRef:(char *)arg5 referenceDate:(id)arg6 referenceTimezone:(id)arg7;
- (id)dateFromReferenceDate:(id)arg1 referenceTimezone:(id)arg2 timezoneRef:(id )arg3 allDayRef:(char *)arg4;
- (double)getDuration;
- (id)valueForUndefinedKey:(id)arg1;
- (void)setSubResults:(id)arg1;
- (id)subResults;
- (BOOL)isEqual:(id)arg1;
- (id)description;
@property(readonly, nonatomic) NSString *matchedString;
- (id)contextualData;
- (id)location;
- (id)rawValue;
@property(readonly, nonatomic) NSString *value;
- (void)setType:(id)arg1;
@property(readonly, nonatomic) NSString *type;
- (BOOL)typeIs:(struct __CFString *)arg1;
- (long long)score;
- (id)cfRange;
@property struct _NSRange range;
@property(readonly, nonatomic) int category;
@property(readonly, nonatomic) struct _NSRange urlificationRange;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)init;

@end

