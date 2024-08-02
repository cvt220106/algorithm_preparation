//
// Created by jacky on 24-7-31.
//
#include <bits/stdc++.h>
using namespace std;

std::vector<int>::iterator myUpperBound(std::vector<int>& vec, int value) {
    int left = 0;
    int right = vec.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return vec.begin() + left;
}

// next operation is O(n) operation, not like vector O(1) operation
// so is not like set::lower_bound
std::set<int>::iterator myUpperBound(std::set<int>& s, int value) {
    int left = 0;
    int right = s.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (*next(s.begin(), mid) <= value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return next(s.begin(), left);
}

int main() {
    std::vector<int> vec(10000000);
    iota(vec.begin(), vec.end(), 1);
    int value = 9999;

    auto start = chrono::high_resolution_clock::now();
    auto it = myUpperBound(vec, value);
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "vec my upper bound cosume time: " << elapsed.count() * 1000 <<
        " ms"
        << endl; //
    if (it != vec.end()) {
        std::cout << "Upper bound of " << value << " is at position: " <<
            std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << value << " not found" << std::endl;
    }

    start = chrono::high_resolution_clock::now();
    it = upper_bound(vec.begin(), vec.end(), value);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "vector std upper bound cosume time: " << elapsed.count() * 1000 <<
        " ms"
        << endl;

    set<int> s(vec.begin(), vec.end());
    start = chrono::high_resolution_clock::now();
    auto s_it = myUpperBound(s, value);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "set my upper bound cosume time: " << elapsed.count() * 1000 <<
        " ms"
        << endl;
    if (s_it != s.end()) {
        std::cout << "Upper bound of " << value << " is at position: " <<
            std::distance(s.begin(), s_it) << std::endl;
    } else {
        std::cout << value << " not found" << std::endl;
    }

    start = chrono::high_resolution_clock::now();
    auto o_it = s.upper_bound(value);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "set origin upper bound cosume time: " << elapsed.count() * 1000 <<
        " ms"
        << endl;

    return 0;
}
