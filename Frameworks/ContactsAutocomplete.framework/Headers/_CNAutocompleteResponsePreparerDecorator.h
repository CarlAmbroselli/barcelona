//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <ContactsAutocomplete/CNAutocompleteQueryResponsePreparer.h>

@interface _CNAutocompleteResponsePreparerDecorator : CNAutocompleteQueryResponsePreparer
{
    CNAutocompleteQueryResponsePreparer *_preparer;
}


@property(readonly) CNAutocompleteQueryResponsePreparer *preparer; // @synthesize preparer=_preparer;
- (void)setMatchingPriorityResultsPromise:(id)arg1;
- (void)setPriorityResultsFuture:(id)arg1;
- (id)prepareResults:(id)arg1;
- (id)initWithResponsePreparer:(id)arg1 delegate:(id)arg2;

@end

