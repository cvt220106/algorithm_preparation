// 本质还是将数组内的内容尽量分为重量相同的两堆
// 因此可以通过计算总和再取一半为背包重量，因为每个物品只能取一次，因此仍是01背包 
// 一维
// dp[j]代表重量j时最大价值
// 递推公式dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
// 一维下从i=0开始遍历，只需初始化为0即可
// 遍历顺序，因为依赖于上一层的dp[j - weight[i]]的状态，因此j的遍历需要从右往左
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            sum += stones[i];
        }

        int weight = sum / 2;
        vector<int> dp(weight + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = weight; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[weight];
    }
};

