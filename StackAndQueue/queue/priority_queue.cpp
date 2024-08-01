//
// Created by jacky on 24-8-1.
//
// leetcode347
// 前k个高频元素
// 优先队列，本质就是堆
// 大根堆 priority_queue<int>，最大的元素在堆顶
// 小根堆 priority_queue<int, vector<int>, greater<>> 最小的元素在堆顶
// 要得到前k个最大值，因此我们需要小根堆，不断的剔除堆顶的小值，维护小根堆的大小为k
// 这样最终小根堆中的k个值就是前k大的值
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 先统计每个元素的出现频率
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }

        auto cmp = [](
            const auto& a, const auto& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<
                           pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto& num : cnt) {
            if (pq.size() < k) {
                pq.emplace(num);
            } else if (pq.top().second < num.second) {
                pq.pop();
                pq.emplace(num);
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};

int main() {
    vector<int> nums = {3, 0, 1, 0};
    cout << Solution().topKFrequent(nums, 1)[0] << endl;
}