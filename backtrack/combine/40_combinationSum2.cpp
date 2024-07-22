// 组合总和2
// 一个 无重复元素 的整数数组 candidates 和一个目标整数 target
// 找出可以和为target的组合
// 重点！！！！ 每个元素只能使用一次！！但存在相同的数字的不同位置的不同元素！！
// [1, 5, 1]，两个1是不同元素，但是[1, 5], [5, 1]是相同组合，需要去重！！，这个去重是在横向for遍历维度！！！
// 和上一题唯一的差距也就是因为元素只能使用一次
// 因此递归时的start_index不能继续传入当前位置，应该+1！！！

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtracking(vector<int>& candidates, int n, vector<vector<int>>& result, vector<int>& path, int remain_sum, int start_index) {
        if (remain_sum == 0) {
            result.push_back(path);
            return;
        }
        
        // 剪枝
        if (remain_sum < 0) {
            return;
        }
        
        for (int i = start_index; i < n; i++) {
            int num = candidates[i];
            // 同层横向遍历，去除重复元素
            if (i > start_index && num == candidates[i - 1]) {
                continue;
            }
            path.push_back(num);
            backtracking(candidates, n, result, path, remain_sum - num, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        // 通过排序将相同数字变为相邻关系
        // 接着在for横向遍历时去重
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, candidates.size(), result, path, target, 0);
        return result;
    }
};