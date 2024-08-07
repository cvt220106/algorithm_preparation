//
// Created by jacky on 24-8-6.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1177
// 使用并查集解决问题
// 因为是无向图，判断两个节点中是否存在路径，只需要判断，二者是否在同一个并查集集合中即可

vector<int> pa, pa_size;

int find(int x) {
    return x == pa[x] ? x : pa[x] = find(pa[x]);
}

bool isSame(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (pa_size[x] < pa_size[y])
        swap(x, y);
    pa[y] = x;
    pa_size[x] += pa_size[y];
}

int main() {
    int n, k;
    cin >> n >> k;
    pa.resize(n + 1);
    iota(pa.begin(), pa.end(), 0);
    pa_size.resize(n + 1, 1);
    while (k--) {
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }

    int s, d;
    cin >> s >> d;
    cout << isSame(s, d) << endl;
    return 0;
}