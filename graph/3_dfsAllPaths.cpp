//
// Created by jacky on 24-8-5.
//
// 题目链接： https://kamacoder.com/problempage.php?pid=1170
#include <bits/stdc++.h>
using namespace std;

// 邻接表， 内层维度只存储与自身节点相连接的节点
vector<vector<int>> graph_list;
// 邻接矩阵，包含所有节点直接的关系，如果对应数组值不为0,则说明存在边
vector<vector<int>> graph_matrix;
// 搜索过程中，需要记录节点是否访问过，来防止重复遍历
// 这也是我们回溯的重要依据
vector<bool> visited;

vector<string> result;

// 邻接表
void dfs(int n, string path, int u) {
    if (u == n) {
        result.push_back(path);
        return;
    }

    for (int v : graph_list[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(n, path + " " + to_string(v), v);
            visited[v] = false;
        }
    }
}

// 邻接矩阵
void dfs2(int n, string path, int u) {
    if (u == n) {
        result.push_back(path);
        return;
    }

    for (int v = 1; v < graph_matrix.size(); v++) {
        if (graph_matrix[u][v] == 1 && !visited[v]) {
            visited[v] = true;
            dfs(n, path + " " + to_string(v), v);
            visited[v] = false;
        }
    }
}

void praseInputConstructGraph(bool directed);
void printGraph();
void resetVisited();


int main() {
    praseInputConstructGraph(true);
    printGraph();
    // 寻找从节点1到节点n的所有可能路径
    visited[1] = true;
    dfs2(graph_list.size() - 1, to_string(1), 1);
    if (result.empty())
        cout << -1 << '\n';
    else
        for_each(result.begin(), result.end(),
                 [](string& s) { cout << s << '\n'; });

    return 0;
}

void printGraph() {
    // 遍历邻接表
    for (int i = 1; i < graph_list.size(); i++) {
        if (!graph_list[i].empty()) {
            cout << i << " --> " << "[";
            for (int j = 0; j < graph_list[i].size(); j++) {
                if (j == 0) {
                    cout << graph_list[i][j];
                } else {
                    cout << ", " << graph_list[i][j];
                }
            }
            cout << "]\n";
        }
    }

    cout << "--------------------" << endl;

    // 遍历邻接矩阵
    for (int i = 1; i < graph_matrix.size(); i++) {
        bool empty = true;
        for (int j = 1; j < graph_matrix.size(); j++) {
            if (empty && graph_matrix[i][j] == 1) {
                empty = false;
                cout << i << " --> " << "[";
                cout << j;
            } else if (graph_matrix[i][j] == 1) {
                cout << ", " << j;
            }
        }
        if (!empty) {
            cout << "]\n";
        }
    }
}

void praseInputConstructGraph(bool directed) {
    // n个节点，m条边， 不会存在重边！
    int n, m;
    cin >> n >> m;
    graph_list.resize(n + 1);
    graph_matrix.resize(n + 1, vector<int>(n + 1, 0));
    visited.resize(n + 1, false);
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (directed) {
            // 有向图，邻接表
            graph_list[a].push_back(b);
            // 有向图，邻接矩阵
            graph_matrix[a][b] = 1;
        } else {
            // 无向图，邻接表
            graph_list[a].push_back(b);
            graph_list[b].push_back(a);
            // 无向图，邻接矩阵
            graph_matrix[a][b] = 1;
            graph_matrix[b][a] = 1;
        }
    }
}

void resetVisited() {
    for (int i = 1; i < visited.size(); i++) {
        visited[i] = false;
    }
}