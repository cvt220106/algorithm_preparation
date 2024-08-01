//
// Created by jackyYoung on 24-8-1.
//
#include <bits/stdc++.h>
using namespace std;

/**
小米手机通信校准
题目描述
小米手机生产过程中会经过严苛的测试环节，其中包括手机通讯功能中的射频校准。射频校准会打点数据上报到云端。
其中包含两组数据:第一组数据中会包含此次校准的频道号(freq)信息；第二组会上传一批数据，包含一组频道号(freg)和其对应的损失值(loss)，其中这一组频道号(freg)不会重复，且是有序的。
现在需要根据第一组数据中的频道号(freg)，找到离第二组中频道号(freq)最近的那个freq对应的loss值，
如果两边一样近，则取两边loss的平均。 注：输入为int，输出为double类型四舍五入保留1位小数

输入描述
包含两组数据:
第一组数据中会包含此次校准的频道号(freq)信息。
第二组会上传一批数据，包含一组频道号(freg)和其对应的损失值(loss)，其中这一组频道号(freg)不会重复，且是有序的。

输出描述
离频道号(freq)最近的freq对应的loss值，如果两边一样近，则取两边loss的平均。
输入示例
2800
1950:10 2000:15 3000:9
输出示例
9.0
*/
int main() {
    int freq;
    cin >> freq;
    cin.ignore();
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> freqs;
    vector<int> losses;
    string pair;
    while (ss >> pair) {
        stringstream s(pair);
        string num;
        vector<int> nums;;
        while (getline(s, num, ':')) {
            nums.push_back(stoi(num));
        }
        freqs.push_back(nums[0]);
        losses.push_back(nums[1]);
    }

    int n = freqs.size();
    int index = lower_bound(freqs.begin(), freqs.end(), freq) - freqs.begin();
    double result = 0;
    if (index == n) {
        result = double(losses[n - 1]);
    } else if (index == 0 || freqs[index] == freq) {
        result = double(losses[index]);
    } else {
        int num1 = freqs[index] - freq;
        int num2 = freq - freqs[index - 1];
        if (num1 == num2) {
            result = double(losses[index] + losses[index - 1]) / 2;
        } else if (num1 < num2) {
            result = double(losses[index]);
        } else {
            result = double(losses[index - 1]);
        }
    }

    printf("%.1f", result);
    return 0;
}