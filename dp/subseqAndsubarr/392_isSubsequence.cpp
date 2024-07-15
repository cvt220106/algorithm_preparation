// 判断子序列
// 本质上还是和最大公共子序列类似
// 不过因为是要判断其中一个字符串是否为另外一个字符串的子序列
// 因此在递推时，当当前字符不同时的推导，只修改大字符串递推即可。
// dp数组
// dp[i][j]以下标i-1为结尾的s字符串子串和以下标j-1为结尾的t字符串子串的最长公共子序列的长度
// 递推公式
// 当前元素相等时，递推依旧是+1
// if s[i - 1] == t[j - 1]，dp[i][j] = dp[i - 1][j - 1] + 1
// 当前元素不等时，在最大公共子序列中，我们是分别两个字符串各去除一个字符，然后取最大值
// 而此时判断子序列，我们只需要去除大字符串的一个字符即可，去除了小字符串那就不就不包含关系了！
// if s[i - 1] != t[j - 1]，dp[i][j] = dp[i][j - 1]
// 初始化
// 初始化为0即可
// 遍历顺序
// 从上往下，从前往后

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        
        // compare dp[n1][n2] with n1
        return dp[n1][n2] == n1;
    }
};