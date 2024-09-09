//
// Created by jackyYoung on 2024/9/9.
//
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
class DataFlowMedium {
private:
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;

public:
    void addNum(int num) {
        if (max_q.size() == min_q.size()) {
            max_q.push(num);
            min_q.push(max_q.top());
            max_q.pop();
        } else {
            min_q.push(num);
            max_q.push(min_q.top());
            min_q.pop();
        }
    }

    double findMedian() {
        if (max_q.size() == min_q.size()) {
            return (min_q.top() + max_q.top()) / 2.0;
        } else {
            return min_q.top();
        }
    }
};

int main() {
    DataFlowMedium mf;

    // 测试奇数个数的情况
    for (int i = 1; i <= 5; ++i) {
        int num = rand() % 100;
        cout << num << " ";
        mf.addNum(num);
    }
    cout << "\n\n";
    std::cout << "Median of 1-5: " << mf.findMedian() << std::endl;

    // 测试偶数个数的情况
    mf.addNum(6);
    std::cout << "Median of 1-6: " << mf.findMedian() << std::endl;
}