//
// Created by jacky on 24-8-9.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1235
// 复杂度定义：密码的复杂度等于在前 len - 1 个字符中有多少字符与它后一个字符不同。
// 也就是说每个字符只与自己相邻字符比较不同，来获取复杂度！
// 要最大化复杂度，我们也就是让相邻字符中？字符处尽量填入与左右相邻字符均不同的字符
// 对于边界条件
// 1. ？出现在密码的两端，此时只需要与一个相邻的字符对比即可
// 2. ？无论怎么选都会与相邻相同时，默认与左或者右相同即可

int main() {
    int n, m;
    cin >> n >> m;
    string password;
    cin >> password;
    for (int i = 0; i < n; ++i) {
        if (password[i] != '?')
            continue;
        bool flag = false; // 用于判断？是否找到合适字符
        for (char j = 'a'; j < 'a' + m; j++) {
            if ((i == 0 || password[i - 1] != j) && (
                    i == n - 1 || password[i + 1] != j)) {
                flag = true;
                password[i] = j;
                break;
            }
        }

        if (!flag) {
            // 没有合适的字符，和前后面其中一个保持一致即可
            if (i > 0)
                password[i] = password[i - 1];
            else
                password[i] = password[i + 1];
        }
    }

    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (password[i] != password[i + 1])
            res++;
    }

    cout << res << '\n';
    return 0;
}