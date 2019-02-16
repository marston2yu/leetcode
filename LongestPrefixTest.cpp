//
// Created by Marston Yu on 2019-02-16.
//
//
// Created by Marston Yu on 2019-02-07.
//

#define CATCH_CONFIG_MAIN
#include <string>
#include <vector>
#include <catch2/catch.hpp>
#include "LongestPrefix.h"
#include "DataStructures.h"
using namespace std;

TEST_CASE("Test longest common prefix function") {
  vector<string> v1 = {"flower", "flow", "flight"};
  vector<string> v2 = {"dog", "racecar", "car"};
  vector<string> v3 = {"c", "c"};
  vector<string> v4 = {"a", "a", "b"};
  REQUIRE(longestCommonPrefix(v1)=="fl");
  REQUIRE(longestCommonPrefix(v2)=="");
  REQUIRE(longestCommonPrefix(v3)=="c");
  REQUIRE(longestCommonPrefix(v4)=="");
}

TEST_CASE("Test Trie class") {
  Trie t1;
  REQUIRE(!t1.contain(""));
  t1.insert("hello");
  REQUIRE(t1.contain("hello"));
  REQUIRE(!t1.contain("hel"));
  REQUIRE(!t1.contain("hello1"));
  t1.insert("hel");
  REQUIRE(t1.contain("hel"));

  vector<string> v1 = {"flower", "flow", "flight"};
  Trie t2(v1);
  REQUIRE(t2.longestPrefix("flo") == "fl");
  REQUIRE(t2.longestPrefix("mul") == "");
  REQUIRE(t2.longestPrefix("f") == "f");
  REQUIRE(t2.longestPrefix("fl") == "fl");

}

