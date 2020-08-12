//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@interface CNHandleStringClassifier : NSObject
{
    id _classificationStrategy;
}

+ (id)classificationStrategyForQuality:(unsigned long long)arg1;
+ (id)classificationOfHandleStrings:(id)arg1 classificationQuality:(unsigned long long)arg2;
+ (id)classificationOfHandleStrings:(id)arg1;

@property(readonly, nonatomic) id classificationStrategy; // @synthesize classificationStrategy=_classificationStrategy;
- (unsigned long long)typeOfHandleString:(id)arg1;
- (void)classifyHandleString:(id)arg1 builder:(id)arg2;
- (id)description;
- (id)initWithClassificationStrategy:(id)arg1;
- (id)initWithClassificationQuality:(unsigned long long)arg1;
- (id)init;

@end

