//
// Created by jacky on 24-7-30.
//
#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    stringstream ss(s);
    vector<string> strs;
    string str;
    while (getline(ss, str, ' ')) {
        strs.push_back(str);
    }

    if (pattern.size() != strs.size()) {
        return false;
    }
    unordered_map<char, string> p2s;
    unordered_map<string, char> s2p;
    for (int i = 0; i < pattern.size(); i++) {
        char c = pattern[i];
        string _s = strs[i];
        if ((p2s.count(c) > 0 && p2s[c] != _s) || (
                s2p.count(_s) > 0 && s2p[_s] != c)) {
            return false;
        }
        p2s[c] = _s;
        s2p[_s] = c;
    }

    return true;
}

int main() {
    string pattern;
    getline(cin, pattern);
    string s;
    getline(cin, s);
    cout << wordPattern(pattern, s) << endl;
}