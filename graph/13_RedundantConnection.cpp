//
// Created by jacky on 24-8-6.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1181
// 对于一个n点n边的连通无向图，尝试删除一条边，使其变为连通无环无向图，也就是n点n-1边的树
// 并查集解决办法
// 并查集加入过程中，如果出现一条边的两个点已经存在于同一集合的情况
// 则说明该边是冗余可删除的

vector<int> pa, pa_size;

int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y) {
    x = pa[x];
    y = pa[y];
    if (pa_size[x] < pa_size[y])
        swap(x, y);
    pa[y] = x;
    pa_size[x] += pa_size[y];
}

int main() {
    int n;
    cin >> n;
    pa.resize(n + 1);
    iota(pa.begin(), pa.end(), 0);
    pa_size.resize(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << x << " " << y << '\n';
            break;
        }
        unite(x, y);
    }

    return 0;
}