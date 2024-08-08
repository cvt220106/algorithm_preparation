//
// Created by jacky on 24-8-7.
//
#include <bits/stdc++.h>
using namespace std;
// 题目链接：https://kamacoder.com/problempage.php?pid=1053
// 前置知识
// 生成树：
// 生成树是图的一个子图，它包含图中的所有顶点，并形成一棵树（没有环路的连通图）。
// 对于一个有n个顶点的图，其生成树总是有n-1条边。
//
// 最小生成树（Minimum Spanning Tree, MST）：
// 最小生成树是一个带权无向图所有生成树中权值和最小的生成树。
// 如果图中的边具有权重，最小生成树就是使所包含边的权重总和最小的生成树。
//
// Kruskal算法：
// Kruskal算法的基本思想是按照边的权重从小到大的顺序选择边，同时避免形成环。
//
// 步骤：
// a) 将图中所有边按权重从小到大排序。
// b) 从权重最小的边开始，如果这条边连接的两个顶点不在同一个连通分量中，就选择这条边。
// c) 重复步骤b，直到选择了n-1条边（n为顶点数）。
//
// 实现细节：
// 使用并查集数据结构来检测和避免环的形成。
// 时间复杂度：O(E log E)，其中E是边的数量。排序边需要O(E log E)时间，而并查集操作接近O(1)。

// 并查集
vector<int> pa, pa_size;

int find(int x) {
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}

bool isSame(int x, int y) {
    return find(x) == find(y);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (pa_size[x] < pa_size[y])
        swap(x, y);
    pa[y] = x;
    pa_size[x] += pa_size[y];
}

struct edge {
    // 边两端顶点与边权存储
    int u, v, w;

    bool operator<(const edge& other) const {
        return w < other.w;
    }
};

int V, E; // 顶点与边的个数
vector<edge> graph;

pair<int, vector<edge>> Kruskal() {
    // 按照边权从小到大排列
    sort(graph.begin(), graph.end());
    vector<edge> mst;
    int mst_weight = 0;

    for (auto& [u, v, w] : graph) {
        // 判断当前是否在同一个树中
        if (!isSame(u, v)) {
            join(u, v);
            mst.push_back({u, v, w});
            mst_weight += w;
            if (mst.size() == V - 1) {
                // 最小生成树的边数等于顶点数 - 1
                break;
            }
        }
    }

    return {mst_weight, mst};
}

void printMST(vector<edge>& mst) {
    for (auto& [u ,v, _] : mst) {
        cout << u << "-->" << v << '\n';
    }
}

int main() {
    cin >> V >> E;
    // 初始化全局变量！
    pa.resize(V + 1);
    iota(pa.begin(), pa.end(), 0);
    pa_size.resize(V + 1, 1);
    graph.resize(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    auto [mst_weight, mst] = Kruskal();
    cout << mst_weight << '\n';
    // 如果需要打印最生成树的边，kruskal也同样保存了相关信息！
    printMST(mst);
    return 0;
}
