//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <ContactsFoundation/CNObservable.h>

@interface _CNDistinctUntilChangedObservable : CNObservable
{
    id _observable;
    id _lastObservedResult;
}


- (BOOL)_resultIsDistinctFromLastResult:(id)arg1;
- (id)subscribe:(id)arg1;
- (id)initWithObservable:(id)arg1;

@end

