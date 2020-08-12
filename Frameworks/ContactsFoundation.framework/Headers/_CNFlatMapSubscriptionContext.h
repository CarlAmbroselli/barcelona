//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class CNQueue, NSMutableArray;

@interface _CNFlatMapSubscriptionContext : NSObject
{
    CNQueue *_decorators;
    NSMutableArray *_tokens;
    id _downstream;
    id _resourceLock;
    BOOL _operatorReceiving;
    BOOL _observerReceiving;
}


@property(readonly) id resourceLock; // @synthesize resourceLock=_resourceLock;
@property(readonly) id downstream; // @synthesize downstream=_downstream;
@property(readonly) NSMutableArray *tokens; // @synthesize tokens=_tokens;
@property(readonly) CNQueue *decorators; // @synthesize decorators=_decorators;
@property(getter=isObserverReceiving) BOOL observerReceiving; // @synthesize observerReceiving=_observerReceiving;
@property(getter=isOperatorReceiving) BOOL operatorReceiving; // @synthesize operatorReceiving=_operatorReceiving;
- (id)initWithSchedulerProvider:(id)arg1;

@end

