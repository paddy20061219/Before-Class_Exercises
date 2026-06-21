#include <iostream>
#include <vector>
using namespace std;

// LeetCode 56 - Merge Intervals
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 蠢錯誤：完全沒有合併區間
        // 題目要把重疊的 interval 合起來，不是直接原樣回傳。
        return intervals;
    }
};
