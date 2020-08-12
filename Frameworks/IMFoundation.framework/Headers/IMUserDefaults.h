//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class NSArray, NSDictionary, NSString;

@protocol IMUserDefaults <NSObject>
- (id)copyValueForKey:(NSString *)arg1 applicationID:(struct __CFString *)arg2 userName:(struct __CFString *)arg3 hostName:(struct __CFString *)arg4;
- (NSDictionary *)copyMultipleForCurrentKeys:(NSArray *)arg1 applicationID:(struct __CFString *)arg2 userName:(struct __CFString *)arg3 hostName:(struct __CFString *)arg4;
- (NSArray *)copyKeyListForApplicationID:(struct __CFString *)arg1 userName:(struct __CFString *)arg2 hostName:(struct __CFString *)arg3;
- (void)synchronizeApplicationID:(struct __CFString *)arg1 userName:(struct __CFString *)arg2 hostName:(struct __CFString *)arg3;
- (void)setMultiple:(NSDictionary *)arg1 remove:(NSArray *)arg2 applicationID:(struct __CFString *)arg3 userName:(struct __CFString *)arg4 hostName:(struct __CFString *)arg5;
- (void)setValue:(void *)arg1 forKey:(NSString *)arg2 applicationID:(struct __CFString *)arg3 userName:(struct __CFString *)arg4 hostName:(struct __CFString *)arg5;
- (id)copyValueForKey:(NSString *)arg1 appID:(NSString *)arg2;
- (NSDictionary *)copyMultipleForCurrentKeys:(NSArray *)arg1 appID:(NSString *)arg2;
- (NSArray *)copyKeyListForAppID:(NSString *)arg1;
- (void)synchronizeAppID:(NSString *)arg1;
- (void)setMultiple:(NSDictionary *)arg1 remove:(NSArray *)arg2 appID:(NSString *)arg3;
- (void)setValue:(void *)arg1 forKey:(NSString *)arg2 appID:(NSString *)arg3;
- (void)setAppBool:(BOOL)arg1 forKey:(NSString *)arg2;
- (BOOL)appBoolForKey:(NSString *)arg1;
- (void)removeAppValueForKey:(NSString *)arg1;
- (void)setAppValue:(id)arg1 forKey:(NSString *)arg2;
- (id)appValueForKey:(NSString *)arg1;
- (void)setAppBool:(BOOL)arg1 byHostForKey:(NSString *)arg2;
- (BOOL)appBoolByHostForKey:(NSString *)arg1;
@end

