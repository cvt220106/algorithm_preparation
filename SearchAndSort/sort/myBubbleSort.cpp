//
// Created by jacky on 24-8-2.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void myBubbleSort(vector<T>& nums, bool increase = true) {
    int n = nums.size();
    bool flag = true; // if false, means no more swap, the seq is sorted
    while (flag) {
        flag = false;
        for (int i = 0; i < n - 1; i++) {
            if ((increase && nums[i] > nums[i + 1]) || (
                    !increase && nums[i] < nums[i + 1])) {
                flag = true;
                swap(nums[i], nums[i + 1]);
            }
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

    // bubble sort func
    myBubbleSort(nums, true); // 升序
    print(nums, "bubble sort by increase: ");
    myBubbleSort(nums, false); // 降序
    print(nums, "bubble sort by descrease: ");
}