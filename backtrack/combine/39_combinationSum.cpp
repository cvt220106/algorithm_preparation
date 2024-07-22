// 组合总和
// 一个 无重复元素 的整数数组 candidates 和一个目标整数 target
// 找出可以和为target的组合
// 重点！！！！ 每个元素可以无限制次数使用！！
// 回溯三部曲
// 1.递归函数的参数
// 整个选择集配合起始start_index得到每次当前的子选择集合
// 当前组合内总和cur_sum，也可以用remain_sum替代，二者关系就是和为target
// 区别就在于是对比cur_sum == target，还是remain_sum == 0
// 结果收集result、当前路径（组合）path
// 2.递归函数的终止条件
// 这里采用remain_sum，也就是剩余空间为0时，我们找到了想要的组合，压入结果并返回
// 因为组合没有长度要求，如果在分支上没有等于条件出现，会无限递归下去
// 因此必须剪枝终止！也就是remain_sum < 0时，我们终止返回
// 3.单层搜索过程
// 当前选择集for i in candidates[start_index:]
// 加入组合
// backtracking,需要注意的细节时，因为一个元素可以重复选取，因此我们继续传入i,而不是i + 1
// 回溯

#include <vector>
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
            path.push_back(candidates[i]);
            backtracking(candidates, n, result, path, remain_sum - candidates[i], i);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(candidates, candidates.size(), result, path, target, 0);
        return result;
    }
};