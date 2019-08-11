#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "StoneGame.h"

TEST_CASE("Test stone game.") {
  vector<int> m{5, 3, 4, 5};
  REQUIRE(stoneGame(m));
}