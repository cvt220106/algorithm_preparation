//
// Created by jacky on 24-9-21.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<unordered_set<int>> tree(n + 1);
    vector<int> values(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }
    function<void(int)> build = [&](int u) {
        for (int v : tree[u]) {
            tree[v].erase(tree[v].find(u));
            build(v);
        }
    };
    build(1);
    int ans = 0;
    function<unordered_map<int, int>(int)> dfs = [&
        ](int u) -> unordered_map<int, int> {
        unordered_map<int, int> res;
        res[values[u]]++;
        for (int v : tree[u]) {
            for (auto& [k, v] : dfs(v)) {
                res[k] += v;
            }
        }
        int max_v = 0;
        for (auto& [_, v] : res) {
            max_v = max(max_v, v);
        }
        int cur_ans = 0;
        for (auto& [k, v] : res) {
            if (v == max_v)
                continue;
            if (v % 2) {
                cur_ans ^= k;
            }
        }
        ans = max(cur_ans, ans);
        return res;
    };
    dfs(1);
    cout << ans << endl;
    return 0;
}