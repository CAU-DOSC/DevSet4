#include "intset.hpp"

IntSetList::IntSetList(unsigned int max_elements, int max_val) : IntSet(max_elements, max_val)
{
  n = 0;
  root_node = new struct node;
  root_node->key_val = -1;
  root_node->next_id = NULL;
}

void IntSetList::deleteAllNodes()
{
 struct node *tmpNode = root_node;

 while(tmpNode)
 {
  struct node *next = tmpNode->next_id;
  delete tmpNode;
  tmpNode = next;
 }
    set_size = 0;
 root_node = NULL;

}

IntSetList::~IntSetList()
{
  deleteAllNodes();
}

void IntSetList::insert(int element)
{
  list_insert(element);
  this->set_size++;
}

void const IntSetList::report(int *v)
{
  int m = 0;
  for (struct node *iter = root_node->next_id; iter; iter = iter->next_id)
    v[m++] = iter->key_val;
}

