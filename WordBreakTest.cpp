#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "WordBreak.h"
TEST_CASE("Test Word Break") {
    string s = "bb";
    vector<string> wordList = {"a", "b", "bbb", "bbbb"};
    REQUIRE(wordBreak(s, wordList));
}