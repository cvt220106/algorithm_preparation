//
// Created by jacky on 24-8-5.
//
// 题目链接：https://kamacoder.com/problempage.php?pid=1173
// 孤岛定义：孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;
// 移动方向
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int res = 0;

void bfs(int x, int y) {
    int m = graph.size();
    int n = graph[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    graph[x][y] = 0;

    while (!q.empty()) {
        auto [bx, by] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = bx + dx[i];
            int ny = by + dy[i];
            // 判断新的转移点 1.在不在graph，2.是不是陆地，3.是不是没有被访问过
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && graph[nx][ny] == 1 &&
                !visited[nx][ny]) {
                visited[nx][ny] = true;
                graph[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}

void dfs(int x, int y) {
    visited[x][y] = true;
    res++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 判断新的转移点 1.在不在graph，2.是不是陆地，3.是不是没有被访问过
        if (nx >= 0 && nx < graph.size() && ny >= 0 && ny < graph[0].size() &&
            graph[nx][ny] == 1 &&
            !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int computeByBfs() {
    int m = graph.size();
    int n = graph[0].size();
    visited.resize(m, vector<bool>(n, false));
    // 遍历从边缘开始的岛屿,将岛屿都变为海洋
    for (int i = 0; i < m; i++) {
        if (graph[i][0] == 1 && !visited[i][0]) {
            bfs(i, 0);
        }
        if (graph[i][n - 1] == 1 && !visited[i][n - 1]) {
            bfs(i, n - 1);
        }
    }
    for (int j = 0; j < n; j++) {
        if (graph[0][j] == 1 && !visited[0][j]) {
            bfs(0, j);
        }
        if (graph[m - 1][j] == 1 && !visited[m - 1][j]) {
            bfs(m - 1, j);
        }
    }
    // 再遍历找到所有中心的孤岛，用res全局变量，统计他们的总面积
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    graph.resize(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cout << computeByBfs() << endl;
    return 0;
}