//
// Created by jacky on 24-8-3.
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mutex_map;
vector<int> values(20);
vector<int> weights(20);

int backtracking(int value, int weight, vector<int>& path, int n, int m,
                 int start_index) {
    int max_value = value;
    for (int i = start_index; i <= n; i++) {
        if (weight + weights[i] > m) {
            continue;
        }
        bool is_mutex = false;
        for (auto t : path) {
            if (mutex_map[t][i] || mutex_map[i][t]) {
                is_mutex = true;
                break;
            }
        }
        if (is_mutex) {
            continue;
        }
        path.push_back(i);
        max_value = max(max_value,
                        backtracking(value + values[i], weight + weights[i],
                                     path, n, m, i + 1));
        path.pop_back();
    }

    return max_value;
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> weights[i + 1] >> values[i + 1];
    }
    mutex_map.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        mutex_map[a][b] = 1;
        mutex_map[b][a] = 1;
    }
    vector<int> path;
    int res = backtracking(0, 0, path, n, m, 1);
    cout << res << endl;
    return 0;
}