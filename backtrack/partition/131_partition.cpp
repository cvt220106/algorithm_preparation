// 字符串分割问题
// 类似于组合问题，也是一个个元素的从集合中选取
// 不同点在于，组合是确定的数字元素，字符串分割的元素是需要通过下标去自行分割区间的
/**
for (int i = start_index; i < s.size(); i++) {
    string substr = s.substr(start_index, i - start_index + 1);
    if (判断逻辑 == 不符合) {
        continue;
    }
    压入
    backtracking();
    回溯
}
*/
// 本题：分割回文串
// 重点在于分割后的判定：是否为字符串，可通过动态规划先将字符串中所有可能的回文子串记录下来


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> computePalindrome(const string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                }
            }
        }
        
        return dp;
    }
    
    void backtracking(vector<vector<int>>& palindromes, const string&s, vector<vector<string>>& result, vector<string>& path, int start_index) {
        if (start_index == s.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = start_index; i < s.size(); i++) {
            string substr = s.substr(start_index, i - start_index + 1);
            if (!palindromes[start_index][i]) {
                continue;
            }
            
            path.push_back(substr);
            backtracking(palindromes, s, result, path, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<int>> palindromes = computePalindrome(s);
        vector<vector<string>> result;
        vector<string> path;
        backtracking(palindromes, s, result, path, 0);
        return result;
    }
};