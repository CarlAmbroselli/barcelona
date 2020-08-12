//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>



@class CNStack, NSString;

@interface CNCoalescingSchedulerDecorator : NSObject
{
    id _scheduler;
    double _coalescingWindow;
    unsigned long long _state;
    CNStack *_delayedBlocks;
}


@property(copy, nonatomic) CNStack *delayedBlocks; // @synthesize delayedBlocks=_delayedBlocks;
@property(nonatomic) unsigned long long state; // @synthesize state=_state;
@property(readonly, nonatomic) double coalescingWindow; // @synthesize coalescingWindow=_coalescingWindow;
@property(readonly, nonatomic) id scheduler; // @synthesize scheduler=_scheduler;
@property(readonly) double timestamp;
- (id)afterDelay:(double)arg1 performBlock:(id)arg2 qualityOfService:(unsigned long long)arg3;
- (id)afterDelay:(double)arg1 performBlock:(id)arg2;
- (id)performCancelableBlock:(id)arg1 qualityOfService:(unsigned long long)arg2;
- (id)performCancelableBlock:(id)arg1;
- (void)performBlock:(id)arg1 qualityOfService:(unsigned long long)arg2;
- (void)performBlock:(id)arg1;
- (void)removeDelayedBlock:(id)arg1;
- (void)flushDelayedBlock;
- (unsigned long long)getAndIncrementState;
- (id)initWithScheduler:(id)arg1 coalescingWindow:(double)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

