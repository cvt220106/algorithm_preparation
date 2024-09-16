//
// Created by jackyYoung on 24-8-17.
//
#include <bits/stdc++.h>
using namespace std;

void printMartix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            printf("%2d ", matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

/// 上下翻转
void verticalFilp(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        swap(matrix[i], matrix[n - 1 - i]);
    }
}

/// 左右翻转
void horizontalFilp(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

/// 主对角线翻转
void mainDiagonalFlip(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

/// 顺时针90°旋转
/// 主对角线翻转 + 左右翻转
void rotate_90(vector<vector<int>>& matrix) {
    mainDiagonalFlip(matrix);
    horizontalFilp(matrix);
}

/// 顺时针180°旋转
/// 上下翻转 + 左右翻转
void rotate_180(vector<vector<int>>& matrix) {
    verticalFilp(matrix);
    horizontalFilp(matrix);
}

/// 顺时针270°旋转等同于逆时针90°
/// 主对角线翻转 + 上下翻转
void rotate_270(vector<vector<int>>& matrix) {
    mainDiagonalFlip(matrix);
    verticalFilp(matrix);
}

int main() {
    vector<vector<int>> matrix(5, vector<int>(5));
    int idx = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = idx++;
        }
    }
    printMartix(matrix);
    // verticalFilp(matrix);
    // printMartix(matrix);
    // horizontalFilp(matrix);
    // printMartix(matrix);
    // mainDiagonalFlip(matrix);
    // printMartix(matrix);
    // rotate_90(matrix);
    // printMartix(matrix);
    // rotate_180(matrix);
    // printMartix(matrix);
    rotate_270(matrix);
    printMartix(matrix);
    return 0;
}