//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>

@class NSArray;

@interface CNHandleStringClassification : NSObject
{
    NSArray *_emailAddresses;
    NSArray *_phoneNumbers;
    NSArray *_unknown;
}

+ (BOOL)supportsSecureCoding;

@property(readonly, copy, nonatomic) NSArray *unknown; // @synthesize unknown=_unknown;
@property(readonly, copy, nonatomic) NSArray *phoneNumbers; // @synthesize phoneNumbers=_phoneNumbers;
@property(readonly, copy, nonatomic) NSArray *emailAddresses; // @synthesize emailAddresses=_emailAddresses;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)description;
- (id)initWithEmailAddresses:(id)arg1 phoneNumbers:(id)arg2 unknown:(id)arg3;
- (id)initWithBuilder:(id)arg1;

@end

