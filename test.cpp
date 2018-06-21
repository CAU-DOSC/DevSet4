#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "intset.hpp"
#include <iostream>

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

TEST_CASE("TEST", "[TEST]")
{
    IntSetBST bst(30, 30);
    cout << "Size of bst: " << bst.size() << endl;
    REQUIRE(bst.size() == 0);
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
