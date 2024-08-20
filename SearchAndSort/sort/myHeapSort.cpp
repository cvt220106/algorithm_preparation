//
// Created by jacky on 24-8-20.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void heapify(vector<T>& nums, int n, int idx) {
    int max_idx = idx;
    int left, right;
    while ((left = 2 * idx + 1) < n) {
        right = left + 1;
        if (nums[left] > nums[max_idx])
            max_idx = left;
        if (right < n && nums[right] > nums[max_idx])
            max_idx = right;
        if (max_idx == idx)
            break;
        swap(nums[idx], nums[max_idx]);
        idx = max_idx;
    }
}

template <typename T>
void buildHeap(vector<T>& nums) {
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
        heapify(nums, nums.size(), i);
    }
}

template <typename T>
void myHeapSort(vector<T>& nums) {
    buildHeap(nums);

    for (int i = nums.size() - 1; i >= 0; --i) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
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

    // bubble sort func
    myHeapSort(nums); // 升序
    print(nums, "heap sort by increase: ");
}