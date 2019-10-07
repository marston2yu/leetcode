#include <cmath>
#include "FindTheShortestSuperstring.h"
string shortestSuperstring(vector<string> &A) {
    int n = A.size();
    vector<vector<int>> overlap(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int len = min(A[i].length(), A[j].length());
            for (int k = len; k > 0; k--) {
                if (A[i].substr(A[i].length() - k, k)==A[j].substr(0, k)) {
                    overlap[i][j] = k;
                    break;
                }
            }
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1)); // Path of overlapping string.
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int bit = 0; bit < n; bit++) {
            if (!(mask & (1 << bit))) continue;
            int pmask = mask ^(1 << bit);  // pmask specifies the subset S-{bit}.
            if (pmask==0) continue; // Ignore subset S with one item.
            for (int i = 0; i < n; i++) {
                if (!(pmask & (1 << i))) continue;
                int val = dp[pmask][i] + overlap[i][bit];
                if (dp[mask][bit] < val) {
                    parent[mask][bit] = i;
                    dp[mask][bit] = val;
                }
            }

        }
    }

    // Find the end string index. Super string end with that one should have a max overlapping length.
    int end_index = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[(1 << n) - 1][i] > dp[(1 << n) - 1][end_index]) {
            end_index = i;
        }
    }

    vector<int> perm; // occurrence sequence of strings.
    vector<bool> seen(n);
    for (int mask = (1 << n) - 1, pos = end_index; pos!=-1;) {
        seen[pos] = true;
        perm.push_back(pos);
        int cur_pos = pos;
        pos = parent[mask][pos];
        mask = mask ^ (1 << cur_pos);
    }

    for (int i = 0; i < n; ++i) {
        if (!seen[i])
            perm.push_back(i);
    }

    // Reconstruct string.
    string str;// First string has no preceding string.
    for (int i = n - 1; i > 0; i--) {
        int cur = perm[i];
        int next = perm[i - 1];
        str += A[cur].substr(0, A[cur].length() - overlap[cur][next]);
    }
    str += A[perm[0]];

    return str;
}