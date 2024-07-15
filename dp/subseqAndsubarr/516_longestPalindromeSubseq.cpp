// 最长回文子序列
// 需要的是回文子序列的最长长度！！
// dp数组
// dp[i][j]就是[i, j]范围内的最长回文子序列长度
// 递推关系
// if s[i] == s[j]
// 二者相等，那么就可以直接加入到回文子序列中，长度加2
// dp[i][j] = dp[i + 1][j - 1] + 2
// if s[i] != s[j]
// 二者不相等，那么不能同时加入到回文子序列中
// 1.只加入s[i]
// dp[i][j] = dp[i][j - 1]
// 2.只加入s[j]
// dp[i][j] = dp[i + 1][j]
// 因为要最长，因此二者取较大值，dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
// 初始化
// 对于单个字符，一定是回文子序列，长度为1,需要进行初始化指明，其余初始化为0即可
// 遍历顺序
// 同样是从下往上，从左往右，j要保证大于i
// 结果，一定是[0, n - 1]范围的最大回文子序列长度！

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};