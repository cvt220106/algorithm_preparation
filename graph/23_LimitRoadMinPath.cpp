//
// Created by jacky on 24-8-8.
//
#include <bits/stdc++.h>
using namespace std;

// 题目链接：https://kamacoder.com/problempage.php?pid=1152
// 单源有限路长的最短路径！
// 松弛操作的次数正好对应的就是边数
// 因此我们将松弛操作的次数限制在有限路长+1内，就可以得到对应的最短路径
// 如果超过k次的松弛操作，dist仍为初始值，则说明不可达！
// 但需要注意的是，因为限制了跳数，我们要保证每次松弛操作
// 都是基于上一次迭代中的松弛操作得到的第i - 1次最短路径出发的，而不是本次迭代中的第i次最短路径
// 因此迭代前需要使用一个last_dist保存i-1次的最短路径信息，通过它进行松弛操作转移

struct edge {
    int u, v, w;
};

int V, E;
vector<edge> graph;
vector<int> dist;

// bool值用于判断是否抵达一个负环
// 需要注意的是，如果返回false,不代表整个图不存在负环
// 只是说明从s点出发，不存在负环！
bool BellmanFord(int s, int k) {
    dist.resize(V + 1, INT_MAX);
    dist[s] = 0;
    vector<int> last_dist;
    bool flag = false; // 判断本次循环中是否发生松弛操作
    // 限制最短路径边数最多为k，因此最多松弛转移k+1次
    for (int i = 0; i <= k; ++i) {
        flag = false;
        // 遍历所有边，寻找松弛操作
        last_dist = dist;
        for (int j = 0; j < E; ++j) {
            auto [u, v, w] = graph[j];
            // 已经是最大值，必定无法松弛
            if (last_dist[u] == INT_MAX)
                continue;;
            if (dist[v] > last_dist[u] + w) {
                dist[v] = last_dist[u] + w;
                flag = true;
            }
        }

        // 没有松弛操作，算法终止
        if (!flag) {
            break;
        }
    }

    // 为true,说明k+1次循环仍有松弛操作，则存在负环
    return flag;
}


int main() {
    cin >> V >> E;
    graph.resize(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i] = {u, v, w};
    }

    int s, d, k;
    cin >> s >> d >> k;
    BellmanFord(s, k);
    if (dist[d] == INT_MAX) {
        cout << "unreachable\n";
    } else {
        cout << dist[d] << '\n';
    }
    return 0;
}