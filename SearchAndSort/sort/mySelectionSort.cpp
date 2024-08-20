//
// Created by jacky on 24-8-2.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void mySelectionSort(vector<T>& nums, bool increase = true) {
    // 默认升序！
    int n = nums.size();
    int index;
    for (int i = 0; i < n; i++) {
        index = i;
        for (int j = i + 1; j < n; j++) {
            if ((increase && nums[index] > nums[j]) || (
                    !increase && nums[index] < nums[j])) {
                index = j;
            }
        }
        if (index != i) {
            swap(nums[index], nums[i]);
        }
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

    // select sort func
    mySelectionSort(nums, true); // 升序
    print(nums, "select sort by increase: ");
    mySelectionSort(nums, false); // 降序
    print(nums, "select sort by descrease: ");

    // use stl quick achieve select sort
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        iter_swap(it, min_element(it, nums.end()));
    }
    print(nums, "stl quick achieve select sort by increase: ");
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        iter_swap(it, max_element(it, nums.end()));
    }
    print(nums, "stl quick achieve select sort by descrease: ");
}