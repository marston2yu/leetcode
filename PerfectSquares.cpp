//
// Created by Marston Yu on 2019-02-26.
//

#include "PerfectSquares.h"
#include <vector>
#include <cmath>
using namespace std;

int dynamicProgrammingSolution(int n) {
  if (n <= 0) return 0;
  // dynamic programming solution.
  vector<int> table(n); // table
  table[0] = 1; // initial condition: 1 is a perfect square number.
  for (int i = 1; i < n; i++) {
    int num = i + 1; // number equals to index plus 1.
    // if number is a square number, it has 1 perfect square component.
    if (num - round(sqrt(num))*round(sqrt(num))==0) {
      table[i] = 1;
    } else {
      // look up (number - j * j)'s answer 'm' in the table
      // then the answer for number is equal to 'm+1' or smaller than 'm+1'.
      table[i] = num;
      for (int j = 1; num - j*j > 0; j++) {
        table[i] = min(table[i], 1 + table[i - j*j]);
      }
    }
  }
  return table[n - 1];
}