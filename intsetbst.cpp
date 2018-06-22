#include "intset.hpp"
InSetBST::IntSetBST(unsigned int max_element, int max_val) : InSet(max_elements, max_val)
{
    struct BSTNode
    {
        int data;
        struct BSTNode*left;
        struct BSTNode*right;
    };
    
}
InSetBST::~InSetBST()
{
    delete[] BSTNode;
}
void InSetBST::insert(int element)
{
    if(root==NULL)
    {
        root = element;
        return root;
    }
    else
    {
        if(root->element > element)
        {
            root->left = insert(root->left, element);
        }
        else if(root->element >element)
        {
            root -> right = insert(root->right, element);
        }
    }
    return root;
}
const void InSetBST::report(int *v)
{
    
}
