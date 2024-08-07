//
// Created by jacky on 24-8-6.
//
#include <bits/stdc++.h>
using namespace std;

// 
class UnionSearch {
    vector<size_t> pa, rank;
    int size;

public:
    UnionSearch(size_t size_) : pa(size_ * 2), rank(size_ * 2, 1), size(size_) {
        iota(pa.begin(), pa.begin() + size_, size_);
        iota(pa.begin() + size_, pa.end(), size_);
    }

    size_t find(size_t x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    void unite(size_t x, size_t y) {
        // 找根
        x = find(x);
        y = find(y);
        // 对比根是否相同，相同则不作处理
        if (x == y)
            return;
        // 根据集合大小决定谁加入谁的集合
        // 保持x作为大集合一方
        if (rank[x] < rank[y])
            swap(x, y);
        pa[y] = x;
        rank[x] += rank[y];
    }

    // 因为存在副本，一开始每个节点的父节点都是副本，因此可以通过将父亲设为自身作为
    void earse(size_t x) {
        --rank[find(x)];
        pa[x] = x;
    }

    void move(size_t x, size_t y) {
        size_t fx = find(x), fy = find(y);
        if (fx == fy)
            return;
        pa[x] = fy;
        --rank[fx], ++rank[fy];
    }
};