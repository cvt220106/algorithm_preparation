//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

bool myBinarySearch(vector<int>& nums, int value) {
    // 两种写法，
    // 1. left = 0, right = n - 1, while (left <= right)
    // 跳出循环，没有找到时，right + 1 = left, left指向的就是该元素插入后继续有序的位置
    // insert(left, value)

    // int left = 0, right = nums.size() - 1;
    // while (left <= right) {
    //     int mid = left + (right - left) / 2;
    //     if (nums[mid] == value) {
    //         return true;
    //     } else if (nums[mid] > value) {
    //         right = mid - 1;
    //     } else {
    //         left = mid + 1;
    //     }
    // }
    // return false;

    // 2. left = 0, right = n, while(left < right)
    // 跳出循环，没有找到时，right == left, left指向的就是该元素插入后继续有序的位置
    // insert(left, value)

    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == value) {
            return true;
        } else if (nums[mid] > value) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    vector<int> nums(9999999);
    iota(nums.begin(), nums.end(), 1);
    int value = 9999;

    // 二分查找用于判断当前值是否存在与序列中
    auto ret = binary_search(nums.begin(), nums.end(), value);
    cout << ret << endl;
    cout << myBinarySearch(nums, value) << endl;
}