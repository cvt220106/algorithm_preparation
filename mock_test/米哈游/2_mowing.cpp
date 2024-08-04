//
// Created by jackyYoung on 24-8-3.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // sort(a.begin(), a.end());
    // int attack = 0;
    // int debuff = 0;
    // while (!a.empty() && a.back() > 2 * n) {
    //     attack += a.back() - n;
    //     debuff++;
    //     a.pop_back();
    // }
    //
    // for (int i : a) {
    //     int remain = i - debuff;
    //
    //     if (remain > i / 2) {
    //         attack += remain - i / 2;
    //         remain = i / 2;
    //     }
    //
    //     if (remain - (n - debuff) > 0) {
    //         // 检查剩余血量能否被余下的debuff杀死
    //         attack += remain - (n - debuff);
    //     }
    //
    //     debuff++;
    // }

    int attack = 0;
    for (int hp : a) {
        attack += max(0, hp - n);
    }

    cout << attack << endl;
}