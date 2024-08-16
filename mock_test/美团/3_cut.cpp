//
// Created by jacky on 24-8-10.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a;
    reverse(b.begin(), b.end());
    ll l = 0, r = 0;
    while (q--) {
        char oper;
        int len;
        cin >> oper >> len;
        unordered_set<int> color;
        if (oper == 'L') {
            for (ll i = l; i < len + l; i++) {
                color.insert(a[i % n]);
            }
            cout << color.size() << '\n';
            l += len;
        } else {
            for (ll i = r; i < len + r; i++) {
                color.insert(b[i % n]);
            }
            cout << color.size() << '\n';
            r += len;
        }
    }

    return 0;
}