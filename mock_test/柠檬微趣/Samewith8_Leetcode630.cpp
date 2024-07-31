//
// Created by jackyYoung on 24-7-31.
//
/**
630. 课程表 III
这里有 n 门不同的在线课程，按从 1 到 n编号。
给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。
你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
返回你最多可以修读的课程数目。

示例 1：
输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
输出：3
解释：
这里一共有 4 门课程，但是你最多可以修 3 门：
首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。

示例 2：
输入：courses = [[1,2]]
输出：1

示例 3：
输入：courses = [[3,2],[4,3]]
输出：0

提示:
1 <= courses.length <= 10^4
1 <= durationi, lastDayi <= 10^4
https://leetcode.cn/problems/course-schedule-iii/description/
*/

// 可以看到，大致的思路和前面的最大营业额是一致的，只不过对比的东西以及结果发生了一些变化
// 上一题中，每个订单消耗的时间是固定的，价值是不同的
// 这个题中，每门课消耗的时间是不定的，但价值是一样的，也就是都是一门课
// 但实际上本质我们都还是要求价值最高，需要变化的一点就是时间的处理
// 不能简单的使用heap的大小表示时间，而需要额外去统计总共时间
// 不过本题中heap的大小可以用来表示选择的课程门数，也就是价值！
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 依照ddl进行升序排序
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        // 不同于value，我们要求value越大越好，选课就需要课程跨度越小越好，因此使用大根堆！
        priority_queue<int> max_heap;
        int total_time = 0;
        for (auto &course : courses) {
            if (total_time + course[0] <= course[1]) {
                total_time += course[0];
                max_heap.push(course[0]);
            } else if (!max_heap.empty() && course[0] < max_heap.top()) {
                total_time -= max_heap.top() - course[0];
                max_heap.pop();
                max_heap.push(course[0]);
            }
        }

        return max_heap.size();
    }
};