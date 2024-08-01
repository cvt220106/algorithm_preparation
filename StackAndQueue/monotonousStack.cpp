//
// Created by jacky on 24-7-31.
//
#include <bits/stdc++.h>
using namespace std;

// use monotonic stack to quick compute next greater/smaller num

// next greater num, descrease stack
// reversal traversal sequence, when current value not smaller than stack top value
// pop the stack until stack is empty or find the bigger value
// if find, this is result what we want
// if not, means no more bigger value than current value
// push current value to stack
vector<int> findNextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }

    return result;
}

// how much day with next greater num, !!store index not direct value!!
// reversal traversal sequence, when current value not smaller than stack top value
// pop the stack until stack is empty or find the bigger value
// if find, st.top() - i, that can get how much days!
// if not, means no more bigger value than current value
// push current value !!index!! to stack
vector<int> findDaysWithNextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && nums[s.top()] <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = nums[s.top()];
        }
        s.push(i);
    }

    return result;
}

// next smaller num, increase stack
// reversal traversal sequence, when current value not larger than stack top value
// pop the stack until stack is empty or find the smaller value
// if find, this is result what we want
// if not, means no more smaller value than current value
// push current value to stack
vector<int> findNextSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() >= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top();
        }
        s.push(nums[i]);
    }

    return result;
}

// leetcode problem
class Solution {
public:
    // 找到多少天后能遇到下一个更热的天气
    // 也就是我们的 find how much day with the next greater num!
    // need store index not value
    // need return index difference not value
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty()
                   && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top() - i;
            }
            st.push(i);
        }

        return result;
    }

    // 不是直接的下一个最大的元素，而是要求当前nums1数组元素x映射到nums2中的位置，在nums2中找下一个最大元素
    // 1.记录nums1中元素与索引的映射关系
    // 2.使用单调栈寻找nums2中元素的下一个最大元素
    // 3.通过元素值映射到nums1的索引中，存储结果
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {
            umap.insert({nums1[i], i});
        }

        vector<int> result(nums1.size(), -1);
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty() && umap.count(nums2[i]) > 0) {
                result[umap[nums2[i]]] = st.top();
            }
            st.push(nums2[i]);
        }

        return result;
    }

    // 循环数组的下一个更大元素
    // 循环展开法，将数组长度*2, 也就是将数组两倍，相当于展开
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        for (int i = n * 2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i % n] = st.top();
            }
            st.push(nums[i % n]);
        }

        return result;
    }

    // 接雨水-双指针法更加简单直观
    // 对于每一列，只需要考量其左右两边是否有比其更高的柱能够围成一个凹槽
    // 对于当前列所能存放的雨水，也就是min(left_max. right_max) - height
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int res = 0;
        while (left < right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (height[left] < height[right]) {
                res += left_max - height[left];
                left++;
            } else {
                res += right_max - height[right];
                right--;
            }
        }
        return res;
    }

    // 柱状图中的最大矩形
    // 要找到当前柱左右两侧第一个小于其的柱体，从而能够最大的扩展宽度
    // 使用两次单调栈，一次逆序遍历，构造递增得到右边第一个小于的高度
    // 一次顺序遍历，同样构造递减得到左边第一个小于的高度
    // 因为需要矩形的宽，因此存储的下标索引，而不是直接高度值
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        // 当一个柱体左右没有其他更低的时候，矩形的宽就是整个左右边界的长度
        vector<int> left(n, -1);
        vector<int> right(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        // 遍历计算每个可能的矩形面积，对比得到最大值
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;
    }
};