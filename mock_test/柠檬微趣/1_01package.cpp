//
// Created by jacky on 24-7-30.
//
#include <bits/stdc++.h>
using namespace std;

int findTargetWays(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (auto num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << findTargetWays(nums, target) << endl;
    return 0;
}