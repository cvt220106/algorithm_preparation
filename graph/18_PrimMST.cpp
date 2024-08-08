//
// Created by jacky on 24-8-7.
//
#include <bits/stdc++.h>
using namespace std;

// Prim算法：
// Prim算法的基本思想是从一个起始顶点开始，逐步扩展生成树，每次选择一个与当前生成树相连的最小权重边。
//
// 步骤：
// a) 选择一个起始顶点，将其加入生成树中。
// b) 考虑所有与当前生成树相连的边，选择权重最小的边，将其连接的新顶点加入生成树。
// c) 重复步骤b，直到所有顶点都被加入生成树。
//
// 实现细节：
//
// 使用优先队列（最小堆）来高效地选择最小权重的边。
// 时间复杂度：O((V+E) log V)，其中V是顶点数，E是边数。

struct edge {
    int v, w;

    bool operator>(const edge& other) const {
        return w > other.w;
    }
};

int V, E; // 顶点数，边数
vector<vector<edge>> graph; // 邻接表，存储出边和边权

pair<int, vector<pair<int, int>>> Prim() {
    vector<bool> visited(V + 1, false);
    vector<int> parent(V + 1, -1);
    vector<pair<int, int>> mst;
    int mst_weight = 0;

    // 使用优先队列，每次获取权值最小的边！
    priority_queue<edge, vector<edge>, greater<>> pq;
    // 从编号为1的节点开始
    pq.push({1, 0});
    while (!pq.empty()) {
        auto [u, w] = pq.top();
        pq.pop();
        if (visited[u])
            continue;

        visited[u] = true;
        mst_weight += w;
        if (parent[u] != -1) {
            mst.push_back({parent[u], u});
        }

        for (auto& [v, w] : graph[u]) {
            if (!visited[v]) {
                pq.push({v, w});
                parent[v] = u;
            }
        }
    }

    return {mst_weight, mst};
}

void printMST(vector<pair<int, int>>& mst) {
    for (auto& [u ,v] : mst) {
        cout << u << "-->" << v << '\n';
    }
}

int main() {
    cin >> V >> E;
    graph.resize(V + 1, vector<edge>());
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // 无向图！！！
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    auto [mst_weight, mst] = Prim();
    cout << mst_weight << endl;
    printMST(mst);
    return 0;
}
