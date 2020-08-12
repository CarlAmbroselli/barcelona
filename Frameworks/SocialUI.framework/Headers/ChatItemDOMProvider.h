//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <SocialUI/DOMProvider.h>

@class BalloonPluginDOMProvider, CollectiveAssociatedMessagesDOMProvider, DOMDocument, DateDOMProvider, NSMutableSet, PluginStatusDOMProvider;

@interface ChatItemDOMProvider : DOMProvider
{
    BOOL _animateReceiptChanges;
    BOOL _createDebugElements;
    BOOL _altFunction;
    BOOL _singleOptionPressed;
    CollectiveAssociatedMessagesDOMProvider *_associatedMessagesDOMProvider;
    BalloonPluginDOMProvider *_balloonPluginDOMProvider;
    PluginStatusDOMProvider *_pluginStatusDOMProvider;
    DateDOMProvider *_dateDOMProvider;
    NSMutableSet *_guidsForAllOwnedTransfers;
}

+ (BOOL)_hideHandlesInTranscript;
+ (void)initialize;

@property BOOL singleOptionPressed; // @synthesize singleOptionPressed=_singleOptionPressed;
@property BOOL altFunction; // @synthesize altFunction=_altFunction;
@property(retain) NSMutableSet *guidsForAllOwnedTransfers; // @synthesize guidsForAllOwnedTransfers=_guidsForAllOwnedTransfers;
@property(nonatomic) BOOL createDebugElements; // @synthesize createDebugElements=_createDebugElements;
@property(nonatomic) BOOL animateReceiptChanges; // @synthesize animateReceiptChanges=_animateReceiptChanges;
@property(retain) DateDOMProvider *dateDOMProvider; // @synthesize dateDOMProvider=_dateDOMProvider;
- (void)deselectChatItem:(id)arg1;
- (void)selectChatItem:(id)arg1;
- (id)parseMessageText:(id)arg1 chatItem:(id)arg2 messageElement:(id)arg3;
- (BOOL)_appendBigEmojiDivIfNeededForText:(id)arg1 chatItem:(id)arg2 messageTextElement:(id)arg3;
- (id)parseMessageSubject:(id)arg1;
- (id)errorElementForMessageGuid:(id)arg1;
- (void)_appendFaceTimeCallMessageItem:(id)arg1 toElement:(id)arg2 withChat:(id)arg3;
- (void)updateFaceTimeMultiwayBubble:(id)arg1 withChat:(id)arg2;
- (id)_childElementFromElement:(id)arg1 withTagName:(id)arg2;
- (id)_createFaceTimeBubbleWithMessageItem:(id)arg1 withChat:(id)arg2;
- (id)_faceTimeButtonForFaceTimeChatItem:(id)arg1 withChat:(id)arg2;
- (id)_faceTimeTextBoxForFacetimeChatItem:(id)arg1 withChat:(id)arg2;
- (id)_rootFaceTimeElementWithFaceTimeItem:(id)arg1 withChat:(id)arg2;
- (id)_faceTimeIconElement;
- (id)_faceTimeCallTextElement:(id)arg1;
- (id)_faceTimeCallHeaderElement:(id)arg1;
- (id)_faceTimeInfoButtonElement:(id)arg1;
- (id)_faceTimeJoinButtonElement:(id)arg1;
- (id)_parseBuddyIcon:(id)arg1;
- (id)_parseLocationShareActionChatItem:(id)arg1;
- (id)_parseMessageActionChatItem:(id)arg1;
- (id)_parseParticipantChangeChatItem:(id)arg1;
- (id)_parseGroupTitleChangeChatItem:(id)arg1;
- (id)_parseGroupActionChatItem:(id)arg1;
- (id)parseDateChatItem:(id)arg1;
- (id)_parseSenderChatItem:(id)arg1;
- (id)_compactDateStamp;
- (void)parseMessageChatItem:(id)arg1 appendToChatItem:(id)arg2 chat:(id)arg3;
- (void)beginPlayingTranscriptEffectOnElement:(id)arg1 itemGUID:(id)arg2 effectID:(id)arg3;
- (void)_playMomentEffectForElement:(id)arg1 effectID:(id)arg2 itemGUID:(id)arg3;
- (void)_playImpactEffectForElement:(id)arg1 effectID:(id)arg2 itemGUID:(id)arg3;
- (void)_performRippleEffectFromElement:(id)arg1 guid:(id)arg2;
- (void)_performForwardRippleEffectFromElement:(id)arg1 guid:(id)arg2;
- (void)_performBackwardRippleEffectFromElement:(id)arg1 guid:(id)arg2;
- (void)finishAnimatingElement:(id)arg1;
- (void)_setAnimationPropertiesOnElement:(id)arg1 className:(id)arg2 animationID:(id)arg3 itemGUID:(id)arg4;
- (void)parseMessageForReplay:(id)arg1 guid:(id)arg2 appendToChatItem:(id)arg3;
- (void)parseExpressiveSendAsTextChatItem:(id)arg1 appendToChatItem:(id)arg2;
- (void)parseEmoteChatItem:(id)arg1 appendToChatItem:(id)arg2;
- (id)_parseMessageChatItemFlags:(id)arg1 chat:(id)arg2;
- (id)_parseTypingChatItem:(id)arg1;
- (id)parseServiceChatItem:(id)arg1;
- (void)refreshBusinessHeader:(id)arg1;
- (id)_parseMessageStatus:(id)arg1;
- (id)parseChatItem:(id)arg1 chat:(id)arg2;
- (id)addRTLSpacingIfNeeded:(id)arg1;
- (void)setTextDirection:(id)arg1;
- (BOOL)_shouldHandlePhishingAttempts;
- (id)_createPhishingMessageDOMElement;
@property(readonly, nonatomic) PluginStatusDOMProvider *pluginStatusDOMProvider; // @synthesize pluginStatusDOMProvider=_pluginStatusDOMProvider;
@property(readonly, nonatomic) BalloonPluginDOMProvider *balloonPluginDOMProvider; // @synthesize balloonPluginDOMProvider=_balloonPluginDOMProvider;
@property(readonly, nonatomic) CollectiveAssociatedMessagesDOMProvider *associatedMessagesDOMProvider; // @synthesize associatedMessagesDOMProvider=_associatedMessagesDOMProvider;
- (void)dealloc;
- (id)initWithController:(id)arg1;
@property(readonly, nonatomic) __weak DOMDocument *DOM; // @dynamic DOM;

@end

