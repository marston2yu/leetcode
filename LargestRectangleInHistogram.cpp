#include "LargestRectangleInHistogram.h"

int largestRectangleArea(vector<int> &heights) {
  if (heights.empty()) return 0;
  vector<int> s;
  int area = 0;
  heights.push_back(0); // tail 0 will clear the stack in below loop.
  for (int i = 0; i < heights.size(); ++i) {
    while (!s.empty() && heights[s.back()] > heights[i]) {
      // When a shorter element is found, rectangle can not extend itself along the right direction.
      // So we pop the height and calculate the rectangle area with the height.
      int height = heights[s.back()];
      // Empty stack means there is no shorter one before that, so the width will be i.
      // Otherwise left limit will be the index of smaller element before current element.
      s.pop_back();
      int width = (s.empty() ? i : i - s.back() - 1);
      area = max(area, height*width);
    }
    s.push_back(i);
  }
  return area;
}
