//
// Created by jackyYoung on 24-7-31.
//
/** 题目介绍
最大营业额
    有一个工作室，有一组订单，每个订单有 ddl和 value。
    每完成一个订单花费一个时间周期。因此不得不放弃一些订单。从周期 0开始到 1e9
    可以满足的最大营业额是多少。
    输入:
    // 3个订单
    3
    2 10
    1 5
    1 7

    输出:17
    解析:从8时刻开始，制作订单3，得到7元。1时刻制作订单1，得到10元。
*/
// 单调队列+贪心
// 将订单按照ddl从小到大升序排列，这样顺序取的时候，可以边取边判断ddl与当前时间是否匹配
// 为了维持获取的订单是满足ddl的，需要维护一个单调队列
// 按照订单的value降序排序的小根堆，也就是说，最小的value的订单会在根顶上
// 这样有便于我们在时间不够用时，替换掉value较小的订单，而选择更大的value
#include <bits/stdc++.h>
using namespace std;

struct Order {
    int deadline;
    int value;
};

int getMaxValue(vector<Order> orders) {
    // sort by deadline, increasing
    sort(orders.begin(), orders.end(), [](const Order a, const Order b) {
        return a.deadline < b.deadline;
    });

    // 构建小根堆
    priority_queue<int, vector<int>, greater<>> min_heap;
    int total_value = 0;
    for (auto& order : orders) {
        if (min_heap.size() < order.deadline) {
            // 当前时间小于货品的ddl，因此可以直接加入
            total_value += order.value;
            min_heap.push(order.value);
        } else if (!min_heap.empty() && min_heap.top() < order.value) {
            // 达到时间限制，如果当前的value更大，那就进行替换
            total_value -= min_heap.top() - order.value;
            min_heap.pop();
            min_heap.push(order.value);
        }
    }

    return total_value;
}

int main() {
    int n;
    cin >> n;
    vector<Order> orders(n);
    for (int i = 0; i < n; i++) {
        cin >> orders[i].deadline >> orders[i].value;
    }

    cout << getMaxValue(orders) << endl;
    return 0;
}