//
// Created by jackyYoung on 24-7-28.
//
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// mod下的pow方法
long long myTwoPow(int b) {
    long long res = 1;
    for (int i = 0; i < b; i++) {
        res = res * 2 % MOD;
    }
    return res;
}

int kCharInSubseq(const string& s, int k) {
    // 抽象背包问题，物品是不同的字符，因此需要先对所有字符统计个数
    // k是背包大小，表示背包中不同字符的个数
    // dp[j]就是j大小的背包时的子序列个数
    // 对于一个出现m次的字符，加入到子序列中存在选1个到m个
    // 对于每个字符都存在选或不选两种可能，也就是2^m种，排除掉全不选的一种情况，最终就是2^m- 1种
    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    vector<long long> v(26, 0);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) {
            v[i] = myTwoPow(cnt[i]) - 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = k; j > 0; j--) {
            dp[j] = (dp[j] + dp[j - 1] * v[i]) % MOD;
        }
    }

    return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << kCharInSubseq(s, k) << endl;
    return 0;
}