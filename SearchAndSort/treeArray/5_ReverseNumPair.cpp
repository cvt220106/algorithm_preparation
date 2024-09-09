//
// Created by jackyYoung on 2024/9/9.
//
#include <iostream>
#include <vector>
using namespace std;

// 根据定义，直接暴力法遍历
int countReverseNumPair(vector<int>& arr) {
    int cnt = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}

// 通过归并排序，在归并排序过程中
// 天然存在左右关系，因此只需要在arr[i] > arr[j]时处理即可
int merge(vector<int>& arr, int left, int mid, int right) {
    int cnt = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            cnt += n1 - i; // 因为L数组是有序数组，因此[i, n1)范围内都与j构成了逆序数！
        }
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    return cnt;
}

int mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + right >> 1;
    int l_cnt = mergeSort(arr, left, mid);
    int r_cnt = mergeSort(arr, mid + 1, right);
    int cnt = merge(arr, left, mid, right);
    return l_cnt + r_cnt + cnt;
}

// 权值树状数组求逆序数对
// 反向遍历原序列，构建权值树状数组，利用树状数组查询当前元素x - 1的个数
vector<int> tree(105);

int lowbit(int x) {
    return x & -x;
}

void update(int x) {
    ++x;
    while (x < 105) {
        tree[x]++;
        x += lowbit(x);
    }
}

int query(int x) {
    ++x;
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int countReversePair(vector<int>& arr) {
    int cnt = 0;
    for (int i = arr.size() - 1; i >= 0; --i) {
        update(arr[i]);
        cnt += query(arr[i] - 1);
    }
    return cnt;
}

int main() {
    vector<int> arr;
    for (int i = 0; i < 50; ++i) {
        int num = rand() % 100;
        arr.emplace_back(num);
    }
    cout << countReverseNumPair(arr) << endl;
    cout << countReversePair(arr) << endl;
    cout << mergeSort(arr, 0, arr.size() - 1) << endl;
}