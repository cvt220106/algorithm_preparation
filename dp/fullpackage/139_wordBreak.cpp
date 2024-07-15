// 单词拆分要求的是将单词拆分成几部分，这几部分据存在于单词列表中
// 这就和完全背包问题类似
// 单词列表就是我们的物品，可以多次使用，因此是完全背包
// 背包就是我们的字符串
// 目的就是用单词填满字符串
// 但不同点在于我们需要按顺序的去切分字符串，然后去寻找可使用的单词
// 并且不再是最大最小或者排列组合数的递推
// 而是可行性bool的递推
// dp[i]视为[0, i)的子字符串是否可以被单词列表中单词进行拆分
// 递推公式也就是吗，dp[j]可被拆分同时子字符串[j, i)对应的单词存在于单词列表中
// dp[i]则可被拆分为true
// 因此是按顺序拆分，因此物品是有序的，可视作排列，因此遍历顺序我们按照先背包再物品
// 物品的遍历我们转为set进行存在性验证即可

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int size = s.size();
        vector<int> dp(size + 1, false);
        dp[0] = true;

        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < i; j++) {
                string substr = s.substr(j, i -j);
                if (dp[j] && wordSet.find(substr) != wordSet.end()) {
                    dp[i] = true;
                }
            }
        }

        return dp[size];
    }
};