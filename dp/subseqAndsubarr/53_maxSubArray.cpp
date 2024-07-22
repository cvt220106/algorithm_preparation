// 最大子数组和
// 对于子数组，立即要想到连续，因此递推只存在于相邻之间！！
// dp数组
// dp[i]表示以nums[i]为结尾的子数组的最大和
// 递推关系
// 前面说到子数组连续，因此递推关系只与dp[i - 1]相关，而每个独立元素本身就是一个子数组，其和就是元素大小
// 因此我们需要对比递推所得与自身，取最大值，dp[i] = max(dp[i - 1] + nums[i], nums[i])
// 初始化
// dp[0]显然就是nums[0]元素本身的子数组和，因此dp[0] = nums[0]
// 遍历顺序
// dp[i]依赖于dp[i - 1]因此从左往右，从1开始

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1]+ nums[i], nums[i]);
            result = max(result, dp[i]);
        } 

        return result;
    }
};