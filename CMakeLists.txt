cmake_minimum_required(VERSION 2.6)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

#add_executable(leetcode main.cpp)
include_directories(${PROJECT_SOURCE_DIR})

# add PrintLibrary and link it to the longest_prifix executable.
#include_directories(${PROJECT_SOURCE_DIR}/PrintLibrary)
#add_subdirectory(PrintLibrary)
#set(EXTRA_LIBS ${EXTRA_LIBS} PrintLibrary)

# add DataStructures as a library
include_directories(${PROJECT_SOURCE_DIR}/DataStructures)
add_subdirectory(DataStructures)
set(EXTRA_LIBS ${EXTRA_LIBS} DataStructures)

# test longest prefix function.
find_package(Catch2 REQUIRED)
add_executable(LongestPrefixTest LongestPrefixTest.cpp LongestPrefix.cpp)
target_link_libraries(LongestPrefixTest Catch2::Catch2 ${EXTRA_LIBS})

include(CTest)
include(Catch)
catch_discover_tests(LongestPrefixTest)

# test longest substring without repeating.
add_executable(LongestSubstringWithoutRepeatingTest LongestSubstringWithoutRepeatingTest.cpp
        LongestSubstringWithoutRepeating.cpp)
target_link_libraries(LongestSubstringWithoutRepeatingTest Catch2::Catch2)
catch_discover_tests(LongestSubstringWithoutRepeatingTest)

# test longest palindromic substring.
add_executable(LongestPalindromicSubstringTest LongestPalindromicSubstringTest.cpp
        LongestPalindromicSubstring.cpp)
target_link_libraries(LongestPalindromicSubstringTest Catch2::Catch2)
catch_discover_tests(LongestPalindromicSubstringTest)

# test perfect squares.
add_executable(PerfectSquaresTest PerfectSquaresTest.cpp
        PerfectSquares.cpp)
target_link_libraries(PerfectSquaresTest Catch2::Catch2)
catch_discover_tests(PerfectSquaresTest)

# test queue reconstrunction by height.
add_executable(QueueReconstructionbyHeightTest QueueReconstructionbyHeightTest.cpp
        QueueReconstructionbyHeight.cpp)
target_link_libraries(QueueReconstructionbyHeightTest Catch2::Catch2)
catch_discover_tests(QueueReconstructionbyHeightTest)

# test linked list cycle II.
add_executable(LinkedListCycleIITest LinkedListCycleIITest.cpp
        LinkedListCycleII.cpp)
target_link_libraries(LinkedListCycleIITest Catch2::Catch2)
catch_discover_tests(LinkedListCycleIITest)

# test edit distance algorithm.
add_executable(EditDistanceTest EditDistanceTest.cpp
        EditDistance.cpp)
target_link_libraries(EditDistanceTest Catch2::Catch2)
catch_discover_tests(EditDistanceTest)

# test unique paths II algorithm.
add_executable(UniquePathsIITest UniquePathsIITest.cpp
        UniquePathsII.cpp)
target_link_libraries(UniquePathsIITest Catch2::Catch2)
catch_discover_tests(UniquePathsIITest)

# test merge intervals algorithm.
add_executable(MergeIntervalsTest MergeIntervalsTest.cpp
        MergeIntervals.cpp)
target_link_libraries(MergeIntervalsTest Catch2::Catch2)
catch_discover_tests(MergeIntervalsTest)

# test distinct subsequences algorithm.
add_executable(DistinctSubsequencesTest DistinctSubsequencesTest.cpp
        DistinctSubsequences.cpp)
target_link_libraries(DistinctSubsequencesTest Catch2::Catch2)
catch_discover_tests(DistinctSubsequencesTest)

# test median of two sorted arrays algorithm.
add_executable(MedianOfTwoSortedArraysTest MedianOfTwoSortedArraysTest.cpp
        MedianOfTwoSortedArrays.cpp)
target_link_libraries(MedianOfTwoSortedArraysTest Catch2::Catch2)
catch_discover_tests(MedianOfTwoSortedArraysTest)

# test largest rectangle in histogram solution.
add_executable(LargestRectangleInHistogramTest LargestRectangleInHistogramTest.cpp
        LargestRectangleInHistogram.cpp)
target_link_libraries(LargestRectangleInHistogramTest Catch2::Catch2)
catch_discover_tests(LargestRectangleInHistogramTest)

# test stone game solution.
add_executable(StoneGameTest StoneGameTest.cpp
        StoneGame.cpp)
target_link_libraries(StoneGameTest Catch2::Catch2)
catch_discover_tests(StoneGameTest)