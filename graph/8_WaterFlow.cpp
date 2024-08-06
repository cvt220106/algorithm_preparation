//
// Created by jacky on 24-8-6.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1175
// 一般思路，从每一个点开始dfs遍历，检查该点能否到达两个边界
// 每一个点的dfs时间复杂度都是O(mn)，mn个点，所有时间复杂度达到了四次方O(m^2*n^2)
// 优化思路
// 从两个边界的点出发，分别记录其dfs能到向上攀爬的范围
// 如果一个点能同时在两个边界的覆盖范围内，说明就是可以到达两个边界的点
// 这样下来，每个边界的dfs都是O(mn)的时间复杂度，检查点覆盖情况时，同样是O(mn)的时间复杂度

vector<vector<int>> graph;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(vector<vector<bool>>& visited, int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < graph.size() && ny >= 0 && ny < graph[0].size() && !
            visited[nx][ny] && graph[x][y] <= graph[nx][ny]) {
            dfs(visited, nx, ny);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    graph.resize(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<vector<bool>> first(m, vector<bool>(n, false));
    vector<vector<bool>> second(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        dfs(first, i, 0); // 左边界
        dfs(second, i, n - 1); // 右边界
    }
    for (int j = 0; j < n; ++j) {
        dfs(first, 0, j); // 上边界
        dfs(second, m - 1, j); // 下边界
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (first[i][j] && second[i][j]) {
                cout << to_string(i) + " " + to_string(j) + "\n";
            }
        }
    }

    return 0;
}