//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "DOMNodeFilter.h"

@class BuddyCSSProvider, DOMCSSMediaRule, DOMCSSStyleSheet, DOMDocument, DOMHTMLBodyElement, DOMHTMLHeadElement, NSMutableArray, NSMutableDictionary, NSMutableSet, NSString, WebView;

@interface TranscriptStyleController : NSObject <DOMNodeFilter>
{
    DOMCSSMediaRule *_2xRules;
    NSMutableSet *_dirtyCSSRules;
    NSMutableDictionary *_cssCache;
    NSMutableArray *_cssCacheOrder;
    NSMutableDictionary *_cssRuleMap;
    NSMutableDictionary *_2xRuleMap;
    unsigned int _changeCount;
    int _inBatchViewChangeCount;
    BOOL _batchChangeRequiresRebuild;
    BOOL _watchMessageAddressing;
    BOOL _messageContentIsHidden;
    BOOL _requiresCSSRebuild;
    BuddyCSSProvider *_buddyCSSProvider;
    WebView *_webView;
    DOMDocument *_DOM;
    DOMHTMLHeadElement *_head;
    DOMHTMLBodyElement *_body;
}

+ (id)scriptFileURLs;
+ (id)cssFilePath;
- (void).cxx_destruct;
@property(readonly, retain, nonatomic) DOMHTMLBodyElement *body; // @synthesize body=_body;
@property(retain, nonatomic) DOMHTMLHeadElement *head; // @synthesize head=_head;
@property(retain, nonatomic) DOMDocument *DOM; // @synthesize DOM=_DOM;
@property(nonatomic) WebView *webView; // @synthesize webView=_webView;
@property(nonatomic) BuddyCSSProvider *buddyCSSProvider; // @synthesize buddyCSSProvider=_buddyCSSProvider;
@property BOOL requiresCSSRebuild; // @synthesize requiresCSSRebuild=_requiresCSSRebuild;
- (double)minHeightPerMessage;
- (id)chatItemGUIDs;
- (short)acceptNode:(id)arg1;
- (void)personPictureChanged:(id)arg1;
- (void)personInfoChanged:(id)arg1;
- (void)applyRulesForChatItem:(id)arg1;
- (void)showPictures;
- (void)showNamesAndPictures;
- (void)bodyFinishLayout;
- (struct CGRect)screenBoundsForElementID:(id)arg1;
- (struct CGRect)screenBoundsForElement:(id)arg1;
- (void)undimTranscriptWithAnimation:(BOOL)arg1;
- (void)dimTranscriptWithAnimation:(BOOL)arg1;
- (BOOL)endBatchViewChange;
- (void)beginBatchViewChange;
- (void)_setNeedsRebuild;
- (void)clear;
- (void)clearCSSSelector:(id)arg1 forProperties:(id)arg2;
- (void)clearCSSSelector:(id)arg1;
- (BOOL)applyCSSSelector:(id)arg1 fromDictionary:(id)arg2;
- (BOOL)applyCSSSelector:(id)arg1 property:(id)arg2 value:(id)arg3;
- (BOOL)applyCSSSelector:(id)arg1 property:(id)arg2 value:(id)arg3 priority:(id)arg4;
- (BOOL)_applyQueuedCSSRules;
- (id)DOM2XMediaRuleForSelector:(id)arg1;
- (id)DOMCSSRuleForSelector:(id)arg1;
- (void)setDOM2XMediaRule:(id)arg1 forSelector:(id)arg2;
- (void)setDOMCSSRule:(id)arg1 forSelector:(id)arg2;
- (void)endChanges;
- (void)applyCurrentChanges;
- (void)_applyChanges;
- (int)changeCount;
- (BOOL)_rebuildCSSContent;
- (void)_rebuildCSSRuleMap;
- (id)_styleElement;
@property(retain, nonatomic) DOMCSSStyleSheet *DOMCSSStyleSheet; // @dynamic DOMCSSStyleSheet;
- (void)beginChanges;
- (void)dealloc;
- (id)window;
- (id)initWithWebView:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

