#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "intset.hpp"
#include <iostream>

using namespace std;

TEST_CASE("TEST", "[TEST]")
{
    IntSetBST bst(30, 30);
    cout << "Size of bst: " << bst.size() << endl;
    REQUIRE(bst.size() == 0);
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
    REQUIRE(bins.size() == 30);
}
