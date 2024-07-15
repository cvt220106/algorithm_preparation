// 不同的子序列
// 本题中与前面的不同点在于，前面都是重复子数组，公共子序列的长度
// 本题是要求计算子序列的个数！因此dp数组的含义相应需要更改
// dp数组
// dp[i][j]表示[0, i - 1]的字符串s子串与[0, j - 1]的字符串t子串的不同子序列个数
// 递推公式
// if s[i - 1] == s[j - 1]
// 我们即可以使用s[i - 1]，那么dp[i][j]包含dp[i - 1][j - 1]的个数
// 我们也可以选择不使用s[i - 1]，那么dp[i][j]包含的就是dp[i - 1][j]的个数
// 因此dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
// if s[i - 1] != s[j - 1]
// 当二者不同时，那就只能使用s[i - 1]，因此dp[i][j] = dp[i - 1][j]
// 初始化
// 之前计算子序列长度，我们可以初始化为0，但是计算个数时，我们需要考虑空字符串依旧算是一个子序列
// 因此当j = 0时，t为空串，i任意都包含一个这个子序列，dp[i][0] = 1;
// 其余依旧初始化为0即可
// 遍历顺序
// 递归公式依旧依托于左边与上边，因此遍历顺序从上往下，从左往右

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n1][n2];
    }
};