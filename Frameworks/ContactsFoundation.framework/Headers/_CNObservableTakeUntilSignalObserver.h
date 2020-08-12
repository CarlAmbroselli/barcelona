//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import "CNObserver.h"

@class NSString;

@interface _CNObservableTakeUntilSignalObserver : NSObject
{
    id _observer;
    id _delegate;
}


@property(readonly) __weak id delegate; // @synthesize delegate=_delegate;
@property(readonly) id observer; // @synthesize observer=_observer;
- (void)observerDidFailWithError:(id)arg1;
- (void)observerDidComplete;
- (void)observerDidReceiveResult:(id)arg1;
@property(readonly, copy) NSString *description;
- (id)initWithObserver:(id)arg1 delegate:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

