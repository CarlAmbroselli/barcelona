//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSViewController.h"

#import "SOEffectPickerViewControllerDelegate.h"

@class NSButton, NSString, NSTextField, SOBalloonEffectPickerViewController, SOEffectPickerUnsentMessage, SOFullScreenEffectPickerViewController;

@interface SOTranscriptEffectPicker : NSViewController <SOEffectPickerViewControllerDelegate>
{
    id <SOTranscriptEffectPickerDelegate> _delegate;
    NSButton *_balloonButton;
    NSButton *_momentButton;
    NSButton *_cancelButton;
    NSButton *_sendButton;
    NSTextField *_titleView;
    SOFullScreenEffectPickerViewController *_momentsViewController;
    SOBalloonEffectPickerViewController *_balloonsViewController;
    NSString *_chosenEffect;
    SOEffectPickerUnsentMessage *_unsentMessage;
}

- (void).cxx_destruct;
@property(retain) SOEffectPickerUnsentMessage *unsentMessage; // @synthesize unsentMessage=_unsentMessage;
@property(retain) NSString *chosenEffect; // @synthesize chosenEffect=_chosenEffect;
@property(retain, nonatomic) SOBalloonEffectPickerViewController *balloonsViewController; // @synthesize balloonsViewController=_balloonsViewController;
@property(retain, nonatomic) SOFullScreenEffectPickerViewController *momentsViewController; // @synthesize momentsViewController=_momentsViewController;
@property(nonatomic) __weak NSTextField *titleView; // @synthesize titleView=_titleView;
@property(nonatomic) __weak NSButton *sendButton; // @synthesize sendButton=_sendButton;
@property(nonatomic) __weak NSButton *cancelButton; // @synthesize cancelButton=_cancelButton;
@property(nonatomic) __weak NSButton *momentButton; // @synthesize momentButton=_momentButton;
@property(nonatomic) __weak NSButton *balloonButton; // @synthesize balloonButton=_balloonButton;
@property __weak id <SOTranscriptEffectPickerDelegate> delegate; // @synthesize delegate=_delegate;
- (void)effectPicker:(id)arg1 setSendEnabled:(BOOL)arg2;
- (void)userChoseSendPicker:(id)arg1;
- (void)userCancelledPicker:(id)arg1;
- (void)effectPickerViewControllerWasCancelled:(id)arg1;
- (void)effectPickerViewController:(id)arg1 didChooseEffect:(id)arg2;
- (void)effectPickerViewController:(id)arg1 didPreviewEffect:(id)arg2;
- (void)viewWillLayout;
- (void)momentsButtonWasPressed:(id)arg1;
- (void)bubbleButtonWasPressed:(id)arg1;
- (void)setBalloonMode:(BOOL)arg1;
- (void)showViewController:(id)arg1 hideViewController:(id)arg2;
- (void)viewDidLoad;
- (id)initWithUnsentMessage:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

