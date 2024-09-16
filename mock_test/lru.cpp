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

int main() {
    LRUCache cache(2);
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