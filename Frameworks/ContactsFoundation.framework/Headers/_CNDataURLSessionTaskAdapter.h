//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

#import <Foundation/Foundation.h>

@class NSString;

@interface _CNDataURLSessionTaskAdapter : NSObject
{
    id _onDataReceived;
    id _onCompletion;
}


@property(copy) id onCompletion; // @synthesize onCompletion=_onCompletion;
@property(copy) id onDataReceived; // @synthesize onDataReceived=_onDataReceived;
- (void)URLSession:(id)arg1 task:(id)arg2 didCompleteWithError:(id)arg3;
- (void)URLSession:(id)arg1 dataTask:(id)arg2 didReceiveData:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

