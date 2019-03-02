# leetcode
My solution to leetcode problems.

## Prerequisites
* [Catch2](https://github.com/catchorg/Catch2) Unit test library for testing algorithms. Cmake-install method should be used. (v2.6.0)

  [Cmake-integration](https://github.com/catchorg/Catch2/blob/master/docs/cmake-integration.md) should be found here.
  
## List of problems solved

| No.  | Problem               | Source files          | Notes |
| :--: | --------------------- | --------------------- | ----- |
|3|Longest Substring Without Repeating Characters|LongestSubstringWithoutRepeating.h<br />LongestSubstringWithoutRepeating.cpp<br />LongestSubstringWithoutRepeatingTest.cpp||
|5|Longest Palindromic Substring|LongestPalindromicSubstring.h<br />LongestPalindromicSubstring.cpp<br />LongestPalindromicSubstringTest.cpp|Implement a dynamic programming solution and Manacher's algorithm. The later's visualized explanations are [here](https://tarokuriyama.com/projects/palindrome2.php) and [here](http://manacher-viz.s3-website-us-east-1.amazonaws.com/#/). There is also [a chinese explanation](https://www.felix021.com/blog/read.php?2040).|
| 14   | Longest Common Prefix | LongestCommonPrefix.h<br/>LongestCommonPrefix.cpp<br/>DataStructures/Trie.h<br/>DataStructures/Trie.cpp<br/>LongestCommonPrefixTest.cpp | Further problem: find a longest common prefix between a string and a collection of string. |
|279|Perfect Squares|PerfectSquares.h<br/>PerfectSquares.cpp<br/>PerfectSquaresTest.cpp|DP solution and solution based on mathematical theorems.|
|406|Queue Reconstruction by Height|QueueReconstructionbyHeight.h<br/>QueueReconstructionbyHeight.cpp<br/>QueueReconstructionbyHeightTest.cpp||
|142|Linked List Cycle II|LinkedListCycleII.h<br/>LinkedListCycleII.cpp|[Floyd's algorithm](https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare).<br/>[Brent's algorithm](http://www.siafoo.net/algorithm/11).|

