//
// Created by jackyYoung on 24-8-15.
//
#include <bits/stdc++.h>
using namespace std;

/// 题目链接：https://kamacoder.com/problempage.php?pid=1238

void print(double x, double y) {
    printf("%.5lf, %.5lf\n", x, y);
}

double distance(vector<double> d1, vector<double> d2) {
    return sqrt(abs(pow(d1[0] - d2[0], 2)) + abs(pow(d1[1] - d2[1], 2)));
}

int main() {
    int n;
    cin >> n;
    vector<vector<double>> v(n);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    double s;
    cin >> s;
    double prev_reamin = 0;
    print(v[0][0], v[0][1]);
    for (int i = 1; i < n; i++) {
        double need_dist = s - prev_reamin;
        double dist = distance(v[i], v[i - 1]);
        if (dist < need_dist) {
            prev_reamin += dist;
        } else if (dist > need_dist) {
            double x_diff = v[i][0] - v[i - 1][0];
            double y_diff = v[i][1] - v[i - 1][1];
            double ratio = need_dist / dist;
            print(v[i - 1][0] + x_diff * ratio,
                  v[i - 1][1] + y_diff * ratio);
            prev_reamin = dist - need_dist;
            int t = 1;
            while (prev_reamin > s) {
                ratio = (need_dist + s * t) / dist;
                print(v[i - 1][0] + x_diff * ratio,
                      v[i - 1][1] + y_diff * ratio);
                prev_reamin -= s;
                t++;
            }
        } else {
            print(v[i][0], v[i][1]);
            prev_reamin = 0;
        }
    }

    return 0;
}