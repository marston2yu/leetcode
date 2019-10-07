#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "FindTheShortestSuperstring.h"
TEST_CASE("Test Find The Shortest Superstring") {
  vector<string> A{"alex","loves","leetcode"};
  vector<string> B{"catg","ctaagt","gcta","ttca","atgcatc"};
  REQUIRE(shortestSuperstring(B) == "gctaagttcatgcatc");
  REQUIRE(shortestSuperstring(A) == "leetcodelovesalex");
}