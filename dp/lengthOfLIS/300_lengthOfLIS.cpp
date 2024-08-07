// 最长递增子序列
// 重点在于明确dp数组的含义
// dp数组
// dp[i] 表示以nums[i]元素为递增序列结尾的最长递增子序列长度
// 递推关系
// 子序列长度必然从小于i的范围内dp[j]的长度，进一步满足递增关系后+1
// 要取最大值，也就是遍历所有满足的dp[j] + 1，找出最大值
// 也就是 for j in 0..i if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
// 初始化
// 每一个元素的子序列必然是递增子序列，因此初始化均为1，dp[i] = 1
// 遍历顺序
// i必然从左往右遍历，对于内层的j，只需要无遗漏的全部对比到，那就不会出错，因此均可
// 结果
// 所有dp数组中元素的最大值


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 1;
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }

        return result;
    }

    // 二分查找
    // dp[i]表示长度为i + 1的最长递增子序列的末尾元素最小值
    // 如果是单调不减，包含大于等于的情况，使用upper_bound
    // 如果是单调增，只包含大于的情况，使用lower_bound，这样相同的元素，不会计入两次序列长度
    // 而是进行覆盖！
    int lengthOfLIS2(vector<int>& nums) {
        int dp[2505];
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        fill(dp, dp + 2505, INT_MAX);
        int mx = dp[0];
        for (int num : nums) {
            *lower_bound(dp, dp + n, num) = num;
        }

        int res = 0;
        while (mx != dp[res]) {
            res++;
        }

        return res;
    }
};