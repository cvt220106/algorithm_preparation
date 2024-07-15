/**
动态规划五部曲

1.确定dp数组及其下标含义
dp[i][j]代表从[0][0]起点位置到[i][j]位置的可行的不同路径数

2.确定递推公式（也就是状态转移方程）
因为机器人每次只能向右或者向下运动
因此dp[i][j]可行的路径只取决于左边或上边移动的可行路径总和
但本题中加入了障碍元素，需要注意的就在于，障碍点应该跳过递推，同时其值为0
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

3.dp数组如何初始化
起始点只能从自己这里走,若无障碍物则为1，有障碍物则无法出发，直接为0
而起点处同行或同列均只能从起始点处向右或向下移动，始终只有一条可能路径
同时判断当前位置是否为障碍处，若为障碍，则设为0

4.确定遍历顺序
跟据递归公式以及我们的分析，dp[i][j]依赖于dp[i - 1][j]和dp[i][j - 1]的状态
因此我们必须从左往右，从上往下的遍历

5.举例推导dp数组
obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
  0 1 2
0 1 1 1   
1 1 x 1
2 1 1 2
2
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 直接使用空间压缩法
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i]) {
                // 遇到障碍，后续均为0
                break;
            }
            dp[i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 并不能照搬上一题的循环条件
                // 上一题因为第一列都是1，因此可以略过迭代
                // 本题中第一列中可能存在障碍物，导致后续为0，因此需要加入遍历判断
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else {
                    if (j > 0) {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }

        return dp[n - 1];
    }
};