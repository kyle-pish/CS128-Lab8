
// Just this one method is provided for you as an example
// of how DynamicArray can override a method from
// PartiallyFilledArray and still call the method
// that it overrode.
void DynamicArray::Append(int new_int) {
  if (this->IsFull()) {
    // If we're full, we need to grow the capacity
    this->Grow();
  }

  // At this point, we know there is enough capacity,
  // so we'll use the *parent* class's version of Append()
  // to complete the work instead of just rewriting basically
  // the same code here.  Code reuse is good!
  PartiallyFilledArray::Append(new_int);
}