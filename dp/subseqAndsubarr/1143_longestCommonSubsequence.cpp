// 最长公共子序列
// 比较两个字符串，并找出它们的最长公共子序列的长度
// 本质上dp逻辑大致与最大公共子数组类似，但不同点在于子序列的不连续性，对于元素不等的情况要更多考虑
// dp数组
// dp[i][j]表[0, i -1]的str1子串1与[0 j-1]的str2子串2的最长公共序列长度。
// 递推关系
// 当str1[i - 1]与str2[j - 1]相等时，还是和之前一样的处理，dp[i][j] = dp[i -1][j-1] + 1
// 但当二者不同，不应该是置为0的处理，因为我们并不要求连续，即使二者不同也不影响序列长度
// 因此我们应该将二者元素分别选择一个剔除后，查看最大公共子序列长度，因此dp[i][j] = max(dp[i -1][j], dp[i][j -1])
// 初始化
// 直接全部为0即可
// 遍历顺序
// 因为dp[i][j]的递推依赖于左边或上边的元素，因此必须是从上往下，从左往右的遍历

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i -1][j], dp[i][j -1]);
                }
            }
        }

        return dp[n1][n2];
    }
};