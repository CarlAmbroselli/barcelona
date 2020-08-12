//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <IMSharedUtilities/IMItem.h>

#import "IMRemoteObjectCoding.h"
#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>

@class NSString;

@interface IMMessageActionItem : IMItem <NSSecureCoding, NSCopying, IMRemoteObjectCoding>
{
    long long _actionType;
    NSString *_otherCountryCode;
    NSString *_otherHandle;
    NSString *_otherUnformattedID;
    NSString *_originalMessageGUID;
}

+ (BOOL)supportsSecureCoding;
@property(retain, nonatomic) NSString *originalMessageGUID; // @synthesize originalMessageGUID=_originalMessageGUID;
@property(retain, nonatomic) NSString *otherUnformattedID; // @synthesize otherUnformattedID=_otherUnformattedID;
@property(retain, nonatomic) NSString *otherHandle; // @synthesize otherHandle=_otherHandle;
@property(retain, nonatomic) NSString *otherCountryCode; // @synthesize otherCountryCode=_otherCountryCode;
@property(nonatomic) long long actionType; // @synthesize actionType=_actionType;
- (BOOL)isEqual:(id)arg1;
- (id)copyDictionaryRepresentation;
- (id)initWithDictionary:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;
- (void)dealloc;

@end

