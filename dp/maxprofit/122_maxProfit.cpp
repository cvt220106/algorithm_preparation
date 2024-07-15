// 股票交易系列
// 可多次买卖的股票交易
// dp数组
// dp[i][0] 表示第i天持有股票所得最多现金，一开始现金是0，那么加入第i天买入股票现金就是 -prices[i]， 这是一个负数。
// dp[i][1] 表示第i天不持有股票所得最多现金
// 递推关系
// 本题相较于上一题，最大的变化点在于股票存在多次买卖的，因此dp[i - 1][0]不再是一定从0 - prices[i]的比较，前面可能已经积累了收益
// 因此应该从前一次的不持有股票出发，前一次不持有股票的最大收益减去当前股票价格
// dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
// do[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
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
        int dp[2][2];
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
        }

        return dp[(n - 1) % 2][1];
    }
};