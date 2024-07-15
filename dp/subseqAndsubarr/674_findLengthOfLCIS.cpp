// 最长连续递增子序列
// 相较于子序列，多出了连续的要求，连续子序列本质也就是子数组
// 因为连续的要求，我们的递推也就简单了很多，只需要与i-1进行比较即可
// dp数组
// dp[i]以元素nums[i]为结尾的最大连续递增子序列的长度
// 递推关系
// 因为连续，因此只能从前一个元素进行推导而得，也就是dp[i - 1] + 1
// 初始化
// 每一个元素的子序列必然是递增子序列，因此初始化均为1，dp[i] = 1
// 遍历顺序
// i依赖于i- 1的状态，因此必须从左往右遍历
// 结果
// 所有dp数组中元素的最大值

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 1;
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};