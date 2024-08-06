//
// Created by jacky on 24-8-5.
//
#include <bits/stdc++.h>
using namespace std;

// 邻接表， 内层维度只存储与自身节点相连接的节点
vector<vector<int>> graph_list;
// 邻接矩阵，包含所有节点直接的关系，如果对应数组值不为0,则说明存在边
vector<vector<int>> graph_matrix;
// 搜索过程中，需要记录节点是否访问过，来防止重复遍历
// 这也是我们回溯的重要依据
vector<bool> visited;

void praseInputConstructGraph(bool directed);
void printGraph();
void resetVisited();


// 打印一条dfs路径,u --> v
// 邻接表递归实现
void dfsGraphList(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v : graph_list[u]) {
        if (!visited[v]) {
            dfsGraphList(v);
        }
    }
}

// 邻接表使用stack实现
void dfsGraphList2(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while (!st.empty()) {
        int u = st.top();
        cout << u << " ";
        st.pop();
        for (int v : graph_list[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

// 递归，邻接矩阵
void dfsGraphMatrix(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v = 1; v < graph_matrix.size(); v++) {
        if (graph_matrix[u][v] == 1 && !visited[v]) {
            dfsGraphMatrix(v);
        }
    }
}

void dfsGraphMatrix2(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";

        for (int v = 1; v < graph_matrix.size(); v++) {
            if (graph_matrix[u][v] == 1 && !visited[v]) {
                st.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    praseInputConstructGraph(true);
    printGraph();
    // 从节点1开始遍历
    dfsGraphList(1);
    cout << "\n------------------------\n";
    // 重置访问状态
    resetVisited();
    dfsGraphList2(1);
    cout << "\n------------------------\n";

    resetVisited();
    dfsGraphMatrix(1);
    cout << "\n------------------------\n";

    resetVisited();
    dfsGraphMatrix2(1);
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