// 完全背包问题
// 相较于01背包问题问题，变化点在于物品不再是只能选择一次，而是可以多次选择
// 因此我们相应的要改变就是背包的迭代逻辑
// 内层的背包循环改变为从小到大遍历，因为是可以复用，直接继续基于当前的先前状态继续dp即可

// 接下来时需要注意的就是物品和背包的迭代优先顺序了
// 对于普通的背包内最大价值问题而言，一维dp数组下，我们都是默认先物品再背包
// 对于背包内组合或排列方式可能总数问题，遍历顺序就有了区分
// 对于组合问题，我们应该先物品再背包
// 对于排列问题，我们应该先背包再物品

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[j]表示j大小背包的所有组合形式
// 初始化时需要注意，背包大小为0时，也应该认为存在一种方式
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (auto coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};