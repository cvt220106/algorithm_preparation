// 组合总和3
// 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
// 只使用数字1到9
// 每个数字 最多使用一次

// 和组合类似，不同点在于初始选择列表是[1, 9]
// 终止条件改为长度为k且和为n
// 回溯三部曲
// 1,递归函数的参数
// 输入数据:k
//  状态辅助参数：组合内剩余空位remains（用于记录组合还能填入多少数)，选择列表起始位置start，(防止重复选取)
// n - 当前组合内元素总和 = remain_sum(剩余可填入元素个数)
// 结果收集结构：vector<vector<int>> result;
// 当前路径path
// 2.终止条件
// 组合内剩余空位remains为0，说明已经获取到一个大小为k的组合，此时若remain_sum == 0, 则压入当前结果并返回
// 剪枝提前终止：
// 1. 当我们当前选择列表内数目小于我们剩余空位时，说明永远都不会填满，即10 - start < remains, 提前终止返回
// 2. 当前选择列表的第一个元素 i > remain_sum，则不可能存在和为n的组合，提前终止返回
// 3.单层搜索过程
// 选择列表: i in [start, 9]
// 做选择：压入 i 至路径，同时更新sum
// 递归，传入新的remains和start、sum以及path
// 回溯：撤销选择，还原sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>>& result, vector<int>& path, int remains, int remain_sum, int start) {
        if (remains == 0 && remain_sum == 0) {
            result.push_back(path);
            return;
        }
        
        // 剪枝
        if (10 - start < remains && remain_sum < start) {
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            backtracking(result, path, remains - 1, remain_sum - i, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, k, n, 1);
        return result;
    }
};