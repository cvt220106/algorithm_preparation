// 子集问题
// 总体框架类似
// 不同点在于组合存在一些要求才能加入到结果集中
// 子集每一次递归都将当前路径压入到结果当中
// ATTENTION!!，注意和90.子集2对比
// 给你一个整数数组 nums ，数组中的元素 互不相同 
// 不能包含重复子集！！

#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(const vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int start_index) {
        result.push_back(path);
        if (start_index == nums.size()) {
            return;
        }
        
        for (int i = start_index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, result, path, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(nums, result, path, 0);
        return result;
    }
};