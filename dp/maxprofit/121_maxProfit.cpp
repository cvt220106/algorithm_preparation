// 股票交易系列
// 只能买一次卖一次的股票交易
// dp数组
// dp[i][0] 表示第i天持有股票所得最多现金，一开始现金是0，那么加入第i天买入股票现金就是 -prices[i]， 这是一个负数。
// dp[i][1] 表示第i天不持有股票所得最多现金
// 递推关系
// dp[i][0]因为只能买一次，因此dp[i][0]的最多现金，取决于dp[i - 1][0]与-prices[i]的最大值
// dp[i][1]，第i天不持有则有两种状态，i-1天也不持有时，那继续保持之前的最多现金状态dp[i - 1][1]
// 当i-1天持有时，则i天不持有，则需要以今日价格卖出, dp[i][1] = dp[i - 1][0] + prices[i]
// 即dp[i][0] = max(dp[i - 1][0], -prices[i]), dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
// 初始化
// dp[0][0] = -prices[0], dp[0][1] = 0
// 遍历顺序，因为递推关系右边值依赖于左边值，因此应该从左往右遍历
// 因为i只依赖于i-1的状态，可以使用常数级内存，滚动存储dp[i - 1]与dp[i]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, 0));
        int dp[2][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++) {
            // dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
        }

        // return dp[n - 1][1];
        return dp[(n - 1) % 2][1];
    }
};