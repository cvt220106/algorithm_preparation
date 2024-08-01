//
// Created by jacky on 24-8-1.
//
// 寻找最长递增子序列的个数
// 同样是之前的dp遍历，寻找最长递增子序列
// 但因为要统计计数。需要同步一个count数组
// count[i]记录以前i为结尾的递增子序列的最大长度为dp[i]的不同序列个数！
// count本身也是一个动态规划数组
// 最长递增子序列中, dp[i] = dp[j] + 1
// 同步的dp[j]情况下的不同序列个数count[j]，同样是该情况下以i为结尾的最新长度的不同序列个数
// 因此count[i] = count[j]
// 如果dp[i] == dp[j] + 1, 则此时count情况，在原来的序列个数基础上加上count[j]
// count[i] += count[j]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        int max_len = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            max_len = max(max_len, dp[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == max_len)
                res += count[i];
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << Solution().findNumberOfLIS(nums) << endl;
}