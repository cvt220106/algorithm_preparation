// 难点不在于01背包的代码
// 在于如何将问题转换为01背包
// 要在数字前加上加减符号，从而使和为target
// 我们记总和为sum，+号和为x，负号和即为（sum - x），因此可推出
// x - (sum - x) = target => x = target + sum / 2
// 这样本题就是要找到装满背包大小为x最多方式
// 也就是组合类动态规划，类似于我们的走楼梯，找路线
// dp[j] 背包容量为j装满的方式
// 递推公式，dp[j] += dp[j - num[i]]，装满j的可能性时所有减去nump[i]的可能性总和
// 因为依赖上一层左边的值，因此遍历背包依旧是从右往左findMaxForm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if ((sum + target) % 2 == 1 || abs(target) > sum) {
            return 0;
        }

        int weight = (sum + target) / 2;
        vector<int> dp(weight + 1, 0);
        dp[0] = 1;
        for (auto num : nums) {
            for (int j = weight; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[weight];
    }
};