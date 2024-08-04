//
// Created by jackyYoung on 24-8-3.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 10;
vector<vector<int>> tree(N, vector<int>());
using ll = long long;
vector<ll> sum(N), v(N), d(N), f(N);

vector<ll> dfs(int node, int parent, int depth) {
    d[node] = depth;
    sum[node] += v[node];
    f[node] += d[node] * sum[node];
    for (auto &child : tree[node]) {
        if (child == parent) {
            continue;
        }
        auto t = dfs(child, node, depth + 1);
        sum[node] += t[0];
        f[node] += t[1];
    }

    return {sum[node], f[node]};
}

int main() {
    int n;
    cin >> n;
    // root从1开始
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0, 1);

    // 初始的总权值
    ll res = f[1];
    for (int i = 2; i <= n; i++) {
        if (d[i] <= 2) continue;
        ll change = (d[i] - 2) * sum[i];
        res = min(res, f[1] - change);
    }
    cout << res << endl;
    return 0;
}