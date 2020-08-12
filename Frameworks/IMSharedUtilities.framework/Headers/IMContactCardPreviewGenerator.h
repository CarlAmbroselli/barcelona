//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <IMSharedUtilities/IMImagePreviewGenerator.h>

#import "IMPreviewGeneratorProtocol.h"
#import "IMUTITypeInformation.h"

@interface IMContactCardPreviewGenerator : IMImagePreviewGenerator <IMPreviewGeneratorProtocol, IMUTITypeInformation>
{
}

+ (struct CGImage *)monogramForData:(id)arg1 constraints:(struct IMPreviewConstraints)arg2;
+ (id)vCardDataForURL:(id)arg1;
+ (struct CGImage *)newPreviewFromSourceURL:(id)arg1 withPreviewConstraints:(struct IMPreviewConstraints)arg2 error:(id )arg3;
+ (id)UTITypes;

@end

