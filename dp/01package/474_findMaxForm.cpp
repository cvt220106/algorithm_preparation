// 因为每个元素依旧只能选择一次，因此还是01背包问题
// 但不同的在于背包变成了两个维度，0，1两个背包都要同时满足下的最大元素个数
// 二维
// dp[i][j]：i容量0背包和j容量1背包下，最多容纳的元素个数
// 递推公式：dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
// 遍历方向：因为以来于上一状态的左上，因此0背包和1背包都需要从右往左遍历

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &str : strs) {
            auto [num0, num1] = count0And1(str);
            for (int i = m; i >= num0; i--) {
                for (int j = n; j >= num1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }

        return dp[m][n];
    }

    auto count0And1(string& str) -> std::pair<int, int> {
        int num0= 0, num1 = 0;
        for (auto c : str) {
            if (c == '0') {
                num0 += 1;
            } else {
                num1 += 1;
            }
        }

        return {num0, num1};
    }
};