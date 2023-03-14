// Author: Brian Law
//
#include <iostream>
#include "partially_filled_array.h"

// Create a new PFA of ints with the specified capacity.
PartiallyFilledArray::PartiallyFilledArray(int capacity) {
  this->contents_ = new int[capacity];
  this->size_ = 0;
  this->capacity_ = capacity;
}

// Create a new PFA of ints containing the given values
// and with capacity twice the size of the given array.
PartiallyFilledArray::PartiallyFilledArray(int input[], int size) {
  this->contents_ = new int[size * 2];
  this->size_ = size;
  this->capacity_ = size * 2;

  // Copy over elements from the array into this PFA
  for (int i=0; i<size; i++) {
    this->contents_[i] = input[i];
  }
}

// Destructor for PFAs deallocates the internal array from the heap.
PartiallyFilledArray::~PartiallyFilledArray() {
  delete[] this->contents_;
}

// Add a new int to this PFA, if there's capacity for it.
void PartiallyFilledArray::Append(int new_int) {
  if (this->size_ < this->capacity_) {
    this->contents_[this->size_] = new_int;
    this->size_++;
  }
}

// Access the int at the specified index in the PFA. Returns -1 if the index is invalid.
int PartiallyFilledArray::Get(int index) {
  if (index >= 0 && index < this->size_) {
    return this->contents_[index];
  }
  else {
    // To be really safe here, we should throw an error or an exception.
    return -1;
  }
}

// Get the size (number of elements) in this PFA.
int PartiallyFilledArray::GetSize() {
  return this->size_;
}

// Get the capacity (max possible number of elements) in this PFA.
int PartiallyFilledArray::GetCapacity() {
  return this->capacity_;
}

// Check to see if the capacity of the PFA has been reached.
bool PartiallyFilledArray::IsFull() {
  return this->GetSize() == this->GetCapacity();
}

// Set the element at the specified index in this PFA to the new value.
// Does nothing if the index is invalid (either < 0 or beyond the size of the PFA).
void PartiallyFilledArray::Set(int index, int new_int) {
  if (index >= 0 && index < this->size_) {
    this->contents_[index] = new_int;
  }
}

