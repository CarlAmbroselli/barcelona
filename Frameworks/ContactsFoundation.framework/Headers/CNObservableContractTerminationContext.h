//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class NSArray;

@interface CNObservableContractTerminationContext : NSObject
{
    NSArray *_callStack;
    unsigned long long _threadId;
}

+ (unsigned long long)currentThreadId;
+ (id)currentContext;

@property(readonly) unsigned long long threadId; // @synthesize threadId=_threadId;
@property(readonly, copy) NSArray *callStack; // @synthesize callStack=_callStack;
- (id)initWithCallStack:(id)arg1 threadId:(unsigned long long)arg2;

@end

