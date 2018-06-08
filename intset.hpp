#ifndef __INTSET_HPP__
#define __INTSET_HPP__
class IntSet
{
  protected:
    unsigned int set_size;
    const int max_elements;
    const int max_val;

  public:
    virtual void insert(int element) = 0;
    virtual const void report(int *v) = 0;
    const unsigned int size()
    {
        return set_size;
    }
    IntSet(int _max_elements, int _max_val) : set_size(0),
                                              max_elements(_max_elements),
                                              max_val(_max_val) {}
    virtual ~IntSet() {}
};

class IntSetArr : public IntSet
{
  private:
  public:
    IntSetArr(int max_elements, int max_val);
    ~IntSetArr();
    void insert(int element);
    void const report(int *v);
};

class IntSetList : public IntSet
{
  private:
  public:
    IntSetList(int max_elements, int max_val);
    ~IntSetList();
    void insert(int element);
    void const report(int *v);
};

class IntSetBST : public IntSet
{
  private:
  public:
    IntSetBST(int max_elements, int max_val);
    ~IntSetBST();
    void insert(int element);
    void const report(int *v);
};

class IntSetBitVec : public IntSet
{
  private:
  public:
    IntSetBitVec(int max_elements, int max_val);
    ~IntSetBitVec();
    void insert(int element);
    void const report(int *v);
};

class IntSetBins : public IntSet
{
  private:
  public:
    IntSetBins(int max_elements, int max_val);
    ~IntSetBins();
    void insert(int element);
    void const report(int *v);
};
#endif