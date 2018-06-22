#include "intset.hpp"
IntSetBST::IntSetBST(unsigned int max_element, int max_val) : IntSet(max_elements, max_val)
{
    typedef struct Node
    {
        int data;
        struct Node*left;
        struct Node*right;
    } Node;
    
}
IntSetBST::~IntSetBST()
{
    delete[] BSTNode;
}
void IntSetBST::insert(Node * parent, int element)
{
    if(parent -> data < data)
    {
        if(parent-> left == nullptr)
            parent->left = new Node({ data, nullptr, nullptr});
        else
            insert(parent->left, data);
    }
    else
    {
        if(parent -> right == nullptr)
            parent->right = new Node({ data, nullptr, nullptr});
        
        else
            insert(parent->right, data);
    }
}
const void IntSetBST::report(int *v)
{
    
}
