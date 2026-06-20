#include <iostream>
using namespace std;

// LeetCode 62 - Unique Paths
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 錯誤想法：每一步都有「往右」或「往下」兩種選擇
        // 所以直接回傳 2 的步數次方。
        int steps = (m - 1) + (n - 1);
        int ans = 1;

        for (int i = 0; i < steps; i++) {
            ans *= 2;
        }

        return ans;
    }
};
