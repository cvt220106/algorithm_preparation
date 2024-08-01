//
// Created by jacky on 24-7-29.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n + 5];
        // dp[i]表示以nums[i]结尾的最长递增子序列长度
        fill_n(dp, n, 1);

        int res = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && nums[i] - nums[j] <= k)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        for_each(dp, dp + n, [](const int x) { cout << x << " "; });
        cout << endl;
        return res;
    }
};

// O(N^2)

// 使用线段树进行优化
// 快速查询区间最值！！
// 线段树存储的是以下标为值的元素而结尾的递增子序列的最大值
class SegTree {
private:
    vector<int> tree;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0; // 初始化为0
            return;
        }
        int mid = start + (end - start) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
            update(node * 2, start, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(node * 2, start, mid, l, r),
                   query(node * 2 + 1, mid + 1, end, l, r));
    }

public:
    SegTree(int size) {
        n = size;
        tree.resize(4 * size);
        build(1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        // 因为是通过线段树下标值表示num值，因此线段树索引的区间就是[0, max_num]
        int size = *max_element(nums.begin(), nums.end()) + 1;
        auto tree = SegTree(size);

        int result = 0;
        for (auto num : nums) {
            // 因为要维持相邻元素相差不大于k,且为递增
            // 因此对于num,我们只查询[num -k, num - 1]范围的最长递增子序列长度
            // 当然num可能小于k,因此对比0和num-k的较大值作为左边界
            // 接着加1即为以num结尾的最长递增子序列长度
            // 进一步将新的长度更新至线段树的num下标下记录
            int prev_max_len = tree.query(max(0, num - k), num - 1);
            int cur_max_len = prev_max_len + 1;
            tree.update(num, cur_max_len);
            // 记录整个遍历过程中的最大值
            result = max(result, cur_max_len);
        }

        return result;
    }
};

void f(void*) { cout << 0 << endl; }
void f(int) { cout << 1 << endl; }
void f(long) { cout << 2 << endl; }

int main() {
    vector<int> v = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    cout << Solution().lengthOfLIS(v, 3) << endl;
    cout << Solution2().lengthOfLIS(v, 3) << endl;
    f(nullptr);
    f(NULL);
    cout << typeid(nullptr).hash_code() << endl;
    cout << typeid(nullptr_t).hash_code() << endl;
    cout << typeid(int).hash_code() << endl;
    cout << typeid(Solution).hash_code() << endl;
    return 0;
}