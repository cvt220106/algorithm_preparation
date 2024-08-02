//
// Created by jacky on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MaxHeap {
public:
    MaxHeap() = default;

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
        // 用于插入新的元素后，大元素向上调整
        // 不断的和父节点元素对比，若大于父节点，就交换到父节点，继续对比
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent])
                break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void siftDown(int index) {
        // 用于删除堆顶后，将堆尾元素替换到堆顶后，小元素向下调整
        // 不断找寻左右子节点中的最大值，进行对比，若大于当前节点，就交换，继续对比调整
        int left, right, max_index;
        while ((left = index * 2 + 1) < heap.size()) {
            right = left + 1;
            max_index = index;
            if (heap[left] > heap[max_index])
                max_index = left;
            if (right < heap.size() && heap[right] > heap[max_index])
                max_index = right;
            if (max_index == index)
                // 未发生改变，说明左右子节点都没父节点大，调整结束
                break;
            swap(heap[index], heap[max_index]);
            index = max_index;
        }
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 6, 5, 4};
    MaxHeap<int> my_max_heap;
    priority_queue<int> std_max_heap;
    for (int num : nums) {
        my_max_heap.push(num);
        std_max_heap.push(num);
        cout << "push check" << endl;
        cout << "my max heap top: " << my_max_heap.top() << endl;
        cout << "std max heap top: " << std_max_heap.top() << endl;
        cout << "my max heap size: " << my_max_heap.size() << endl;
        cout << "std max heap size: " << std_max_heap.size() << endl;
    }

    for (int i = 0; i < 6; i++) {
        my_max_heap.pop();
        std_max_heap.pop();
        cout << "pop check" << endl;
        cout << "my max heap top: " << my_max_heap.top() << endl;
        cout << "std max heap top: " << std_max_heap.top() << endl;
        cout << "my max heap size: " << my_max_heap.size() << endl;
        cout << "std max heap size: " << std_max_heap.size() << endl;
    }
    cout << "empty check" << endl;
    cout << "my max heap empty: " << my_max_heap.empty() << endl;
    cout << "std max heap empty: " << std_max_heap.empty() << endl;
}