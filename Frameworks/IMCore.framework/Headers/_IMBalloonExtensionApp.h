//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "IMBalloonApp.h"

@class LSPlugInKitProxy, NSExtension;

@interface _IMBalloonExtensionApp : IMBalloonApp
{
    NSExtension *_extension;
    LSPlugInKitProxy *_proxy;
}

@property(retain, nonatomic) LSPlugInKitProxy *proxy; // @synthesize proxy=_proxy;
@property(retain, nonatomic) NSExtension *extension; // @synthesize extension=_extension;
- (BOOL)isLaunchProhibited;
- (id)plugin;
- (void)setIsEnabled:(BOOL)arg1;
- (BOOL)isEnabled;
- (BOOL)showableInBrowser;
- (BOOL)showInBrowser;
- (id)applicationType;
- (BOOL)isBetaPlugin;
- (BOOL)isStickerPackOnly;
- (id)itemID;
- (id)version;
- (id)initWithPluginBundle:(id)arg1 extension:(id)arg2 pluginKitProxyClass:(Class)arg3 proxy:(id)arg4;
- (id)initWithPluginBundle:(id)arg1 extension:(id)arg2;
- (id)initWithPluginBundle:(id)arg1 pluginKitProxy:(id)arg2 extension:(id)arg3;

@end

