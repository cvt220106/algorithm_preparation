//
// Created by jackyYoung on 24-8-3.
//
// https://www.nowcoder.com/discuss/571445180465778688
#include <bits/stdc++.h>
using namespace std;

int test(vector<string>& t, vector<string>& s) {
    int score = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == s[i])
            score++;
        else
            score--;
        if (score < 0)
            break;
    }
    return score >= 0;
}

vector<string> parseInput(int n) {
    cin.ignore();
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    return v;
}

int main() {
    int t;
    cin >> t;
    int pass = 0;
    while (t--) {
        int n;
        cin >> n;
        vector<string> teacher = parseInput(n);
        vector<string> student = parseInput(n);
        pass += test(teacher, student);
    }

    cout << pass << endl;
    return 0;
}