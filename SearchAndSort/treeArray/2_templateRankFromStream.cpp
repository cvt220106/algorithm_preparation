//
// Created by jacky on 24-9-9.
//
#include <bits/stdc++.h>
using namespace std;
// 模板题型，面试题 10.10. 数字流的秩
// https://leetcode.cn/problems/rank-from-stream-lcci
class StreamRank {
public:
    StreamRank() : v(50002, 0) {}

    void track(int x) {
        ++x;
        while (x <= 50001) {
            v[x]++;
            x += lowbit(x);
        }
    }

    int getRankOfNumber(int x) {
        ++x;
        int ans = 0;
        while (x > 0) {
            ans += v[x];
            x -= lowbit(x);
        }
        return ans;
    }

private:
    vector<int> v;

    int lowbit(int x) {
        return x & -x;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) : kth(k), tree(2005, 0) {
        for (int num : nums) {
            update(num + OFFSET);
            count++;
        }
    }

    int add(int val) {
        update(val + OFFSET);
        count++;
        return findKth(count - kth + 1) - OFFSET;
        // int l = 1, r = n - 1;
        // while (l < r) {
        //     int mid = l + (r - l >> 1);
        //     if (query(mid) < count - kth + 1) {
        //         l = mid + 1;
        //     } else {
        //         r = mid;
        //     }
        // }

        // return l - OFFSET;
    }

private:
    vector<int> tree;
    int kth;
    int count = 0;
    int n = 2005;
    const int OFFSET = 1001;

    int lowbit(int x) { return x & -x; }

    void update(int x) {
        while (x < n) {
            tree[x]++;
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

    int findKth(int k) {
        int sum = 0, x = 0;
        for (int i = log2(n); i >= 0; --i) {
            x += 1 << i;
            if (x >= n || sum + tree[x] >= k)
                x -= 1 << i;
            else
                sum += tree[x];
        }
        return x + 1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    KthLargest obj(3, {4, 5, 8, 2});
    cout << obj.add(3) << endl;
    cout << obj.add(5) << endl;
    cout << obj.add(10) << endl;
}