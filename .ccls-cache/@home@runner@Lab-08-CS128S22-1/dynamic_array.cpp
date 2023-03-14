//Kyle Pish, Josh Reed
//3-3-22
#include <iostream>
#include "dynamic_array.h"
// Just this one method is provided for you as an example
// of how DynamicArray can override a method from
// PartiallyFilledArray and still call the method
// that it overrode.

//Basic constructor 
DynamicArray::DynamicArray(int capacity) : PartiallyFilledArray(capacity) {
}

//Constructor that takes an array of integers and its size, and creates a Dynamic Array with all the same elements and an initial capacity of 2x the size of the input array.
DynamicArray::DynamicArray(int integers[], int size) : PartiallyFilledArray(integers, size) {
  this->capacity_ = size * 2;
}

DynamicArray::~DynamicArray() {
}

//A method primarily for internal use; reallocates the array to a new location with twice the capacity
void DynamicArray::Grow() {
  this->capacity_ *= 2;
  int* new_array = new int[this->capacity_];

  for (int i = 0; i < this->size_; i++) {
    new_array[i] = this->contents_[i];
  }

  delete[] this->contents_;
  this->contents_ = new_array;
}

//Takes an int as an input and adds it to the end of the array, using Grow() if the array is full.
void DynamicArray::Append(int new_int) {
  if (this->IsFull()) {
    this->Grow();
    PartiallyFilledArray::Append(new_int);
  }

  // At this point, we know there is enough capacity,
  // so we'll use the *parent* class's version of Append()
  // to complete the work instead of just rewriting basically
  // the same code here.  Code reuse is good!
  else { PartiallyFilledArray::Append(new_int);
  }
}

//Takes as input an int value and an int index. Places given value at given index, using Grow() if the array is full.
void DynamicArray::Insert(int insert_me, int index) {
  if (this->IsFull()) {
    this->Grow();
    this->PartiallyFilledArray::Insert(insert_me, index);
  } 

  else {
  this->PartiallyFilledArray::Insert(insert_me, index);
  }
}

//Takes as input another DynamicArray. Extends the array by appending all elements of a given DynamicArray to it.
void DynamicArray::Extend(DynamicArray& other) {
  for (int i = 0; i < other.size_; i++) {
    this->Append(other.contents_[i]);
  }
}

//Takes as input a start and stop int. Creates a new dynamic array containing the elements between the start and stop indexes.
DynamicArray DynamicArray::Slice(int start, int stop) {
  DynamicArray new_array = DynamicArray(stop - start);
  for (int i = start; i < stop; i++) {
    new_array.Append(this->contents_[i]);
  }

  return new_array;
}

//Empties the contents of the DynamicArray, setting all elements and size to 0.
void DynamicArray::Clear() {
  for (int i = 0; i < this->size_; i++) {
    this->contents_[i] = 0;
  }

  this->size_ = 0;
}

//Tests for the DynamicArray class
void DynamicArray_main() {
  PartiallyFilledArray PFA_test = PartiallyFilledArray(10);
  DynamicArray example_array1 = DynamicArray(4);
  DynamicArray example_array2 = DynamicArray(10);
  
  for (int i = 0; i < 6; i++) {
    example_array1.Append(i);
    PFA_test.Append(i);
  }

  for (int i = 0; i < 26; i += 2){
    example_array2.Append(i);
    }
  example_array1.Print();

  example_array2.Extend(example_array1);
  example_array2.Print();

  DynamicArray new_array = example_array2.Slice(0, 5);
  new_array.Print();

  new_array.Clear();

  new_array.Print();

  std::cout << new_array.PopAt(3);

  int test_array[] = {1, 2, 3, 4, 5};
  int test_size = 5;

  DynamicArray array_to_DA = DynamicArray(test_array, test_size);

  array_to_DA.Print();
  std::cout << array_to_DA.GetCapacity();

}