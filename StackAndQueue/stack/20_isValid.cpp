//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 使用栈进行模拟，对比栈顶括号与当前括号的是否对应进行判断
    // 排除不符合规则的可能
    // 1.左右括号不对应
    // 2.左括号更多--最后栈不为空
    // 3.右括号更多--栈为空，但此时括号为右括号
    // 优化，遇到左括号时，压入右括号，这样遇到右括号对比时就只需要对比是否相同
    // 而不需要分情况的对比三种括号
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(')
                st.push(')');
            else if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            else if (st.empty() || st.top() != c)
                // 右括号更多或括号不匹配
                return false;
            else
                st.pop();
        }

        // 最后判断栈是否为空，来检查左括号是否更多
        return st.empty();
    }
};