//
// Created by jacky on 24-8-8.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1152
// 单源含负权值的最短路径！
// bellman-ford算法
// 本质还是和dijkstra一样的松弛操作，不断去更新dist[v] = min(dist[v], dist[u] + w)
// 这么做的含义是显然的：我们尝试用 S --> u --> v（其中 S --> u 的路径取最短路）
// 这条路径去更新 v 点最短路的长度，如果这条路径更优，就进行更新。
// Bellman–Ford 算法所做的，就是不断尝试对图上每一条边进行松弛。
// 我们每进行一轮循环，就对图上所有的边都尝试进行一次松弛操作，当一次循环中没有成功的松弛操作时，算法停止。
// 每次循环是 O(m) 的，那么最多会循环多少次呢？
//
// 在最短路存在的情况下，由于一次松弛操作会使最短路的边数至少 +1，
// 而最短路的边数最多为 n-1，因此整个算法最多执行 n-1 轮松弛操作。故总时间复杂度为 O(nm)。
//
// 但还有一种情况，如果从 S 点出发，抵达一个负环时，松弛操作会无休止地进行下去。
// 对于最短路存在的图，松弛操作最多只会执行 n-1 轮，
// 因此如果第 n 轮循环时仍然存在能松弛的边，说明从 S 点出发，能够抵达一个负环。

struct edge {
    int u, v, w;
};

int V, E;
vector<edge> graph;
vector<int> dist;

// bool值用于判断是否抵达一个负环
// 需要注意的是，如果返回false,不代表整个图不存在负环
// 只是说明从s点出发，不存在负环！
bool BellmanFord(int s) {
    dist.resize(V + 1, INT_MAX);
    dist[s] = 0;
    bool flag = false; // 判断本次循环中是否发生松弛操作
    // 最短路最多只需要n-1次，第n次用于判断负环的存在
    for (int i = 0; i < V; ++i) {
        flag = false;
        // 遍历所有边，寻找松弛操作
        for (int j = 0; j < E; ++j) {
            auto [u, v, w] = graph[j];
            // 已经是最大值，必定无法松弛
            if (dist[u] == INT_MAX)
                continue;;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                flag = true;
            }
        }

        // 没有松弛操作，算法终止
        if (!flag) {
            break;
        }
    }

    // 为true,说明n次循环仍有松弛操作，则存在负环
    return flag;
}


int main() {
    cin >> V >> E;
    graph.resize(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i] = {u, v, w};
    }

    bool flag = BellmanFord(1);
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