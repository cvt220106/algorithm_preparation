//
// Created by jacky on 24-8-10.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<unordered_set<int>> tree;
    int n;

    void build(int node, int start, int end, const vector<int>& colors) {
        if (start == end) {
            tree[node].insert(colors[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, colors);
        build(2 * node + 1, mid + 1, end, colors);
        tree[node].insert(tree[2 * node].begin(), tree[2 * node].end());
        tree[node].insert(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
    }

    unordered_set<int> query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return {};
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        auto left = query(2 * node, start, mid, l, r);
        auto right = query(2 * node + 1, mid + 1, end, l, r);
        left.insert(right.begin(), right.end());
        return left;
    }

public:
    SegmentTree(const vector<int>& colors) {
        n = colors.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, colors);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r).size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    SegmentTree st(colors);

    int left = 0, right = n - 1;
    for (int i = 0; i < m; i++) {
        char direction;
        int length;
        cin >> direction >> length;

        if (direction == 'L') {
            int result = st.query(left, (left + length - 1) % n);
            left = (left + length) % n;
            cout << result << '\n';
        } else {
            // direction == 'R'
            int new_right = (right - length + 1 + n) % n;
            if (new_right <= right) {
                int result = st.query(new_right, right);
                cout << result << '\n';
            } else {
                int result = st.query(new_right, n - 1) + st.query(0, right);
                cout << result << '\n';
            }
            right = (right - length + n) % n;
        }
    }

    return 0;
}