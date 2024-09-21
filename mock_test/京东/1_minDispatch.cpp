//
// Created by jacky on 24-9-21.
//
#include <bits/stdc++.h>
using namespace std;

void sol1() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto isValid = [&](int j, int i) -> bool {
        return *max_element(a.begin() + j, a.begin() + i) -
               *min_element(a.begin() + j, a.begin() + i) <= k;
    };
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] != INT_MAX) {
                if (isValid(j, i))
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[n] << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 1;
    int cur_min = a[0];
    int cur_max = a[0];
    for (int i = 1; i < n; ++i) {
        cur_min = min(cur_min, a[i]);
        cur_max = max(cur_max, a[i]);
        if (cur_max - cur_min > k) {
            res++;
            cur_min = a[i];
            cur_max = a[i];
        }
    }
    cout << res << endl;
    return 0;
}