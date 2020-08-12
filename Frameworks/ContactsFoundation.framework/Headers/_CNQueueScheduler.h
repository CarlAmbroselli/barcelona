//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>



@class NSObject, NSString;

@interface _CNQueueScheduler : NSObject
{
    NSObject *_queue;
}


@property(readonly) NSObject *queue; // @synthesize queue=_queue;
@property(readonly) double timestamp;
- (id)afterDelay:(double)arg1 performBlock:(id)arg2 qualityOfService:(unsigned long long)arg3;
- (id)afterDelay:(double)arg1 performBlock:(id)arg2;
- (id)performCancelableBlock:(id)arg1 qualityOfService:(unsigned long long)arg2;
- (id)performCancelableBlock:(id)arg1;
- (id)_queueForQualityOfService:(unsigned long long)arg1;
- (void)performBlock:(id)arg1 qualityOfService:(unsigned long long)arg2;
- (void)performBlock:(id)arg1;
- (id)initWithQueue:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

