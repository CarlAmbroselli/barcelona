//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSButton.h"

@class NSDictionary;

@interface SOWebLinkButton : NSButton
{
    NSDictionary *_attributes;
    NSDictionary *_mouseOverAttributes;
}

+ (Class)cellClass;
- (void).cxx_destruct;
@property(retain, nonatomic) NSDictionary *mouseOverAttributes; // @synthesize mouseOverAttributes=_mouseOverAttributes;
@property(retain, nonatomic) NSDictionary *attributes; // @synthesize attributes=_attributes;
- (void)setTitle:(id)arg1;
- (void)setAttributedTitle:(id)arg1;
- (void)cursorUpdate:(id)arg1;
- (void)mouseExited:(id)arg1;
- (void)mouseEntered:(id)arg1;
- (void)updateAttributedTitle:(BOOL)arg1;
- (void)_initializeButtonStyle;
- (void)sizeToFit;
- (void)setFont:(id)arg1;
- (void)setAlignment:(long long)arg1;
- (void)updateTrackingAreas;
- (void)awakeFromNib;
- (id)init;

@end

