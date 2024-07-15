// 编辑距离
// 538题的两个字符串，1.只能删除操作，2.word1和word2达到一个相同的状态（不需要一定是二者其一）
// 编辑距离则是，1.可删除、添加、替换 2.word1转为word2！！（必须word2不变的）
// 因此我们的删除、添加、替换操作都是基于word1而言的
// dp数组
// dp[i][j]表示[0, i - 1]的word1子串转变为[0, j - 1]的word2子串的最小编辑距离
// 递推关系
// if word1[i - 1] == word2[i - 1]
// 那么就依赖于dp[i - 1][j - 1]要走的最小编辑距离即可, dp[i][j] = dp[i - 1][j - 1]
// if word1[i - 1] != word2[j - 1]
// 因为不等，那么必然就存在编辑，此时就要考虑如何编辑
// 1.删除，因为是word1转为word2,因此必然是word1执行删除操作
// 也就是从dp[i - 1][j]状态推导，删除word[i - 1]，距离加1
// 2.添加，同样必然是word1执行添加操作
// 也就是在word1[0, i - 1]后添加word2[j - 1]，此时二者尾部元素相同，因此也就是回到
// dp[i][j - 1]的状态，再加上添加操作，距离加1
// 3.替换，word1[i - 1]替换为word2[j - 1]，此时二者相同
// 回到dp[i - 1][j - 1]的状态，再加上替换操作，距离加1
// 因为是要求最小，因此三者取最小值得到递推公式
// dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
// 初始化
// 转换为空字符串的操作必然就是另一个字符串的长度
// for i in 0..n1 dp[i][0] = i, for j in 0..n2 dp[0][j] = j
// 遍历顺序
// 依旧是从上到下，从左到右

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
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }
        
        return dp[n1][n2];
    }
};