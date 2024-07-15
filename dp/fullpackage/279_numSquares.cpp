// 与322题相似
// 都是完全背包下的最小物品数问题
// 背包大小也就是目标整数n
// 不同点在于本题中，物品需要自身进行构造
// 也就是统计小于等于背包大小的完全平方数

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; i * i <= n; i++) {
            nums.push_back(i * i);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (auto num : nums) {
            for (int j = num; j <= n; j++) {
                if (dp[j - num] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - num] + 1);
                }
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};