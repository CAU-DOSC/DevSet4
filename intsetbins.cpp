#include "intset.hpp"

IntSetBins::IntSetBins(unsigned int max_elements, int max_val) : IntSet(max_elements, max_val)
{
}

IntSetBins::~IntSetBins()
{
    for (auto iter = bucket.begin(); iter != bucket.end(); iter++)
        delete iter->second;
}

void IntSetBins::insert(int element)
{
    if (this->set_size == this->max_elements || element > this->max_val)
    {
        return;
    }

    unsigned int key = getKey(element);

    /* Key not exist */
    if (bucket.find(key) == bucket.end())
    {
        vector<int> *bin = new vector<int>();
        bin->push_back(element);
        bucket[key] = bin;
        set_size++;
    }
    else
    {
        auto bin = bucket[key];
        if (find(bin->begin(), bin->end(), element) != bin->end())
        {
            return;
        }
        bucket[key]->push_back(element);
        set_size++;
    }
}

void const IntSetBins::report(int *v)
{
    vector<int> result;
    for (auto iter = bucket.begin(); iter != bucket.end(); iter++)
    {
        auto bin = iter->second;
        for (auto value = bin->begin(); value != bin->end(); value++)
        {
            result.push_back(*value);
        }
    }
    sort(result.begin(), result.end());
    for (unsigned int i = 0; i < result.size(); i++)
    {
        v[i] = result[i];
    }
}
