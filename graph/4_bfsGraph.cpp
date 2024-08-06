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
void restorePath(int x);


// 打印一条dfs路径,u --> v
// 邻接表、使用栈模拟
void bfsGraphList(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int v : graph_list[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

void bfsGraphMatrix(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int v = 1; v < graph_matrix.size(); v++) {
            if (graph_matrix[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

// 实际上在bfs过程中，我们还可以记录从出发节点到当前节点的最短距离与具体最短路径
// 以邻接表为例子
vector<int> d; // 记录从起点到当前点的最短距离
vector<int> path; // 记录从哪个节点走到当前节点的
void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    d[s] = 0;
    path[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph_list[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                d[v] = d[u] + 1;
                path[v] = u;
            }
        }
    }
}

int main() {
    praseInputConstructGraph(true);
    printGraph();
    // 从节点1开始遍历
    bfsGraphList(1);
    cout << "\n------------------------\n";;

    resetVisited();
    bfsGraphMatrix(1);
    cout << "\n------------------------\n";

    resetVisited();
    bfs(1);
    // 打印距离
    for (int i = 1; i < graph_list.size(); i++) {
        cout << "1 to " << i << " min distance = " << d[i] << '\n';
        cout << "the min distance path is: ";
        restorePath(i);
        cout << '\n';
    }
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

    d.resize(n + 1, -1);
    path.resize(n + 1, -1);
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

void restorePath(int x) {
    vector<int> res;
    for (int v = x; v != -1; v = path[v]) {
        // 反向搜寻
        res.push_back(v);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        if (i == 0) {
            cout << res[i];
        } else {
            cout << "-->" << res[i];
        }
    }
}
