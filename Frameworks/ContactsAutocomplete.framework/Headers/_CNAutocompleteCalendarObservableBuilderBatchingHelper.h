//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import "CNAutocompleteObservableBuilderBatchingHelper.h"

@class NSString, _CNAutocompleteObservableBuilderBatchingHelper;

@interface _CNAutocompleteCalendarObservableBuilderBatchingHelper : NSObject
{
    _CNAutocompleteObservableBuilderBatchingHelper *_helper;
}


@property(retain, nonatomic) _CNAutocompleteObservableBuilderBatchingHelper *helper; // @synthesize helper=_helper;
- (BOOL)batchAtIndexIncludesServer:(unsigned long long)arg1;
- (void)addCalendarServerObservable:(id)arg1;
- (void)addCachedCalendarServerObservable:(id)arg1;
- (void)addDirectoryServerObservable:(id)arg1;
- (void)addCachedDirectoryServerObservable:(id)arg1;
- (void)addSupplementalObservable:(id)arg1;
- (void)addDuetObservable:(id)arg1;
- (void)addLocalExtensionObservable:(id)arg1;
- (void)addSuggestionsObservable:(id)arg1;
- (void)addCoreRecentsObservable:(id)arg1;
- (void)addContactsObservable:(id)arg1;
- (id)batchedObservables;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

