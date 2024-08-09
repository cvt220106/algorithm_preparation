//
// Created by jackyYoung on 24-8-9.
//
#include <bits/stdc++.h>
using namespace std;

/// 题目链接：https://kamacoder.com/problempage.php?pid=1233、
/// 解题思路，构造一个数据结构C，存储一个元素的出现次数与其相应的索引信息
/// 重载比较符号，元素出现次数越大，索引越小的对象删除优先级越高
/// 使用优先队列存储所有对象C
/// ！！！tips：当有多个对象有相同cnt大小时，例如为5,而我们剩余删除次数为4
/// 此时即使我们执行删除操作，依旧不能够降低f值至4,因此直接终止，减少代价损耗！！！
/// 因此还需要一个map来存储同样的元素出现次数cnt下，有多少个不同的对象C

/// 操作流程
/// 1. 每次删除操作选取队头元素t进行操作
/// 2. 删除队头元素t的index中的第一个索引
/// 3. 更新map中当前cnt对应的值-1, cnt - 1对应的值 + 1
/// 4. 队头元素t的相应出现次数cnt - 1
/// 5. 此时队头元素t不为空，重新压入优先队列
/// 结束判断：1.k次删除机会用完 2.优先队列为空 3.当前队头元素的cnt对应map的值大于剩余操作次数

struct C {
    int cnt;
    queue<int> index;

    bool operator<(const C& other) const {
        if (cnt == other.cnt) {
            return index.front() > other.index.front();
        }

        return cnt < other.cnt;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, C> cnt;
    // 初始化C对象，记录相同元素的出现次数与其下标索引队列
    // 需要注意，对象索引i从1开始计算！
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        if (cnt.count(v) > 0) {
            cnt[v].cnt++;
            cnt[v].index.push(i);
        } else {
            queue<int> q;
            q.push(i);
            cnt[v] = {1, q};
        }
    }

    // 优先队列，每次队头获取每次删除操作对象
    priority_queue<C> pq;
    // 记录相同元素的出现次数的不同的对象个数
    unordered_map<int, int> count;
    for (auto& [k, v] : cnt) {
        count[v.cnt]++;
        pq.push(std::move(v));
    }
    cnt.clear();

    int cost = 0;
    while (k--) {
        auto t = pq.top();
        pq.pop();
        // 如果剩余操作次数小于能得到下一个更小f值所需的最小操作次数时，直接结束
        if (k + 1 < count[t.cnt]) {
            break;
        }
        // 删除后，更新count信息，当前cnt对应计数-1,下一级cnt - 1对应计数+1
        count[t.cnt]--;
        count[t.cnt - 1]++;
        // 更新t对象信息，同时记录代价值
        t.cnt--;
        cost += t.index.front();
        t.index.pop();
        // 如果t对象仍包含信息，重新压入优先队列
        if (!t.index.empty()) {
            pq.push(t);
        }
    }
    // 时间复杂度，优先队列压入O(logn), 其他操作O(1)，k次循环，O(klogn)

    // 最终优先队列为空，则说明全部删除，若不为空则队头元素cnt即为最小f
    int f = pq.empty() ? 0 : pq.top().cnt;
    cout << f << " " << cost << '\n';
    return 0;
}