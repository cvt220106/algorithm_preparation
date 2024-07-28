//
// Created by jackyYoung on 24-7-28.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        int unused_char = 26 - cnt.size();
        int min_oper = 0;
        for (auto [c, num] : cnt) {
            while (num > 3) {
                if (unused_char > 0) {
                    min_oper++;
                    num -= 2;
                    unused_char--;
                } else {
                    min_oper += num / 2;
                    num = num / 2 + num % 2;
                }
            }
            if (num == 3) {
                if (unused_char > 0) {
                    min_oper++;
                    unused_char--;
                } else {
                    min_oper += 2;
                }
            } else if (num == 2) {
                min_oper++;
            }
        }

        cout << min_oper << endl;
    }
}