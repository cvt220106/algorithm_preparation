// 电话号码的字母组合
// 不同点在于每一层选择列表是和当前digit对应的字母相关
// 外层递归纵向遍历digits的每一个字符
// 内层for横向遍历字符对应的字母
// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // digit 2-9, so pattern index also 2-9
    vector<string> pattern = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtracking(vector<string>& result, string& path, string& digits, int n, int start_index) {
        if (start_index == n) {
            result.push_back(path);
            return;
        }
        
        int num = digits[start_index] - '0';
        for (char c : pattern[num]) {
            path.push_back(c);
            backtracking(result, path, digits, n, start_index + 1);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> result;
        string path;
        backtracking(result, path, digits, digits.size(), 0);
        return result;
    }
};