#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "ReverseNodesInKGroup.h"
#include "DataStructures.h"
TEST_CASE("Test Reverse Nodes In K Group") {
    vector<int> a{1, 2};
    ListNode *b = vectorToList(a);
    vector<int> c{2, 1};
    ListNode *d = reverseKGroup(b, 2);
    vector<int> e = listToVector(d);
    REQUIRE(c==e);
}