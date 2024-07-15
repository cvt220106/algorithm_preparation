#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 因为不同顺序视为不同组合，因此实际上本题是一个排列
// 前面提到过，对于排列我们应该先遍历背包，再遍历物品
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int j = 0; j <= target; j++) {
            for (auto num : nums) {
                if (j >= num && dp[j] < INT_MAX - dp[j - num]) {
                    dp[j] += dp[j - num];
                }
            }
        }

        return dp[target];
    }
};