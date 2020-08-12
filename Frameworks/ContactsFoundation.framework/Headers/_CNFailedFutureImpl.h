//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import "CNFutureImpl.h"

@class NSError, NSString;

@interface _CNFailedFutureImpl : NSObject
{
    NSError *_error;
}


- (void)updateDescriptionWithBuilder:(id)arg1;
- (BOOL)cancel;
- (BOOL)isCancelled;
- (BOOL)isFinished;
- (void)addFailureBlock:(id)arg1;
- (void)addSuccessBlock:(id)arg1;
- (id)resultBeforeDate:(id)arg1 error:(id )arg2;
- (id)initWithError:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

