//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "IMAssociatedMessageChatItem.h"

#import "IMVisibleAssociatedMessageHost-Protocol.h"

@class NSArray, NSAttributedString, NSString;

@interface IMMessageEditChatItem : IMAssociatedMessageChatItem <IMVisibleAssociatedMessageHost>
{
    NSArray *_visibleAssociatedMessageChatItems;
}

@property(retain, nonatomic, setter=_setVisibleAssociatedMessageChatItems:) NSArray *visibleAssociatedMessageChatItems; // @synthesize visibleAssociatedMessageChatItems=_visibleAssociatedMessageChatItems;
@property(readonly, retain, nonatomic) NSAttributedString *editedBody;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

