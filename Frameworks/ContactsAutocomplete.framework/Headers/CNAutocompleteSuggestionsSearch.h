//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import "CNAutocompleteSearch.h"

@class CNContactStore, NSString;

@interface CNAutocompleteSuggestionsSearch : NSObject
{
    CNContactStore *_contactStore;
}

+ (unsigned long long)charactersThreshold;

@property(readonly, nonatomic) CNContactStore *contactStore; // @synthesize contactStore=_contactStore;
- (id)resultTransformWithFactory:(id)arg1 properties:(id)arg2;
- (id)resultTransformWithRequest:(id)arg1;
- (id)convertContacts:(id)arg1 request:(id)arg2;
- (id)suggestedContactsForRequest:(id)arg1 error:(id )arg2;
- (id)executeRequest:(id)arg1 completionHandler:(id)arg2;
- (id)initWithContactStore:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

