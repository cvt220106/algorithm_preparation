//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;
// 分割回文串2
// 将字符串分割成一个个回文串，且要求最小的次数
// 字符串的分割还是上面的讨论的方式，dp[i]代表[0, i)的子串的最小分割次数
// 所以每次递推时获取的子串就是[j, i)的子串，s.substr(j, i - j)
// 判断规则变为了是否为回文串，可以提前写个dp获取到字符串可能为回文串的二维dp判断数组
// 要求是最小次数，因此递推时，使用min逻辑！

class Solution {
public:
    vector<vector<int>> computePalindrome(const string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][j]表示以[i,j]范围的子串是否为回文子串
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[j] == s[i] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                }
            }
        }

        return dp;
    }

    int minCut(string s) {
        int n = s.size();
        if (n == 1) {
            return 0;
        }
        vector<vector<int>> palindromes = computePalindrome(s);
        vector<int> dp(n + 1, INT_MAX);
        // dp[i]子串[0, i - 1]的最少分割次数
        // dp[j] [0, j - 1] [j, i - 1]
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (palindromes[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] - 1;
    }
};