//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

// 逆波兰表达式求值
// 常见的人类阅读表达式本质上是中缀表达式，也就是数字、运算符、数字的顺序
// 需要使用括号指明计算顺序
// 但逆波兰表达式，也就是后缀表达式，是数字，数字，运算符的顺序
// 这样从前往后，按续遍历，遇到运算符就拿到前面的两个数字进行相应运算
// 这样无需括号，也能正确的得到计算结果！
// 所以本题本质上还是栈模拟类型
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // 数字是逆序的，后面的才是前面的操作数！
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (token == "+")
                    st.push(num1 + num2);
                else if (token == "-")
                    st.push(num1 - num2);
                else if (token == "*")
                    st.push(num1 * num2);
                else
                    st.push(num1 / num2);
            } else {
                st.push(stoi(token));
            }
        }

        // 最终栈中只会有一个数字，因此栈顶元素就是结果
        return st.top();
    }
};

int main() {
    vector<string> v = {"4", "13", "5", "/", "+"};
    cout << Solution().evalRPN(v) << endl;
}