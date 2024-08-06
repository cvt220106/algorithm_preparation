//
// Created by jacky on 24-8-3.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define Niu(X) X * X

ll maxValue(vector<ll>& nums, ll n) {
    ll res = nums[0] * nums[1];
    if (n == 3) {
        res = max({res, nums[0] * nums[2], nums[1] * nums[2]});
    } else if (n > 3) {
        for (ll i = 1; i < n - 1; i++) {
            res = max({res, nums[i - 1] * nums[i], nums[i - 1] * nums[i + 1]});
        }
        res = max(res, nums[n - 2] * nums[n - 1]);
    }

    return res;
}

ll main() {
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll res = maxValue(nums, n);

    cout << res << '\n';
    return 0;
}