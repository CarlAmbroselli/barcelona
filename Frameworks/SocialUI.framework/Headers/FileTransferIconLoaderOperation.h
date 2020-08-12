//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class NSData, NSDictionary, NSURL;

@interface FileTransferIconLoaderOperation : NSOperation
{
    NSDictionary *_options;
    NSURL *_url;
    NSData *_bookmark;
    id _delegate;
    struct CGSize _thumbnailSize;
}


@property(nonatomic) __weak id delegate; // @synthesize delegate=_delegate;
@property(nonatomic) struct CGSize thumbnailSize; // @synthesize thumbnailSize=_thumbnailSize;
@property(retain, nonatomic) NSData *bookmark; // @synthesize bookmark=_bookmark;
@property(copy, nonatomic) NSURL *url; // @synthesize url=_url;
- (void)main;
- (void)_notifyDelegate:(id)arg1;
- (id)init;

@end

