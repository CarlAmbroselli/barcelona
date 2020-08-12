//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class NSMutableSet, TranscriptStyleController;

@interface BuddyCSSProvider : NSObject
{
    unsigned int _iconSize;
    TranscriptStyleController *_styleController;
    NSMutableSet *_visibleIMHandles;
}


@property(readonly, nonatomic) NSMutableSet *visibleIMHandles; // @synthesize visibleIMHandles=_visibleIMHandles;
@property(nonatomic, setter=setIconSize:) unsigned int iconSize; // @synthesize iconSize=_iconSize;
@property(nonatomic) TranscriptStyleController *styleController; // @synthesize styleController=_styleController;
- (id)_personiconUrlForID:(id)arg1 accountGUID:(id)arg2 iconSize:(unsigned long long)arg3 hostPath:(id)arg4;
- (void)updateInfoForIMHandle:(id)arg1 force:(BOOL)arg2;
- (void)updateInfoForIMHandle:(id)arg1;
- (void)updatePictureForIMHandle:(id)arg1;
- (void)_updatePictureForIMHandle:(id)arg1 forceRule:(BOOL)arg2;
- (void)createRulesForIMHandle:(id)arg1;
- (void)clear;
- (id)initWithTranscriptStyleController:(id)arg1;

@end

