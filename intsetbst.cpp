#include "intset.hpp"

IntSetBST::IntSetBST(unsigned int max_elements, int max_val) : IntSet(max_elements, max_val)
{
}

IntSetBST::~IntSetBST()
{
    if (this->set_size == 0)
    {
        return;
    }

    for (unsigned int i = 0; i < node_vector.size(); i++)
    {
        delete node_vector[i];
    }

    delete this->root_node;
}

void IntSetBST::insert(int element)
{
    if (element > this->max_val || this->set_size >= this->max_elements)
    {
        return;
    }

    if (this->root_node == nullptr)
    {
        this->root_node = new struct bstNode;
        setBstNode(element, this->root_node);
        this->set_size++;
    }
    else
    {
        struct bstNode *iter = this->root_node;
        while (iter)
        {
            if (element > iter->val)
            {
                if (iter->right == nullptr)
                {
                    iter->right = new struct bstNode;
                    iter = iter->right;
                    break;
                }
                else
                {
                    iter = iter->right;
                    continue;
                }
            }
            else if (element < iter->val)
            {
                if (iter->left == nullptr)
                {
                    iter->left = new struct bstNode;
                    iter = iter->left;
                    break;
                }
                else
                {
                    iter = iter->left;
                    continue;
                }
            }
            else
            {
                return;
            }
        }

        setBstNode(element, iter);
        node_vector.push_back(iter);
        this->set_size++;
    }
}

const void IntSetBST::report(int *v)
{
    if (this->set_size == 0)
    {
        return;
    }

    vector<int> result;
    result.push_back(root_node->val);
    for (unsigned int i = 0; i < node_vector.size(); i++)
    {
        result.push_back(node_vector[i]->val);
    }

    sort(result.begin(), result.end());

    for (unsigned int i = 0; i < node_vector.size(); i++)
    {
        v[i] = result[i];
    }
}
