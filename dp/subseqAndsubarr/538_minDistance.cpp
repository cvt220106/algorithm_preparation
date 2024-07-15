// 两个字符串的删除操作
// 删除两个不同字符串word1，word2中一些字符使得二者相同的最小步数
// 本质还是和最大公共子序列类似，最小变化步数可以理解为两个字符串到最大公共子序列的长度需要减去的长度
// min_step = word1.size() + word2.size - 2 * max_common_size

// 当然也可以用最小的递推逻辑来执行
// dp数组
// dp[i][j]表示[0, i - 1]的word1子串与[0, j - 1]的word2子串要相同的最小步数
// 递推关系
// if word1[i - 1] == word2[i - 1]
// 那么就依赖于dp[i - 1][j - 1]要走的最小步数即可, dp[i][j] = dp[i - 1][j - 1]
// if word1[i - 1] != word2[j - 1]
// 因为不等，那么必然就存在删除移动的步数，此时就要考虑如何移动
// 1.word1删去word1[i - 1]的字符， 那么就是从dp[i - 1][j]的最小步数再加上当前删除移动操作1
// dp[i][j] = dp[i - 1][j] + 1
// 2.word2删除word2[j - 1]的字符，同理就有dp[i][j] = dp[i][j - 1] + 1
// 因为是要最小步数，因此二者取小，dp[i][j] = min(dp[i- 1][j], dp[i][j - 1]) + 1
// 初始化
// 如果一个字符串为空，则另一个走的最小步数必须为自身！
// for i in 0..n1 dp[i][0] = i; for j in 0..n2 dp[0][j] = j;
// 遍历顺序
// 依旧是从上到下，从左往有

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for (int i = 0; i <= n1; i++) dp[i][0] = i;
        for (int j = 1; j <= n2; j++) dp[0][j] = j;
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        
        return dp[n1][n2];
    }
};