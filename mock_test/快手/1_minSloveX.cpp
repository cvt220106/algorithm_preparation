//
// Created by jackyYoung on 24-8-15.
//
#include <bits/stdc++.h>
using namespace std;
#define lint int64_t

/// 题目链接：https://kamacoder.com/problempage.php?pid=1236
/// 贝组等式: 对于任意的整数a，b都有整数x，y满足
/// ax + by = gcd(a, b)
/// 本题中 ax % b = 1 等价于 ax + by = 1
/// 所以a，b一定满足gcd(a, b) = 1
/// 因此可以通过扩展欧几里得解法，反求x
/// 因为贝祖等式是在整数范围内求解
/// 我们需要最小正整数解，因此可以先对b取模，再加上b，排除复解的情况，再去b取模，防止整数加b后错误
/// (x % b + b) % b

tuple<lint, lint, lint> extended_gcd(lint a, lint b) {
    if (b == 0) {
        // 对应的就是gcd, x, y
        return {a, 1, 0};
    }
    auto [gcd, x1, y1] = extended_gcd(b, a % b);
    lint x = y1;
    lint y = x1 - (a / b) * y1;
    return {gcd, x, y};
}


int main() {
    lint a, b;
    cin >> a >> b;

    /// 解法1
    /// 选择性遍历
    /// b = ak + t, ax = mb + 1
    /// x = m(ak + t) + 1 / a= mk + (mt + 1) / a
    /// 因此mt + 1一定是a的倍数
    /// 遍历m时，实际上只需要遍历a的倍数i，计算满足(ia - 1) % t == 0的m

    // lint t = b % a;
    // lint k = b / a;
    //
    // for (lint i = 1; i <= a; i++) {
    //     lint m = (i * a - 1) / t;
    //     if ((m * b + 1) % a == 0) {
    //         cout << (m * b + 1) / a << endl;
    //         break;
    //     }
    // }

    /// 解法二，扩展欧几里得方法
    auto [gcd, x, y] = extended_gcd(a, b);
    cout << (x % b + b) % b  << endl;

    return 0;
}