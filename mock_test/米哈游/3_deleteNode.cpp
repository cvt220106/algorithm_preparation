//
// Created by jacky on 24-8-3.
//
/**
*3
4 2
1 2
1 3
1 4
3 4
5 2
1 2
1 3
1 4
3 4
2 5
3 1
1 2
1 3
2 3

Xiaoyo
Pyrmont
Draw
*/
#include <bits/stdc++.h>
using namespace std;

string competition(vector<vector<int>>& graph, vector<int>& indegree, int n,
                   int x) {
    if (indegree[x] == 1) {
        return "Xiaoyo";
    }
    string res;

    // 记录所有初始可能走到的度为1的节点个数
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 1) {
            q.push(i);
        }
    }

    int cnt = 0;
    bool flag = false;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;
        if (node == x) {
            flag = true;
            continue;
        }
        for (int next : graph[node]) {
            indegree[next]--;
            if (indegree[next] == 1) {
                q.push(next);
            }
        }
    }

    if (flag) {
        if (cnt % 2 == 0) {
            res = "Pyrmont";
        } else {
            res = "Xiaoyo";
        }
    } else {
        res = "Draw";
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<int> indegree(n + 1);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }
        cout << competition(graph, indegree, n, x) << endl;
    }

    return 0;
}