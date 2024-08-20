//
// Created by jacky on 24-8-20.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void merge(vector<T>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            nums[k++] = L[i++];
        else
            nums[k++] = R[j++];
    }
    while (i < n1)
        nums[k++] = L[i++];
    while (j < n2)
        nums[k++] = R[j++];
}

template <typename T>
void myMergeSort(vector<T>& nums, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left >> 1);
    myMergeSort(nums, left, mid);
    myMergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
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
    myMergeSort(nums, 0, nums.size() - 1); // 升序
    print(nums, "heap sort by increase: ");
}