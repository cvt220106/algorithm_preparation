//
// Created by jacky on 24-8-9.
//
#include <bits/stdc++.h>
using namespace std;

/// 题目链接：https://kamacoder.com/problempage.php?pid=1234

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    // 触发技能时，优先选当前战斗力最大的，以期许获得最大的勇气值加成 max(a[i]) - x
    // 直接战胜时，选当前最小的，x变为min(a[i]),
    // 这样下次触发技能时，就有max(a[i]) - min(a[i])的最大勇气值,循环往复到达中间相遇时，即为所求
    int power = 0;
    int res = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (power < a[r])
            res += a[r] - power;
        power = a[l];
        l++;
        r--;
    }

    cout << res << '\n';
    return 0;
}