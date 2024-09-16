//
// Created by jackyYoung on 24-8-4.
//

class SingleTon {
private:
    SingleTon() {}
    ~SingleTon() = default;
public:
    SingleTon(SingleTon &other) = delete;
    SingleTon& operator=(SingleTon &other) = delete;
    SingleTon(SingleTon &&other) = delete;
    SingleTon& operator=(SingleTon &&other) = delete;

    static SingleTon& getInstance() {
        static SingleTon instance;
        return instance;
    }
};
#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

// MOD下a的乘法逆元，使用快速幂计算
int64_t reverseInt(int64_t a) {
    int64_t b = MOD - 2;
    int64_t res = 1;
    a %= MOD;
    for (; b > 0; b >>= 1) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

int main() {
    auto begin = chrono::system_clock::now();
    int n;
    string s;
    cin >> n >> s;
    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    vector<int64_t> fab(10005, 1);
    for (int i = 2; i <= n / 2; ++i) {
        fab[i] = i * fab[i - 1] % MOD;
    }
    vector<int> v;
    int odd_cnt = 0;
    int size = 0;
    for (int num : cnt) {
        if (num == 0) continue;
        if (num % 2) {
            odd_cnt++;
            if (num > 1) v.push_back(num / 2);
        } else {
            v.push_back(num / 2);
        }
        size += num / 2;
    }
    int64_t res = fab[size];
    for (int num : v) {
        res = res * reverseInt(fab[num]) % MOD;
    }
    if (odd_cnt > 0) res = res * odd_cnt % MOD;
    cout << res << endl;
    cout << chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - begin).count() << endl;
    return 0;
}