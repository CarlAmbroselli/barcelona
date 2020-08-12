//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import "CNAutocompleteSourceInclusionPolicy.h"

@class CNUserDefaults, NSString;

@interface _CNAutocompleteUserDefaultsSourceInclusionPolicy : NSObject
{
    CNUserDefaults *_userDefaults;
}


@property(readonly) CNUserDefaults *userDefaults; // @synthesize userDefaults=_userDefaults;
@property(readonly) BOOL includeSupplementalResults;
@property(readonly) BOOL includeCalendarServers;
@property(readonly) BOOL includeDirectoryServers;
@property(readonly) BOOL includePredictions;
@property(readonly) BOOL includeLocalExtensions;
@property(readonly) BOOL includeSuggestions;
@property(readonly) BOOL includeRecents;
@property(readonly) BOOL includeContacts;
- (id)initWithUserDefaults:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

