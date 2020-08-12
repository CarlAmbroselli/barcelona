//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <SocialUI/SOTranscriptViewController.h>

#import "IMChatTranscriptLayoutEngineDataSource.h"
#import "IMFullScreenEffectManagerDelegate.h"
#import "NSCollectionViewDataSource.h"
#import "SOTranscriptCollectionViewItemDelegate.h"

@class IMChatTranscriptLayoutEngine, IMChatTranscriptLayoutSpecification, NSCollectionView, NSString;

@interface SONativeTranscriptViewController : SOTranscriptViewController <IMChatTranscriptLayoutEngineDataSource, NSCollectionViewDataSource, SOTranscriptCollectionViewItemDelegate, IMFullScreenEffectManagerDelegate>
{
    BOOL _geometryDirty;
    struct NSEdgeInsets _scrollViewInsets;
    id <SONativeTranscriptViewControllerDelegate> _delegate;
    id <IMChatTranscriptItemVending> _chatTranscriptItemProvider;
    NSCollectionView *_collectionView;
    IMChatTranscriptLayoutEngine *_layoutEngine;
    IMChatTranscriptLayoutSpecification *_layoutSpecification;
}

+ (void)load;
- (void).cxx_destruct;
@property(retain, nonatomic) IMChatTranscriptLayoutSpecification *layoutSpecification; // @synthesize layoutSpecification=_layoutSpecification;
@property(retain, nonatomic) IMChatTranscriptLayoutEngine *layoutEngine; // @synthesize layoutEngine=_layoutEngine;
@property __weak NSCollectionView *collectionView; // @synthesize collectionView=_collectionView;
@property(retain, nonatomic) id <IMChatTranscriptItemVending> chatTranscriptItemProvider; // @synthesize chatTranscriptItemProvider=_chatTranscriptItemProvider;
@property __weak id <SONativeTranscriptViewControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(readonly, nonatomic) IMChatTranscriptLayoutSpecification *test_layoutSpecification;
@property(retain, nonatomic, setter=test_setChatTranscriptItemProvider:) id <IMChatTranscriptItemVending> test_chatTranscriptItemProvider;
@property(readonly, nonatomic) NSCollectionView *test_collectionView;
- (id)_hostView;
- (void)_createLayoutSpecificationIfNeeded;
- (void)_collectionViewFrameDidChange:(id)arg1;
- (id)collectionView:(id)arg1 itemForRepresentedObjectAtIndexPath:(id)arg2;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (id)layoutEngine:(id)arg1 transcriptItemAtIndex:(unsigned long long)arg2;
- (unsigned long long)numberOfTranscriptItemsForLayoutEngine:(id)arg1;
- (void)setBottomOverlap:(double)arg1;
- (void)setTopOverlap:(double)arg1;
- (void)_scrollToLastItemAnimated:(BOOL)arg1;
- (double)distanceFromBottom;
- (BOOL)lastMessageIsVisible;
- (void)endChanges;
- (void)updateAttachments;
- (void)processChatItemChanges:(id)arg1;
- (void)_processLayoutEngineDrawableChanges:(id)arg1;
- (void)_scrollRectToVisible:(struct CGRect)arg1 animated:(BOOL)arg2;
- (void)_scrollToIndexPath:(id)arg1 animated:(BOOL)arg2;
- (long long)currentScrollPosition;
- (void)chatDisplayControllerDidChange:(id)arg1;
- (void)reloadDataAndScrollToEnd:(BOOL)arg1;
- (void)transcriptCollectionViewItemPlayExpressiveMessageIfNeeded:(id)arg1;
- (void)transcriptCollectionViewItemReplayExpressiveMessage:(id)arg1;
- (void)transcriptCollectionViewItemBeginLoadingMoreHistory:(id)arg1;
- (void)_didFinishScrolling:(id)arg1;
- (id)scrollView;
- (void)viewDidLoad;
- (id)nibName;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

