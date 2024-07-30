//
// Created by jacky on 24-7-30.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> findNextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }

    return result;
}

vector<int> findNextSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() >= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }

    return result;
}

vector<int> findNextGreaterMin(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    set<int> s;

    for (int i = n - 1; i >= 0; --i) {
        auto it = s.upper_bound(nums[i]);
        if (it != s.end()) {
            result[i] = *it;
        }
        s.insert(nums[i]);
    }

    return result;
}

vector<int> findNextSmallerMax(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    set<int, greater<int>> s; // set with greater<int> comparator

    for (int i = n - 1; i >= 0; --i) {
        auto it = s.upper_bound(nums[i]);
        if (it != s.end()) {
            result[i] = *it;
        }
        s.insert(nums[i]);
    }

    return result;
}

void print(vector<int> arr) {
    for_each(arr.begin(), arr.end(), [](const int x) { cout << x << " "; });
    cout << endl;
}

int main() {
    vector<int> nums = {2, 1, 3, 5, 4, 3, 7, 1, 2};
    // the next greater num
    print(findNextGreater(nums));
    // the next min greater num
    print(findNextGreaterMin(nums));
    // the next smaller num
    print(findNextSmaller(nums));
    // the next max smaller num
    print(findNextSmallerMax(nums));
    return 0;
}