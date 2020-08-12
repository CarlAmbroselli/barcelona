//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSDictionary;

@interface IMServiceAgent : NSObject
{
    NSDictionary *_currentAVChatInfo;
}

+ (id)notificationCenter;
+ (void)forgetStatusImageAppearance;
+ (id)imageNameForStatus:(unsigned long long)arg1;
+ (id)imageURLForStatus:(unsigned long long)arg1;
+ (id)sharedAgent;
+ (long long)serviceAgentCapabilities;
+ (void)setServiceAgentCapabilities:(long long)arg1;
- (id)myPictureData;
- (void)launchIfNecessary;
@property(readonly, nonatomic) unsigned long long vcCapabilities;
- (unsigned long long)requestVideoStillForPerson:(id)arg1;
@property(readonly, nonatomic) unsigned long long requestAudioReflectorStop;
@property(readonly, nonatomic) unsigned long long requestAudioReflectorStart;
@property(readonly, nonatomic) __weak NSDictionary *currentAVChatInfo;
@property(retain, nonatomic) NSArray *myAwayMessages;
@property(retain, nonatomic) NSArray *myAvailableMessages;
- (void)setMyStatus:(unsigned long long)arg1 message:(id)arg2;
- (id)notificationCenter;
- (id)serviceWithNameNonBlocking:(id)arg1;
- (id)serviceWithName:(id)arg1;

@end

