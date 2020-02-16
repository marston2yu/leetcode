#include "WordBreak.h"

bool wordBreak(string s, vector<string> &wordDict) {
    vector<int> dp(s.length() + 1, 0);
    dp[0] = 1;
    int l = s.length();
    for (int i = 1; i <= l; i++) {
        for (auto w: wordDict) {
            int wl = w.length();
            if (i >= wl && dp[i - wl] && (s.substr(i - wl, wl)==w)) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[l];
}