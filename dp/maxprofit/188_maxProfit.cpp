// 股票教育
// 最多交易k次的股票交易
// dp数组
// 思路与两次没有差别
// 2次时最多有5个状态，k次也就有2k+1种状态
// 1. 没有操作 （其实我们也可以不设置这个状态）
// 2. 第一次持有股票
// 3. 第一次不持有股票
// 4. 第二次持有股票
// 5. 第二次不持有股票
// 。。。
// 2k. 第k次持有股票
// 2k+1. 第k次不持有股票
// 递推公式
// 也和前面也是一样的， 若为持有，则是前一次的持有与前一次的不持有减去当前价格的最大值
// 若为不持有，则是前一次的不持有与前一次的持有加上当前价格的最大值
// 初始化
// 持有的初始化为-prices[0]，不持有初始化为0
// 遍历顺序，从左往右

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[2][2*k+1];
        for (int i = 0; i < 2 * k + 1; i++) {
            if (i % 2 == 0) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = -prices[0];
            }
        }

        for (int i = 1; i < n; i++) {
            dp[i % 2][0] = dp[(i - 1) % 2][0];
            for (int j = 1; j < 2 * k + 1; j++) {
                if (j % 2 == 0) {
                    // 不持有
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1] + prices[i]);
                } else {
                    // 持有
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1] - prices[i]);
                }
            }
        }

        return dp[(n - 1) % 2][2 * k];
    }
};