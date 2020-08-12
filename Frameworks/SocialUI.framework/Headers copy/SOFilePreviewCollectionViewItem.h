//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSCollectionViewItem.h"

@class NSBlockOperation;

@interface SOFilePreviewCollectionViewItem : NSCollectionViewItem
{
    NSBlockOperation *_previewLoadOperation;
}

+ (id)_previewLoadOperationQueue;
- (void).cxx_destruct;
- (void)dealloc;
- (void)_deleteSection:(id)arg1;
- (void)copy:(id)arg1;
- (void)_openSelection:(id)arg1;
- (void)openFile;
- (void)mouseDown:(id)arg1;
- (void)setHighlightState:(long long)arg1;
- (void)setSelected:(BOOL)arg1;
- (void)setRepresentedObject:(id)arg1;

@end

