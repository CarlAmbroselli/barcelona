//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSView.h"

@class NSImage, NSLayoutConstraint;

@interface SOPreviewingWaveformView : NSView
{
    NSImage *_waveform;
    NSLayoutConstraint *_waveformWidthLayoutConstraint;
    NSImage *_unplayedWaveform;
    NSImage *_playedWaveform;
}

- (void).cxx_destruct;
@property(retain, nonatomic) NSImage *playedWaveform; // @synthesize playedWaveform=_playedWaveform;
@property(retain, nonatomic) NSImage *unplayedWaveform; // @synthesize unplayedWaveform=_unplayedWaveform;
@property(retain, nonatomic) NSLayoutConstraint *waveformWidthLayoutConstraint; // @synthesize waveformWidthLayoutConstraint=_waveformWidthLayoutConstraint;
@property(retain, nonatomic) NSImage *waveform; // @synthesize waveform=_waveform;
- (void)clearWaveform;
- (void)drawRect:(struct CGRect)arg1;

@end

