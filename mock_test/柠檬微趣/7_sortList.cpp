//
// Created by jacky on 24-7-30.
//
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pValue;
    Node* pNext;
    Node(int val) : pValue(val), pNext(nullptr) {}
};

// 插入排序
Node* sortList(Node* pHead) {
    Node* index = pHead->pNext;
    pHead->pNext = nullptr;
    while (index != nullptr) {
        Node* next = index->pNext;
        Node* j = pHead;
        while (j->pNext != nullptr && j->pNext->pValue <= index->pValue) {
            j = j->pNext;
        }
        index->pNext = j->pNext;
        j->pNext = index;
        index = next;
    }
    return pHead;
}

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    Node* dummy_head = new Node(-1);

    string num;
    Node* index = dummy_head;
    while (getline(ss, num, ' ')) {
        Node* node = new Node(stoi(num));
        index->pNext = node;
        index = index->pNext;
    }

    dummy_head = sortList(dummy_head);

    index = dummy_head;
    while (index->pNext != nullptr) {
        cout << index->pNext->pValue << " ";
        index = index->pNext;
    }

    delete(index);
    delete(dummy_head);
    return 0;
}