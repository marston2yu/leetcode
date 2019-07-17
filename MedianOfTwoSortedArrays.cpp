
#include "MedianOfTwoSortedArrays.h"

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int m = nums1.size();
  int n = nums2.size();
  int im = 0; // index of median, counting from 0.
  bool odd = (m + n) % 2;
  if (odd) {
    im = (m + n) / 2;
  } else {
    im = (m + n - 1) / 2; // smaller one of the two median.
  }

  // one of the array is empty.
  if (!m) return odd ? nums2[im] : (nums2[im] + nums2[im + 1]) / 2.0;
  if (!n) return odd ? nums1[im] : (nums1[im] + nums1[im + 1]) / 2.0;

  int count = 0;
  int pre = max(nums1.back(), nums2.back());
  double median = odd ? max(nums1.back(), nums2.back()) : (nums1.back() + nums2.back()) / 2.0;
  // pop largest of the two array until median is found. i.e. until half of total number is popped.
  while (count++ <= im + (int) !odd) { // one more iteration for odd number to find the smaller of two median number
    if (nums1.empty()) {
      median = odd ? nums2.back() : (pre + nums2.back()) / 2.0;
      pre = nums2.back();
      nums2.pop_back();
    } else if (nums2.empty()) {
      median = odd ? nums1.back() : (pre + nums1.back()) / 2.0;
      pre = nums1.back();
      nums1.pop_back();
    } else if (nums1.back() < nums2.back()) {
      median = odd ? nums2.back() : (pre + nums2.back()) / 2.0;
      pre = nums2.back();
      nums2.pop_back();
    } else {
      median = odd ? nums1.back() : (pre + nums1.back()) / 2.0;
      pre = nums1.back();
      nums1.pop_back();
    }
  }
  return median;
}