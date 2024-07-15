// 打家劫舍1.0版本
// 顺序型房舍，相邻不可同时偷盗，计算最大偷盗金额
// 根据这个规则，不难得出
// dp[i]为到达第i家时的最大偷盗金额
// dp由两种状态得到，dp[i - 2] + value[i]或者dp[i - 1]
// 因为计算最大金额，因此二者选取最大值dp[i] = max(dp[i - 2] + value[i], dp[i - 1])
// 初始化，因为递推中存在i-2，我们就需要从i=2开始递推，因此需要初始化dp[0]与dp[1]
// dp[0] = value[0], dp[1] = max(dp[0]. dp[1])
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};