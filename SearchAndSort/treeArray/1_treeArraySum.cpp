//
// Created by jacky on 24-9-9.
//
#include <bits/stdc++.h>
using namespace std;

class treeArray {
private:
    vector<int> tree;
    int n;

    int lowbit(int x) {
        return x & -x;
    }

public:
    treeArray(int size) : tree(size + 1, 0), n(size) {}

    // O(nlogn), 传入的array已经是一个权值数组！
    void initTree(vector<int>& arr) {
        for (int i = 0; i < n; ++i) {
            update(i + 1, arr[i]);
        }
    }

    // O(n)
    void initTree2(vector<int>& arr) {
        for (int i = 1; i <= n; ++i) {
            tree[i] += arr[i - 1];
            int j = i + lowbit(i);
            if (j <= n)
                tree[j] += tree[i];
        }
    }

    void update(int x, int delta) {
        ++x;
        while (x <= n) {
            tree[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        ++x;
        int sum = 0;
        while (x > 0) {
            sum += tree[x];
            x -= lowbit(x);
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        // [l, r] -> [1, r] - [1, l - 1]
        return query(r) - query(l - 1);
    }
};