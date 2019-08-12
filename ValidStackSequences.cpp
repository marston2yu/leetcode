#include "ValidStackSequences.h"
#include <stack>

bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
  // Greedy solver.
  stack<int> s;
  int j = 0;
  for (int i : pushed) {
    s.push(i);
    while (!s.empty() && s.top() == popped[j]) {
      s.pop();
      j++;
    }
  }

  return s.empty();
}