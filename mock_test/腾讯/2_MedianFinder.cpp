//
// Created by jacky on 24-8-9.
//
#include <bits/stdc++.h>
using namespace std;

/// 题目链接：https://kamacoder.com/problempage.php?pid=1232
/// 使用两个有序集合维护序列的各一半元素
/// A维护较大的一半，能够快速获取到A中最小值
/// B维护较小的一半，能够快速获取到B中最大值
/// 同时规定，当常数N为奇数时，A的长度为（N + 1）/2， B的长度为（N - 1） / 2
/// 当为偶数时，二者长度均为N / 2
/// 计算中位数时
/// A.size() = B.size()，说明总集合长度为偶数，取A中最小值与B中最大值，取平均
/// 不等时，说明总集合长度为奇数，因为规定A中元素更多，因此直接取A中最小值即为所求

multiset<int> s1; // 存储较大的一半，第一个元素是最小值
multiset<int, greater<>> s2; // 存储较小的一半，第一个元素是最大值

void printMedian() {
    if (s1.size() == s2.size()) {
        if ((*s1.begin() - *s2.begin()) % 2) {
            // 防止int相加后溢出，同时存在float有效位数精度不够的情况
            // 使用double存储
            double median = *s2.begin() + (*s1.begin() - *s2.begin()) / 2.0;
            printf("%.1f ", median);
        } else {
            int median = *s2.begin() + (*s1.begin() - *s2.begin()) / 2;
            printf("%d ", median);
        }
    } else {
        cout << *s1.begin() << " ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            cin >> b[i];
        }
        vector<int> nums = a;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; ++i) {
            s2.insert(nums[i]);
        }
        for (int i = n / 2; i < n; ++i) {
            s1.insert(nums[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            printMedian();
            int r = a[b[i]];
            if (r <= *s2.begin()) {
                // 存在相同元素，不能直接erase具体元素值，而是erase具体位置！
                auto pos = s2.find(r);
                s2.erase(pos);
                if (s2.size() < s1.size() - 1) {
                    s2.insert(*s1.begin());
                    s1.erase(s1.begin());
                }
            } else {
                auto pos = s1.find(r);
                s1.erase(pos);
                if (s1.size() < s2.size()) {
                    s1.insert(*s2.begin());
                    s2.erase(s2.begin());
                }
            }
        }
        // 最后一个中位数一定在s1中
        cout << *s1.begin() << '\n';
        s1.clear(); //重置状态
        s2.clear();
    }
    return 0;
}