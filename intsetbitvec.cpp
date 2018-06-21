#include "intset.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using std::cout;
using std::endl;

IntSetBitVec::IntSetBitVec(int max_elements, int max_val) : IntSet(max_elements, max_val)
{
	if(max_elements < 0 || max_val < 0) return;

	// calloc for making bits to 0000...
	this->bits = (char*)calloc((int)(max_val/8)+1,sizeof(char));
}

IntSetBitVec::~IntSetBitVec()
{
	free(this->bits);
}

void IntSetBitVec::insert(int element)
{
	if(element < 0 || element > max_val) return;

	// if there is no "element" in bitVec
	if(bits[element/8] == (bits[element/8] & ~(1 << element % 8)))
	{
		// increase size
		this->set_size += 1;
		
		// set "element"
		bits[element/8] = bits[element/8] | ( 1 << (element % 8));
	}
}

void const IntSetBitVec::report(int *v)
{
	int index = 0;
	for(int i = 0; i <= max_val; i++){
		
		// if the i-th bit == 1
		if((bits[i/8] & (1 << (i % 8)))){

			// there is number "i" in the bitVec
			v[index] = i;
			index++;
		}
	}

}

