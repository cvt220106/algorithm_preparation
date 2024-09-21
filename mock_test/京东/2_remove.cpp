//
// Created by jacky on 24-9-21.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        s[i] = v[i].second;
    }
    vector<int> dp(n + 1, INT_MAX);
    for (int num : s) {
        *upper_bound(dp.begin(), dp.end(), num) = num;
    }
    int cnt = 0;
    while (dp[cnt] != INT_MAX) {
        cnt++;
    }
    cout << n - cnt << endl;
    return 0;
}