// 打家劫舍2
// 屋舍之间的条件从线性升级为环状，也就是说首尾是相连的
// 这个情况下，我们不能一次性的递推得到结果
// 分为两种情况分别运用线性地推的方式，再比较二者结果
// 因为首尾元素不可能同时选取，因此分别去掉一个首元素或者尾元素时，剩下的元素列表和打家劫舍1相同
// dp1[i] 去掉尾元素的动态规划
// dp2[i] 去掉头元素的动态规划
// result = max(dp1[n - 1], dp2[n - 1])
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
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        int current_result = dp[n - 2];
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return max(current_result, dp[n -1]);
    }

    int rob2(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } 

        int result1 = robPart(nums, 0, nums.size() - 2);
        int result2 = robPart(nums, 1, nums.size() - 1);
        
        return max(result1, result2);
    }

    int robPart(vector<int> &nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[end];
    }
};