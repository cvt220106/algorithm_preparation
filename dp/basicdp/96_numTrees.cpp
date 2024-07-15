// dp[i] i个节点的二叉搜索树种类
// 要想当前树为二叉搜索树，则左子树和右子树均为二叉搜索
// 因此dp[i] = {j: for 0 to i - 1} sum dp[j] * dp[i - j - 1]
// 初始化 dp[0] = 1, dp[1] = 1
// 遍历，从左往右
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
          vector<int> dp(n + 1, 0);
          dp[0] = 1;
          dp[1] = 1;

          for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};