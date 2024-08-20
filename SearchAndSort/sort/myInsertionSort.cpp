//
// Created by jacky on 24-8-2.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void myInsertionSort(vector<T>& nums, bool increase = true) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        // 快速判断
        if ((increase && nums[i] >= nums[i - 1]) || (
                !increase && nums[i] <= nums[i - 1])) {
            continue;
        }
        // 有序序列[0, i)， 无序序列[i, n)
        // 因此每次在[0, i - 1]范围内查找插入位置，查找过程中向后移动腾出位置
        // 为了腾出位置，因此我们倒序查找！
        int val = nums[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if ((increase && nums[j] > val) || (!increase && nums[j] < val)) {
                nums[j + 1] = nums[j];
            } else {
                break;
            }
        }
        nums[j + 1] = val;
    }
}

template <typename T>
void myOptimizeInsertionSort(vector<T>& nums, bool increase = true) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int val = nums[i];
        // 使用lower_bound快速在以有序序列中找到要插入的位置
        vector<int>::iterator pos;
        if (increase)
            pos = lower_bound(nums.begin(), nums.begin() + i, val);
        else
            pos = lower_bound(nums.begin(), nums.begin() + i, val,
                              [](const T a, T b) { return a > b; });
        move_backward(pos, nums.begin() + i, nums.begin() + i + 1);
        *pos = val;
    }
}

void print(vector<int>& nums, const string& info = "") {
    cout << info << endl;
    for_each(nums.begin(), nums.end(), [](const int x) { cout << x << " "; });
    cout << "\n\n";
}

int main() {
    vector<int> nums(50);
    iota(nums.begin(), nums.end(), 1);
    print(nums, "origin sequence: ");
    shuffle(nums.begin(), nums.end(), random_device());
    print(nums, "shuffle sequence: ");

    // insertion sort func
    myInsertionSort(nums, true); // 升序
    print(nums, "insertion sort by increase: ");
    myInsertionSort(nums, false); // 降序
    print(nums, "insertion sort by descrease: ");
    myOptimizeInsertionSort(nums);
    print(nums, "optimize insertion sort by increase");
    myOptimizeInsertionSort(nums, false);
    print(nums, "optimize insertion sort by descrease");
}