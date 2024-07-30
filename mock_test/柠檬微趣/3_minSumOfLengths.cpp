//
// Created by jacky on 24-7-30.
//
#include <bits/stdc++.h>
using namespace std;

int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();
    int l = 0, r;
    int sum = 0;
    int min_sum_len = INT_MAX;
    vector<int> dp(n + 1, 0);
    // dp[i]表示前i个元素中，满足和为target的最短子数组的长度
    dp[0] = n + 1;
    for (r = 0; r < n; r++) {
        sum += arr[r];

        while (sum > target) {
            sum -= arr[l++];
        }

        if (sum == target) {
            int len = r - l + 1;
            min_sum_len = min(min_sum_len, len + dp[l]);
            dp[r + 1] = min(dp[r], len);
        } else {
            dp[r + 1] = dp[r];
        }
    }

    return min_sum_len > n ? -1 : min_sum_len;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << minSumOfLengths(nums, target) << endl;
    return 0;
}