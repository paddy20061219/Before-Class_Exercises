#include <iostream>
#include <vector>
using namespace std;

// LeetCode 74 - Search a 2D Matrix
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 錯誤想法：只搜尋第一列
        // 但 target 可能出現在其他列。
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == target) {
                return true;
            }
        }

        return false;
    }
};
