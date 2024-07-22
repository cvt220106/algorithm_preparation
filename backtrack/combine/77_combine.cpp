// 组合问题
// n个数中k个数的不同组合
// 回溯三部曲
// 1,递归函数的参数
// 输入数据: n
// 状态辅助参数：组合内剩余空位remains（用于记录组合还能填入多少数)，选择列表起始位置start，(防止重复选取)
// 结果收集结构：vector<vector<int>> result;
// 当前路径path
// 2.终止条件
// 组合内剩余空位remains为0，说明已经获取到一个大小为k的组合，压入当前结果并返回
// 剪枝提前终止：当我们当前选择列表内数目小于我们剩余空位时，说明永远都不会填满
// n - start + 1 < remains, 提前终止返回
// 3.单层搜索过程
// 选择列表: i in [start, n]
// 做选择：压入 i 至路径
// 递归，传入新的remains和start以及path
// 回溯：撤销选择

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtracking(vector<vector<int>> &result, vector<int> &path, int n, int remains, int start) {
        // 终止条件
        if (remains == 0) {
            result.push_back(path);
            return;
        }
        
        // 剪枝
        if (n - start + 1 < remains) {
            return;
        }
        
        // 选择
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            backtracking(result, path, n, remains - 1, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, n, k, 1);
        return result;
    }
};