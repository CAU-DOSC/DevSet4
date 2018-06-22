#include "intset.hpp"

IntSetArr::IntSetArr(unsigned int max_elements, int max_val) : IntSet(max_elements, max_val)
{
  this->arr = new bool[max_elements];
  for (int i = 0; i < max_val+1; i++){
    this->arr[i] = 0;
  }
}

IntSetArr::~IntSetArr()
{
  delete[] arr;
}

void IntSetArr::insert(int element)
{
  if (!arr[element]){
    arr[element] = true;
    this->set_size++;
  }
}

void const IntSetArr::report(int *v)
{
  int j = 0;
  for (int i = 0; i < max_val+1; i++){
    if (arr[i]){
      v[j++] = i;
    }
  }
}
