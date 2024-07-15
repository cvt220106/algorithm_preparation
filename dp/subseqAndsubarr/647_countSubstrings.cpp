// 回文子串
// 统计一个字符串s中的回文子串的数目
// 相同的子串，不同的起始位置视作不同，子串是连续的！！
// dp数组
// dp[i][j]表示s的[i, j]范围的子串是否为回文子串，true/false
// 递推关系
// 考虑边界的元素的关系，s[i]与s[j]
// if s[i] != s[j],那么dp[i][j] = false 不等显然不是回文子串
// if s[i] == s[j]，相等时，还需要继续判断
// 1.i == j，单个元素显然是回文子串
// 2.j - i == 1, 两个相同元素依旧是回文子串
// 3.判断内部子串[i + 1, j - 1]是否为子串，也就是dp[i + 1, j - 1]的状态
// 所以dp[i][j] = s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])
// 初始化
// 所有的都默认为非回文子串，也就是false
// 遍历顺序
// 因为dp[i][j]依赖于dp[i + 1][j - 1]的状态，也就是它的左下方
// 因此遍历顺序应该是从下往上，从左往右,要保证i在j左边，也就是i <= j
// 结果
// 因为我们dp数组记录的只是回文子串的状态，数目还需要自己去收集！！

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, false));
        
        int result = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    result++;
                }
            }
        }
        
        return result;
    }
    
    // 双指针法
    // 寻找中心点，向外扩散，对比双指针i,j的关系，s[i] == s[j]则继续扩散，寻找新的回文子串
    // 重点在于中心点有两种情况，i == j或者i + 1 == j，得到的回文子串也就是奇数长度或偶数长度
    int countSubstrings2(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += extend(s, i, i);
            result += extend(s, i, i + 1);
        }
        
        return result;
    }
    
    int extend(string& s, int i, int j) {
        int n = s.size();
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        
        return res;
    }
};