//
// Created by jacky on 24-8-6.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1177
// 给定一个有向图，包含 N 个节点，节点编号分别为 1，2，...，N。
// 现从 1 号节点开始，如果可以从 1 号节点的边可以到达任何节点，则输出 1，否则输出 -1。
// 直接以1号节点作为起点，进行dfs或bfs搜索即可，看是否能够将所有节点均访问到
// 遍历结束，检查visited数组，若存在未访问的节点，返回-1

vector<vector<int>> graph; // 邻接表
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    graph.resize(n + 1, vector<int>());
    visited.resize(n + 1, false);
    while (k--) {
        int u, v;
        cin >> u >> v;
        // 有向图
        graph[u].push_back(v);
    }

    // dfs
    // dfs(1);
    // bfs
    bfs(1);

    // 检查节点访问情况,0号节点要跳过！！！！
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            res = -1;
        }
    }
    cout << res << '\n';

    return 0;
}