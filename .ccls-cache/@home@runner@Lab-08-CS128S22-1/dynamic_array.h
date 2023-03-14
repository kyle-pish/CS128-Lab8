//Kyle Pish, Josh Reed
//3-3-22
#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include "partially_filled_array.h"

class DynamicArray : public PartiallyFilledArray {
  public:
    DynamicArray(int capacity);
    DynamicArray(int integers[], int size);
    ~DynamicArray();
    void Grow();
    void Append(int new_int);
    void Insert(int insert_me, int index);
    void Extend(DynamicArray& other);
    DynamicArray Slice(int start, int stop);
    void Clear();
};

void DynamicArray_main();

#endif