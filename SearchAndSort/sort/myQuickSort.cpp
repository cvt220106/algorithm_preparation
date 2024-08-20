//
// Created by jacky on 24-8-20.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
int partition(vector<T>& nums, int low, int high) {
    int pivot_index = low + rand() % (high - low + 1);
    int pivot = nums[pivot_index];
    swap(nums[low], nums[pivot_index]);
    while (low < high) {
        while (low < high && nums[high] >= pivot)
            high--;
        swap(nums[low], nums[high]);
        while (low < high && nums[low] <= pivot)
            low++;
        swap(nums[high], nums[low]);
    }
    nums[low] = pivot;
    return low;
}

template <typename T>
void quickSort(vector<T>& nums, int low, int high) {
    if (low >= high)
        return;
    int pi = partition(nums, low, high);
    quickSort(nums, low, pi - 1);
    quickSort(nums, pi + 1, high);
}

template <typename T>
void myQuickSort(vector<T>& nums) {
    quickSort(nums, 0, nums.size() - 1);
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
    myQuickSort(nums); // 升序
    print(nums, "quick sort by increase: ");
}