//
// Created by jacky on 24-8-1.
//
// 单个字符串dp递推的分割的重点在于如果遍历字符串以及获取子串
// 对于单个字符串的dp，默认dp[0]为空字符串
// dp[i]表示字符串的前i个元素下的情况，也就是子串[0, i)
// 因此dp[j]就是[0, j), 递推过程中需要判断的子串就是
// [j, i), 对应cpp代码就是s.substr(j, i - j)
// 明确了dp的定义以及子串的获取，实施起来就简单很多
// 主要就是要获取到子串，然后对子串进行判断，是否满足一些条件（因题目而异）
// 若满足，就可以触发我们的dp递推
// 递推的方式同样因题目而已
// 若为总的数目，则为+=， 若为最多最少，则为max/min

// 解码方法的总数，首先是总数，就可以确定递推方式是+=
// 再就是判断子串是否符合解码规则
// 将所有decode方式存入map中，快速判断子串是否出现在我们的字典中，若存在，则满足
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        unordered_set<string> decode_map;
        for (int i = 1; i <= 26; i++) {
            decode_map.insert(to_string(i));
        }

        // dp[i]表示[0, i)的子串可编码的总数
        // dp[0]无意义！
        // 全部字符串是dp[s.size()] [0, s.size())
        // dp[j] -> dp[i] [j, i)的子串是合法解码，也就是s.substr(j, i - j)
        // for j in 0..i if substr[j, i)可编码，dp[i] += dp[j]
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (decode_map.count(sub)) {
                    dp[i] += dp[j];
                }
            }
        }

        return dp[s.size()];
    }
};