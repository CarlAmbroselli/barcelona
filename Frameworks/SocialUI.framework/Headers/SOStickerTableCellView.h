//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class NSTextField;

@interface SOStickerTableCellView : NSTableCellView
{
    NSTextField *_nameLabel;
    NSTextField *_timeLabel;
}


@property(retain) NSTextField *timeLabel; // @synthesize timeLabel=_timeLabel;
@property(retain) NSTextField *nameLabel; // @synthesize nameLabel=_nameLabel;
- (void)setObjectValue:(id)arg1;
- (id)imageForTransferGuid:(id)arg1;

@end

