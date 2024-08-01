//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

// 本质上和括号匹配类似，只不过匹配的对象从左右括号
// 变为了相同字符，因为最后需要返回一个字符串
// 因此使用stack的话，最终结果存储在栈中，弹出后是逆序的，还需要再倒一下得到结果
// 因此可以使用string来模拟栈，只在string的尾部进行压入和删除操作，模拟栈的特性
// 最终string的状态也就是我们的结果
class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for (char c : s) {
            if (st.empty() || st.back() != c) {
                st.push_back(c);
            } else {
                st.pop_back();
            }
        }

        return st;
    }
};

int main() {
    string s = "abaabba"; // aba
    cout << Solution().removeDuplicates(s) << endl;
    return 0;
}