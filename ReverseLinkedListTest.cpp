#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "ReverseLinkedList.h"
#include <vector>

using namespace std;

TEST_CASE("test reverse linked list") {
  vector<int> v{1, 2, 3, 4, 5};
  ListNode *origin = vectorToList(v);
  ListNode *reversed = reverseBetween(origin, 1, 4);
  vector<int> rv = listToVector(reversed);
  vector<int> u{4, 3, 2, 1, 5};

  ListNode *origin2 = vectorToList(v);
  ListNode *reversed2 = reverseBetweenIterative(origin2, 2, 4);
  vector<int> rv2 = listToVector(reversed2);
  vector<int> u2{1, 4, 3, 2, 5};
  REQUIRE(rv == u);
  REQUIRE(rv2 == u2);
}