// Prints out this PFA.
void PartiallyFilledArray::Print() {
  std::cout << "[ ";
  for (int i=0; i < this->size_; i++) {
    std::cout << this->contents_[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// Check whether find_me exists within this PFA.
bool PartiallyFilledArray::Contains(int find_me) {
  for (int i=0; i < this->size_; i++) {
    if (this->contents_[i] == find_me) {
      return true;
    }
  }
  return false;
}

// Count the number of times count_me occurs in this PFA.
int PartiallyFilledArray::Count(int count_me) {
  int count = 0;
  for (int i=0; i < this->size_; i++) {
    if (this->contents_[i] == count_me) {
      count++;
    }
  }
  return count;
}

// Find the first index of index_me in this PFA. -1 if not found.
int PartiallyFilledArray::Index(int index_me) {
  for (int i=0; i < this->size_; i++) {
    if (this->contents_[i] == index_me) {
      return i;
    }
  }
  return -1;
}

// Remove and return the last element in this PFA.
int PartiallyFilledArray::Pop() {
  this->size_--;
  return this->contents_[this->size_];
}

// Remove and return the element at the specified index in this PFA.
int PartiallyFilledArray::PopAt(int index) {
  int temp = this->contents_[index];
  // shift over values to the right of the removed element
  for (int i=index; i < this->size_ - 1; i++) {
    this->contents_[i] = this->contents_[i + 1];
  }
  this->size_--;
  return temp;
}

// Insert insert_me into this PFA at the specified index,
// pushing the element it's replacing and all subsequent elements
// back 1 positions. Does nothing if PFA is already full.
void PartiallyFilledArray::Insert(int insert_me, int index) {
  if (this->size_ < this->capacity_) {
    for (int i=this->size_-1; i>=index; i--) {
      this->contents_[i + 1] = this->contents_[i];
    }
    this->contents_[index] = insert_me;
    this->size_++;
  }
}

// Remove and return the first occurrence of remove_me from this PFA.
// This implementation will crash if not found, as Index will return
// -1 and all heck will break loose.
void PartiallyFilledArray::Remove(int remove_me) {
  this->PopAt(this->Index(remove_me));
}



void PartiallyFilledArray_main() {
  std::cout << "This is PartiallyFilledArray_main()." << std::endl << std::endl;

  PartiallyFilledArray pfa1 = PartiallyFilledArray(10);

  pfa1.Append(7);
  pfa1.Append(17);
  pfa1.Append(27);
  pfa1.Append(37);
  pfa1.Append(47);
  pfa1.Append(57);

  pfa1.Print();

  std::cout << "Does the PFA contain 7? " << pfa1.Contains(7) << std::endl;
  std::cout << "Does the PFA contain 27? " << pfa1.Contains(27) << std::endl;
  std::cout << "Does the PFA contain 107? " << pfa1.Contains(107) << std::endl << std::endl;

  std::cout << "Is there still room in my PFA? " << (pfa1.GetSize() < pfa1.GetCapacity()) << std::endl;

  pfa1.Append(67);
  pfa1.Append(77);
  pfa1.Append(87);
  pfa1.Append(97);

  std::cout << "Is my PFA full? " << pfa1.IsFull() << std::endl;
  pfa1.Append(107);

  pfa1.Print(); // Expecting 7 17 27 37 47 57 67 77 87 97

  std::cout << "Does the PFA contain 7 now? " << pfa1.Contains(7) << std::endl;
  std::cout << "Does the PFA contain 27 now? " << pfa1.Contains(27) << std::endl;
  std::cout << "Does the PFA contain 107 now? " << pfa1.Contains(107) << std::endl << std::endl;

  // Empty out the PFA and start over.
  while (pfa1.GetSize() > 0) {
    pfa1.Pop();
  }

  pfa1.Append(1);
  pfa1.Append(2);
  pfa1.Append(3);
  pfa1.Append(4);
  pfa1.Append(5);
  pfa1.Append(6);
  pfa1.Print(); // Expecting 1 2 3 4 5 6
  std::cout << std::endl;

  std::cout << "Testing Insert" << std::endl;
  pfa1.Append(10);
  pfa1.Insert(10, 3);
  pfa1.Insert(10, 3);
  pfa1.Insert(10, 3);
  pfa1.Print(); // Expecting 1 2 3 10 10 10 4 5 6 10

  std::cout << "How many times does the PFA contain 1? " << pfa1.Count(1) << std::endl;
  std::cout << "How many times does the PFA contain 10? " << pfa1.Count(10) << std::endl;
  std::cout << "How many times does the PFA contain 100? " << pfa1.Count(100) << std::endl << std::endl;

  int popped = pfa1.Pop();
  std::cout << "Popped a " << popped << " from the PFA" << std::endl;  // Expecting 10
  pfa1.Print(); // Expecting 1 2 3 10 10 10 4 5 6

  popped = pfa1.Pop();
  std::cout << "Popped a " << popped << " from the PFA" << std::endl;  // Expecting 6
  pfa1.Print(); // Expecting 1 2 3 10 10 10 4 5

  popped = pfa1.PopAt(0);
  std::cout << "Popped a " << popped << " from the PFA" << std::endl;  // Expecting 1
  pfa1.Print(); // Expecting 2 3 10 10 10 4 5

  popped = pfa1.PopAt(2);
  std::cout << "Popped a " << popped << " from the PFA" << std::endl;  // Expecting 10
  pfa1.Print(); // Expecting 2 3 10 10 4 5

  popped = pfa1.PopAt(5);
  std::cout << "Popped a " << popped << " from the PFA" << std::endl;  // Expecting 5
  pfa1.Print(); // Expecting 2 3 10 10 4
  std::cout << std::endl;

  pfa1.Remove(2);;
  std::cout << "Removing a 2 gets us... ";
  pfa1.Print(); // Expecting 3 10 10 4

  pfa1.Remove(10);
  std::cout << "Removing a 10 gets us... ";
  pfa1.Print(); // Expecting 3 10 4

  // Over-declared to test constructor.
  int test_array[20] = {-1, -2, -3, -4, -5, -6};
  PartiallyFilledArray pfa2 = PartiallyFilledArray(test_array, 6);
  std::cout << pfa2.GetSize() << std::endl; // Expecting 6
  std::cout << pfa2.GetCapacity() << std::endl; // Expecting 12
  pfa2.Print(); // Expecting -1, -2, -3, -4, -5, -6
}