// Author: Brian Law
//
#ifndef PARTIALLY_FILLED_ARRAY_H_
#define PARTIALLY_FILLED_ARRAY_H_

class PartiallyFilledArray {
  public:
    PartiallyFilledArray(int capacity);
    PartiallyFilledArray(int input[], int size);
    ~PartiallyFilledArray();

    void Append(int new_int);
    int Get(int index);
    int GetSize();
    int GetCapacity();
    bool IsFull();
    void Set(int index, int new_int);

    void Print();
    bool Contains(int find_me);
    int Count(int count_me);
    int Index(int index_me);
    int Pop();
    int PopAt(int index);
    void Insert(int insert_me, int index);
    void Remove(int remove_me);

  protected:
    int size_;
    int capacity_;
    
    // This is the array that is backing this PFA.
    // It will be heap-allocated, so it's a pointer.
    int* contents_;
};

void PartiallyFilledArray_main();

#endif