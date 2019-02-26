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

int mathematicalApproach(int n) {
  if (n <= 0) return 0;
  // according to Lagrange's Four Square theorem, the answer must be smaller than or equal to 4.

  if (n - round(sqrt(n))*round(sqrt(n))==0) {
    return 1;
  }

  // Legendre's three-square theorem: n has 4 perfect square components
  // only when n can be written as 4^k*(8*m+7)
  while ((n & 3)==0)
    n >>= 2;
  if (n%8==7)
    return 4;

  // check if the answer is 2.
  for (int i = 1; i*i < n; i++) {
    int num = n - i*i;
    if (num - round(sqrt(num))*round(sqrt(num))==0) {
      return 2;
    }
  }

  return 3;
}