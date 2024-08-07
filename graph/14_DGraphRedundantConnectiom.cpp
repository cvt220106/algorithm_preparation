//
// Created by jacky on 24-8-7.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1182
// 相较于上题，是一个有向图的冗余连接
// 这时候就不能简单的直接使用连通性来判断是否冗余了
// 对于一个有向树，有以下性质
// 1.根节点的入度一定为0
// 2.其他节点的入度一定为1
// 因此出现入度为2的节点，那么一定它相连的某一条边就是我们的删除对象
// 具体删除哪一条，1.取决于删除后是否为有向树，2.若删除后都是，则优先选择后出现的
// 如果没有入度为2的几点，便出现成环的情况，此时所有节点的入度都为1，我们就只需要删除环内的一条边即可
// 明确这些目标后，那如何判断删除后是不是有向树了
// 这时候并查集的作用就有出现了
// 删除后，判断当前其他边加入并查集时，会不会出现相同节点已经在同一个集合的情况
// 如果出现了，就说明当前存在环，这不是一个合格的有向树！

class dsu {
    vector<int> pa, pa_size;

public:
    dsu(int _size) : pa(_size + 1), pa_size(_size + 1, 1) {
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    int isSame(int x, int y) {
        return find(x) == find(y);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (pa_size[x] < pa_size[y])
            swap(x, y);
        pa[y] = x;
        pa_size[x] += pa_size[y];
    }
};

vector<vector<int>> edges;

// 判断删除一边入度为2节点相连的边后，是否构成有向树
bool isDirectedGraph(int delete_edge) {
    int n = edges.size();
    dsu s(n);
    for (int i = 0; i < n; i++) {
        if (i == delete_edge)
            continue;
        if (s.isSame(edges[i][0], edges[i][1])) {
            // 构成环，非有向树，直接返回false
            return false;
        }
        s.unite(edges[i][0], edges[i][1]);
    }
    return true;
}

// 判断导致构成环的那条边，边输出
void getRemoveEdge() {
    int n = edges.size();
    dsu s(n);
    for (int i = 0; i < n; i++) {
        if (s.isSame(edges[i][0], edges[i][1])) {
            // 构成环，非有向树，删除该边，输出返回
            cout << edges[i][0] << " " << edges[i][1] << '\n';
            return;
        }
        s.unite(edges[i][0], edges[i][1]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        indegree[v]++;
    }

    vector<int> v; // 寻找入度为2的节点相关的边
    // 因为优先输出后出现的边，因此反向遍历插入
    for (int i = n - 1; i >= 0; --i) {
        if (indegree[edges[i][1]] == 2) {
            v.push_back(i);
        }
    }

    // 存在入度为2的节点，尝试删除其的两边之一
    if (v.size() > 0) {
        // 优先删除后出现的
        if (isDirectedGraph(v[0])) {
            cout << edges[v[0]][0] << " " << edges[v[0]][1] << '\n';
        } else {
            cout << edges[v[1]][0] << " " << edges[v[1]][1] << '\n';
        }
    } else {
        // 不存在入度为2的节点，说明成环了，直接并查集查找环出现的第一条边
        getRemoveEdge();
    }

    return 0;
}