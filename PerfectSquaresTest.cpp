//
// Created by Marston Yu on 2019-02-26.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "PerfectSquares.h"

TEST_CASE("Test dynamic programming solution.") {
  REQUIRE(dynamicProgrammingSolution(6665)==3);
  REQUIRE(dynamicProgrammingSolution(1)==1);
  REQUIRE(dynamicProgrammingSolution(2)==2);
  REQUIRE(dynamicProgrammingSolution(12)==3);
  REQUIRE(dynamicProgrammingSolution(13)==2);
}

TEST_CASE("Test mathematical approach.") {
  REQUIRE(mathematicalApproach(6665)==3);
  REQUIRE(mathematicalApproach(1)==1);
  REQUIRE(mathematicalApproach(2)==2);
  REQUIRE(mathematicalApproach(12)==3);
  REQUIRE(mathematicalApproach(13)==2);
}