//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import "CNAutocompletePerformanceProbe.h"

@class CNTracedLogger, NSMutableArray, NSString;

@interface CNAutocompletePerformanceTracing : NSObject
{
    CNTracedLogger *_logger;
    NSMutableArray *_pendingLogs;
}


@property(retain, nonatomic) NSMutableArray *pendingLogs; // @synthesize pendingLogs=_pendingLogs;
@property(retain, nonatomic) CNTracedLogger *logger; // @synthesize logger=_logger;
- (void)sendData;
- (void)recordNumberOfCalendarServerResults:(unsigned long long)arg1 inTimeInterval:(double)arg2;
- (void)recordNumberOfSupplementalResults:(unsigned long long)arg1 inTimeInterval:(double)arg2;
- (void)recordNumberOfPredictionResults:(unsigned long long)arg1 inTimeInterval:(double)arg2;
- (void)recordNumberOfDirectoryServerResults:(unsigned long long)arg1 inTimeInterval:(double)arg2;
- (void)recordNumberOfSuggestionResults:(unsigned long long)arg1 inTimeInterval:(double)arg2;
- (void)recordNumberOfContactResults:(unsigned long long)arg1 inTimeInterval:(double)arg2;
- (void)recordNumberOfRecentResults:(unsigned long long)arg1 inTimeInterval:(double)arg2;
- (void)recordLatency:(double)arg1 forResultCount:(unsigned long long)arg2 forSource:(id)arg3;
- (void)recordNumberOfResultsReturned:(unsigned long long)arg1 inTimeInterval:(double)arg2 forBatch:(unsigned long long)arg3 includesServers:(BOOL)arg4;
- (id)buildTraceLogWithSource:(id)arg1 numberOfResults:(unsigned long long)arg2 latency:(double)arg3;
- (id)initWithTracedLogger:(id)arg1;
- (id)domain;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

