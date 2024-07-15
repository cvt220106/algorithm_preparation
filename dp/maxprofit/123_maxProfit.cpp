// 股票教育
// 最多交易两次的股票交易
// dp数组
// 一天一共就有五个状态，
// 1. 没有操作 （其实我们也可以不设置这个状态）
// 2. 第一次持有股票
// 3. 第一次不持有股票
// 4. 第二次持有股票
// 5. 第二次不持有股票
// dp[i][j]中 i表示第i天，j为 [0 - 4] 五个状态，dp[i][j]表示第i天状态j所剩最大现金。
// 递推关系
// dp[i][0] = dp[i - 1][0]
// dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
// dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i])
// dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i])
// dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i])
// 初始化
// dp[0][0] = dp[0][2] = dp[0][4] = 0
// dp[0][1] = dp[0][3] = -prices[i]
// 递推顺序
// 从左往右

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[2][5];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;

        for (int i = 1; i < n; i++) {
            dp[i % 2][0] = dp[(i - 1) % 2][0];
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] - prices[i]);
            dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1] + prices[i]);
            dp[i % 2][3] = max(dp[(i - 1) % 2][3], dp[(i - 1) % 2][2] - prices[i]);
            dp[i % 2][4] = max(dp[(i - 1) % 2][4], dp[(i - 1) % 2][3] + prices[i]);
        }

        return dp[(n - 1) % 2][4];
    }
};