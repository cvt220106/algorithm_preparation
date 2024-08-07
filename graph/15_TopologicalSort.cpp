//
// Created by jacky on 24-8-7.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1191
// AOV网（Activity On Vertex Network）：
// 用顶点表示活动，用边表示活动之间的优先关系的有向图。
// 边<A, B> 表示活动A必须在活动B之前完成。

// 拓扑排序，用于解决有向无环图中，V用于表示活动，E中的有向性表示活动之间的优先关系
// 拓扑排序中给出的序列，就是能够满足所有优先关系的活动顺序，但其并不唯一！

// 本质上就是不断遍历入度为0的节点，直接队列为空
// 每次从队列中取出入度为0的节点时，删除其相关联的出边，对应的连接节点入度减少
// 若对应节点的入度减少到0,将其加入队列
// 最终队列为空，所有节点均被输出，拓扑排序完成
// 反之则说明队列存在环，因此拓扑排序也能用作判断有向图是否存在环！

vector<vector<int>> graph; // 邻接表
vector<int> indegree; // 入度表

vector<int> TopologicalSort() {
    vector<int> result;
    queue<int> q; // 入度为0的节点队列

    // 先收集原始图中所有入度为0的节点
    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return result;
}

int main() {
    int n, m; // n个结点，m条边
    cin >> n >> m;
    graph.resize(n, vector<int>());
    indegree.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        // 有向图！
        graph[u].push_back(v);
        indegree[v]++;
    }

    vector<int> result = TopologicalSort();
    if (result.size() != n) {
        // 排序节点数不等于图中节点数，说明存在环！！！
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i == n - 1)
            cout << result[i] << '\n';
        else
            cout << result[i] << " ";
    }

    return 0;
}