#include "intset.hpp"

IntSetArr::IntSetArr(unsigned int max_elements, int max_val) : IntSet(max_elements, max_val)
{
    this->arr = new bool[max_val]();
}

IntSetArr::~IntSetArr()
{
    delete[] arr;
}

void IntSetArr::insert(int element)
{
    if (element < 0 || element > this->max_val || this->set_size >= this->max_elements)
        return;

    if (!arr[element])
    {
        arr[element] = true;
        this->set_size++;
    }
}

void const IntSetArr::report(int *v)
{
    int j = 0;
    for (int i = 0; i < this->max_val; i++)
    {
        if (arr[i])
        {
            v[j++] = i;
        }
    }
}
