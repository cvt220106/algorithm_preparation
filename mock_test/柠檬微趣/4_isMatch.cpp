//
// Created by jacky on 24-7-30.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Initialize dp table
        dp[0][0] = true;

        // Initialize first row (empty string s and pattern p)
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // '*' matches zero preceding element
            }
        }

        // Fill the dp table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    // '*' matches zero preceding element
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                        // '*' matches one or more preceding element
                    }
                } else if (p[j - 1] == '?') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};