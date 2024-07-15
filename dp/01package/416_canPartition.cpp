// 01背包问题
// 二维中dp[i][j]的含义，从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
// 递推公式，每个物品都有两种选择，取或者不取
// 不取则等同于dp[i - 1][j]
// 取则等于dp[i - 1][j - weight[i]] + value[i]
// 要获得最大值，因此dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])
// 当然必须当前的背包容量 j >= weight[i]才能装入！
// 初始化：对于第一个物品，只要是j > weight[0]的均可装入，for j = weight[0] to max_weight, dp[0][j] = value[0]
// 遍历顺序，从递推公式不难看出，当前值依赖于上方和左方，因此，从上往下先遍历物品，再从左往右遍历重量

// 一维空间压缩，因为上一层i - 1并不需要做过多操作，只是简单的复制拷贝，上一层可以重复利用
// dp[j]当前j重量下可以获取的最大价值
// 递推公式类似，只不过将二维dp[i - 1][j]视作上一状态的自身dp[j]
// dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
// 需要注意的是，更新过程中需要用到上一状态的dp[j - weight[i]]，因此遍历顺序应该从右往左！！
// 一维中并不需要特意的初始化过程，因为i从0开始遍历
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }

        int weight = sum / 2;
        vector<int> dp(weight + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = weight; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return dp[weight];
    }
};