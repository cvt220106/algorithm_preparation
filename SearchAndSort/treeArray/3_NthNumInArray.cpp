//
// Created by jacky on 24-9-9.
//

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
#define N 100000
#define K 9999
vector<int> cnt; // 权值数组

int seqFindKth(int k) {
    for (int i = 1; i < cnt.size(); i++) {
        if (k <= cnt[i]) {
            return i;
        } else {
            k -= cnt[i];
        }
    }
    return -1;
}


vector<int> tree; // 树状权值数组

int lowbit(int x) { return x & -x; }

void update(int x, int delta) {
    while (x < tree.size()) {
        tree[x] += delta;
        x += lowbit(x);
    }
}

int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int findKthNum(int k) {
    int l = 1, r = tree.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (query(mid) < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int findKth(int k) {
    int sum = 0, x = 0;
    for (int i = log2(tree.size() - 1); i >= 0; --i) {
        x += 1 << i;
        if (x >= tree.size() || sum + tree[x] >= k) {
            x -= 1 << i;
        } else {
            sum += tree[x];
        }
    }
    return x + 1;
}

int main() {
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 10000000;
    }
    // 排序数组用于验证
    auto sort_arr = arr;
    sort(sort_arr.begin(), sort_arr.end());
    // 1.将原数组离散化
    set<int> s(arr.begin(), arr.end());
    // 2.记录离散化哈希
    int rank = 1;
    unordered_map<int, int> arr_map;
    unordered_map<int, int> rank_map;
    for (int val : s) {
        rank_map[rank] = val;
        arr_map[val] = rank++;
    }
    // 3.离散化后的权值数组长度也就是rank，对应权值范围[1, rank)
    cnt.resize(rank, 0);
    tree.resize(rank, 0);
    // 4.顺序化查找权值数组cnt,查找kth的数
    for (int num : arr) {
        cnt[arr_map[num]]++;
    }
    assert(rank_map[seqFindKth(K)] == sort_arr[K - 1]);
    cout << rank_map[seqFindKth(K)] << " " << sort_arr[K - 1] << "\n\n";
    // 5.树状数组二分查找， O(log2n^2)
    // 初始化树状数组，也可以根据权值数组cnt初始化
    for (int num : arr) {
        update(arr_map[num], 1);
    }
    // 树状数组查找第k大
    assert(rank_map[findKthNum(K)] == sort_arr[K - 1]);
    cout << rank_map[findKthNum(K)] << " " << sort_arr[K - 1] << "\n\n";

    // 6.树状数组倍增查找O(log2n)
    assert(rank_map[findKth(K)] == sort_arr[K - 1]);
    cout << rank_map[findKth(K)] << " " << sort_arr[K - 1] << "\n\n";
}