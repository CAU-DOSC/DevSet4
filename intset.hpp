#ifndef __INTSET_HPP__
#define __INTSET_HPP__

#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct node
{
  int key_val;
  struct node *next_id;
};

struct bstNode
{
  int val;
  struct bstNode *left;
  struct bstNode *right;
};

unsigned int MurmurHash2(const void *key, int len, unsigned int seed);

class IntSet
{
protected:
  static const unsigned int MASK = 0x80000000;
  unsigned int set_size;
  const unsigned int max_elements;
  const int max_val;

public:
  virtual void insert(int element) = 0;
  virtual const void report(int *v) = 0;
  const unsigned int size()
  {
    return set_size;
  }
  IntSet(unsigned int _max_elements, int _max_val) : set_size(0),
                                                     max_elements(_max_elements),
                                                     max_val(_max_val)
  {
    /* Check max_elements */
    if ((_max_elements & MASK) == MASK)
    {
      throw invalid_argument("Max elements must be bigger than 0");
    }
  }
  virtual ~IntSet() {}
};

class IntSetArr : public IntSet
{
private:
  bool *arr;

public:
  IntSetArr(unsigned int max_elements, int max_val);
  ~IntSetArr();
  void insert(int element);
  void const report(int *v);
};

class IntSetList : public IntSet
{
private:
  struct node *root_node;
  void deleteAllNodes();
  void list_insert(int elements);

public:
  IntSetList(unsigned int max_elements, int max_val);
  ~IntSetList();
  void insert(int element);

  void const report(int *v);
};

class IntSetBST : public IntSet
{
private:
  struct bstNode *root_node = nullptr;
  vector<struct bstNode *> node_vector;
  inline void setBstNode(int element, struct bstNode *node)
  {
    node->val = element;
    node->left = nullptr;
    node->right = nullptr;
  }

public:
  IntSetBST(unsigned int max_elements, int max_val);
  ~IntSetBST();
  void insert(int element);
  void const report(int *v);
};

class IntSetBitVec : public IntSet
{
private:
  char *bits;

public:
  IntSetBitVec(unsigned int max_elements, int max_val);
  ~IntSetBitVec();
  void insert(int element);
  void remove(int element);
  int contains(int element);
  void const report(int *v);
};

class IntSetBins : public IntSet
{
private:
  map<int, vector<int> *> bucket;

public:
  static inline unsigned int getKey(int element)
  {
    return MurmurHash2(&element, 1, 0xfffffff);
  }
  IntSetBins(unsigned int max_elements, int max_val);
  ~IntSetBins();
  void insert(int element);
  void const report(int *v);
};
#endif
