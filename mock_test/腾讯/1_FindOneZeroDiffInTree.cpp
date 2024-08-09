//
// Created by jacky on 24-8-9.
//
#include <bits/stdc++.h>
using namespace std;

/// 题目链接：https://kamacoder.com/problempage.php?pid=1231
/// 本题最大的问题在于理解题目！！
/// 1.给出的是树的层序遍历序列，这不等同于用数组存储树，父亲节点与左右子树节点的下标之间
/// 并不全部满足规律！！因此正确做法是使用队列，根据层序遍历序列，重新建树
/// 2.注意题目是cnt(1) - cnt(0) = 1,不是单纯的多，而是恰好多1的路径数！！

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};

int dfs(TreeNode* root, int diff) {
    if (root == nullptr) {
        return 0;
    }

    // 根处理
    diff += root->val == 1 ? 1 : -1;
    // 叶子节点直接返回结果
    if (root->left == nullptr && root->right == nullptr) {
        return diff == 1;
    }

    // 继续遍历左右子树
    return dfs(root->left, diff) + dfs(root->right, diff);
}

int main() {
    int n;
    cin >> n;
    int v;
    cin >> v;

    // 利用队列重新构建树
    auto* root = new TreeNode(v);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < n && !q.empty()) {
        cin >> v;
        TreeNode* node = q.front();
        q.pop();
        if (i < n && v != -1) {
            node->left = new TreeNode(v);
            q.push(node->left);
        }
        i++;
        cin >> v;
        if (i < n && v != -1) {
            node->right = new TreeNode(v);
            q.push(node->right);
        }
        i++;
    }

    cout << dfs(root, 0) << '\n';

    delete root;
    return 0;
}