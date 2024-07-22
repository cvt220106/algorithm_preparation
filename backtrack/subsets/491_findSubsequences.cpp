// 非递减子序列的子集
// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素
// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
// 重点
// 1. 选择压入时，判断当前元素是否大于等于当前选择集path中最后一个元素
// 2. 存在重复元素，需要在for循环遍历层进行去重
// 因为非递减的要求本身就包含顺序性，因此不能直接对数组排序进行去重，应该使用哈希来判断是否出现

#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(const vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int start_index) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        if (start_index == nums.size()) {
            return;
        }
        
        // 因为nums[i]的范围是[-100, 100]
        // 因此可以使用定长数组作为哈希表
        // nums[i] + 100进行索引
        int used[200] = {0};
        for (int i = start_index; i < nums.size(); i++) {
            // 未使用过或不符合非递减，跳过
            if (used[nums[i] + 100] > 0 || (!path.empty() && nums[i] < path[path.size() - 1])) {
                continue;
            }
            used[nums[i] + 100]++;
            
            path.push_back(nums[i]);
            backtracking(nums, result, path, i + 1);
            path.pop_back();
        }
    }    

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(nums, result, path, 0);
        return result;
    }
};