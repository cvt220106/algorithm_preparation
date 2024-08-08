//
// Created by jacky on 24-8-8.
//
#include <bits/stdc++.h>
using namespace std;

// floyd 算法
// 用于解决多源节点直接的最短路径问题
// 边权值，正负均不影响
// 并且可以检测回路，正负权值同样不影响

// floyd的本质就是一个动态规划
// 不断对比以当前k作为中间节点时，dis[i][j]与dis[i][k] + dis[k][j]之间的距离关系
// 找出最小的那个进行更新，这样最终就能得到所有i到j节点的最短路径dis[i][j]
// 题目链接：https://kamacoder.com/problempage.php?pid=1155

int V, E;
vector<vector<int>> graph;
// floyd算法
void floyd(vector<vector<int>>& dist) {
    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// floyd寻找最小权值和的环
// dist为floyd处理后的结果！
int findMinWeightCycle(vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;
    floyd(dist);
    int min_cycle = INT_MIN;

    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = i + 1; j <= V; ++j) {
                if (i != k && j != k && graph[i][k] < INT_MAX && graph[k][j] <
                    INT_MAX) {
                    int cycle_weight = dist[i][j] + graph[i][k] + graph[k][j];
                    min_cycle = min(min_cycle, cycle_weight);
                }
            }
        }
    }

    return min_cycle == INT_MIN ? -1 : min_cycle;
}

int main() {

    cin >> V >> E;
    graph.resize(V + 1, vector<int>(V + 1, INT_MAX)); // floyd算法使用邻接矩阵存储
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // floyd算法
    vector<vector<int>> dist = graph;
    floyd(dist);

    int n;
    cin >> n;
    while (n--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] != INT_MAX)
            cout << dist[u][v] << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}