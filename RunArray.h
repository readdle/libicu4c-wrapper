//
//  RunArray.h
//  SmartMailMessageParser
//
//  Created by Andrew on 3/15/17.
//  Copyright © 2017 Readdle. All rights reserved.
//

#ifndef RunArray_h
#define RunArray_h

#include <stdio.h>

struct CRunArrayItem {
    int32_t length;
    void *obj;
};
typedef struct CRunArrayItem CRunArrayItem;

struct CRunArray {
    int32_t length;
    int32_t numBlocks;
    int32_t maxBlocks;
    int32_t cachedBlock;
    int32_t cachedLocation;
    
    CRunArrayItem *list;
    
    int8_t (*isSame)(void *, void*);
    void* (*merge)(void *, void*);
    void (*retain)(void *);
    void (*release)(void *);
};
typedef struct CRunArray CRunArray;

CRunArray createNewCRunArray();
void deleteCRunArray(CRunArray *runArray);

int32_t runArrayBlockForLocation(CRunArray *runArray, int32_t location, int32_t *start, int32_t *end);
void runArrayInsert(CRunArray *runArray, int32_t lowerBound, int32_t upperBound, void *obj);
void runArrayReplace(CRunArray *runArray, int32_t rangeLowerBound, int32_t rangeUpperBound, void *value, int32_t newLength);
void runArraySetAttributes(CRunArray *runArray, int32_t rangeLowerBound, int32_t rangeUpperBound, void *replacementAttrs, int32_t numAdditionalItems, int clearOtherAttributes);

void runArraySetBlockCapacity(CRunArray *runArray, int32_t desiredCount, int8_t withExtra);

#endif /* RunArray_h */
