//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class IMCloudKitSyncState, IMCloudKitSyncStatistics, NSArray, NSString;

@interface IMCloudKitSyncProgress : NSObject
{
    BOOL _shouldShowProgressBar;
    BOOL _shouldShowIndeterminateProgress;
    BOOL _shouldShowUserActionLabel;
    BOOL _shouldShowUserMessageLabel;
    NSString *_progressLabel;
    double _progressBarValue;
    double _progressBarMax;
    NSString *_userMessageLabel;
    NSString *_actionLabel;
    long long _actionType;
    IMCloudKitSyncState *_syncState;
    IMCloudKitSyncStatistics *_syncStatistics;
    double _broadcastDeferralOverride;
}

@property(nonatomic) double broadcastDeferralOverride; // @synthesize broadcastDeferralOverride=_broadcastDeferralOverride;
@property(readonly, nonatomic) IMCloudKitSyncStatistics *syncStatistics; // @synthesize syncStatistics=_syncStatistics;
@property(readonly, nonatomic) IMCloudKitSyncState *syncState; // @synthesize syncState=_syncState;
@property(nonatomic) long long actionType; // @synthesize actionType=_actionType;
@property(retain, nonatomic) NSString *actionLabel; // @synthesize actionLabel=_actionLabel;
@property(retain, nonatomic) NSString *userMessageLabel; // @synthesize userMessageLabel=_userMessageLabel;
@property(nonatomic) BOOL shouldShowUserMessageLabel; // @synthesize shouldShowUserMessageLabel=_shouldShowUserMessageLabel;
@property(nonatomic) BOOL shouldShowUserActionLabel; // @synthesize shouldShowUserActionLabel=_shouldShowUserActionLabel;
@property(nonatomic) double progressBarMax; // @synthesize progressBarMax=_progressBarMax;
@property(nonatomic) double progressBarValue; // @synthesize progressBarValue=_progressBarValue;
@property(nonatomic) BOOL shouldShowIndeterminateProgress; // @synthesize shouldShowIndeterminateProgress=_shouldShowIndeterminateProgress;
@property(nonatomic) BOOL shouldShowProgressBar; // @synthesize shouldShowProgressBar=_shouldShowProgressBar;
@property(retain, nonatomic) NSString *progressLabel; // @synthesize progressLabel=_progressLabel;
@property(readonly, nonatomic, getter=isHidden) BOOL hidden; // @dynamic hidden;
@property(readonly, nonatomic) NSArray *errors; // @dynamic errors;
@property(readonly, nonatomic) double remainingItems; // @dynamic remainingItems;
@property(readonly, nonatomic) double percentComplete; // @dynamic percentComplete;
- (id)description;
- (void)configureSelf;
@property(readonly, nonatomic) NSString *percentCompleteString; // @dynamic percentCompleteString;
- (id)initWithSyncState:(id)arg1 syncStatistics:(id)arg2;
- (id)init;

@end

