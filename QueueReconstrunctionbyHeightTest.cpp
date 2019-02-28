//
// Created by marston on 2019/2/27.
//
#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "QueueReconstructionbyHeight.h"

TEST_CASE("Test Queue Reconstruction by Height algorithm.") {
  using element = pair<int, int>;
  vector<element> v{make_pair(2, 4), make_pair(3, 4), make_pair(9, 0),
                    make_pair(0, 6), make_pair(7, 1), make_pair(6, 0),
                    make_pair(7, 3), make_pair(2, 5), make_pair(1, 1), make_pair(8, 0)};
  vector<element> vr{make_pair(6, 0), make_pair(1, 1), make_pair(8, 0),
                     make_pair(7, 1), make_pair(9, 0), make_pair(2, 4), make_pair(0, 6),
                     make_pair(2, 5), make_pair(3, 4), make_pair(7, 3)};
  REQUIRE(reconstructQueue(v) == vr);
  element p1(7, 0);
  element p2(4, 4);
  element p3(7, 1);
  element p4(5, 0);
  element p5(6, 1);
  element p6(5, 2);
  vector<element> p{p1, p2, p3, p4, p5, p6};
  vector<element> r{p4, p1, p6, p5, p2, p3};
  REQUIRE(reconstructQueue(p) == r);
}