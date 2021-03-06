#include "intset.hpp"
#include <stdlib.h>

IntSetBitVec::IntSetBitVec(unsigned int max_elements, int max_val) : IntSet(max_elements, max_val)
{
    // calloc for making bits to 0000...
    this->bits = new char[((int)(max_val / 8) + 1) * sizeof(char)]();
}

IntSetBitVec::~IntSetBitVec()
{
    delete[] bits;
}

void IntSetBitVec::insert(int element)
{
    if (element < 0 || element > max_val || set_size >= max_elements)
        return;

    // if there is no "element" in bitVec
    if (bits[element / 8] == (bits[element / 8] & ~(1 << (element % 8))))
    {
        // increase size
        this->set_size += 1;

        // set "element"
        bits[element / 8] = bits[element / 8] | (1 << (element % 8));
    }
}

void IntSetBitVec::remove(int element)
{
    // "element" range check
    if (element < 0 || element > max_val || set_size <= 0)
        return;

    // if there is "element" in bitVec
    if (bits[element / 8] == (bits[element / 8] | (1 << (element % 8))))
    {
        // decrease size
        this->set_size -= 1;

        // remove "element"
        // make bit to 0
        bits[element / 8] = bits[element / 8] & ~(1 << (element % 8));
    }
}

int IntSetBitVec::contains(int element)
{
    // "element" range check
    if (element < 0 || element > max_val)
        return 0;

    // if there is "element" in bitVec
    if (bits[element / 8] == (bits[element / 8] | (1 << (element % 8))))
    {
        return 1;
    }
    // if there is not...
    else
    {
        return 0;
    }
}

void const IntSetBitVec::report(int *v)
{
    int index = 0;
    for (int i = 0; i <= max_val; i++)
    {

        // if the i-th bit == 1
        if ((bits[i / 8] & (1 << (i % 8))))
        {

            // there is number "i" in the bitVec
            v[index] = i;
            index++;
        }
    }
}
