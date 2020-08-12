//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <ContactsFoundation/CNTask.h>

@class ACAccountStore, CNResult, NSMutableArray;

@interface CNFamilyCircleConfigurationUpdateTask : CNTask
{
    id _accountSource;
    id _accountSink;
    ACAccountStore *_accountStore;
    NSMutableArray *_delegateAccounts;
    CNResult *_result;
}

+ (id)os_log;

@property(retain, nonatomic) CNResult *result; // @synthesize result=_result;
@property(readonly, nonatomic) NSMutableArray *delegateAccounts; // @synthesize delegateAccounts=_delegateAccounts;
@property(readonly, nonatomic) ACAccountStore *accountStore; // @synthesize accountStore=_accountStore;
@property(readonly, nonatomic) id accountSink; // @synthesize accountSink=_accountSink;
@property(readonly, nonatomic) id accountSource; // @synthesize accountSource=_accountSource;
- (void)updateDelegateAccounts;
- (void)loadDefaultSinkIfNecessary;
- (void)loadDelegateAccountsFromSource;
- (void)loadDefaultSourceIfNecessary;
- (id)run:(id )arg1;
- (id)description;
- (id)initWithAccountSource:(id)arg1 accountSink:(id)arg2 accountStore:(id)arg3;
- (id)initWithName:(id)arg1;
- (id)init;

@end

