//
// Created by jacky on 24-7-31.
//
#include <bits/stdc++.h>
using namespace std;
// increasing and descreasing is based on queue front to back
// desc queue: front [9, 6, 5] back
// get max value from queue front
// add new value to back, if new value is bigger than back value, pop_back
// find the first one back value bigger than new value or queue is empty

// inc queue: front [5, 6, 9] back
// get min value from queue front
// add new value to back, if new value is smaller than back value, pop_back
// find the first one back value smaller than new value or queue is empty

class MonotonicIncQueue {
    // use it in find sliding windows min value
private:
    deque<pair<int, int>> q; // pair is (value, index)
    // index is used to check the front value whether in sliding window

public:
    void push(int value, int index) {
        while (!q.empty() && q.back().first > value) {
            q.pop_back();
        }
        q.emplace_back(value, index);
    }

    void pop(int index) {
        if (!q.empty() && q.front().second == index) {
            q.pop_front();
        }
    }

    int front() {
        return q.front().first;
    }
};

class MonotonicDescQueue {
    // use it in find sliding windows max value
private:
    deque<pair<int, int>> q; // pair is (value, index)
    // index is used to check the front value whether in sliding window

public:
    void push(int value, int index) {
        while (!q.empty() && q.back().first < value) {
            q.pop_back();
        }
        q.emplace_back(value, index);
    }

    void pop(int index) {
        if (!q.empty() && q.front().second == index) {
            q.pop_front();
        }
    }

    int front() {
        return q.front().first;
    }
};

std::vector<int> slidingWindowMin(vector<int>& nums, int k) {
    int n = nums.size();
    MonotonicIncQueue q;

    vector<int> result(n - k + 1);
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            q.pop(i - k);
        }
        q.push(nums[i], i);
        if (i >= k - 1) {
            result[i - k + 1] = q.front();
        }
    }

    return result;
}

std::vector<int> slidingWindowMax(vector<int>& nums, int k) {
    int n = nums.size();
    MonotonicDescQueue q;

    vector<int> result(n - k + 1);
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            q.pop(i - k);
        }
        q.push(nums[i], i);
        if (i >= k - 1) {
            result[i - k + 1] = q.front();
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> maxValues = slidingWindowMax(nums, k);
    std::vector<int> minValues = slidingWindowMin(nums, k);

    std::cout << "Max values in sliding window: ";
    for (int val : maxValues) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Min values in sliding window: ";
    for (int val : minValues) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}