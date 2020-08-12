//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>

@class NSString;

@interface CNFoundationSocialProfile : NSObject
{
    NSString *_urlString;
    NSString *_username;
    NSString *_userIdentifier;
    NSString *_service;
    NSString *_displayName;
}

+ (id)emptySocialProfile;

@property(readonly, copy) NSString *displayName; // @synthesize displayName=_displayName;
@property(readonly, copy) NSString *service; // @synthesize service=_service;
@property(readonly, copy) NSString *userIdentifier; // @synthesize userIdentifier=_userIdentifier;
@property(readonly, copy) NSString *username; // @synthesize username=_username;
@property(readonly, copy) NSString *urlString; // @synthesize urlString=_urlString;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)description;
- (BOOL)isEmpty;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithUrlString:(id)arg1 username:(id)arg2 userIdentifier:(id)arg3 service:(id)arg4 displayName:(id)arg5;

@end

