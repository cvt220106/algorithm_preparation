// 打家劫舍3
// 树形dp
// 根据子孩子的状态来推导父亲的状态
// 子孩子存在两个状态dp[0], dp[1]，0代表不偷子孩子，1代表偷子孩子
// 对于当前节点，如果偷取当前节点，就不能偷取子孩子节点，dp[1] = val + left[0] + right[0]
// 如果不偷取当前节点，则可同时对子孩子节点进行选择，dp[0] = max(left[0], left[1]) + max(right[0], right[1])

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> dp = robTree(root);

        return max(dp[0], dp[1]);
    }

    vector<int> robTree(TreeNode* cur) {
        if (cur == nullptr) {
            return {0, 0};
        }

        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        
        return {max(left[0], left[1]) + max(right[0], right[1]), cur->val + left[0] + right[0]};
    }
};