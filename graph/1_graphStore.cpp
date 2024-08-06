//
// Created by jacky on 24-8-5.
//
#include <bits/stdc++.h>
using namespace std;

// 邻接表， 内层维度只存储与自身节点相连接的节点
vector<vector<int>> graph_list;
// 邻接矩阵，包含所有节点直接的关系，如果对应数组值不为0,则说明存在边
vector<vector<int>> graph_matrix;

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

int main() {
    praseInputConstructGraph(false);
    printGraph();
    return 0;
}