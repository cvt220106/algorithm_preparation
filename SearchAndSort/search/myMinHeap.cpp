//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MinHeap {
public:
    MinHeap() = default;

    void push(T val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty())
            throw out_of_range("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
    }

    T top() {
        if (heap.empty())
            throw out_of_range("Heap is empty");
        return heap[0];
    }

    int size() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }

private:
    vector<T> heap;

    void siftUp(int index) {
        // 用于插入新的元素后，小元素向上调整
        // 不断的和父节点元素对比，若小于父节点，就交换到父节点，继续对比
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] >= heap[parent])
                break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void siftDown(int index) {
        // 用于删除堆顶后，将堆尾元素替换到堆顶后，大元素向下调整
        // 不断找寻左右子节点中的最小值，进行对比，若小于当前节点，就交换，继续对比调整
        int left, right, min_index;
        while ((left = index * 2 + 1) < heap.size()) {
            right = left + 1;
            min_index = index;
            if (heap[left] < heap[min_index])
                min_index = left;
            if (right < heap.size() && heap[right] < heap[min_index])
                min_index = right;
            if (min_index == index)
                // 未发生改变，说明左右子节点都没父节点小，调整结束
                break;
            swap(heap[index], heap[min_index]);
            index = min_index;
        }
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 6, 5, 4};
    MinHeap<int> my_min_heap;
    priority_queue<int, vector<int>, greater<>> std_min_heap;
    for (int num : nums) {
        my_min_heap.push(num);
        std_min_heap.push(num);
        cout << "push check" << endl;
        cout << "my min heap top: " << my_min_heap.top() << endl;
        cout << "std min heap top: " << std_min_heap.top() << endl;
        cout << "my min heap size: " << my_min_heap.size() << endl;
        cout << "std min heap size: " << std_min_heap.size() << endl;
    }

    for (int i = 0; i < 6; i++) {
        my_min_heap.pop();
        std_min_heap.pop();
        cout << "pop check" << endl;
        cout << "my min heap top: " << my_min_heap.top() << endl;
        cout << "std min heap top: " << std_min_heap.top() << endl;
        cout << "my min heap size: " << my_min_heap.size() << endl;
        cout << "std min heap size: " << std_min_heap.size() << endl;
    }
    cout << "empty check" << endl;
    cout << "my min heap empty: " << my_min_heap.empty() << endl;
    cout << "std min heap empty: " << std_min_heap.empty() << endl;
}