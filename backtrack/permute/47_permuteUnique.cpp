// 全排列
// ！！！包含重复元素
// 相较于上一题，因为序列中存在重复元素，因此我们需要在for横向遍历时进行去重
// 也就是和40.组合总和2, 90.子集2中类似的处理逻辑
// 因为排列存在顺序关系，因此使用used数组进行for循环时去重

#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(const vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& appear) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        
        // nums[i]的范围[-10, 10]
        // 使用定长的数组used[21]
        // 通过nums[i] + 10访问
        int used[21] = {0};
        for (int i = 0; i < nums.size(); i++) {
            if (used[nums[i] + 10] || appear[i]) {
                continue;
            }
            used[nums[i] + 10]++;
            appear[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, result, path, appear);
            path.pop_back();
            appear[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> appear(nums.size(), false);
        backtracking(nums, result, path, appear);
        return result;
    }
};