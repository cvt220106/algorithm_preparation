//
// Created by jacky on 24-8-8.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1152
// 单源含负权值的最短路径！
// bellman-ford算法的队列优化
// 每次松弛操作并不需要重新的整个边集中去搜寻
// 只有上一次被松弛的节点所连接的边，才有可能引起下一次松弛操作
// 因此可以用队列进行维护下一次可能松弛的边！

struct edge {
    int v, w;
};

int V, E;
vector<vector<edge>> graph; // 邻接表
vector<bool> inqueue;
vector<int> dist;
vector<int> cnt; // 记录最短路径经过的边数，如果超过n说明出现负环

bool spfa(int s) {
    inqueue.resize(V + 1, false);
    dist.resize(V + 1, INT_MAX);
    dist[s] = 0;
    cnt.resize(V + 1, 0);
    queue<int> q;
    q.push(s);
    inqueue[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;

        for (auto& [v, w] : graph[u]) {
            if (dist[u] < INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= V)
                    return true; // 存在环！
                if (!inqueue[v]) {
                    q.push(v);
                    inqueue[v] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> V >> E;
    graph.resize(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    bool flag = spfa(1);
    if (flag) {
        cout << "circle\n";
    } else {
        if (dist[V] == INT_MAX) {
            cout << "unconnected\n";
        } else {
            cout << dist[V] << '\n';
        }
    }
    return 0;
}