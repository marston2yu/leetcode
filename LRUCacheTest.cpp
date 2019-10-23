#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "LRUCache.h"
TEST_CASE("Test LRUCache") {
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    REQUIRE(obj->get(1)==1);
    obj->put(3, 3);
    REQUIRE(obj->get(2)==-1);
    obj->put(4, 4);
    REQUIRE(obj->get(1)==-1);
    REQUIRE(obj->get(3)==3);
    REQUIRE(obj->get(4)==4);
}