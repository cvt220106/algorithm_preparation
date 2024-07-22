#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // dfs + backtrack
    int directions[2][2] = {{1, 0}, {0, 1}};
    bool dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &path, vector<vector<int>> &visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1 && j == n - 1 && grid[i][j] == 0) {
            return true;
        }
        
        for (auto dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && visited[x][y] == 0) {
                visited[x][y] = 1;
                path.push_back({x, y});
                if (dfs(grid, x, y, path, visited)) {
                    return true;
                }
                path.pop_back();
            }
        }
        
        return false;
    }
    
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid.empty() || obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) {
            return {};
        }
        vector<vector<int>> path;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = true;
        path.push_back({0, 0});
        if (dfs(obstacleGrid, 0, 0, path, visited)) {
            return path;
        } else {
            return {};
        }
    }
    
    // dp version solution
    // dp[i][j]表示是否从(0,0)出发后能否到达(i, j)处
    // 因此dp主要用于先判断(0, 0)能都到达(m - 1, n - 1)处
    // 若能到达，则从终点不断查看dp[i][j]的可行性，倒退得到一条可行路径
    // 递推顺序
    // 一个点的可达性取决于它自身是否存在障碍与上方或左方的可达性
    // dp[i][j] = obstacleGrid[i][j] == 0 && (dp[i - 1][j] || dp[i][j - 1]);
    // 初始化
    // 第一行与第一列的可行性仅取决于前面是否存在障碍
    // for i in 0..m if (obstacleGrid[i][0]) break; dp[i][0] = true;
    // for j in 0..n if (obstacleGrid[0][j]) break; dp[0][j] = true;
    // 递推顺序，从上到下，从左往右
    // 
    vector<vector<int>> pathWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid.empty() || obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) {
            return {};
        }
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0]) {
                break;
            }
            dp[i][0] = true;
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j]) {
                break;
            }
            dp[0][j] = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0 && (dp[i -1][j] || dp[i][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        
        // 不可达
        if (!dp[m - 1][n - 1]) {
            return {};
        }
        
        // 可达，逆推得到路径
        vector<vector<int>> path;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            path.push_back({i, j});
            if (i > 0 && dp[i - 1][j]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(path.begin(), path.end());
        
        return path;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution().pathWithObstacles2(grid);
    return 0;
}