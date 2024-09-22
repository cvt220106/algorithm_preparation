//
// Created by jackyYoung on 24-9-16.
//
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
private:
    int capacity;
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>> m;

public:
    LRUCache(int size) : capacity(size) {}
    ~LRUCache() = default;

    int get(int key) {
        if (m.count(key) > 0) {
            lru.splice(lru.begin(), lru, m[key].second);
            m[key] = {m[key].first, lru.begin()};
            return m[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.count(key) == 0) {
            if (lru.size() == capacity) {
                m.erase(lru.back());
                lru.pop_back();
            }
            lru.push_front(key);
        } else {
            lru.splice(lru.begin(), lru, m[key].second);
        }
        m[key] = {value, lru.begin()};
    }
};

struct LinkNode {
    int val;
    LinkNode* prev;
    LinkNode* next;
    explicit LinkNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};

/// 手写双链表构建lru
class DoubleLinkList {
private:
    LinkNode* dummy_head{nullptr};
    LinkNode* dummy_tail{nullptr};
    int size_{0};
public:
    DoubleLinkList() {
        dummy_head = new LinkNode(-1);
        dummy_tail = new LinkNode(-1);
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }

    ~DoubleLinkList() {
        if (dummy_head) {
            auto node = dummy_head->next;
            delete dummy_head;
            dummy_head = node;
        }
    }

    void push_front(int val) {
        size_++;
        auto node = new LinkNode(val);
        auto tmp = dummy_head->next;
        dummy_head->next = node;
        node->prev = dummy_head;
        node->next = tmp;
        tmp->prev = node;
    }

    int pop_back() {
        size_--;
        auto node = dummy_tail->prev;
        int val = node->val;
        dummy_tail->prev = node->prev;
        node->prev->next = dummy_tail;
        delete node;
        return val;
    }

    void renew(LinkNode* node) {
        if (node == dummy_head->next) return;
        // remove
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // insert
        node->next = dummy_head->next;
        dummy_head->next->prev = node;
        dummy_head->next = node;
        node->prev = dummy_head;
    }

    LinkNode* front() { return dummy_head->next; }

    int length() { return size_; }
};

class LRUCache2 {
private:
    int capacity;
    DoubleLinkList lru;
    unordered_map<int, pair<int, LinkNode*>> m;

public:
    LRUCache2(int size) : capacity(size) {}
    ~LRUCache2() = default;

    int get(int key) {
        if (m.count(key) > 0) {
            lru.renew(m[key].second);
            m[key] = {m[key].first, lru.front()};
            return m[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (lru.length() == capacity) {
                int val = lru.pop_back();
                m.erase(val);
            }
            lru.push_front(key);
        } else {
            lru.renew(m[key].second);
        }
        m[key] = {value, lru.front()};
    }
};


int main() {
    LRUCache2 cache(2);
    int prev_num = 0;
    for (int i = 0; i < 10; i++) {
        int num = rand() % 5 + 1;
        printf("put key %d : %d\n", num, num);
        cache.put(num, num);
        if (i > 0)
            printf("cache get key %d, value %d\n", prev_num, cache.get(prev_num));

        prev_num = num;
    }
}