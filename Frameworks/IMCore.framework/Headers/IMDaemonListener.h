//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSDaIMDaemonListenernary, NSMutableArray, NSMutableDictionary, NSProtocolChecker, NSString;

@interface IMDaemonListener : NSObject
{
    NSMutableDictionary *_properties;
    NSMutableDictionary *_persistentProperties;
    NSMutableArray *_deferredChatMessages;
    NSMutableArray *_handlers;
    NSProtocolChecker *_protocol;
    NSMutableDictionary *_services;
    NSDate *_myIdleSince;
    NSData *_myPicture;
    NSMutableDictionary *_contexts;
    NSString *_myStatusMessage;
    NSString *_myNowPlayingString;
    unsigned long long _myStatus;
    unsigned long long _vcCapabilities;
    BOOL _setupComplete;
    BOOL _postedSetupComplete;
    BOOL _holdingChatMessages;
    BOOL _hidingDisconnect;
    BOOL _hasPendingProcessChange;
}

@property(readonly, nonatomic) NSDictionary *persistentProperties; // @synthesize persistentProperties=_persistentProperties;
@property(readonly, nonatomic) NSDictionary *properties; // @synthesize properties=_properties;
@property(readonly, nonatomic) BOOL hasPostedSetupComplete; // @synthesize hasPostedSetupComplete=_postedSetupComplete;
@property(readonly, nonatomic) BOOL shouldHoldChatMessages; // @synthesize shouldHoldChatMessages=_holdingChatMessages;
@property(readonly, nonatomic) unsigned long long vcCapabilities; // @synthesize vcCapabilities=_vcCapabilities;
@property(readonly, nonatomic) NSString *myStatusMessage; // @synthesize myStatusMessage=_myStatusMessage;
@property(readonly, nonatomic) BOOL isSetupComplete; // @synthesize isSetupComplete=_setupComplete;
@property(readonly, nonatomic) NSArray *handlers; // @synthesize handlers=_handlers;
@property(nonatomic, setter=_setHidingDisconnect:) BOOL _hidingDisconnect; // @synthesize _hidingDisconnect;
@property(readonly, nonatomic) NSMutableDictionary *_contexts; // @synthesize _contexts;
- (void)oneTimeCodesDidChange:(id)arg1;
- (void)pendingNicknamesOrHandledNicknamesDidChange;
- (void)updatePersonalNickname:(id)arg1;
- (void)updateNicknameHandlesSharing:(id)arg1 handlesBlocked:(id)arg2;
- (void)handlesSharingNicknamesDidChange;
- (void)updatePendingNicknameUpdates:(id)arg1 handledNicknameUpdates:(id)arg2;
- (void)updateNicknameData:(id)arg1;
- (void)nicknameRequestResponse:(id)arg1 encodedNicknameData:(id)arg2;
- (void)receivedUrgentRequestForMessages:(id)arg1;
- (void)updateCloudKitStateWithDictionary:(id)arg1;
- (void)updateCloudKitState;
- (void)didAttemptToDisableAllDevicesResult:(BOOL)arg1;
- (void)didPerformAdditionalStorageRequiredCheckWithSuccess:(BOOL)arg1 additionalStorageRequired:(unsigned long long)arg2 forAccountId:(id)arg3 error:(id)arg4;
- (void)didAttemptToSetEnabledTo:(BOOL)arg1 result:(BOOL)arg2;
- (void)qosClassWhileServicingRequestsResponse:(unsigned int)arg1 identifier:(id)arg2;
- (void)forwardInvocation:(id)arg1;
- (id)methodSignatureForSelector:(SEL)arg1;
- (void)didFetchCloudKitSyncDebuggingInfo:(id)arg1;
- (void)didAttemptToDisableiCloudBackups:(long long)arg1 error:(id)arg2;
- (void)didFetchRampState:(id)arg1;
- (void)didFetchSyncStateStats:(id)arg1;
- (void)databaseChatSpamUpdated:(id)arg1;
- (void)databaseUpdated:(id)arg1;
- (void)_deferredSetup:(id)arg1;
- (void)setupComplete:(BOOL)arg1 info:(id)arg2;
- (void)account:(id)arg1 defaults:(id)arg2 blockList:(id)arg3 allowList:(id)arg4 blockingMode:(unsigned int)arg5 blockIdleStatus:(BOOL)arg6 status:(id)arg7 capabilities:(unsigned long long)arg8 serviceLoginStatus:(unsigned int)arg9 loginStatusMessage:(id)arg10;
- (void)service:(id)arg1 properties:(id)arg2 defaults:(id)arg3 defaultAccountSettings:(id)arg4 allAccounts:(id)arg5 activeAccounts:(id)arg6;
- (void)services:(id)arg1 properties:(id)arg2 persistentProperties:(id)arg3;
- (void)account:(id)arg1 status:(id)arg2 capabilities:(unsigned long long)arg3 serviceLoginStatus:(unsigned int)arg4 loginStatusMessage:(id)arg5;
- (void)persistentProperty:(id)arg1 changedTo:(id)arg2 from:(id)arg3;
- (void)_cacheValue:(id)arg1 forPersistentProperty:(id)arg2;
- (id)valueOfPersistentProperty:(id)arg1;
- (void)property:(id)arg1 changedTo:(id)arg2 from:(id)arg3;
- (void)_cacheValue:(id)arg1 forProperty:(id)arg2;
- (id)valueOfProperty:(id)arg1;
- (id)_stampForContext:(id)arg1;
- (void)_setStamp:(id)arg1 forContext:(id)arg2;
- (void)account:(id)arg1 postedError:(id)arg2;
- (void)account:(id)arg1 blockIdleStatusChanged:(BOOL)arg2;
- (void)account:(id)arg1 blockingModeChanged:(unsigned int)arg2;
- (void)account:(id)arg1 allowListChanged:(id)arg2;
- (void)account:(id)arg1 blockListChanged:(id)arg2;
- (void)account:(id)arg1 handleSubscriptionRequestFrom:(id)arg2 withMessage:(id)arg3;
- (void)account:(id)arg1 groupsChanged:(id)arg2 error:(id)arg3;
- (void)fileTransferHighQualityDownloadFailed:(id)arg1;
- (void)fileTransfer:(id)arg1 highQualityDownloadSucceededWithPath:(id)arg2;
- (void)fileTransfer:(id)arg1 updatedWithCurrentBytes:(unsigned long long)arg2 totalBytes:(unsigned long long)arg3 averageTransferRate:(unsigned long long)arg4;
- (void)fileTransfer:(id)arg1 updatedWithProperties:(id)arg2;
- (void)fileTransfers:(id)arg1 createdWithLocalPaths:(id)arg2;
- (void)fileTransfer:(id)arg1 createdWithProperties:(id)arg2;
- (void)account:(id)arg1 chat:(id)arg2 style:(unsigned char)arg3 chatProperties:(id)arg4 messagesReceived:(id)arg5;
- (void)account:(id)arg1 chat:(id)arg2 style:(unsigned char)arg3 chatProperties:(id)arg4 messageReceived:(id)arg5;
- (void)account:(id)arg1 chat:(id)arg2 style:(unsigned char)arg3 chatProperties:(id)arg4 invitationReceived:(id)arg5;
- (void)account:(id)arg1 buddyInfo:(id)arg2 commandDelivered:(id)arg3 properties:(id)arg4;
- (void)account:(id)arg1 buddyInfo:(id)arg2 commandReceived:(id)arg3 properties:(id)arg4;
- (void)account:(id)arg1 buddyProperties:(id)arg2 buddyPictures:(id)arg3;
- (void)pinCodeAlertCompleted:(id)arg1 deviceName:(id)arg2 deviceType:(id)arg3 phoneNumber:(id)arg4 responseFromDevice:(BOOL)arg5 wasCancelled:(BOOL)arg6;
- (void)displayPinCodeForAccount:(id)arg1 pinCode:(id)arg2 deviceName:(id)arg3 deviceType:(id)arg4 phoneNumber:(id)arg5;
- (void)account:(id)arg1 buddyPictureChanged:(id)arg2 imageData:(id)arg3 imageHash:(id)arg4;
- (void)account:(id)arg1 buddyPropertiesChanged:(id)arg2;
- (void)networkDataAvailabilityChanged:(BOOL)arg1;
- (void)vcCapabilitiesChanged:(unsigned long long)arg1;
- (void)account:(id)arg1 capabilitiesChanged:(unsigned long long)arg2;
- (void)account:(id)arg1 statusChanged:(id)arg2;
- (void)account:(id)arg1 loginStatusChanged:(unsigned int)arg2 message:(id)arg3 reason:(int)arg4 properties:(id)arg5;
- (void)accountRemoved:(id)arg1;
- (void)accountAdded:(id)arg1 defaults:(id)arg2 service:(id)arg3;
- (void)account:(id)arg1 defaultsChanged:(id)arg2;
- (void)activeAccountsChanged:(id)arg1 forService:(id)arg2;
- (void)defaultsChanged:(id)arg1 forService:(id)arg2;
- (void)releaseHeldChatMessages;
- (void)holdChatMessages;
@property(readonly, nonatomic) BOOL isHoldingChatMessages;
- (void)_deferNotification:(id)arg1;
- (void)_processDeferredInvitationDictionary:(id)arg1;
@property(readonly, nonatomic) unsigned int myIdleTime;
@property(readonly, nonatomic) unsigned long long myStatus;
- (void)_processMyStatusChanged;
- (void)_reallyProcessMyStatusChanged;
- (id)serviceWithName:(id)arg1;
@property(readonly, nonatomic) NSArray *allServices;
- (void)removeHandler:(id)arg1;
- (void)addHandler:(id)arg1;
- (void)_noteDisconnected;
- (id)init;

@end

