//
// Created by jacky on 24-7-30.
//

#ifndef SEGEMENTTREE_H
#define SEGEMENTTREE_H
#include <vector>
using namespace std;
// template code
// for max/min/sum/gcd/lcm operation
// we just need modify combine function and identity num
class SegementTree
{
private:
    vector<int> tree;
    int n;

    // template function
    int combine(int left, int right)
    {
        return max(left, right);
        // return left + right; // sum operation
        // return min(left, right); // min operation
        // return gdc/lcm(left, right); //gcd/lcm operation
    }

    /**
     * 
     * @param arr 构造线段树的元素序列
     * @param node 当前的线段树编号，从1开始
     * @param start 线段树节点对应的arr中需要操作区间起始
     * @param end  线段树节点对应的arr中需要操作区间末尾
     * tree[node] = opration(arr[start]..arr[end])
     */
    void build(vector<int>& arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        // 递归dfs左右根后序建树
        int mid = start + (end - start) / 2;
        // node * 2为左子树
        build(arr, node * 2, start, mid);
        // node * 2 + 1为右子树
        build(arr, node * 2 + 1, mid + 1, end);
        // 处理父节点
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }

    /**
     *
     * @param node 需要更新的线段树节点编号
     * @param start 当前线段树节点维护的左区间，用于二分查找idx
     * @param end 当前线段树节点维护的右区间
     * @param idx 更新的元素下标
     * @param val 更新的元素大小
     */
    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        if (idx <= mid)
            // 二分查找更新区间
            update(node * 2, start, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, end, idx, val);
        // 更新父节点
        tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
    }

    /**
     * 
     * @param node 线段树编号
     * @param start 线段树所维护的数组序列左区间
     * @param end 线段树所维护的数组序列右区间
     * @param l 查询的左区间
     * @param r 查询的右区间
     * @return 区间[l,r]的总操作值
     */
    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            // 异常查询范围
            return INT_MIN; // 取决于combine operation
        // max, return lowest number
        // min, return largest number
        // sum, return 0, etc..
        if (l <= start && end <= r)
            // 查询区间包含当前线段树node的范围，直接返回该线段树维护的值
            return tree[node];
        // 递归处理
        int mid = start + (end - start) / 2;
        int left = query(node * 2, start, mid, l, r);
        int right = query(node * 2 + 1, mid + 1, end, l, r);
        return combine(left, right);
    }

public:
    SegementTree(vector<int>& arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        // 线段树编号从1开始，传入的左右均为arr的闭区间！
        build(arr, 1, 0, n - 1);
    }

    void print()
    {
        for_each(tree.begin(), tree.end(), [](const int x) { cout << x << " "; });
        cout << endl;
    }

    void update(int idx, int val)
    {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};


#endif //SEGEMENTTREE_H
