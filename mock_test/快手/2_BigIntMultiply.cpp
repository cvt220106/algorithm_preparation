//
// Created by jackyYoung on 24-8-15.
//
#include <bits/stdc++.h>
using namespace std;

/// 题目链接：https://kamacoder.com/problempage.php?pid=1237
/// 大整数乘法

// 大整数加法
vector<int> add(vector<int>& num1, vector<int>& num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 < len2) {
        return add(num2, num1);
    }
    int i = len1 - 1;
    int j = len2 - 1;
    int carry = 0;
    vector<int> res(len1);
    while (i >= 0 && j >= 0) {
        res[i] = (carry + num1[i] + num2[j]) % 10;
        carry = (carry + num1[i] + num2[j]) / 10;
        i--;
        j--;
    }
    while (i >= 0) {
        res[i] = (carry + num1[i]) % 10;
        carry = (carry + num1[i]) / 10;
        i--;
    }
    if (carry > 0) {
        res.insert(res.begin(), carry);
    }

    return res;
}

// 大整数乘以个位数
vector<int> singleMultiply(vector<int>& num1, int c, int n) {
    vector<int> res(num1.size());
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i) {
        res[i] = (num1[i] * c + carry) % 10;
        carry = (num1[i] * c + carry) / 10;
    }
    if (carry > 0) {
        res.insert(res.begin(), carry);
    }
    for (int i = 0; i < n; ++i) {
        res.push_back(0);
    }
    return res;
}

// 大整数乘法
vector<int> multiply(vector<int> num1, vector<int> num2) {
    if (num1.size() < num2.size()) {
        return multiply(num2, num1);
    }
    vector<int> res;
    for (int i = num2.size() - 1; i >= 0; --i) {
        auto tmp = singleMultiply(num1, num2[i], num2.size() - i - 1);
        res = add(res, tmp);
    }

    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> num1(a.size());
    vector<int> num2(b.size());

    for (int i = 0; i < a.size(); ++i) {
        num1[i] = a[i] - '0';
    }
    for (int i = 0; i < b.size(); ++i) {
        num2[i] = b[i] - '0';
    }
    vector<int> res = multiply(num1, num2);
    for (int i = 0; i < res.size(); ++i) {
        if (i == res.size() - 1) {
            cout  << res[i] << '\n';
        } else {
            cout << res[i];
        }
    }

    return 0;
}