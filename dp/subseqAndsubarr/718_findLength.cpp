// 最长公共子数组
// 因为要求是子数组，因此本质上是连续的
// 所以推导起来也必定是相邻之间的推导再加1
// 与之前的不同点在于，之前仅在一个对象上遍历递推，寻找子数组
// 现在是两个数组之间的公共子数组，遍历对象是两个
// dp数组
// dp[i][j]代表以i - 1为结尾的nums1数组和以j - 1为结尾的nums2数组的最大公共子数组长度
// 递推关系
// 因为是子数组，因此必须是连续的，递推必由相邻对象推导而出
// if (num1[i - 1] == nums[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
// 初始化
// 根据dp数组的含义，dp[0][j]与dp[i][0]毫无意义，因此应从dp[1][1]出发，其值取决于nums1[0]与nums2[0]的关系
// 遍历顺序
// 对于二维，因为依赖于前一个的状态，因此二者都是从左往右遍历

// 优化--一维dp数组
// 观察二维的递推关系，可以看到，dp[i][j] = dp[i - 1][j - 1] + 1;
// 仅仅只是依赖于上一层的左边状态，因此可以讲i这一维度进行压缩，保留上一层的j-1状态即可
// 但因为当前层要依赖上一层的j-1状态，因此j维度的遍历应该从右往左，这一点与01背包问题的压缩是一致的。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int result = 0;

        // vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // for (int i = 1; i <= n1; i++) {
        //     for (int j = 1; j <= n2; j++) {
        //         if (nums1[i - 1] == nums2[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1] + 1;
        //         }

        //         result = max(result, dp[i][j]);
        //     }
        // }

        // 一维
        vector<int> dp(n2 + 1, 0);
        for (int i = 1; i <= n1; i++) {
            for (int j = n2; j > 0; j--) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 0;
                }

                result = max(result, dp[j]);
            }
        }

        return result;
    }

    // 查找两个字符串的最长公共子串
    string findLengthString(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        string result;

        vector<int> dp(n2 + 1, 0);
        for (int i = 1; i <= n1; i++) {
            for (int j = n2; j > 0; j--) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 0;
                }

                if (dp[j] > result.size()) {
                    result = str2.substr(j - dp[j], dp[j]);
                }
            } 
        }

        return result;
    }
};

int main() {
    cout << Solution().findLengthString("hlllll", "hell") << endl;
}