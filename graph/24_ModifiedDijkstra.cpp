//
// Created by jackyYoung on 24-9-16.
//
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = INT_MAX;

struct Edge {
    int v, weight;
};

struct Node {
    int id, max_weight, min_weight;
    double ratio;

    bool operator>(Node& other) {
        return ratio > other.ratio; // 用于小根堆优先队列
    }
};

Node modifiedDijkstra(vector<vector<Edge>>& graph, int st, int dst) {
    int n = graph.size();
    vector<double> min_ratios(n, INF);
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({st, 0, INF, 0.0});
    min_ratios[st] = 0.0;

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if (cur.id == dst) {
            return cur;
        }
        if (cur.ratio > min_ratios[cur.id]) continue;

        for (auto &[v, weight] : graph[cur.id]) {
            int new_max_weight = max(weight, cur.max_weight);
            int new_min_weight = min(weight, cur.min_weight);
            double new_ratio = 1.0 * new_max_weight / new_min_weight;
            if (new_ratio < min_ratios[v]) {
                min_ratios[v] = new_ratio;
                pq.push({v, new_max_weight, new_min_weight, new_ratio});
            }
        }
    }

    // 没找到
    return {0, 0, INF, INF};
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, st, dst;
        cin >> n >> m >> st >> dst;
        vector<vector<Edge>> graph(n + 1);
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        auto res = modifiedDijkstra(graph, st, dst);

        function<int(int, int)> gcd = [&](int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        };

        if (res.ratio == INF) {
            cout << "%%%%" << endl;
        } else {
            int g = gcd(res.max_weight, res.min_weight);
            if (g == res.min_weight) {
                cout << res.max_weight / g << endl;
            } else {
                cout << to_string(res.max_weight / g) + "/" + to_string(res.min_weight / g) << endl;
            }
        }
    }
    return 0;
}

