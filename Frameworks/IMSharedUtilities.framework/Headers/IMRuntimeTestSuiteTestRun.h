//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <IMSharedUtilities/IMRuntimeTestRun.h>

@class NSArray, NSMutableArray;

@interface IMRuntimeTestSuiteTestRun : IMRuntimeTestRun
{
    NSMutableArray *_testRuns;
    NSArray *_testRun;
}


@property(readonly, copy) NSArray *testRuns; // @synthesize testRuns=_testRun;
- (void)addTestRun:(id)arg1;
- (id)init;

@end

