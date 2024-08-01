//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n3 != n1 + n2) {
            return false;
        }

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        // s2为空字符串时，对比s1和s3
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];
        }
        // s1为空字符串时，对比s2和s3
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = (s2[j - 1] == s3[j - 1]) && dp[0][j - 1];
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                // 遍历s1和s2, s3的字符就是第i + j个字符
                // 对比s1和s3
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                // 对比s2和s3,并结合上一次对比的结果
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n1][n2];
    }
};