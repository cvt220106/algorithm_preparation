// 完全背包问题
// 要求装满背包时所需最少的物品数
// 一维dp[j]代表装满j大小背包时所需最少的物品数
// 遍历顺序，因为是完全背包，因此先物品再背包，都是从左往右
// 递推公式dp[j] = min(dp[j], dp[j - num[i]] + 1);
// 初始化，因为是找最小值，就不能全部初始化为0了，初始化INT_MAX
// 同时需要注意dp[0]依旧需要是0，这是迭代的开始，而应为初始化为INT_MAX，当他们还是该值时，不能执行+1，否则会导致溢出。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (auto coin : coins) {
            for (int j = coin; j <= amount; j++) {
                if (dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};