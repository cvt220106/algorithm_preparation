// 子集2
// 给你一个整数数组 nums ，其中可能包含重复元素！！！
// 包含重复元素，但不能存在重复子集！！
// 这就是40.组合总和2中的去重场景一致
// 我们就需要排序加去重判断逻辑

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtracking(const vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int start_index) {
        result.push_back(path);
        if (start_index == nums.size()) {
            return;
        }
        
        for (int i = start_index; i < nums.size(); i++) {
            if (i > start_index && nums[i] == nums[i - 1]) {
                continue;
            }
            
            path.push_back(nums[i]);
            backtracking(nums, result, path, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        backtracking(nums, result, path, 0);
        return result;
    }
};