#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "intset.hpp"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

TEST_CASE("Wrong max_elements", "[Exception Test]")
{
    try
    {
        IntSetBins bins(-1, 100);
    }
    catch (const std::exception &e)
    {
        cout << "---- Wrong max_elements Test ----" << endl;
        cout << e.what() << endl;
        REQUIRE(true);
        return;
    }
    REQUIRE(false);
}

TEST_CASE("INTSETBITVECTOR TEST", "[bitvector]")
{

    cout << "-------------bitVec test------------" << endl;
    int bv_maxEle = 15;
    int bv_maxVal = 30;
    IntSetBitVec bv(bv_maxEle, bv_maxVal);

    bv.insert(-1);
    bv.insert(0);
    bv.insert(1);
    bv.insert(bv_maxVal/2);
    bv.insert(bv_maxVal/3);
    bv.insert(bv_maxVal-1);
    bv.insert(bv_maxVal);
    bv.insert(bv_maxVal+1);
    bv.insert(bv_maxVal+2);

    cout << "bitvector size : " << bv.size() << endl;

    REQUIRE(bv.size() == 6);

    SECTION("report"){
        cout << "bitvec report" << endl;
        int* v = new int[bv_maxEle]();
        bv.report(v);
        for(int i = 0; i < (int)bv.size(); i++)
        {
            cout << v[i] << endl;
        }
        REQUIRE(v[0] == 0);
        REQUIRE(v[5] == bv_maxVal);

        delete[] v;
    }

    SECTION("remove"){
        cout << "after remove" << endl;
        
        bv.remove(-1);
        bv.remove(0);
        bv.remove(30);
        bv.remove(29);
        
        int* v = new int[bv_maxEle]();
        bv.report(v);
        for(int i = 0; i < (int)bv.size(); i++)
        {
            cout << v[i] << endl;
        }
        
        cout << "bitvector size : " << bv.size() << endl;
        
        REQUIRE(bv.size() == 3);

        delete[] v;
    }

    SECTION("contains"){
        cout << "bitVec contains.." << endl;
        for (int i = 0; i < bv_maxVal; i++)
        {
            if(bv.contains(i))
            {
                cout << i << endl;
            }
        }
    }

}

TEST_CASE("HASH TEST", "[HASH TEST]")
{
    int *arr = new int[50];
    for (int i = 0; i < 50; i++)
    {
        arr[i] = IntSetBins::getKey(100);
    }
    bool flag = true;
    for (int i = 1; i < 50; i++)
    {
        if (arr[0] != arr[i])
        {
            flag = false;
            break;
        }
    }
    delete[] arr;
    REQUIRE(flag);
}

TEST_CASE("INTSETBINS SMOKE TEST", "[SMOKE TEST]")
{
    IntSetBins bins(30, 30);
    bins.insert(100);
    bins.insert(100);
    for (int i = 1; i < 31; i++)
    {
        bins.insert(i);
    }
    int *v = new int[30];
    bins.report(v);
    cout << "---- BINS REPORT 1~30 ----" << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << v[i] << endl;
    }
    delete[] v;
    REQUIRE(bins.size() == 30);
}

TEST_CASE("INTSETARR SMOKE TEST", "[setarr]")
{
    IntSetArr arr(30, 30);
    arr.insert(-1);
    arr.insert(100);
    for (int i = 0; i < 30; i++)
    {
      arr.insert(i+1);
    }
    int *v = new int[30];
    arr.report(v);
    cout << "------bitarr test------" << endl;
    for (int i = 0; i < 30; i++){
      cout << v[i] << endl;
    }
    delete[] v;
    REQUIRE(arr.size() == 30);
}

TEST_CASE("INTSETLIST SMOKE TEST", "[setlist]")
{
    IntSetList list(30,30);
    list.insert(1);
    list.insert(100);
    for (int i = 1; i < 31; i++){
        list.insert(i+1);
    }
    int *v = new int[30];
    list.report(v);
    cout << "------bitlist test------"<<endl;
    for(int i = 0; i<30; i++){
        cout << v[i] << endl;
    }
    delete[] v;
    REQUIRE(list.size() == 30);
}

TEST_CASE("INTSETBST SMOKE TEST", "[intsetbst]") 
{
    IntSetBins bins(30, 30);
    bins.insert(100);
    bins.insert(100);
    for (int i = 1; i < 31; i++)
    {
        bins.insert(i);
    }
    int *v = new int[30];
    bins.report(v);
    cout << "---- BST REPORT 1~30 ----" << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << v[i] << endl;
    }
    delete[] v;
    REQUIRE(bins.size() == 30);
}

inline void performance(IntSet *set, int *data, int size)
{
    for (int i = 0; i < size; i++) 
    {
        set->insert(data[i]);
    }
    cout << "Size of Set: " << set->size() << endl;
}

TEST_CASE("PERFORMANCE TEST", "[all sets]")
{
    // 10^6
    const int size = 1000000;
    const int max_size = 2147483647;
    int* data = new int[size];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, max_size);

    for (int i = 0; i < size; i++) 
    {
        data[i] = dis(gen);
    }

    int start;
    double times[5];

    cout << "---- PERFORMANCE TEST ----" << endl;

    IntSet *set = new IntSetArr(size, max_size);
    start = clock();
    performance(set, data, size);
    times[0] = clock() - start;
    delete set;

    set = new IntSetBins(size, max_size);
    start = clock();
    performance(set, data, size);
    times[1] = clock() - start;
    delete set;

    set = new IntSetBitVec(size, max_size);
    start = clock();
    performance(set, data, size);
    times[2] = clock() - start;
    delete set;

    set = new IntSetBST(size, max_size);
    start = clock();
    performance(set, data, size);
    times[3] = clock() - start;
    delete set;

    /*
    set = new IntSetList(size, max_size);
    start = clock();
    performance(set, data, size);
    times[4] = clock() - start;
    delete set;
    */

    for (int i = 0; i < 4; i++) 
    {
        times[i] = (times[i] / CLOCKS_PER_SEC) * 1000;
    }

    cout << "IntSetArr: " << times[0] << endl;
    cout << "IntSetBins: " << times[1] << endl;
    cout << "IntSetBitVec: " << times[2] << endl;
    cout << "IntSetBst: " << times[3] << endl;
    //cout << "IntSetList: " << times[4] << endl;
}
