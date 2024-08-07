//
// Created by jacky on 24-8-7.
//
#include <bits/stdc++.h>
using namespace std;

// 前置知识点
// AOE网（Activity On Edge Network）：
// 用边表示活动，用顶点表示事件的有向图。
// 边的权重通常表示活动持续时间。
// 关键路径：
// 在AOE网中，从起点到终点的最长路径。
// 关键路径上的活动称为关键活动，决定了整个工程的完成时间。

// 求取关键路径的步骤：
// a. 计算每个事件的最早发生时间（正向遍历）：
// ve[i] = max{ve[j] + weight(j,i)}，其中j是i的前驱
// b. 计算每个事件的最晚发生时间（反向遍历）：
// vl[i] = min{vl[j] - weight(i,j)}，其中j是i的后继
// c. 计算每个活动的最早开始时间e和最晚开始时间l：
// e[i] = ve[start of activity i]
// l[i] = vl[end of activity i] - duration of activity i
// d. 计算每个活动的时间余量：
// slack = l[i] - e[i]
// e. 时间余量为0的活动构成关键路径。

// example 结点事件1--7,起点事件1,终点事件6
// 其中边活动对应权值为
// 1 --w = 3--> 2
// 2 --w = 4--> 3
// 3 --w = 5--> 4
// 3 --w = 5--> 5
// 4 --w = 3--> 5
// 5 --w = 4--> 6
// 2 --w = 4--> 7
// 拓扑排序可能执行顺序 1, 2, 3, 7, 4, 5, 6
// 关键路径1--> 2 --> 3 --> 5 --> 6

struct edge {
    int v, w;
};

int V; // 节点个数
vector<vector<edge>> graph; // 邻接表，存储相邻节点，以及边的权值
vector<int> indegree;

vector<int> TopologicalSort() {
    vector<int> in_degree = indegree;
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= V; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (auto& [v, _] : graph[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    return result;
}

// 计算每个事件最早发生时间数组ve
// 事件最晚发生时间数组vl
pair<vector<int>, vector<int>> CriticalPath() {
    vector<int> ve(V + 1, 0); // 最早发生时间
    vector<int> vl(V + 1, INT_MAX); // 最晚发生时间

    // 计算最早发生时间
    // 使用拓扑排序获取事件的只能执行顺序
    vector<int> topo = TopologicalSort();
    for (int u : topo) {
        for (auto& [v, w] : graph[u]) {
            ve[v] = max(ve[v], ve[u] + w);
        }
    }

    // 计算最晚发生事件，反向遍历！
    vl[topo.back()] = ve[topo.back()]; // 终点结束事件时间一致
    for (int i = topo.size() - 2; i >= 0; --i) {
        int u = topo[i];
        for (auto& [v, w] : graph[u]) {
            vl[u] = min(vl[u], vl[v] - w);
        }
    }
    return {ve, vl};
}

void PrintCriticalActivities() {
    auto [ve, vl] = CriticalPath();
    cout << "Critical activities:" << endl;
    for (int u = 1; u <= V; u++) {
        for (auto& [v, weight] : graph[u]) {
            int e = ve[u];
            int l = vl[v] - weight;
            if (e == l) {
                cout << u << " -> " << v << endl;
            }
        }
    }
}

int main() {
    V = 7;
    graph.resize(V + 1, vector<edge>());
    indegree.resize(V + 1, 0);
    // u, v, w顺序输入
    vector<tuple<int, int, int>> example = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5},
                                            {3, 5, 5},
                                            {4, 6, 3}, {5, 6, 4}, {2, 7, 4}};
    // 构建AOE网
    for (auto& [u, v, w] : example) {
        graph[u].push_back({v, w});
        indegree[v]++;
    }

    // 打印topo排序可能执行路径
    cout << "Topological order: ";
    for (int v : TopologicalSort()) {
        cout << v << " ";
    }
    cout << endl;
    // 打印关键路径
    PrintCriticalActivities();
}