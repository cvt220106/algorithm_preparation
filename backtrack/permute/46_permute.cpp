// 排列问题
// ！！！不含重复元素的序列nums进行全排列
// 排列因为存在顺序关系，[1, 2]和[2, 1]是不同的结果
// 因此此时我们横向for循环遍历，就不需要start_index来防止不同顺序的选取
// 但我们依旧需要防止同一个元素的重复选取
// 因此加入appear数组来记录元素这该搜索路径树分支上的出现情况
// 接着全排列是所有元素的排列
// 因此终止条件一定是当前路径长度等于元素长度 

#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(const vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& appear) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (appear[i]) {
                continue;
            }
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