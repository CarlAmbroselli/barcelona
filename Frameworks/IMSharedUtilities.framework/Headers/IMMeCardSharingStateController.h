//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@interface IMMeCardSharingStateController : NSObject
{
}

+ (id)sharedInstance;
- (BOOL)wasSharingEverEnabled;
- (void)_syncPreferenceDidChange;
- (void)_incrementSharingVersion;
@property(nonatomic) BOOL imageForkedFromMeCard;
@property(nonatomic) BOOL nameForkedFromMeCard;
- (void)postNameFormatChangedNotification;
@property(nonatomic) unsigned long long nameFormat;
@property(nonatomic) unsigned long long sharingAudience;
@property(nonatomic) BOOL sharingEnabled;
- (void)_migrateMeCardDomains;
- (id)init;

@end

