#include <iostream>
#include <vector>
using namespace std;

// LeetCode 48 - Rotate Image
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 錯誤想法：只做矩陣轉置
        // 但題目要求的是順時針旋轉 90 度，不是單純轉置。
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
