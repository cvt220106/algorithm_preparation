//
// Created by jackyYoung on 2024/9/8.
//
#include <bits/stdc++.h>
using namespace std;

class DataFlowMedium {
private:
    vector<int> data;
    int64_t total_count;
    static constexpr int RANGE = 65536;
    static constexpr int OFFSET = 32769;

    int64_t query(int index) {
        int64_t sum = 0;
        while (index > 0) {
            sum += data[index];
            index -= index & -index;
        }
        return sum;
    }

    void update(int index) {
        while (index <= RANGE) {
            ++data[index];
            index += index & -index;
        }
    }

    // 找到第k小的数
    int findKthNum(int64_t k) {
        int left = 1, right = RANGE;
        while (left < right) {
            int mid = left + (right - left >> 1);
            if (query(mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int findKth(int64_t k) {
        int64_t sum = 0, x = 0;
        for (int i = log2(RANGE); i >= 0; --i) {
            x += 1 << i;
            if (x >= RANGE || sum + data[x] >= k) {
                x -= 1 << i;
            } else {
                sum += data[x];
            }
        }
        return x + 1;
    }
public:
    DataFlowMedium() : data(RANGE + 1, 0), total_count(0) {}
    ~DataFlowMedium() = default;

    void addNum(int16_t num) {
        update(num + OFFSET);
        total_count++;
    }

    double findMedian() {
        if (total_count == 0) {
            throw std::runtime_error("No data");
        }

        if (total_count % 2 == 0) {
            // int16_t left = findKthNum(total_count / 2) - OFFSET;
            // int16_t right = findKthNum(total_count / 2 + 1) - OFFSET;
            int16_t left = findKth(total_count / 2) - OFFSET;
            int16_t right = findKth(total_count / 2 + 1) - OFFSET;
            return (left + right) / 2.0;
        } else {
            // return findKthNum(total_count / 2 + 1) - OFFSET;
            return findKth(total_count / 2 + 1) - OFFSET;
        }
    }

    int64_t getCount() const {
        return total_count;
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