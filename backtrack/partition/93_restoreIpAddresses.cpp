// 复原IP地址
// 和分割回文串大致逻辑一直
// 只不过要更换if判断逻辑
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
// IP地址只能是4个整数，限制了递归深度！！

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isIpNumber(const string& s) {
        if (s[0] == '0' && s.size() > 1) {
            return false;
        }
        if (stoi(s) > 255) {
            return false;
        }
        
        return true;
    }
    
    void backtracking(const string&s, vector<string>& result, vector<string>& path, int start_index) {
        if (path.size() == 4 && start_index == s.size()) {
            string res = path[0];
            for (int i = 1; i < 4; i++) {
                res += "." + path[i];
            }
            result.push_back(res);
            return;
        }
        
        for (int i = start_index; path.size() < 4 && i < min(int(s.size()), start_index + 3); i++) {
            string substr = s.substr(start_index, i - start_index + 1);
            if (!isIpNumber(substr)) {
                continue;
            }
            
            path.push_back(substr);
            backtracking(s, result, path, i + 1);
            path.pop_back();
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtracking(s, result, path, 0);
        return result;
    }
};