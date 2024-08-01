//
// Created by jacky on 24-7-29.
//
#include <bits/stdc++.h>
using namespace std;
#define MAXN (10000 + 5)
int d[MAXN];
int x[MAXN], y[MAXN];

class Solution {
public:
    // 记忆化搜索，但在第85测例10^6大小下会超时
    int dp(int c, int n) {
        if (d[c] != -1) {
            return d[c];
        }
        d[c] = 1;
        for (int i = 0; i < n; i++) {
            if (x[i] > x[c] && y[i] > y[c]) {
                d[c] = max(d[c], dp(i, n) + 1);
            }
        }
        return d[c];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        for (int i = 0; i < n; i++) {
            d[i] = -1;
            x[i] = envelopes[i][0];
            y[i] = envelopes[i][1];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp(i, n));
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 通过排序，将问题转化为最长递增子序列问题
        // 排序规则，宽度升序，高度降序
        // 高度降序是为了避免宽度相同的信封被重复选取
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        };
        sort(envelopes.begin(), envelopes.end(), compare);

        // 二分查找
        int dp[n + 5];
        fill(dp, dp + n + 5, INT_MAX);
        int mx = dp[0];
        for (auto ev : envelopes) {
            *lower_bound(dp, dp + n, ev[1]) = ev[1];
        }

        int res = 0;
        while (mx != dp[res]) {
            res++;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> e = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    Solution sol;
    cout << sol.maxEnvelopes(e) << endl;
    cout << Solution2().maxEnvelopes(e) << endl;
    return 0;
}