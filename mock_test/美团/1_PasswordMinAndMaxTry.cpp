//
// Created by jacky on 24-8-10.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string password;
    cin >> password;
    unordered_set<string> s;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        s.insert(str);
    }

    multiset<int> m;
    for (auto& v : s) {
        m.insert(v.size());
    }
    auto low = m.lower_bound(password.size());
    auto high = m.upper_bound(password.size());
    cout << distance(m.begin(), low) + 1 << " " << distance(m.begin(), high)
        <<
        '\n';
}