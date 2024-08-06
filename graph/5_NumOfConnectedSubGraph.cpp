//
// Created by jacky on 24-8-5.
//
// 题目链接：https://kamacoder.com/problempage.php?pid=1171
#include <bits/stdc++.h>
using namespace std;

// 计算连通子图个数，本质就是找到一个没有被访问的点
// 以这个点为起点，进行bfs/dfs搜索，对所有bfs/dfs搜索到节点设置为以访问
vector<vector<int>> graph;
vector<vector<bool>> visited;
// 移动方向
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y) {
    int m = graph.size();
    int n = graph[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

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
                q.push({nx, ny});
            }
        }
    }
}

int computeByBfs() {
    int m = graph.size();
    int n = graph[0].size();
    visited.resize(m, vector<bool>(n, false));
    int cnt = 0;
    // 开始遍历每一个为1的点，如果没有被访问过，就从该点开始
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }

    return cnt;
}

void dfs(int x, int y) {
    visited[x][y] = true;
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

int computeByDfs() {
    int m = graph.size();
    int n = graph[0].size();
    visited.resize(m, vector<bool>(n, false));
    int cnt = 0;
    // 开始遍历每一个为1的点，如果没有被访问过，就从该点开始
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    return cnt;
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
    //cout << computeByBfs() << endl;
    cout << computeByDfs() << endl;
    return 0;
}