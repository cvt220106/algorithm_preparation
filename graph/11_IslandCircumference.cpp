//
// Created by jacky on 24-8-6.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1178
// ！！！不能一看到岛屿题目就想着dfs/bfs遍历
// 本题属于是反套路题，不能使用bfs和dfs来达到目的
// 要想计算岛屿的周长
// 我们需要换个角度思考，对于每一个独立的岛屿，它的周长都是4
// 而两个岛屿相邻时，就会互相覆盖一条边，这时候总周长就需要减去2
// 因此我们岛屿的总周长就是，4 * 岛屿数 - 2 * (相邻次数, 记为cover)

// 但在遍历记录cover数量时，一定要这选择两个方向，不然会重复记录
// 比如a与b左右相邻。 a的左边是b,就不能再去记录b的右边是a了！！

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int island_num = 0;
    int cover = 0;
    // 只判断上边和左边的相邻！
    int dx[2] = {-1, 0};
    int dy[2] = {0, -1};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 1) {
                island_num++;
                for (int k = 0; k < 2; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && graph[nx][ny]
                        == 1) {
                        cover++;
                    }
                }
            }
        }
    }

    cout << island_num * 4 - 2 * cover << '\n';

    return 0;
}