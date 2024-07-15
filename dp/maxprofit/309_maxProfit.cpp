// 股票交易
// 不限制次数，但包含冷冻期！
// 冷冻期也就是卖出后需要间隔一天（也就是冷冻期）后才能再次购入
// dp数组
// dp[2][4]
// 每一天中主要有四个状态
// 1.持有股票状态--今日买入或之前持有保持至今日
// 2.保持卖出，不持有股票的状态（前一天也是如此或前一天是冷冻期）
// 3.今日卖出，不持有股票
// 4.今日冷冻期（昨日一定卖出）
// 递推公式
// 状态一dp[i][0]只能是昨日也持有，dp[i - 1][0]，或者今日买入，今日买入的昨日可能是保持卖出不持有或冷冻期
// 状态二dp[i][1]则可能是dp[i - 1][1]和dp[i - 1][3]两种状态得来依旧是取较大值
// 状态三今日卖出，那么一定是从状态一持有股票得来dp[i - 1][0] + prices[i]
// 状态四今日冷冻期，那么一定是从昨日卖出得来，dp[i - 1][2]
// dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]) 
// dp[i][1] = max(dp[i - 1][1], dp[i - 1][3])
// dp[i][2] = dp[i - 1][0] + prices[0]
// dp[i][4] = dp[i - 1][2]
// 初始化
// dp[0][0] = -prices[i]; dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0;
// 结果一定是从不持有股票的状态里取最大值
// 也就是max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]})

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        int prev = 0;
        int cur = 1;

        for (int i = 1; i < n; i++) {
            dp[cur][0] = max(dp[prev][0], max(dp[prev][1], dp[prev][3]) - prices[i]);
            dp[cur][1] = max(dp[prev][1], dp[prev][3]);
            dp[cur][2] = dp[prev][0] + prices[i];
            dp[cur][3] = dp[prev][2];
            swap(prev, cur);
        }

        int res = (n - 1) % 2;
        return max({dp[res][1], dp[res][2], dp[res][3]});
    }
};