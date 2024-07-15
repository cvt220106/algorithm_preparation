/**
动态规划五部曲

1.确定dp数组及其下标含义
dp[i][j]代表从[0][0]起点位置到[i][j]位置的可行的不同路径数

2.确定递推公式（也就是状态转移方程）
因为机器人每次只能向右或者向下运动
因此dp[i][j]可行的路径只取决于左边或上边移动的可行路径总和
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

3.dp数组如何初始化
起始点只能从自己这里走也就是dp[0][0] = 1
而起点处同行或同列均只能从起始点处向右或向下移动，始终只有一条可能路径
for (int i = 0; i < m; i++) {
    dp[i][0] = 1;
}
for (int j = 1; j < n; j++) {
    dp[0][j] = 1;
}

4.确定遍历顺序
跟据递归公式以及我们的分析，dp[i][j]依赖于dp[i - 1][j]和dp[i][j - 1]的状态
因此我们必须从左往右，从上往下的遍历

5.举例推导dp数组
m = 7, n = 3
  0 1 2 3 4 5 6 
0 1 1 1 1 1 1 1
1 1 2 3 4 5 6 7
2 1 3 6 10 15 21 28
后续通过打印验证
*/
#include <iostream>
class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     int dp[m][n] = {0};
    //     for (int i = 0; i < m; i++) {
    //         dp[i][0] = 1;
    //     }
    //     for (int j = 1; j < n; j++) {
    //         dp[0][j] = 1;
    //     }

    //     for (int i = 1; i <m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     } 

    //     // print to verify
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             std::cout << dp[i][j] << " ";
    //         }
    //         std::cout << std::endl;
    //     }

    //     return dp[m - 1][n - 1];
	// }

    // 优化空间复杂度
    int uniquePaths(int m, int n) {
        // defination and intilize the first line
        int dp[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    std::cout << solution.uniquePaths(3, 7) << std::endl;
    return 0;
}
