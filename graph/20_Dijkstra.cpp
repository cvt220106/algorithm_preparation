//
// Created by jacky on 24-8-8.
//
#include <bits/stdc++.h>
using namespace std;
// 最短路径问题是指在一个加权图中，找到从一个起始顶点到其他顶点（或特定目标顶点）的最小权重路径。
// 这里的"权重"可以代表距离、时间、成本等。
// Dijkstra算法是解决带非负权边的图的单源最短路径问题的经典算法。
// 它的核心思想是贪心策略，每次选择当前最短路径的顶点进行扩展。
// 将结点分成两个集合：已确定最短路长度的点集（记为 S 集合）的和未确定最短路长度的点集（记为 T 集合）。
// 一开始所有的点都属于 T 集合。
// 初始化 dis(s)=0，其他点的 dis 均为 +\infty。
// 然后重复这些操作：
// 1.从 T 集合中，选取一个最短路长度最小的结点，移到 S 集合中。
// 如何选取也就是不同实现的区别！！
// 2.对那些刚刚被加入 S 集合的结点的所有出边执行松弛操作。
// 松弛操作就是dist[v] = min(dist[v], dist[u] + w)
// 直到 T 集合为空，算法结束。

// 堆优化版本通过使用优先队列来更有效地选择下一个要处理的顶点，从而提高了算法的效率。
// 暴力搜索的时间复杂度是 O(V^2)，其中 V 是顶点数。
// 堆优化实现的时间复杂度是 O((V+E)log V)，其中 V 是顶点数，E 是边数。
// 适用性：两种实现都适用于非负权边的图。
// 对于稠密图，普通版本可能更有优势；对于稀疏图，堆优化版本通常更快
// 题目链接：https://kamacoder.com/problempage.php?pid=1047


struct edge {
    int v, w;

    bool operator>(const edge& other) const {
        return w > other.w;
    }
};

int V, E;
vector<vector<edge>> graph; //邻接表
vector<int> dist;
vector<int> visited;

// 暴力搜索，每次遍历所有节点，找到dist最小的进行处理
void Dijkstra(int s) {
    dist.resize(V + 1, INT_MAX);
    dist[s] = 0;
    for (int i = 1; i <= V; ++i) {
        int u = 0;
        int min_dist = INT_MAX;
        // 暴力搜索O(V)找到最小距离值
        for (int j = 1; j <= V; ++j) {
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }
        visited[u] = true;
        // 寻找u的邻边v，更新dist[v]
        for (auto& [v, w] : graph[u]) {
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
}

// 单调队列优化，堆顶的就是每次最小的dist节点！
void Dijkstra_priority_queue(int s) {
    dist.resize(V + 1, INT_MAX);
    dist[s] = 0;
    priority_queue<edge, vector<edge>, greater<>> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;

        for (auto& [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    cin >> V >> E;
    graph.resize(V + 1, vector<edge>());
    // visited.resize(V + 1, false);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    // Dijkstra(1);
    Dijkstra_priority_queue(1);

    if (dist[V] == INT_MAX) {
        cout << "-1\n";
    } else {
        cout << dist[V] << '\n';
    }
    return 0;
}