#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "ValidStackSequences.h"

TEST_CASE("Test Valid Stack Sequences") {
  vector<int> pushed{1, 2, 3, 4, 5};
  vector<int> popped{4, 5, 3, 2, 1};
  REQUIRE(validateStackSequences(pushed, popped));
}