//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class NSSegmentedControl, SOContentAttachmentsViewController, SOPhotoAttachmentsViewController;

@interface SOAttachmentsTabViewController : NSTabViewController
{
    BOOL _hasUpdatedAttachments;
    id _delegate;
    SOPhotoAttachmentsViewController *_photoAttachmentsViewController;
    SOContentAttachmentsViewController *_fileAttachmentsViewController;
}


@property BOOL hasUpdatedAttachments; // @synthesize hasUpdatedAttachments=_hasUpdatedAttachments;
@property(retain) SOContentAttachmentsViewController *fileAttachmentsViewController; // @synthesize fileAttachmentsViewController=_fileAttachmentsViewController;
@property(retain) SOPhotoAttachmentsViewController *photoAttachmentsViewController; // @synthesize photoAttachmentsViewController=_photoAttachmentsViewController;
@property __weak id  delegate; // @synthesize delegate=_delegate;
- (void)setRepresentedObject:(id)arg1;
- (void)chatDisplayControllerDidChange:(id)arg1;
- (void)chatDisplayControllerWillChange:(id)arg1;
- (id)chatDisplayController;
- (void)_chatPurgedAttachmentsDownloadBatchDidComplete:(id)arg1;
- (void)_chatItemsChanged:(id)arg1;
- (void)_updateSelectedTabViewItemIndex;
- (void)_updateEnabledTabs;
- (void)_updateAttachments;
- (void)_parseAndSetAttachments:(id)arg1;
- (double)stackViewFrameDidChange:(struct CGSize)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (void)tabView:(id)arg1 didSelectTabViewItem:(id)arg2;
- (void)viewDidLoad;
@property(readonly, nonatomic) BOOL hasPhotoAttachments;
@property(readonly) BOOL hasAttachments;
@property(readonly, nonatomic) NSSegmentedControl *segmentedControl;

@end

