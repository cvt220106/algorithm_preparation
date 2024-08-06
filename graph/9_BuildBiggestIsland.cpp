//
// Created by jacky on 24-8-6.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1176
// 1.首先通过之前一样的dfs/bfs策略，将原本的岛屿找到
// 2.通过将每个岛屿的进行编号，同时使用map记录下它们对应的面积
// 3.遍历整个图，尝试将每个0边为1,同时检查其周围的岛屿编号
// 4.这样就能快速得到将当前海水变为岛屿后，新的岛屿的总面积就是 sum(周围岛屿）+ 1
// 5.在这个过程中，维护一个最大值，遍历结束即为所得

// tips: 最多可以将一个海水变为岛屿，但其实可以不变，如果没有更好选择的话
// 原本岛屿中的最大值就是所求！

vector<vector<int>> graph;
vector<vector<bool>> visited;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int island_num = 2;
int area = 0;

void dfs(int x, int y) {
    visited[x][y] = true;
    area++;
    graph[x][y] = island_num;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < graph.size() && ny >= 0 && ny < graph[0].size() &&
            graph[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    graph.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    // 统计各个连通子图的面积并标号
    unordered_map<int, int> island_area;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                island_area.insert({island_num, area});
                island_num++;
                area = 0;
            }
        }
    }

    // 尝试将海水变为岛屿，同时计算新岛屿周围岛屿面积
    int max_island_area = 0;
    for (auto& [k, v] : island_area) {
        max_island_area = max(max_island_area, v);
    }
    unordered_set<int> visited_island;
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (graph[x][y] == 0) {
                area = 1;
                visited_island.clear();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < graph.size() && ny >= 0 && ny < graph[0]
                        .size() &&
                        graph[nx][ny] > 1) {
                        if (visited_island.count(graph[nx][ny]) > 0)
                            continue;
                        area += island_area.at(graph[nx][ny]);
                        visited_island.insert(graph[nx][ny]);
                    }
                }
                max_island_area = max(max_island_area, area);
            }
        }
    }

    cout << max_island_area << '\n';

    return 0;
}