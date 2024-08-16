//
// Created by jacky on 24-8-10.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, x;

ll getMinDeleteCost(vector<int>& nums) {
    ll mex = -1;
    multiset<int> s(nums.begin(), nums.end());
    for (int i = 0; i <= n; i++) {
        if (s.count(i) == 0) {
            mex = i;
            break;
        }
    }
    if (mex == -1) {
        mex = n + 1;
    }

    ll min_cost = mex * k;
    for (int i = 0; i < n; i++) {
        s.erase(s.find(nums[i]));
        if (nums[i] < mex && s.count(nums[i]) == 0) {
            mex = nums[i];
        }
        ll cur_cost = x * (i + 1) + mex * k;
        min_cost = min(min_cost, cur_cost);
    }
    return min_cost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << getMinDeleteCost(nums) << '\n';
    }

    return 0;
}