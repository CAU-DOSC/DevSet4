#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "intset.hpp"
#include <iostream>

using namespace std;

TEST_CASE("TEST", "[TEST]") {
    IntSetBST bst(30, 30);
    cout << "Size of bst: " << bst.size() << endl;
    REQUIRE(bst.size() == 0);
}
