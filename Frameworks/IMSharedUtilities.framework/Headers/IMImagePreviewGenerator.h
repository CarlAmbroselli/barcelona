//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <IMSharedUtilities/IMPreviewGenerator.h>

#import "IMPreviewGeneratorProtocol.h"
#import "IMUTITypeInformation.h"

@interface IMImagePreviewGenerator : IMPreviewGenerator <IMPreviewGeneratorProtocol, IMUTITypeInformation>
{
}

+ (struct CGImage *)newThumbnailFillToSize:(struct CGSize)arg1 imagePxSize:(struct CGSize)arg2 imageSource:(struct CGImageSource *)arg3 scale:(double)arg4;
+ (struct CGSize)sizePreviewAtSourceURL:(id)arg1 withPreviewConstraints:(struct IMPreviewConstraints)arg2 error:(id )arg3;
+ (struct CGImage *)newPreviewFromSourceURL:(id)arg1 withPreviewConstraints:(struct IMPreviewConstraints)arg2 error:(id )arg3;
+ (id)UTITypes;
+ (id)fetchUTITypes;

@end

