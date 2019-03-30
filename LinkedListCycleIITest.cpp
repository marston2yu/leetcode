//
// Created by marston on 2019/3/1.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "LinkedListCycleII.h"

TEST_CASE("Test brent algorithm.") {
  ListNode head = ListNode(3);
  ListNode two = ListNode(2);
  ListNode three = ListNode(0);
  ListNode four = ListNode(-4);
  head.next = &two;
  two.next = &three;
  three.next = &four;
  four.next = &two;
  REQUIRE(brentAlgorithm(&head) == &two);
}