//
// Created by jackyYoung on 24-7-28.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> parseInput(const string& input) {
    vector<int> arr;
    string arr_list = input.substr(1, input.size() - 2);
    stringstream ss(arr_list);
    string num;
    while (getline(ss, num, ',')) {
        arr.push_back(stoi(num));
    }

    return arr;
}

int longestIncSubseq(vector<int>& arr) {
    int n = arr.size();
    int result = 1;
    // dp[i]表示以第i个元素为结尾的序列中最长子序列的长度。
    // 初始化，dp[i] = 1，每个元素自身就是满足的序列
    // 递推关系，如果arr[i] > arr[j] dp[i] = dp[j] + 1
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 保存当前最大递增序列长度
        result = max(result, dp[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    std::cin.ignore(); // 忽略换行符
    while (n--) {
        string input;
        getline(cin, input);
        vector<int> arr = parseInput(input);
        cout << longestIncSubseq(arr) << endl;
    }
    return 0;
}