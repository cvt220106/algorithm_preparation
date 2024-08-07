// 递推公式
// dp[i] = max(dp[i], (i - j) * j, dp[i - j] * j)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});
            }
        }

        return dp[n];
    }
};